#include "HCEnemyBase.h"
#include "Umbrella.h"
#include <cmath>

HCEnemyBase::HCEnemyBase()
{
	m_position1.Set(0, 0);
	m_position2.Set(0, 0);
}

HCEnemyBase::~HCEnemyBase()
{
}

void HCEnemyBase::setup()
{
	// 派生クラス（HCEnemy1 / HCEnemy2）側で初期位置などを設定する
	m_hp = 30;
	m_targetIndex = 0;

	// ルートが設定されていれば、最初の地点に配置
	if (!m_route.empty()) {
		int offsetX = m_position2.nX - m_position1.nX;
		int offsetY = m_position2.nY - m_position1.nY;

		m_position1 = m_route[0];
		m_position2.Set(m_position1.nX + offsetX, m_position1.nY + offsetY);
	}
}

void HCEnemyBase::update()
{
	// 派生クラス側で個別の挙動を追加する場合はここから EnemyMove() を呼び出す
	EnemyMove();
}

void HCEnemyBase::draw()
{
	// 派生クラス側で見た目（色・画像など）を指定する
}

void HCEnemyBase::setRoute(const std::vector<HSPoint>& route)
{
	m_route = route;
}

void HCEnemyBase::EnemyMove()
{
	if (m_route.empty()) return;

	// 現在の目標地点
	HSPoint target = m_route[m_targetIndex];

	int dx = target.nX - m_position1.nX;
	int dy = target.nY - m_position1.nY;
	double dist = std::sqrt(static_cast<double>(dx) * dx + static_cast<double>(dy) * dy);

	if (dist < m_speed) {
		// 目標地点に到着 → 次の地点へ（サイズ分のオフセットを維持したまま更新）
		int offsetX = m_position2.nX - m_position1.nX;
		int offsetY = m_position2.nY - m_position1.nY;

		m_position1 = target;
		m_position2.Set(target.nX + offsetX, target.nY + offsetY);

		m_targetIndex = (m_targetIndex + 1) % m_route.size();  // 最後まで行ったら最初に戻る
	}
	else {
		// 目標地点に向かって進む
		int moveX = static_cast<int>((dx / dist) * m_speed);
		int moveY = static_cast<int>((dy / dist) * m_speed);

		m_position1.nX += moveX;
		m_position1.nY += moveY;
		m_position2.nX += moveX;
		m_position2.nY += moveY;
	}
}
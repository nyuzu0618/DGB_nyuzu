#pragma once
#include "HCCharacter.h"
#include "Holy.h"
#include <vector>

class HCEnemyBase : public HCCharacter {
public:
	HCEnemyBase( );
	virtual ~HCEnemyBase( );

	void setup( ) override;
	void update( ) override;
	void draw( ) override;

	bool isDead( ) const { return m_hp <= 0; }
	void takeDamage( int dmg ) { m_hp -= dmg; }
	void Kill( ) { m_hp = 0; }  // ボールに近距離で当たった時など、即死させたい場合に使う

	// ボールとの当たり判定などで使う、敵の現在座標
	HSPoint GetPosition( ) const { return m_position1; }

	// ルートを設定する（派生クラスや外部から呼ぶ）
	void setRoute( const std::vector<HSPoint>& route );

protected:
	// ルートに沿って座標を更新する共通処理
	// （HCEnemy1 / HCEnemy2 それぞれの update() から呼び出す想定）
	void EnemyMove( );

protected:
	HSPoint m_position1;
	HSPoint m_position2;
	int     m_speed = 2;
	int     m_hp = 30;

	std::vector<HSPoint> m_route;    // 巡回する座標リスト
	int                   m_targetIndex = 0;  // 現在向かっている目標地点のインデックス
};
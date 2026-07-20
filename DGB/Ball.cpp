#include "Ball.h"
#include "DxLib.h"
#include "Input.h"
#include "Umbrella.h"
#include "HCPlayerBase.h"
#include "EnemyManager.h"
#include "HCEnemyBase.h"
#include <cmath>

Ball::Ball( ) {}

Ball::~Ball( ) {}

void Ball::setup( ) {
	// 初期状態：1Pの右手がボールを持っている状態からスタート
	// （どこから始めるかはここを変えれば調整できる）
	m_state = BallState::HeldByPlayer;
	m_currentSlot = BallOwnerSlot::P1_Right;
	m_lastThrowerSlot = m_currentSlot;
	m_position = GetSlotPosition( m_currentSlot );
}

HSPoint Ball::GetSlotPosition( BallOwnerSlot slot ) const {
	switch ( slot ) {
	case BallOwnerSlot::P1_Right:
		return ( g_pPlayer1 != nullptr ) ? g_pPlayer1->GetPosition1( ) : HSPoint( 0, 0 );
	case BallOwnerSlot::P1_Left:
		return ( g_pPlayer1 != nullptr ) ? g_pPlayer1->GetPosition2( ) : HSPoint( 0, 0 );
	case BallOwnerSlot::P2_Bottom:
		return ( g_pPlayer2 != nullptr ) ? g_pPlayer2->GetPosition1( ) : HSPoint( 0, 0 );
	case BallOwnerSlot::P2_Top:
		return ( g_pPlayer2 != nullptr ) ? g_pPlayer2->GetPosition2( ) : HSPoint( 0, 0 );
	}
	return HSPoint( 0, 0 );
}

void Ball::ThrowTo( BallOwnerSlot targetSlot ) {
	m_lastThrowerSlot = m_currentSlot;
	m_throwOrigin = m_position;
	m_targetSlot = targetSlot;
	m_state = BallState::Flying;
}

void Ball::update( ) {
	if ( m_state == BallState::HeldByPlayer ) {
		// 保持中は、持っているプレイヤーの動きに同期する
		m_position = GetSlotPosition( m_currentSlot );

		bool isP1Holding = ( m_currentSlot == BallOwnerSlot::P1_Right || m_currentSlot == BallOwnerSlot::P1_Left );
		bool isP2Holding = ( m_currentSlot == BallOwnerSlot::P2_Bottom || m_currentSlot == BallOwnerSlot::P2_Top );

		if ( isP1Holding ) {
			// 1Pが持っている：左矢印→下の2Pへ、右矢印→上の2Pへ
			if ( Input::isKeyTrigger( KEY_INPUT_LEFT ) )  ThrowTo( BallOwnerSlot::P2_Bottom );
			if ( Input::isKeyTrigger( KEY_INPUT_RIGHT ) ) ThrowTo( BallOwnerSlot::P2_Top );
		} else if ( isP2Holding ) {
			// 2Pが持っている：Sキー→左の1Pへ、Wキー→右の1Pへ
			if ( Input::isKeyTrigger( KEY_INPUT_S ) ) ThrowTo( BallOwnerSlot::P1_Left );
			if ( Input::isKeyTrigger( KEY_INPUT_W ) ) ThrowTo( BallOwnerSlot::P1_Right );
		}
		return;
	}

	// ── 飛んでいる最中 ──
	// 目標スロットの「今の座標」を常に追従する
	HSPoint target = GetSlotPosition( m_targetSlot );

	int dx = target.nX - m_position.nX;
	int dy = target.nY - m_position.nY;
	double dist = std::sqrt( static_cast< double >( dx ) * dx + static_cast< double >( dy ) * dy );

	if ( dist < m_speed ) {
		// 目標に到達 → そのスロットが保持する
		m_currentSlot = m_targetSlot;
		m_state = BallState::HeldByPlayer;
		m_position = GetSlotPosition( m_currentSlot );
		return;
	}

	m_position.nX += static_cast< int >( ( dx / dist ) * m_speed );
	m_position.nY += static_cast< int >( ( dy / dist ) * m_speed );

	// ── 敵との当たり判定 ──
	if ( g_pEnemyManager != nullptr ) {
		HCEnemyBase* hitEnemy = g_pEnemyManager->CheckCollision( m_position, m_hitRadius );
		if ( hitEnemy != nullptr ) {
			// 投げた地点から何マス分移動したところで当たったかを計算
			int ox = m_position.nX - m_throwOrigin.nX;
			int oy = m_position.nY - m_throwOrigin.nY;
			double traveled = std::sqrt( static_cast< double >( ox ) * ox + static_cast< double >( oy ) * oy );
			int cellsTraveled = static_cast< int >( traveled / g_cell_width );

			if ( cellsTraveled >= 2 ) {
				// 2マス以上進んでから当たった → 敵がキャッチ
				// ボールは消えて、最後に投げた人の元へ瞬間移動で戻る
				m_currentSlot = m_lastThrowerSlot;
				m_state = BallState::HeldByPlayer;
				m_position = GetSlotPosition( m_currentSlot );
			} else {
				// 2マス未満（投げてすぐ近くで）当たった → 敵は死ぬ。ボールはそのまま飛び続ける
				hitEnemy->Kill( );
			}
		}
	}
}

void Ball::draw( ) {
	DrawCircle( m_position.nX, m_position.nY, 12, GetColor( 255, 255, 0 ), TRUE );
}
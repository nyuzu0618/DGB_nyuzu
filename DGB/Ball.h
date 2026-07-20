#pragma once
#include "Holy.h"

// ボールを持っている/投げ先となる4つの「持ち手」
// P1_Right = 1Pの右側（HCPlayer1::GetPosition1）
// P1_Left  = 1Pの左側（HCPlayer1::GetPosition2）
// P2_Bottom= 2Pの下側（HCPlayer2::GetPosition1）
// P2_Top   = 2Pの上側（HCPlayer2::GetPosition2）
enum class BallOwnerSlot {
	P1_Right,
	P1_Left,
	P2_Bottom,
	P2_Top
};

enum class BallState {
	HeldByPlayer,  // どこかのプレイヤーが持っている
	Flying         // 投げられて飛んでいる最中
};

class Ball {
public:
	Ball( );
	~Ball( );

	void setup( );
	void update( );
	void draw( );

private:
	// 指定したスロットの現在座標を取得する（プレイヤーの今の位置を追従するため毎回問い合わせる）
	HSPoint GetSlotPosition( BallOwnerSlot slot ) const;

	// targetSlotに向かって投げる
	void ThrowTo( BallOwnerSlot targetSlot );

private:
	BallState     m_state = BallState::HeldByPlayer;
	BallOwnerSlot m_currentSlot = BallOwnerSlot::P1_Right;      // 保持中のスロット／飛行中は目標到達後にここに入る
	BallOwnerSlot m_lastThrowerSlot = BallOwnerSlot::P1_Right;  // 最後に投げた人（キャッチされた時にここへ戻る）
	BallOwnerSlot m_targetSlot = BallOwnerSlot::P1_Right;       // 飛行中の目標スロット

	HSPoint m_position;     // 現在のボール座標
	HSPoint m_throwOrigin;  // 投げた瞬間の座標（通過マス数の計算に使う）

	int m_speed = 6;        // 飛行速度
	int m_hitRadius = 24;   // 敵との当たり判定の半径
};
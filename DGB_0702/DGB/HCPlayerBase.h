#pragma once
#include "HCCharacter.h"
#include "Holy.h"

class HCPlayerBase : public HCCharacter
{
public:
	HCPlayerBase();
	virtual ~HCPlayerBase();

	void setup() override;
	void update() override;
	void draw() override;

protected:
	// 上下左右のキーコードを受け取って座標を更新する共通処理
	// （HCPlayer1 / HCPlayer2 それぞれの update() から呼び出す想定）
	void Move(int upKey, int downKey, int leftKey, int rightKey);

protected:
	HSPoint m_position1;
	HSPoint m_position2;
	int     m_speed = 4;
};

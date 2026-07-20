#include "HCPlayer1.h"
#include "Umbrella.h"

HCPlayer1::HCPlayer1()
{
}

HCPlayer1::~HCPlayer1()
{
}

void HCPlayer1::setup()
{
	int step_width = SCREEN_WIDTH / ( SCREEN_WIDTH / 10 );
	int step_height = SCREEN_HEIGHT / ( SCREEN_HEIGHT / 10 );
	// プレイヤー1の初期位置
	m_position1.Set( SCREEN_WIDTH - step_width * 7, SCREEN_HEIGHT / 2 );
	m_position2.Set( step_width * 6, SCREEN_HEIGHT / 2 );
}

void HCPlayer1::update()
{
	// プレイヤー1は矢印キーで操作
	//Move(KEY_INPUT_UP, KEY_INPUT_DOWN, KEY_INPUT_LEFT, KEY_INPUT_RIGHT);
	Move(KEY_INPUT_UP, KEY_INPUT_DOWN, 0, 0);
}

void HCPlayer1::draw()
{
	DrawString(m_position1.nX, m_position1.nY, _T("P1_1"), GetColor(255, 0, 0));
	DrawString(m_position2.nX, m_position2.nY, _T("P1_2"), GetColor(255, 0, 0));
}
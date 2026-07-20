#include "HCPlayer2.h"
#include "Umbrella.h"

HCPlayer2::HCPlayer2()
{
}

HCPlayer2::~HCPlayer2()
{
}

void HCPlayer2::setup()
{

	int step_width = SCREEN_WIDTH / ( SCREEN_WIDTH / 10 );
	int step_height = SCREEN_HEIGHT / ( SCREEN_HEIGHT / 10 );

	// プレイヤー2の初期位置
	m_position1.Set( SCREEN_WIDTH / 2, SCREEN_HEIGHT - step_height * 7 );
	m_position2.Set( SCREEN_WIDTH / 2, step_height * 6 );
}

void HCPlayer2::update()
{
	// プレイヤー2は WASD で操作
	Move(0, 0, KEY_INPUT_A, KEY_INPUT_D);
}

void HCPlayer2::draw()
{
	DrawString(m_position1.nX, m_position1.nY, _T("P2_1"), GetColor(0, 0, 255));
	DrawString(m_position2.nX, m_position2.nY, _T("P2_2"), GetColor(0, 0, 255));
}
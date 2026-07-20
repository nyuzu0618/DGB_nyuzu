#include "HCPlayer2.h"
#include "Umbrella.h"

HCPlayer2::HCPlayer2( ) {
	g_pPlayer2 = this;
}

HCPlayer2::~HCPlayer2( ) {}

void HCPlayer2::setup( ) {
	// プレイヤー2の初期位置
	m_position1.Set( g_player2_1_base_spawn_width, g_player2_1_base_spawn_height );
	m_position2.Set( g_player2_2_base_spawn_width, g_player2_2_base_spawn_height );
}

void HCPlayer2::update( ) {
	// プレイヤー2は WASD で操作(左右移動)
	Move( 0, 0, KEY_INPUT_A, KEY_INPUT_D );

	// ステージの左右上下の座標
	const int map_left = ( g_SCREEN_WIDTH - g_stage_width ) / 2;
	const int map_right = map_left + g_stage_width;
	const int map_top = ( g_SCREEN_HEIGHT - g_stage_height ) / 2;
	const int map_bottom = map_top + g_stage_height;

	// 横方向の移動可能範囲(左右端の1.5セル分=ゴールエリアを除く)
	const int move_left = map_left + g_cell_width * 1.5;
	const int move_right = map_right - g_cell_width * 1.5;

	// 縦方向の移動可能範囲(ステージ内に収める。プレイヤー2は上下移動しない想定)
	const int move_top = map_top;
	const int move_bottom = map_bottom - g_player_height;

	// プレイヤー1(P2_1)
	if ( m_position1.nX < move_left )   m_position1.nX = move_left;
	if ( m_position1.nX > move_right )  m_position1.nX = move_right;
	if ( m_position1.nY < move_top )    m_position1.nY = move_top;
	if ( m_position1.nY > move_bottom ) m_position1.nY = move_bottom;

	// プレイヤー2(P2_2)
	if ( m_position2.nX < move_left )   m_position2.nX = move_left;
	if ( m_position2.nX > move_right )  m_position2.nX = move_right;
	if ( m_position2.nY < move_top )    m_position2.nY = move_top;
	if ( m_position2.nY > move_bottom ) m_position2.nY = move_bottom;
}

void HCPlayer2::draw( ) {
	DrawString( m_position1.nX, m_position1.nY, _T( "P2_1" ), GetColor( 0, 0, 255 ) );
	DrawString( m_position2.nX, m_position2.nY, _T( "P2_2" ), GetColor( 0, 0, 255 ) );
}
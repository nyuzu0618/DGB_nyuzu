#include "HCPlayer1.h"
#include "Umbrella.h"

HCPlayer1::HCPlayer1( ) {
    g_pPlayer1 = this;
}

HCPlayer1::~HCPlayer1( ) {}

void HCPlayer1::setup( ) {
    // プレイヤー1の初期位置
    m_position1.Set( g_player1_1_base_spawn_width, g_player1_1_base_spawn_height );
    m_position2.Set( g_player1_2_base_spawn_width, g_player1_2_base_spawn_height );
}

void HCPlayer1::update( ) {
    Move( KEY_INPUT_UP, KEY_INPUT_DOWN, 0, 0 );

    // ステージの左右上下の座標
    const int map_left = ( g_SCREEN_WIDTH - g_stage_width ) / 2;
    const int map_right = map_left + g_stage_width;
    const int map_top = ( g_SCREEN_HEIGHT - g_stage_height ) / 2;
    const int map_bottom = map_top + g_stage_height;

    // 縦方向の移動可能範囲(上下端の1セル分=ゴールエリアを除く)
    const int move_top = map_top + g_cell_height * 1.5;
    const int move_bottom = map_bottom - g_cell_height * 1.5;

    // 横方向の移動可能範囲(ステージ内に収める)
    const int move_left = map_left;
    const int move_right = map_right - g_player_width;

    // プレイヤー1
    if ( m_position1.nY < move_top )    m_position1.nY = move_top;
    if ( m_position1.nY > move_bottom ) m_position1.nY = move_bottom;
    if ( m_position1.nX < move_left )   m_position1.nX = move_left;
    if ( m_position1.nX > move_right )  m_position1.nX = move_right;

    // プレイヤー2(このクラス内の2体目)
    if ( m_position2.nY < move_top )    m_position2.nY = move_top;
    if ( m_position2.nY > move_bottom ) m_position2.nY = move_bottom;
    if ( m_position2.nX < move_left )   m_position2.nX = move_left;
    if ( m_position2.nX > move_right )  m_position2.nX = move_right;
}

void HCPlayer1::draw( ) {
    DrawString( m_position1.nX, m_position1.nY, _T( "P1_1" ), GetColor( 255, 0, 0 ) );
    DrawString( m_position2.nX, m_position2.nY, _T( "P1_1" ), GetColor( 255, 0, 0 ) );
}
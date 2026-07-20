#include "HCEnemy1.h"
#include "DxLib.h"
#include "Map.h"
#include "Umbrella.h"

HCEnemy1::HCEnemy1( ) {}

HCEnemy1::~HCEnemy1( ) {}

void HCEnemy1::setup( ) {
	// Umbrella.hのg_Enemy1_Route_idx（デフォルトのルート配列）をそのまま使う
	std::vector<int> routeLabels( g_Enemy1_Route_idx, g_Enemy1_Route_idx + g_Enemy1_Route_count );
	setup( routeLabels );
}

void HCEnemy1::setup( const std::vector<int>& routeLabels ) {
	// 指定されたエリア番号を順に辿り、巡回ルートを組み立てる
	std::vector<HSPoint> route;

	if ( g_pMap != nullptr ) {
		for ( int label : routeLabels ) {
			const MapArea* area = g_pMap->GetAreaByLabel( label );
			if ( area != nullptr ) {
				HSPoint p;
				p.Set( area->posX + g_cell_width / 2, area->posY + g_cell_height / 2 );
				route.push_back( p );
			}
		}
	}

	// Mapが未生成、または指定されたエリア番号が全部無効だった場合のフォールバック
	if ( route.empty( ) ) {
		HSPoint p;
		p.Set( 100, 100 );
		route.push_back( p );
	}

	setRoute( route );

	// Enemy1固有の初期サイズ（当たり判定の矩形サイズ）を設定（ルート先頭を初期位置に）
	m_position1.Set( route[ 0 ].nX, route[ 0 ].nY );
	m_position2.Set( m_position1.nX + 32, m_position1.nY + 32 );

	// 基底クラスのsetup()でルート先頭に配置・HP初期化などを行う
	HCEnemyBase::setup( );

	m_speed = 2;
}

void HCEnemy1::draw( ) {
	// Enemy1の見た目（仮の矩形描画。画像に差し替える場合はここを変更）
	DrawBox( m_position1.nX, m_position1.nY, m_position2.nX, m_position2.nY, GetColor( 255, 0, 0 ), TRUE );
}
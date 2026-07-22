#pragma once
#include "Umbrella.h"
#include <vector>

//スクリーンの縦横のピクセル数
inline int g_SCREEN_WIDTH = 1920;
inline int g_SCREEN_HEIGHT = 1080;

//セルのサイズ
inline int g_cell_width = 180;
inline int g_cell_height = 180;
inline int g_cell_max_width = 5;
inline int g_cell_max_height = 5;

//コートの大きさ
inline int g_stage_width = g_cell_width * g_cell_max_width;
inline int g_stage_height = g_cell_height * g_cell_max_height;


//プレイヤーの基本パラメーター（当たり判定サイズ：横60・縦120）
inline int g_player_width = 60;
inline int g_player_height = 120;

//エネミーの基本パラメーター（当たり判定サイズ：横60・縦120）
inline int g_enemy_width = 60;
inline int g_enemy_height = 120;

//プレイヤーの初期リスポーン
inline int g_player1_1_base_spawn_width = 1320;
inline int g_player1_1_base_spawn_height = 540;
inline int g_player1_2_base_spawn_width = 600;
inline int g_player1_2_base_spawn_height = 540;
inline int g_player2_1_base_spawn_width = 960;
inline int g_player2_1_base_spawn_height = 900;
inline int g_player2_2_base_spawn_width = 960;
inline int g_player2_2_base_spawn_height = 180;

//エネミーの初期リスポーン位置（Mapのエリアインデックス指定。プランナーが調整）
//実際の座標(x, y)は g_pMap->GetAreaByIndex(idx) で実行時に取得する
//エネミー1の巡回ルート（Mapのエリア番号を並べたもの。プランナーが自由に追加・変更可能）
inline int g_Enemy1_Route_idx[ ] = { 7, 13, 19, 13 };
inline int g_Enemy1_Route_count = sizeof( g_Enemy1_Route_idx ) / sizeof( g_Enemy1_Route_idx[ 0 ] );

//Enemy1をまとめて複数体出現させる場合のルート一覧
//（1体につき1つのルート＝エリア番号の並び。ここに追加・削除するだけで出現数と経路を調整できる）
inline std::vector<std::vector<int>> g_Enemy1_SpawnRoutes = {
	{ 7, 12, 17, 12, 7 },   // 1体目のルート
	{ 13, 18, 13, 8 ,13 },    // 2体目のルート
	{ 19, 14, 9, 14, 19 },  // 3体目のルート
};
#pragma once
#include "Umbrella.h"
#include <list>

// TCHAR文字列用のstring型（Unicodeビルドならwstring、そうでなければstring）
using tstring = std::basic_string<TCHAR>;

// 1つの配置エリア（背景画像を貼る予定の矩形）を表す構造体
struct MapArea {
	tstring name;  // 例: _T("background1"), _T("background2")
	int posX;
	int posY;
	int width;
	int height;
	int color;
	int row = 0;   // グリッド上の行番号（0始まり、縦方向）
	int col = 0;   // グリッド上の列番号（0始まり、横方向）
};


class Map {
public:
	Map();
	~Map();

	void setup();
	void update();
	void draw();

	// 中央3×3のエリア一覧を取得する（どこからでも呼び出し可能）
	std::list<MapArea> GetCenterAreas() const;

	// グリッド上の(row, col)に対応するエリアを1つ取得する（見つからなければnullptr）
	const MapArea* GetAreaAt(int row, int col) const;

	// m_areas内のidx番目のエリアを取得する（見つからなければnullptr）
	const MapArea* GetAreaByIndex(int idx) const;

	// 画面表示される「エリア番号」（1始まり。draw()で表示されるnameの数字と一致）でエリアを取得する
	const MapArea* GetAreaByLabel(int label) const;

private:
	// デバッグ用矩形を追加するヘルパー
	void AddArea(const tstring& name, int posX, int posY, int width, int height, int color, int row, int col);

private:
	std::list<MapArea> m_areas;

};

// どこからでもMapのインスタンスにアクセスできるようにするためのグローバルポインタ
// （Mapのコンストラクタで自動的にセットされる）
extern Map* g_pMap;
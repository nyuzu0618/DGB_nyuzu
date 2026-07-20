#include "Map.h"
#include <iterator>

// どこからでもアクセスできるMapのグローバルポインタ
Map* g_pMap = nullptr;

Map::Map() {
	g_pMap = this;
}

Map::~Map() {
	if (g_pMap == this) {
		g_pMap = nullptr;
	}
}

void Map::AddArea(const tstring& name, int posX, int posY, int width, int height, int color, int row, int col) {
	MapArea area;
	area.name = name;
	area.posX = posX;
	area.posY = posY;
	area.width = width;
	area.height = height;
	area.color = color;
	area.row = row;
	area.col = col;
	m_areas.push_back(area);
}

void Map::setup() {
	//AddArea(_T("stage"),
	//	g_SCREEN_WIDTH / 2 - g_stage_width / 2,
	//	g_SCREEN_HEIGHT / 2 - g_stage_width / 2,
	//	g_stage_height, g_stage_height,
	//	GetColor(200, 100, 100));

	int cell_base_pos_width = (g_SCREEN_WIDTH / 2) - (g_cell_width * g_cell_max_width * 0.5);
	int cell_base_pos_height = (g_SCREEN_HEIGHT / 2) - (g_cell_height * g_cell_max_height * 0.5);

	int countloop = 0;
	for (int i = 0; i < g_cell_max_width; i++) {
		for (int j = 0; j < g_cell_max_height; j++) {
			countloop++;

			TCHAR buf[16];
			_stprintf_s(buf, _T("%d"), countloop);
			tstring label = buf;

			AddArea(label,
				cell_base_pos_width + i * g_cell_width,
				cell_base_pos_height + j * g_cell_height,
				g_cell_width, g_cell_height,
				GetColor(100, 200, 100),
				j, i);   // row = j（縦方向）, col = i（横方向）
		}
	}

}

void Map::update() {
	// 現時点では特に更新処理なし
}

void Map::draw() {
	for (const auto& area : m_areas) {
		// デバッグ用: 枠線のみ描画（画像を貼ったら不要になる想定）
		DrawBox(area.posX, area.posY,
			area.posX + area.width, area.posY + area.height,
			area.color, FALSE);

		// どのエリアか分かるように名前も表示しておく
		DrawString(area.posX + 5, area.posY + 5, area.name.c_str(), GetColor(255, 255, 255));
	}

}

std::list<MapArea> Map::GetCenterAreas() const {
	std::list<MapArea> result;

	// グリッドの中心3×3にあたる行・列の範囲を求める
	// （g_cell_max_width/heightが変わっても中心3×3を自動計算する）
	int startRow = (g_cell_max_height - 3) / 2;
	int endRow = startRow + 3 - 1;
	int startCol = (g_cell_max_width - 3) / 2;
	int endCol = startCol + 3 - 1;

	for (const auto& area : m_areas) {
		if (area.row >= startRow && area.row <= endRow &&
			area.col >= startCol && area.col <= endCol) {
			result.push_back(area);
		}
	}

	return result;
}

const MapArea* Map::GetAreaAt(int row, int col) const {
	for (const auto& area : m_areas) {
		if (area.row == row && area.col == col) {
			return &area;
		}
	}
	return nullptr;
}

const MapArea* Map::GetAreaByIndex(int idx) const {
	if (idx < 0 || idx >= static_cast<int>(m_areas.size())) {
		return nullptr;
	}

	auto it = m_areas.begin();
	std::advance(it, idx);
	return &(*it);
}

const MapArea* Map::GetAreaByLabel(int label) const {
	// 画面表示上の番号は1始まりなので、0始まりのidxに変換する
	return GetAreaByIndex(label - 1);
}
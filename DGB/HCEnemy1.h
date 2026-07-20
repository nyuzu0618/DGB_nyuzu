#pragma once
#include "HCEnemyBase.h"
#include <vector>

class HCEnemy1 : public HCEnemyBase {
public:
	HCEnemy1( );
	virtual ~HCEnemy1( );

	void setup( ) override;                            // Umbrella.hのg_Enemy1_Route_idxを使う（デフォルト）
	void setup( const std::vector<int>& routeLabels );   // 指定したエリア番号を巡回ルートにする
	void draw( ) override;
};
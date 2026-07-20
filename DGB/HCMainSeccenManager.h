#pragma once
#include "HCSeccenGameModeBase.h"
#include "HCGameModeManager.h"
#include "HCPlayer1.h"
#include "HCPlayer2.h"
#include "Map.h"
#include "EnemyManager.h"
#include "Ball.h"

#include "Umbrella.h"


class HCMainSeccenManager : public HCSeccenGameModeBase {
public:
	HCMainSeccenManager( );
	~HCMainSeccenManager( );

	void MainToChangeGameModeRequest( );

	void draw( ) override;
	void update( ) override;

private:
	EnemyManager enemyManage;
	Ball m_ball;
	HCPlayer1* m_pPlayer1 = nullptr;
	HCPlayer2* m_pPlayer2 = nullptr;
	Map* m_pMap = nullptr;
};
#pragma once
#include "HCSeccenGameModeBase.h"
#include "HCGameModeManager.h"
#include "HCPlayer1.h"
#include "HCPlayer2.h"

#include "Umbrella.h"


class HCMainSeccenManager : public HCSeccenGameModeBase
{
public:
	HCMainSeccenManager();
	~HCMainSeccenManager();

	void MainToChangeGameModeRequest();

	void draw() override;
	void update() override;

private:
	HCPlayer1* m_pPlayer1 = nullptr;
	HCPlayer2* m_pPlayer2 = nullptr;
};
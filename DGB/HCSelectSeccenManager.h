#pragma once

#include "HCGameModeManager.h"
#include "HCSeccenGameModeBase.h"

#include "Umbrella.h"

class HCSelectSeccenManager : public HCSeccenGameModeBase
{
public:
	HCSelectSeccenManager();
	~HCSelectSeccenManager();

	void SelectToChangeGameModeRequest();

public:
	void draw() override;
	void update() override;
};
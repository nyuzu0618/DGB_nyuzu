#pragma once

#include "HCGameModeManager.h"
#include "HCSeccenGameModeBase.h"

#include "Umbrella.h"

class HCTitleSeccenManager : public HCSeccenGameModeBase
{
public:
	HCTitleSeccenManager();
	~HCTitleSeccenManager();

	void TitleToChangeGameModeRequest();

public:
	void draw() override;
	void update() override;
};


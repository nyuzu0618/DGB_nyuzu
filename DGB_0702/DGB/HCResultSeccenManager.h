#pragma once

#include "HCGameModeManager.h"
#include "HCSeccenGameModeBase.h"

#include "Umbrella.h"

class HCResultSeccenManager : public HCSeccenGameModeBase
{
public:
	HCResultSeccenManager();
	~HCResultSeccenManager();

	void ResultToChangeGameModeRequest();

public:
	void draw() override;
	void update() override;
};


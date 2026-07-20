#pragma once

#include "HCGameModeManager.h"

#include "Umbrella.h"

class HCSeccenGameModeBase
{
public:
	virtual ~HCSeccenGameModeBase() = default;

	virtual void draw() = 0;
	virtual void update() = 0;

};


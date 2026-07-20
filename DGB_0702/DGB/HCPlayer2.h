#pragma once
#include "HCPlayerBase.h"

class HCPlayer2 : public HCPlayerBase
{
public:
	HCPlayer2();
	~HCPlayer2();

	void setup() override;
	void update() override;
	void draw() override;
};
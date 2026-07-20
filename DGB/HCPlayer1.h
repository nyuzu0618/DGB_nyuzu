#pragma once
#include "HCPlayerBase.h"
class HCPlayer1 : public HCPlayerBase
{

public:
	HCPlayer1();
	~HCPlayer1();

	void setup() override;
	void update() override;
	void draw() override;

};


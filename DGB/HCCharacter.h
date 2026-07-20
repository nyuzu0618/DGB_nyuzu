#pragma once
class HCCharacter
{
public:
	virtual ~HCCharacter() = default;

	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};


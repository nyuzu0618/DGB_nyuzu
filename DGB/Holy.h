#pragma once
#include "Umbrella.h"

struct HSPoint {
	union {
		struct {
			int nX;
			int nY;
		};

		struct {
			float fX;
			float fY;
		};
	};

	void Set(int nXtoSet, int nYtoSet) {
		nX = nXtoSet;
		nY = nYtoSet;
	}

	void Set(float fXtoSet, float fYtoSet) {
		fX = fXtoSet;
		fY = fYtoSet;
	}

	HSPoint()
	{
	}

	HSPoint(int nXtoSet, int nYtoSet)
	{
		Set(nXtoSet, nYtoSet);
	}

	HSPoint(float fXtoSet, float fYtoSet)
	{
		Set(fXtoSet, fYtoSet);
	}

	HSPoint(const HSPoint& rstpToSet)
	{
		*this = rstpToSet;
	}

	POINT* GetPointerTo()
	{
		return	(POINT*)this;
	}
};
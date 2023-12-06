#include "Game.h"

void CAnimal::Move(int x, int y)
{
	mX += x;
	mY += y;
	if (mX < 0)
	{
		mX = 25;
	}
}

void CAnimal::Tell()
{
}

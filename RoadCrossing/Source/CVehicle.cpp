#include "Game.h"

void CVehicle::Move(int x, int y)
{
	mX += x;
	mY += y;
	if (mX > 30)
	{
		mX = 0;
	}
}

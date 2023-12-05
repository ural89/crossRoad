#include "Game.h"
void CVehicle::Move(int x, int y)
{
	mX += x;
	mY += y;
	if (mX > 100)
	{
		mX = 0;
	}
//	std::cout << mX << '\n';
}

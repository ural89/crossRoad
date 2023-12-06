#include "Game.h"
void GoToXY(int, int);
void CVehicle::Move(int x, int y)
{
	//GoToXY(mX, mY);
	mX += x;
	mY += y;
	if (mX > 30)
	{
		mX = 0;
	}
//	std::cout << mX << '\n';
}

#include "Game.h"


CPeople::CPeople(){

}
void CPeople::Up(int y)
{
	mY -= y;
	if (mY < 0)
		mIsFinish = true;
	
}

void CPeople::Left(int x)
{
	mX -= x;
}

void CPeople::Right(int x)
{
	mX += x;
}

void CPeople::Down(int y)
{
	mY += y;

	
}

bool CPeople::isImpact(const CVehicle*)
{
	return false;
}

bool CPeople::isImpact(const CAnimal*)
{
	return false;
}

bool CPeople::isFinish()
{
	return mIsFinish;
}

bool CPeople::isDead()
{
	return false;
}

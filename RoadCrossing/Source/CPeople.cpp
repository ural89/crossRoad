#include "Game.h"


CPeople::CPeople() {

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

bool CPeople::isImpact(const std::vector<CVehicle*>& vehicles)
{

	for (const auto vehicle : vehicles)
	{
		if (vehicle == nullptr) continue;
		if (vehicle->mX == mX && vehicle->mY == mY)
			return true;
	}
	return false;
}

bool CPeople::isImpact(const std::vector<CAnimal*>& animals)
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

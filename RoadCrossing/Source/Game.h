#include <iostream>
#include <vector>
#include <conio.h>
#include <thread>
#include <time.h>
#include <Windows.h>



class CVehicle
{
public:
	CVehicle(int mx, int my) : mX(mx), mY(my) {}
	int mX, mY;
	virtual void Move(int, int) ;
	char symbol = 178;

};

class CTruck :public CVehicle
{
public:
	CTruck(int mx, int my) : CVehicle(mx, my)
	{
		symbol = 178;
	}
	void Move(int x, int y) override
	{
		mX -= x;
		mY += y;
		if (mX < 0)
		{
			mX = 30;
		}
	}
	
};
class CCar : public CVehicle
{
public:
	CCar(int mx, int my) : CVehicle(mx, my)
	{
		symbol = 178;
	}
	void Move(int x, int y) override
	{
		mX += x;
		mY += y;
		if (mX > 30)
		{
			mX = 0;
		}
	}
};
class CAnimal
{
public:
	CAnimal(int mx, int my) : mX(mx), mY(my) {}
	int mX, mY;
	virtual void Move(int, int);
	virtual void Tell();
	char symbol = 178;
};
class CDinausor : public CAnimal
{
	CDinausor(int mx, int my) : CAnimal(mx, my)
	{
		symbol = 178;
	};
	

	void Tell() override {
		std::cout << "Tweet\n";
	}

};
class CBird : public CAnimal
{
public:
	CBird(int mx, int my) : CAnimal(mx, my)
	{
		symbol = 178;
	};
	

	void Tell() override {
		std::cout << "Tweet\n";
	}
};

class CPeople
{
	bool mState;
	bool mIsFinish = false;
public:
	int mX = 10, mY = 6;
	CPeople();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const std::vector<CVehicle*>&);
	bool isImpact(const std::vector<CAnimal*>&);
	bool isFinish();
	bool isDead();
	char symbol = 165;
};

class CGame
{
	CTruck* truck;
	CCar* car;
	CDinausor* ad;
	CPeople* p;
private:
	CPeople people;
	std::vector<CVehicle*> vehicles;
	std::vector<CAnimal*> animals;
public:
	CGame();
	void drawGame();
	~CGame();
	CPeople &getPeople();
	std::vector<CVehicle*> getVehicles();
	std::vector<CAnimal*> getAnimals();
	void resetGame();
	void exitGame(HANDLE);
	void startGame();
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
	void updatePosPeople(char);
	void updatePosVehicle();
	void updatePosAnimal();

};
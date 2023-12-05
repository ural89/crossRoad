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
	char symbol = 182;

};

class CTruck :public CVehicle
{
	
};
class CCar : public CVehicle
{

};
class CAnimal
{
public:
	int mX, mY;
	virtual void Move(int, int);
	virtual void Tell();
	char symbol;
};
class CDinausor : public CAnimal
{


};
class CBird : public CAnimal
{

};

class CPeople
{
	bool mState;
	bool mIsFinish = false;
public:
	int mX = 10, mY = 10;
	CPeople();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVehicle*);
	bool isImpact(const CAnimal*);
	bool isFinish();
	bool isDead();
	char symbol = 178;
};

class CGame
{
	CTruck* truck;
	CCar* car;
	CDinausor* ad;
	CPeople* p;
private:
	CPeople people;
	std::vector<CVehicle> vehicles;
	std::vector<CAnimal> animals;
public:
	CGame();
	void drawGame();
	~CGame();
	CPeople &getPeople();
	CVehicle* getVehicle();
	CAnimal* getAnimal();
	void resetGame();
	void exitGame(HANDLE);
	void startGame();
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
	void updatePosPeople(char);
	void updatePosVehicle();
	void updatePosAnimal();

};
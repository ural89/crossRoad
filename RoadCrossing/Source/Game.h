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
	CAnimal(int mx, int my) : mX(mx), mY(my) {}
	int mX, mY;
	virtual void Move(int, int);
	virtual void Tell();
	char symbol = 219;
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
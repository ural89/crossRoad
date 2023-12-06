#include "Game.h"
#include "Core.h"
void FixConsoleWindow();
void GoToXY(int x, int y);

void CGame::updatePosAnimal()
{
}


CGame::CGame()
{
 
    vehicles.push_back(new CVehicle(0, 1));
    vehicles.push_back(new CVehicle(1, 2));

}

void CGame::drawGame()
{
    //

   
    for (const auto& vehicle : vehicles)
    {
        GoToXY(vehicle->mX, vehicle->mY);
        std::cout << vehicle->symbol;
    }

    
    for (const auto& animal : animals)
    {
      //  GoToXY(animal.mX, animal.mY);
        std::cout << animal.symbol;
    }

    
    GoToXY(people.mX, people.mY);
    std::cout << people.symbol;
    Sleep(100);

    system("cls");

}

CGame::~CGame()
{
}

CPeople &CGame::getPeople()
{
	return people;
}

CVehicle* CGame::getVehicle()
{
	return vehicles[0];
}

CAnimal* CGame::getAnimal()
{
	return nullptr;
}

void CGame::resetGame()
{
}

void CGame::exitGame(HANDLE handle)
{
	TerminateThread(handle, 0);
	CloseHandle(handle);
}

void CGame::startGame()
{
}

void CGame::pauseGame(HANDLE)
{
}

void CGame::resumeGame(HANDLE)
{
}

void CGame::updatePosPeople(char)
{
}

void CGame::updatePosVehicle()
{
    for (CVehicle* vehicle : vehicles)
    {
      
        vehicle->Move(1, 0);
		
        //std::cout << vehicle.symbol;
    }
}


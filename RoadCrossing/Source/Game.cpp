#include "Game.h"
#include "Core.h"
void FixConsoleWindow();
void GoToXY(int x, int y);


CGame::CGame()
{
 
    vehicles.push_back(new CTruck(0, 1));
    vehicles.push_back(new CTruck(5, 1));
    vehicles.push_back(new CCar(5, 3));
    vehicles.push_back(new CCar(10, 3));
    animals.push_back(new CBird(25, 5));
    animals.push_back(new CBird(20, 5));

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
        GoToXY(animal->mX, animal->mY);
        std::cout << animal->symbol;
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

std::vector<CVehicle*> CGame::getVehicles()
{
	return vehicles;
}

std::vector<CAnimal*> CGame::getAnimals()
{
	return animals;
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
		
       
    }
}

void CGame::updatePosAnimal()
{
    for (CAnimal* animal : animals)
    {

        animal->Move(-1, 0);


    }
}



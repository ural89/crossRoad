#include "Game.h"
#include "Core.h"
void FixConsoleWindow();
void GoToXY(int x, int y);


CGame::CGame()
{
 
    vehicles.push_back(new CTruck(0, 1));
    vehicles.push_back(new CTruck(10, 1));
    vehicles.push_back(new CCar(5, 3));
    vehicles.push_back(new CCar(15, 3));
    animals.push_back(new CBird(25, 5));
    //animals.push_back(new CBird(20, 5));

}

void CGame::drawGame()
{
    //

   
    for (const auto& vehicle : vehicles)
    {
        if (CCar* car = dynamic_cast<CCar*>(vehicle))
        {
            GoToXY(vehicle->mX - 1, vehicle->mY);
            std::cout << "[" << vehicle->symbol << "]";
            GoToXY(vehicle->mX, vehicle->mY + 1);
            std::cout << "0";
            GoToXY(vehicle->mX - 1, vehicle->mY + 1);
            std::cout << "0";
        }
        else if (CTruck* truck = dynamic_cast<CTruck*>(vehicle))
        {
            GoToXY(vehicle->mX - 1, vehicle->mY);
            std::cout << "[" << vehicle->symbol << " " << vehicle->symbol << "]";
            GoToXY(vehicle->mX, vehicle->mY + 1);
            std::cout << "0" << "0" << "0";
          
        }
    

    }

    
    for (const auto& animal : animals)
    {
        if (CBird* bird = dynamic_cast<CBird*>(animal))
        {
            GoToXY(animal->mX, animal->mY - 1);
            std::cout << "  \\";
            GoToXY(animal->mX, animal->mY);
            std::cout << ">('-')>";
            GoToXY(animal->mX, animal->mY + 1);
            std::cout << "  /";
        }
    }

    
    GoToXY(people.mX, people.mY);
    std::cout << people.symbol;
    Sleep(50);

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




#include "Game.h"
#include "Core.h"
bool IsRunning = true;
char Moving;
CGame cg;
void FixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GoToXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void exitGame(std::thread* t)
{
    system("cls");
    IsRunning = false;
    t->join();
}
void SubThread()
{
    while (IsRunning)
    {
        if (!cg.getPeople().isDead())
        {
            cg.updatePosPeople(Moving);
        }
        Moving = ' ';
        cg.updatePosVehicle();
        cg.updatePosAnimal();
        cg.drawGame();
        if (cg.getPeople().isImpact(cg.getVehicle()) || cg.getPeople().isImpact(cg.getAnimal()))
        {
            std::cout << "impact!" << '\n';
        }
       
    }
}


int main()
{
    cg = CGame();
    FixConsoleWindow();
    cg.startGame();
    int temp;
    std::thread t1(SubThread);
   
    while (1)
    {
        temp = toupper(_getch());

        if (!cg.getPeople().isDead())
        {
			if (temp == 27)
		    {
            cg.exitGame(t1.native_handle());
            return 0;
		    }
            if (toupper(temp) == 'A')
            {
                cg.getPeople().Left(1);
            }
            if (toupper(temp) == 'D')
            {
                cg.getPeople().Right(1);
            }
            if (toupper(temp) == 'W')
            {
                cg.getPeople().Up(1);
            }
			if (toupper(temp) == 'S')
            {
                cg.getPeople().Down(1);
            }
        }
    }
}


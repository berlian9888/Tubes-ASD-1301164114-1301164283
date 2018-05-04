#include "mainHead.h"

void gotoxy(int x,int y)
{
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

bool contains(string domain, string keyword)
{
    int j = 0;
    for(int i = 0; i<domain.length(); i++)
    {
        j = (domain[i] == keyword[j]) ? j+1 : 0;
        if (j == keyword.length()) return true;
    }
    return false;
}
void clean()
{
    system("cls");
}



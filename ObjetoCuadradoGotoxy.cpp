#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

void gotoxy(int, int, COORD*);

class Square {
private:
    int height = 1;
    COORD coord = { 0, 0 };
public:
    Square(int height) {
        this->height = height;
    }

    void CreateSquare(int x, int y) {
        int initX = x;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < height; j++) {
                gotoxy(x, y, &coord);
                cout << "*";
                x += 2;
            }
            y++;
            x = initX;
        }
    }
    
};

int main()
{
    int x = 0, y = 0, medida = 0;
    cout << "Ingrese la medida del cuadrado: ";
    cin >> medida;
    system("cls");

    Square square(medida);
    square.CreateSquare(x, y);

    char opt = {};
    while (opt != 27)  {
        if (_kbhit()) {
            opt = _getch();
            switch (opt) {
            case 97:
                system("cls");
                square.CreateSquare(--x, y);
                break;
            case 115: 
                system("cls");
                square.CreateSquare(x, ++y);
                break;
            case 100:
                system("cls");
                square.CreateSquare(++x, y);
                break;
            case 119:
                system("cls");
                square.CreateSquare(x, --y);
                break;
            }
            
        }
    }
}

void gotoxy(int x, int y, COORD *coord) {
    coord->X = x;
    coord->Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *coord);
}
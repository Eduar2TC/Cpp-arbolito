#include <iostream>
#include <windows.h>
using namespace std;

class Arbolito
{
  public:
    void OcultaCursor()
    {
        HANDLE Posicion;
        Posicion = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO rosruC;
        rosruC.dwSize = 2;
        rosruC.bVisible = FALSE;
        SetConsoleCursorInfo(Posicion, &rosruC);
    }

    void situaCoordenada(int a, int b)
    {
        HANDLE mueve;
        mueve = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD Posicion;
        Posicion.X = a;
        Posicion.Y = b;
        SetConsoleCursorPosition(mueve, Posicion);
    }

    void dibujaArbol(int ancho)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // color de texto
        int color = 10;                                    //verde
        SetConsoleTextAttribute(hConsole, color);

        int contadorIzq = ancho / 2;
        int contadorDer = ancho / 2;
        //dibuja parte superior
        for (int i = 1; i <= (ancho / 2); i++) // filas
        {

            for (int j = 1; j <= ancho; j++)
            {
                if (j < contadorIzq)
                {
                    cout << " ";
                }
                else if (j > contadorIzq && j < contadorDer)
                {
                    cout << "*";
                }
            }
            cout << endl;
            contadorIzq--;
            contadorDer++;
        }

        //Dibuja tronco
        SetConsoleTextAttribute(hConsole, 8);

        int k = 0;
        while (k < 5)
        {
            for (int i = 1; i <= ancho; i++)
            {
                if (i == (ancho / 2) - 2)
                {
                    for (int l = i; l <= (i + 2); l++)
                    {
                        cout << "*";
                    }
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
            k++;
        }
    }

    void dibujaEstrella(int x, int y, int largoEstrella, int anchoEstrella)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // color de texto
        int color = 14;                                    //verde
        SetConsoleTextAttribute(hConsole, color);

        situaCoordenada(x + 1, y);
        cout << "^";
        situaCoordenada(x - 1, y + 1);
        cout << "< ";
        situaCoordenada(x + 1, y + 1);
        cout << "*";
        situaCoordenada(x + 2, y + 1);
        cout << " >";
        situaCoordenada(x + 1, y + 2);
        cout << "v";
    }

    void dibujaRegalo(int x, int y)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // color de texto
        int color = 12;                                    //verde
        SetConsoleTextAttribute(hConsole, color);

        situaCoordenada(x, y);
        for (int i = 0; i < 4; i++)
        {
            situaCoordenada(x + i, y);
            cout << "-";
        }
        situaCoordenada(x + 4, y);
        cout << "\\";
        situaCoordenada(x + 5, y);
        cout << "v";
        situaCoordenada(x + 6, y);
        cout << "//";
        for (int i = 7; i < 10; i++)
        {
            situaCoordenada(x + i, y);
            cout << "-";
        }

        situaCoordenada(x, y);
        for (int i = 0; i < 3; i++)
        {
            situaCoordenada(x, y + i);
            cout << ".";
        }

        for (int i = 0; i < 3; i++)
        {
            situaCoordenada(x + 10, y + i);
            cout << ".";
        }
        //situaCoordenada(x, y + 3);
        for (int i = 1; i <= 8; i++)
        {
            situaCoordenada(x + i, y + 3);
            cout << "-";
        }

        for (int i = 1; i < 3; i++)
        {
            situaCoordenada(x + 10 / 2, y + i);
            cout << "|";
        }
        for (int i = 1; i < 5; i++)
        {
            situaCoordenada(x + i, y + 1);
            cout << "_";
        }

        for (int i = 6; i < 10; i++)
        {
            situaCoordenada(x + i, y + 1);
            cout << "_";
        }
    }
};

int main()
{
    Arbolito miArbol;
    miArbol.OcultaCursor();
    miArbol.dibujaEstrella(40, 3, 3, 3);
    miArbol.dibujaArbol(30);
    miArbol.dibujaRegalo(20, 21);
    cin.get();
}

#include <iostream>

using namespace std;

class Arbolito
{
  public:
    Arbolito()
    {
    }
    void dibujaArbol(int ancho)
    {
        int contadorIzq = ancho / 2;
        int contadorDer = ancho / 2;

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

                if (i == (ancho / 2) && j == (ancho / 2))
                {
                    cout << "|";
                }
            }
            cout << endl;
            contadorIzq--;
            contadorDer++;
        }
    }
};

int main()
{
    Arbolito miArbol;
    miArbol.dibujaArbol(120);
    cin.get();
}

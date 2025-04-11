#include <iostream>
#include <cstdlib>
#include "time.h"
#include "rlutil.h"

using namespace std;
#include "Estilo.h"
#include "funciones.h"
#include "puntaje.h"
#include "dados.h"
#include "DosJugadores.h"



int main()
{
    rlutil::setBackgroundColor(rlutil::MAGENTA);
    rlutil::setColor(rlutil::WHITE);
    rlutil::cls();

    int opcion = 1;
    int y = 0;
    int dados[6];


    rlutil::hidecursor();

    do
    {
        for (int i = 9; i <= 15; ++i)
        {
            rlutil::locate(24, i);
            cout << "|";
            rlutil::locate(69, i);
            cout << "|";
        }



        rlutil::locate(25, 8);
        cout << "_____________________________________________" << endl;
        rlutil::locate(30, 10);
        cout << "1 - UN JUGADOR." << endl;
        rlutil::locate(30, 11);
        cout << "2 - DOS JUGADORES." << endl;
        rlutil::locate(30, 12);
        cout << "3 - MOSTRAR PUNTACION MAS ALTA." << endl;
        rlutil::locate(30, 13);
        cout << "0 - SALIR." << endl;
        rlutil::locate(25, 15);
        cout << "_____________________________________________" << endl;

        rlutil::locate(28, 10 + y);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch (key)
        {
        case rlutil::KEY_UP:
            rlutil::locate(28, 10 + y);
            cout << " " << endl;
            y--;
            if (y < 0)
            {
                y = 0;
            }
            break;
        case rlutil::KEY_DOWN:
            rlutil::locate(28, 10 + y);
            cout << " " << endl;
            y++;
            if (y > 3)
            {
                y = 3;
            }
            break;
        case 1:
            switch (y)
            {
            case 0:
                opcion = 1;
                system ("cls");
                unJugador(dados);
                break;

            case 1:
                opcion = 2;
                system ("cls");
                DosJugadores(dados);
                break;

            case 2:
                opcion = 3;
                system("cls");

                break;

            case 3:
                opcion = 0;
                break;
            default:
                break;

            }
            break;
        default:
            break;
        }

        system("cls");

    }

    while (opcion != 0);

    switch (opcion)
    {
    case 1:
        unJugador(dados);
        break;
    case 2:
        DosJugadores(dados);
        break;
    case 3:

        break;
    default:
        break;
    }

    return 0;
}

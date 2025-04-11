#ifndef DOSJUGADORES_H_INCLUDED
#define DOSJUGADORES_H_INCLUDED

void DosJugadores(int dados[]);

void DosJugadores(int dados[])
{
    int y=0;

    int num, conti = 1, j, i, x, rondas;
    int Acum1Jug = 0;
    int Acum2Jug = 0;

    int AcumPartida1=0;
    int AcumPartida2=0;

    char nombre[10], nombre2[10];
    rlutil::locate(25,8);
    cout<<"__________________________________________"<<endl;
    rlutil::locate(25,16);
    cout<<"__________________________________________"<<endl;
    for (int t=9; t<=16; t++)
    {

        rlutil::locate(24,t);
        cout<<"|";
        rlutil::locate(67,t);
        cout<<"|";

    }




    rlutil::locate(30,10);
    cout << "NOMBRE DEL 1er JUGADOR: ";
    cin >> nombre;
    rlutil::locate(30,12);
    cout << "NOMBRE DEL 2do JUGADOR: ";
    cin >> nombre2;
    rlutil::locate(30,14);
    cout << "NRO DE RONDAS QUE DESEAN JUGAR: ";
    cin >> rondas;

    rlutil::locate(26,20);
    system("pause");
    system ("cls");


    rlutil::locate(25,8);
    cout<<"__________________________________________"<<endl;
    rlutil::locate(25,15);
    cout<<"__________________________________________"<<endl;

    for (int t=9; t<=15; t++)
    {

        rlutil::locate(24,t);
        cout<<"|";
        rlutil::locate(67,t);
        cout<<"|";

    }

    rlutil::locate(35,10);
    cout << "¡¡COMIENZA LA PARTIDA!!"<< endl;
    //rlutil::locate(35,12);
    //cout<< "¿DESEA TIRAR LOS DADOS?" << endl;
    rlutil::locate(41,12);
    cout << "TIRAR DADOS " << endl;
    rlutil::locate(41,13);
    cout << "VOLVER " << endl;

    rlutil::locate(40, 12 + y);
    cout << (char)175 << endl;
    int key = rlutil::getkey();


    do
    {
        key = rlutil::getkey();

        switch (key)
        {
        case rlutil::KEY_UP:
            rlutil::locate(40, 12+ y);
            cout << " ";
            y--;
            if (y < 0)
            {
                y = 1;
            }
            rlutil::locate(40, 12 + y);
            cout << (char)175 << endl;
            break;
        case rlutil::KEY_DOWN:
            rlutil::locate(40, 12 + y);
            cout << " ";
            y++;
            if (y > 1)
            {
                y = 0;
            }
            rlutil::locate(40, 12 + y);
            cout << (char)175 << endl;
            break;
        case rlutil::KEY_ENTER:
            switch (y)
            {
            case 0: // SI
                conti = 1;
                break;
            case 1: //NO
                conti = 0;
                break;
            }
            break;
        default:
            break;
        }
    }
    while (key != rlutil::KEY_ENTER);

    system("cls");




    for (x = 1; x <= rondas; x++)
    {

        if (conti == 1)
        {
            rlutil::locate(25,8);
            cout<<"__________________________________________"<<endl;
            rlutil::locate(30,10);
            cout<<"RONDA NUMERO "<<x<<endl;
            rlutil::locate(30,11);
            cout<<"PROXIMO TURNO: "<<nombre<<endl;
            rlutil::locate(30,12);
            cout<<"PUNTAJE DE "<<nombre<<":"<<AcumPartida1<<endl;
            rlutil::locate(30,13);
            cout<<"PUNTAJE DE "<<nombre2<<":"<<AcumPartida2<<endl;
            rlutil::locate(25,15);
            cout<<"__________________________________________"<<endl;
            for (int t=9; t<=15; t++)
            {

                rlutil::locate(24,t);
                cout<<"|";

                rlutil::locate(67,t);
                cout<<"|";

            }


            rlutil::locate(1,17);
            system("pause");
            system("cls");

            int puntajeXronda = 0;

            cout <<"_____________________________________________________________"<<endl;

            cout<<"TURNO DE "<<nombre<<"   |   RONDA NUMERO: "<<x << "   |   TUS PUNTOS: " << AcumPartida1 <<endl;

            cout<<"_____________________________________________________________"<<endl;



            for (j = 1; j <= 3; j++)
            {


                int repetidos[6] = {0};


                cout << j << " LANZAMIENTO" << endl;

                srand(time(NULL));
                for (int i = 0; i < 6; i++)
                {
                    /*num = 1 + rand() % 6;
                    dados[i] = num;
                    cout << "Dado " << i + 1 << ":" << dados[i] << endl;
                    repetidos[dados[i] - 1]++;*/

                      cout << "Ingreso de num: "<< endl;
                      cin >> num;
                      dados[i]=num;
                      repetidos[dados[i]-1]++;
                }

                int numeroJugada = AnalizaJugadas(dados);
                mostrarjugadas(numeroJugada);

                int puntajeCalculado = CalcularPuntaje(numeroJugada, repetidos, dados);
                if(puntajeCalculado== -1)
                {
                    system ("pause");
                    system("cls");
                    return;
                }
                cout<<"_____________________________________________________________"<<endl;

                cout << "TUS PUNTOS SON: " << puntajeCalculado << endl;
                cout<<"_____________________________________________________________"<<endl;

                puntajeXronda = PuntajeRonda(puntajeCalculado, puntajeXronda);
                cout << "TUS PUNTOS MAS ALTOS EN ESTA RONDA:  " << puntajeXronda << endl;
                cout<<"_____________________________________________________________"<<endl;

                if(puntajeXronda==0||puntajeCalculado==0)
                {
                    Acum1Jug=0;
                    AcumPartida1=Acum1Jug;
                }

                system("pause");
            }

            Acum1Jug+=puntajeXronda;
            AcumPartida1 = Acum1Jug;
            system("cls");

            rlutil::locate(25,8);
            cout<<"__________________________________________"<<endl;
            rlutil::locate(30,10);
            cout<<"RONDA NUMERO "<<x<<endl;
            rlutil::locate(30,11);
            cout<<"PROXIMO TURNO: "<<nombre2<<endl;
            rlutil::locate(30,12);
            cout<<"PUNTAJE DE "<<nombre<<":"<<AcumPartida1<<endl;
            rlutil::locate(30,13);
            cout<<"PUNTAJE DE "<<nombre2<<":"<<AcumPartida2<<endl;
            rlutil::locate(25,15);
            cout<<"__________________________________________"<<endl;
            for (int t=9; t<=15; t++)
            {

                rlutil::locate(24,t);
                cout<<"|";

                rlutil::locate(67,t);
                cout<<"|";

            }


            rlutil::locate(1,17);
            system("pause");
            system("cls");


            cout<<"TURNO DE "<<nombre2<<"   |   RONDA NUMERO: "<<x<<"    |   PUNTAJE: "<<AcumPartida2<<endl;
            cout<<"_______________________________________________________"<<endl;

            int puntajeXronda2 = 0;

            for (j = 1; j <= 3; j++)
            {

                int repetidos[6] = {0};

                cout << j << " LANZAMIENTO" << endl;
                srand(time(NULL));
                for (int i = 0; i < 6; i++)
                {
                    /*num = 1 + rand() % 6;
                    dados[i] = num;
                    cout << "Dado " << i + 1 << ":" << dados[i] << endl;
                    repetidos[dados[i] - 1]++;*/

                    cout << "Ingreso de num: "<< endl;
                      cin >> num;
                      dados[i]=num;
                      repetidos[dados[i]-1]++;
                }

                int numeroJugada = AnalizaJugadas(dados);
                mostrarjugadas(numeroJugada);

                int puntajeCalculado = CalcularPuntaje(numeroJugada, repetidos, dados);
                if(puntajeCalculado== -1)
                {
                    rlutil::locate(70,15);
                    cout<<"FELICIDADES "<<nombre<<" GANASTE EL JUEGO."<<endl;
                    system ("pause");
                    system("cls");
                    return;
                }
                cout<<"_______________________________________________________"<<endl;

                cout << "TUS PUNTOS SON: " << puntajeCalculado << endl;
                cout<<"_______________________________________________________"<<endl;
//

                puntajeXronda2 = PuntajeRonda(puntajeCalculado, puntajeXronda2);
                cout << "TUS PUNTOS MAS ALTOS EN ESTA RONDA:  " << puntajeXronda2 << endl;
                cout<<"_______________________________________________________"<<endl;
//

                if(puntajeXronda2==0||puntajeCalculado==0)
                {
                    Acum2Jug=0;
                    AcumPartida2=Acum2Jug;
                }

                system("pause");
            }



            Acum2Jug+=puntajeXronda2;
            AcumPartida2 = Acum2Jug;

            system("cls");






        }
        if(conti==0)
        {
            return;
        }


    }

    if(Acum1Jug>Acum2Jug)
            {
                for (int t=9; t<=15; t++)
                {

                    rlutil::locate(24,t);
                    cout<<"|";
                    rlutil::locate(67,t);
                    cout<<"|";

                }
                rlutil::locate(25,8);
                cout<<"__________________________________________"<<endl;
                rlutil::locate(30,10);
                cout<<"FELICIDADES "<<nombre<<" GANASTE EL JUEGO"<<endl;
                rlutil::locate(30,12);
                cout<<"TUS PUNTOS FUERON: "<<AcumPartida1<<endl;
                rlutil::locate(30,14);
                cout<<"GANASTE EN: "<<x<<" RONDAS."<<endl;
                rlutil::locate(25,15);
                cout<<"__________________________________________"<<endl;

                rlutil::locate(1,20);
                system("pause");
                system("cls");
                return;
            }
            if(Acum2Jug>Acum1Jug)
            {
                for (int t=9; t<=15; t++)
                {

                    rlutil::locate(24,t);
                    cout<<"|";
                    rlutil::locate(67,t);
                    cout<<"|";

                }
                rlutil::locate(25,8);
                cout<<"__________________________________________"<<endl;
                rlutil::locate(30,10);
                cout<<"FELICIDADES "<<nombre2<<" GANASTE EL JUEGO"<<endl;
                rlutil::locate(30,12);
                cout<<"TUS PUNTOS FUERON: "<<AcumPartida2<<endl;
                rlutil::locate(30,14);
                cout<<"GANASTE EN: "<<x<<" RONDAS."<<endl;
                rlutil::locate(25,15);
                cout<<"__________________________________________"<<endl;

                rlutil::locate(1,20);
                system("pause");
                system("cls");
                return;

            }

            if(Acum1Jug==Acum2Jug)
            {
                for (int t=9; t<=15; t++)
                {

                    rlutil::locate(24,t);
                    cout<<"|";
                    rlutil::locate(74,t);
                    cout<<"|";

                }
                rlutil::locate(25,8);
                cout<<"_________________________________________________"<<endl;
                rlutil::locate(30,10);
                cout<<"HUBO UN EMPATE ENTRE "<<nombre<<" Y "<<nombre2<<endl;
                rlutil::locate(30,12);
                cout<<"PUNTOS DE "<<nombre2<<": "<<AcumPartida2<<endl;
                rlutil::locate(30,14);
                cout<<"PUNTOS DE "<<nombre<<": "<<AcumPartida1<<endl;
                rlutil::locate(25,15);
                cout<<"_________________________________________________"<<endl;
            }
            rlutil::locate(1,17);
            system("pause");
            system("cls");



}


#endif // DOSJUGADORES_H_INCLUDED



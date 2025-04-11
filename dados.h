#ifndef DADOS_F_H_INCLUDED
#define DADOS_F_H_INCLUDED


//Declaracion de la funcion
void unJugador(int dados[]);

//Desarrollo
void unJugador(int dados[])
{
    int y=0;




    int num, conti=1, rondas,x;
    int repetidos[6]= {0};

    int Acum = 0;
    int AcumPartida=0;




    char nombre[10];
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
    rlutil::locate(30,10);
    cout << "INGRESE SU NOMBRE: ";
    cin >>nombre;
    rlutil::locate(30,12);
    cout<<"NUMERO DE RONDAS QUE DESEA JUGAR: ";
    cin>>rondas;

    rlutil::locate(26,14);
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


    rlutil::locate(37,10);
    cout << "COMIENZA EL JUEGO"<< endl;
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



    for(x=1; x<=rondas; x++)
    {

        int puntajeXronda=0;


        if(conti==1)
        {

            rlutil::locate(25,8);
            cout<<"__________________________________________"<<endl;
            rlutil::locate(30,10);
            cout<<"RONDA NUMERO "<<x<<endl;
            rlutil::locate(30,12);
            cout<<"TURNO DE: "<<nombre<<endl;
            rlutil::locate(30,14);
            cout<<"PUNTAJE DE "<<nombre<<":"<<AcumPartida<<endl;

            rlutil::locate(25,15);
            cout<<"__________________________________________"<<endl;
            for (int t=9; t<=15; t++)
            {

                rlutil::locate(24,t);
                cout<<"|";

                rlutil::locate(67,t);
                cout<<"|";
            }

            cout << endl;
            rlutil::locate(24,16);
            system ("pause");
            system("cls");




            cout <<"_____________________________________________________________"<<endl;

            cout<<"TURNO DE "<<nombre<<"   |   RONDA NUMERO: "<<x << "   |   TUS PUNTOS: " << AcumPartida <<endl;

            cout<<"_____________________________________________________________"<<endl;



            for( int j=1; j<=3; j++)
            {

                imprimirBarraLateral();

                int repetidos[6]= {0};

                rlutil::locate(1,4);
                cout << j <<" LANZAMIENTO " << endl;
                srand(time(NULL));
                for (int i=0; i <6; i++)
                {



                    num=1+rand()%6;
                    dados[i]=num;
                    //cout << "Dado "<< i+1 <<":" <<dados[i] << endl;
                    repetidos[dados[i]-1]++;

                    DibujoDados(dados);
                    printDice(dados);



                    /*cout << "Ingreso de num: "<< endl;
                       cin >> num;
                       dados[i]=num;
                       repetidos[dados[i]-1]++;
                       */



                }

                int numeroJugada = AnalizaJugadas(dados);
                mostrarjugadas(numeroJugada);

                int puntajeCalculado=CalcularPuntaje(numeroJugada, repetidos, dados);

                if(puntajeCalculado== -1)
                {
                    system ("pause");
                    system("cls");
                    return;
                }


                rlutil:: locate(1,14);
                cout<<"_____________________________________________________________"<<endl;
                rlutil:: locate(1,15);


                cout << "TUS PUNTOS SON: " << puntajeCalculado << endl;
                rlutil:: locate(1,16);
                cout<<"_____________________________________________________________"<<endl;



                puntajeXronda = PuntajeRonda(puntajeCalculado, puntajeXronda);

                rlutil:: locate(1,17);

                cout << "TUS PUNTOS MAS ALTOS EN ESTA RONDA:  " << puntajeXronda << endl;
                rlutil:: locate(1,18);
                cout<<"_____________________________________________________________"<<endl;


                if(puntajeXronda==0||puntajeCalculado==0)
                {
                    Acum=0;
                    AcumPartida=Acum;
                }


                system("pause");
                //system("cls");

            }

            system("cls");

            Acum += puntajeXronda;
            AcumPartida = Acum;




        }


        if(conti==0)
        {

            return;
        }
    }

    if(AcumPartida>=500)
    {

        for (int t=9; t<=15; t++)
        {

            rlutil::locate(24,t);
            cout<<"|";
            rlutil::locate(67,t);
            cout<<"|";

        }
        rlutil::locate(25,8);
        cout<<"__________________________________________________"<<endl;
        rlutil::locate(30,10);
        cout<<"FELICIDADES "<<nombre<<" GANASTE EL JUEGO"<<endl;
        rlutil::locate(30,12);
        cout<<"TUS PUNTOS FUERON: "<<AcumPartida<<endl;
        rlutil::locate(30,14);
        cout<<"GANASTE EN: "<<x<<" RONDAS."<<endl;
        rlutil::locate(25,15);
        cout<<"__________________________________________________"<<endl;

        rlutil::locate(1,20);
        system("pause");
        system("cls");
        return;
    }

    if(AcumPartida<500)
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
        cout<<"LO SIENTO "<<nombre<<" NO GANASTE EL JUEGO."<<endl;
        rlutil::locate(30,13);
        cout<<"TUS PUNTOS FUERON: "<<AcumPartida<<endl;
        rlutil::locate(25,15);
        cout<<"__________________________________________"<<endl;;

        rlutil::locate(1,20);
        system("pause");
        system("cls");
        return;

    }
}


#endif // DADOS_H_INCLUDED

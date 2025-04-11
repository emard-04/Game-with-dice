#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED



int TriplePuntaje(int repetidos[], int dados[]);
int SextetoXPuntaje(int repetidos[], int dados[]);
int PuntajeSuma(int repetidos[], int dados[]);
int CalcularPuntaje(int numeroJugada, int repetidos[], int dados[]);
int PuntajeRonda(int puntajeCalculado, int puntajeMasAlto);
int puntajesexteto(int dados[]);



//DESARROLLO
int puntajesexteto(int dados[])
{
    int puntaje;
    bool sexteto=1;

    for (int i=0; i <6; i++)
    {

        if(dados[i]!=6)
        {
            sexteto=0;
        }
    }
    if(sexteto==1)
    {
        puntaje=0;
    }

    return puntaje;




}
int TriplePuntaje(int repetidos[], int dados[])
{

    int i,j,con=0,puntaje, mayor=0;
    bool trio=0;
    for(i=0; i<6; i++)
    {
        con=0;
        for(j=0; j<6; j++)
        {
            if(dados[i]==dados[j])
            {
                con++;
            }
        }
        if(con>=3&&con!=6)
        {
            trio=1;
            if (dados[i] > mayor)
            {
                mayor = dados[i];  // Actualiza el valor del trío más grande
            }
        }

    }
    if(trio==1)
    {
        puntaje=mayor*10;

    }

    return puntaje;


}

int SextetoXPuntaje(int repetidos[], int dados[])
{
    for (int i = 0; i <6; ++i)
    {
        repetidos[dados[i] - 1]++;
    }

    // Calcular el puntaje
    int puntaje = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (repetidos[i] >= 6)
        {
            puntaje += (i + 1) * 50;
        }
    }

    return puntaje;
}

int PuntajeSuma(int repetidos[], int dados[])
{
    int i, j, con=0, puntaje=0;


    for(i=0; i<6; i++)
    {
        con=0;
        for(j=0; j<6; j++)
        {
            if(dados[i]==dados[j])
            {
                con++;
            }
        }

        if(con<=2)
        {
            puntaje+=dados[i];
        }
    }
    return puntaje;

}


int CalcularPuntaje(int numeroJugada, int repetidos[], int dados[])
{
    int puntaje = 0;

    switch (numeroJugada)
    {
    case 1:
        puntaje=puntajesexteto(dados);
        return puntaje;


    case 3:
        puntaje = SextetoXPuntaje(repetidos, dados);

        return puntaje;
    case 4:
        puntaje = TriplePuntaje(repetidos, dados);
        return puntaje;
    case 5:
        puntaje = PuntajeSuma(repetidos, dados);
        return puntaje;



    }

    return -1;
}

int PuntajeRonda(int puntajeCalculado,int puntajeMasAlto)
{
    if(puntajeCalculado==0)
    {
        return puntajeCalculado;
    }
    if (puntajeCalculado > puntajeMasAlto)
    {
        return puntajeCalculado;
    }


    return puntajeMasAlto;
}










#endif // PUNTAJE_H_INCLUDED

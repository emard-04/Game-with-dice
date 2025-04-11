#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



//DECLARACION DE FUNCIONES
bool EsIguales(int dados[]);
bool EsSexteto(int dados[]);
bool EsEscalera(int dados[]);
bool EsTriple(int repetidos, int dados[]);
bool EsSuma(int dados[]);
int AnalizaJugadas(int repetidos, int dados[]);
void mostrarjugadas(int numeroJugada);

//void mostrarjugadas(int dados[]);

//DESARROLLO DE FUNCIONES
bool EsSuma(int dados[])
{
    int i,j,con=0;
    bool suma=false;
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
    }


    if(con<=2)
    {

        suma=true;
    }


    return suma;

}

bool EsTriple(int  dados[])
{
    int i,j,con=0, mayor=0;
    bool trio=0,triple=false;
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
        triple = true;
    }

        return triple;



}


bool EsEscalera(int dados[])
{

    int ant;
    bool escalera = false,hayescalera=false;

    // Ordenar el vector de forma ascendente (de menor a mayor)
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (dados[i] > dados[j])
            {
                // Intercambiar los elementos si están en el orden incorrecto
                ant = dados[i];
                dados[i] = dados[j];
                dados[j] = ant;
            }
        }
    }

    for (int k = 0; k < 6; k++)
    {
        //cout << esc[k] << " ";
        if (k < 5 && dados[k] != dados[k + 1] - 1)
        {
            escalera = true;
        }
    }

    if (escalera==false)
    {

        hayescalera=true;
    }
        return hayescalera;




}


bool EsSexteto(int dados[])
{

    bool sexteto=0,haysexteto;

    for (int i=0; i <6; i++)
    {

        if(dados[i]!=6)
        {
            sexteto=1;
        }
    }
    if(sexteto==0)
    {

        haysexteto=true;
    }
        return haysexteto;



}

bool EsIguales (int dados[])
{


    bool hayiguales=false,iguales=0;

    for (int i=0; i <6; i++)
    {

        if(dados[0]!=dados[i]||dados[i]==6)
        {
            iguales=1;
        }
    }
    if(iguales==0)
    {

        hayiguales=true;
    }
        return hayiguales;


}

int AnalizaJugadas(int dados[])
{
    if(EsSexteto(dados))
    {

        return 1;
    }

   if(EsEscalera(dados)){

    return 2;
   }


    if(EsIguales(dados))
    {

        return 3;
    }
    if (EsTriple(dados))
    {

        return 4;

    }
     if(EsSuma(dados))
    {

       return 5;

    }


}
void mostrarjugadas(int numeroJugada)
{
  switch (numeroJugada)
  {
  case 1:
      cout << "TUS PUNTUAJE VUELVE A 0" << endl;
    break;
  case 2:
      cout << "FELICIDADES GANASTE" << endl;

    break;
  case 3:
      cout << "OBTUVISTE UN SEXTETO" << endl;
    break;
  case 4:
      cout << "OBTUVISTE UN TRIPLE" << endl;
    break;
  case 5:
       cout << "SUMA DE TODOS LOS DADOS " << endl;
    break;
  }

}





#endif // FUNCIONES_H_INCLUDED

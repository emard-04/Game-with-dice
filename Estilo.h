#ifndef ESTILO_H_INCLUDED
#define ESTILO_H_INCLUDED

void imprimirBarraLateral();
void DibujoDados(int dados[]);
void printDie(int value, int offsetX, int offsetY);
void printDie(int value);
void printDice(const int diceValues[]);
void DibujoDados(const int dados[]);


void imprimirBarraLateral()
{
    for (int i = 2; i < 17; ++i)
    {
        rlutil::locate(62, i);
        cout << "|";
    }
}
void printDie(int value, int offsetX, int offsetY) {
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(1 + offsetX, 1 + offsetY);
    std::cout << "+-----+" << std::endl;

    if (value == 1 || value == 3 || value == 5) {
        rlutil::setColor(rlutil::RED);
        rlutil::locate(1 + offsetX, 2 + offsetY);
        std::cout << "|     |" << std::endl;
        rlutil::locate(1 + offsetX, 3 + offsetY);
        std::cout << "|  *  |" << std::endl;
        rlutil::locate(1 + offsetX, 4 + offsetY);
        std::cout << "|     |" << std::endl;
    }

    if (value == 2 || value == 3) {
        rlutil::setColor(rlutil::RED);
        rlutil::locate(1 + offsetX, 2 + offsetY);
        std::cout << "|*    |" << std::endl;
        rlutil::locate(1 + offsetX, 3 + offsetY);
        std::cout << "|     |" << std::endl;
        rlutil::locate(1 + offsetX, 4 + offsetY);
        std::cout << "|    *|" << std::endl;
    }

    if (value == 4 || value == 5 || value == 6) {
        rlutil::setColor(rlutil::RED);
        rlutil::locate(1 + offsetX, 2 + offsetY);
        std::cout << "|*   *|" << std::endl;
        rlutil::locate(1 + offsetX, 3 + offsetY);
        std::cout << "|     |" << std::endl;
        rlutil::locate(1 + offsetX, 4 + offsetY);
        std::cout << "|*   *|" << std::endl;
    }

    if (value == 6) {
        rlutil::setColor(rlutil::RED);
        rlutil::locate(1 + offsetX, 2 + offsetY);
        std::cout << "|*   *|" << std::endl;
        rlutil::locate(1 + offsetX, 3 + offsetY);
        std::cout << "|*   *|" << std::endl;
        rlutil::locate(1 + offsetX, 4 + offsetY);
        std::cout << "|*   *|" << std::endl;
    }

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(1 + offsetX, 5 + offsetY);
    std::cout << "+-----+" << std::endl;
}




void DibujoDados(int dados[]) {
    int ubiX = 47;
    int ubiY = 9;
    int cont = 0;
    int contY = 0;

    for (int i = 0; i < 3; ++i) {
        if (i == 3) {
            contY = 8;
            cont = 0;
        }

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(ubiX + cont, ubiY + contY);
        std::cout << "+-----+" << std::endl;

        // Esquinas
        rlutil::locate(ubiX + cont + 1, ubiY + contY + 1);
        std::cout << "|";
        rlutil::locate(ubiX + cont + 11, ubiY + contY + 1);
        std::cout << "|";
        rlutil::locate(ubiX + cont + 1, ubiY + contY + 5);
        std::cout << "|";
        rlutil::locate(ubiX + cont + 11, ubiY + contY + 5);
        std::cout << "|";

        // Verticales
        rlutil::locate(ubiX + cont + 1, ubiY + contY + 2);
        std::cout << "|";
        rlutil::locate(ubiX + cont + 11, ubiY + contY + 2);
        std::cout << "|";
        rlutil::locate(ubiX + cont + 1, ubiY + contY + 4);
        std::cout << "|";
        rlutil::locate(ubiX + cont + 11, ubiY + contY + 4);
        std::cout << "|";

        // Horizontales
        rlutil::locate(ubiX + cont + 2, ubiY + contY + 1);
        std::cout << "-";
        rlutil::locate(ubiX + cont + 10, ubiY + contY + 1);
        std::cout << "-";
        rlutil::locate(ubiX + cont + 2, ubiY + contY + 5);
        std::cout << "-";
        rlutil::locate(ubiX + cont + 10, ubiY + contY + 5);
        std::cout << "-";

        // Puntos
        switch (dados[i]) {
            case 1:
                rlutil::locate(ubiX + cont + 6, ubiY + contY + 3);
                std::cout << "*";
                break;
            case 2:
                rlutil::locate(ubiX + cont + 4, ubiY + contY + 2);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 8, ubiY + contY + 4);
                std::cout << "*";
                break;
            case 3:
                rlutil::locate(ubiX + cont + 4, ubiY + contY + 2);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 6, ubiY + contY + 3);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 8, ubiY + contY + 4);
                std::cout << "*";
                break;
            case 4:
                rlutil::locate(ubiX + cont + 4, ubiY + contY + 2);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 8, ubiY + contY + 2);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 4, ubiY + contY + 4);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 8, ubiY + contY + 4);
                std::cout << "*";
                break;
            case 5:
                rlutil::locate(ubiX + cont + 4, ubiY + contY + 2);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 8, ubiY + contY + 2);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 6, ubiY + contY + 3);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 4, ubiY + contY + 4);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 8, ubiY + contY + 4);
                std::cout << "*";
                break;
            case 6:
                rlutil::locate(ubiX + cont + 4, ubiY + contY + 2);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 6, ubiY + contY + 2);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 8, ubiY + contY + 2);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 4, ubiY + contY + 4);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 6, ubiY + contY + 4);
                std::cout << "*";
                rlutil::locate(ubiX + cont + 8, ubiY + contY + 4);
                std::cout << "*";
                break;
            default:
                break;
        }

        cont += 20;
    }
}

void printDie(int value) {
    rlutil::setColor(rlutil::WHITE);
    std::cout << "+-----+" << std::endl;

    if (value == 1 || value == 3 || value == 5) {
        rlutil::setColor(rlutil::RED);
        std::cout << "|     |" << std::endl;
        std::cout << "|  *  |" << std::endl;
        std::cout << "|     |" << std::endl;
    }

    if (value == 2 || value == 3) {
        rlutil::setColor(rlutil::RED);
        std::cout << "|*    |" << std::endl;
        std::cout << "|     |" << std::endl;
        std::cout << "|    *|" << std::endl;
    }

    if (value == 4 || value == 5 || value == 6) {
        rlutil::setColor(rlutil::RED);
        std::cout << "|*   *|" << std::endl;
        std::cout << "|     |" << std::endl;
        std::cout << "|*   *|" << std::endl;
    }

    if (value == 6) {
        rlutil::setColor(rlutil::RED);
        std::cout << "|*   *|" << std::endl;
        std::cout << "|*   *|" << std::endl;
        std::cout << "|*   *|" << std::endl;
    }

    rlutil::setColor(rlutil::WHITE);
    std::cout << "+-----+" << std::endl;
}

void printDice(const int diceValues[]) {
    int offsetX = 0;
    int offsetY = 0;

    for (int i = 0; i < 3; ++i) {
        printDie(diceValues[i], offsetX, offsetY);
        offsetX += 8; // Ajusta el offset basado en el ancho de un dado
    }
}









#endif // ESTILO_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include "Funciones.h"

using namespace std;

// ==================== UTILIDADES DE ENTRADA ====================

// Lee un entero entre min y max, repitiendo hasta que sea valido.
int readIntInRange(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min && value <= max) return value;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid value. Enter a number between " << min << " and " << max << "." << endl;
    }
}

// Pausa hasta que el usuario presione Enter.
void pause() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ==================== NUMEROS ALEATORIOS ====================

// Genera un numero entre 1 y 100 que NO haya salido antes (registro, como pide el diagrama).
int generateNumber(bool drawn[101]) {
    int n;
    do {
        n = rand() % 100 + 1;
    } while (drawn[n]);
    drawn[n] = true;
    return n;
}

// ==================== TABLERO ====================

bool numberAlreadyExistsInBoard(int matrix[8][4], int value, int startRow, int endRow, int skipRow, int skipCol) {
    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == skipRow && j == skipCol) continue;
            if (matrix[i][j] == value) return true;
        }
    }
    return false;
}

string formatCellValue(int value, bool isSelected) {
    ostringstream oss;
    string text = (value == -1) ? "XX" : to_string(value);   // tachada se ve como XX
    if (isSelected) oss << "[" << setw(2) << setfill(' ') << text << "]";
    else            oss << " " << setw(2) << setfill(' ') << text << " ";
    return oss.str();
}

void displayBoardSection(const int matrix[8][4], int startRow, int endRow, const string& title, int curRow, int curCol) {
    cout << title << "\n";
    cout << "╭────┬────┬────┬────╮\n";
    for (int i = startRow; i < endRow; i++) {
        cout << "│";
        for (int j = 0; j < 4; j++) {
            bool isCurrent = (i == curRow && j == curCol);
            cout << formatCellValue(matrix[i][j], isCurrent) << "│";
        }
        cout << "\n";
        if (i < endRow - 1) cout << "├────┼────┼────┼────┤\n";
    }
    cout << "╰────┴────┴────┴────╯\n";
}

void displayMatrix(int matrix[8][4]) {
    cout << "\n" << "Player 1" << string(18, ' ') << "Player 2\n";
    for (int row = 0; row < 4; row++) {
        cout << "╭────┬────┬────┬────╮    ╭────┬────┬────┬────╮\n";
        cout << "│";
        for (int col = 0; col < 4; col++)
            cout << formatCellValue(matrix[row][col], false) << "│";
        cout << "    │";
        for (int col = 0; col < 4; col++)
            cout << formatCellValue(matrix[row + 4][col], false) << "│";
        cout << "\n";
        if (row < 3) cout << "├────┼────┼────┼────┤    ├────┼────┼────┼────┤\n";
    }
    cout << "╰────┴────┴────┴────╯    ╰────┴────┴────┴────╯\n";
}

void set_all_zero(int matrix[8][4]) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = 0;
}

// Cuenta las casillas tachadas (-1) de cada jugador.
bool verify_play(int matrix[8][4], int &playerone, int &playertwo) {
    playerone = 0;
    playertwo = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (matrix[i][j] == -1) playerone++;
    for (int i = 4; i < 8; i++)
        for (int j = 0; j < 4; j++)
            if (matrix[i][j] == -1) playertwo++;
    return (playerone == 16 || playertwo == 16);
}

// ==================== LLENADO DE TABLEROS ====================

void fillPlayerBoard(int matrix[8][4], int startRow, int endRow, const string& playerName) {
    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < 4; j++) {
            int value;
            while (true) {
                system("clear");
                displayBoardSection(matrix, startRow, endRow, playerName + " board", i, j);
                value = readIntInRange(
                    playerName + ", enter a number for position [" + to_string(i) + "][" + to_string(j) + "], between 1 and 100: ",
                    1, 100);
                if (numberAlreadyExistsInBoard(matrix, value, startRow, endRow, i, j)) {
                    cout << "That number is already used. Enter another one." << endl;
                    pause();
                } else break;
            }
            matrix[i][j] = value;
        }
    }
}

void fillMatrixManually(int matrix[8][4]) {
    set_all_zero(matrix);
    fillPlayerBoard(matrix, 0, 4, "Player 1");
    fillPlayerBoard(matrix, 4, 8, "Player 2");
}

void fillMatrixRandomly(int matrix[8][4]) {
    set_all_zero(matrix);
    for (int section = 0; section < 2; section++) {
        int startRow = section * 4;
        int endRow = startRow + 4;
        for (int i = startRow; i < endRow; i++) {
            for (int j = 0; j < 4; j++) {
                int value;
                do {
                    value = rand() % 100 + 1;
                } while (numberAlreadyExistsInBoard(matrix, value, startRow, endRow, i, j));
                matrix[i][j] = value;
            }
        }
    }
}

// ==================== JUEGO ====================

// La maquina tacha el numero en SU tablero (filas 4-7) si aparece.
void botIA(int matrix[8][4], int number) {
    for (int i = 4; i < 8; i++)
        for (int j = 0; j < 4; j++)
            if (matrix[i][j] == number)
                matrix[i][j] = -1;
}

// Turno de UN jugador. startRow = 0 (J1, filas 0-3) o 4 (J2, filas 4-7).
// currentNumber se muestra DESPUES de limpiar la pantalla, para que no se borre.
void do_play(int matrix[8][4], int startRow, const string& playerName, int currentNumber) {
    int p1 = 0, p2 = 0;
    verify_play(matrix, p1, p2);   // solo para mostrar el puntaje

    system("clear");
    displayMatrix(matrix);
    cout << "Number of this turn: " << currentNumber << endl;          // <-- ya no se borra
    cout << "Score  ->  Player 1: " << p1 << "/16    Player 2: " << p2 << "/16" << endl;

    int mark = readIntInRange(playerName + ", do you want to mark a cell? (1 = yes, 0 = no): ", 0, 1);
    if (mark == 0) {
        cout << "No cell was marked." << endl;
        pause();
        return;
    }

    while (true) {
        int row = readIntInRange("Row (1-4): ", 1, 4) - 1;
        int col = readIntInRange("Column (1-4): ", 1, 4) - 1;
        if (matrix[startRow + row][col] == -1) {                       // <-- no retachar
            cout << "That cell is already marked. Choose another one." << endl;
            continue;
        }
        matrix[startRow + row][col] = -1;                              // <-- SOLO su tablero
        cout << "Marked cell (" << row + 1 << ", " << col + 1 << ")." << endl;
        break;
    }
    pause();
}

void playAgainstComputer(int matrix[8][4]) {
    bool drawn[101] = {false};
    int playerone = 0, playertwo = 0;

    while (true) {
        int currentNumber = generateNumber(drawn);
        do_play(matrix, 0, "Player 1", currentNumber);
        botIA(matrix, currentNumber);
        if (verify_play(matrix, playerone, playertwo)) break;
    }

    displayMatrix(matrix);
    if (playerone == 16 && playertwo == 16) cout << "Draw!" << endl;
    else if (playerone == 16)             cout << "Player 1 wins!" << endl;
    else                                  cout << "The bot wins!" << endl;
    pause();
}

void playAgainstUser(int matrix[8][4]) {
    bool drawn[101] = {false};
    int playerone = 0, playertwo = 0;

    while (true) {
        int currentNumber = generateNumber(drawn);
        do_play(matrix, 0, "Player 1", currentNumber);
        do_play(matrix, 4, "Player 2", currentNumber);
        if (verify_play(matrix, playerone, playertwo)) break;
    }

    displayMatrix(matrix);
    if (playerone == 16 && playertwo == 16) cout << "Draw!" << endl;
    else if (playerone == 16)             cout << "Player 1 wins!" << endl;
    else                                  cout << "Player 2 wins!" << endl;
    pause();
}

void fillMatrix(int matrix[8][4], int playOP) {
    system("clear");
    int option = readIntInRange("Choose how to fill the board\n"
                                "1.- Fill the board manually\n"
                                "2.- Fill the board randomly\n"
                                "0.- Back to main menu\n"
                                "Option: ", 0, 2);

    if (option == 0) {
        cout << "Returning to main menu..." << endl;
        pause();
        return;
    }
    if (option == 1) fillMatrixManually(matrix);
    else             fillMatrixRandomly(matrix);

    if (playOP == 1) playAgainstComputer(matrix);
    else             playAgainstUser(matrix);
}
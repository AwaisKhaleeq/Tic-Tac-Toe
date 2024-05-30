#include <iostream>

using namespace std;

const int BOARD_SIZE = 3;

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1)
                cout << " | ";
        }
        cout << endl;
        if (i < BOARD_SIZE - 1)
            cout << "---------" << endl;
    }
    cout << endl;
}

bool isBoardFull(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

char checkWinner(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return board[0][j];
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

void getComputerMove(int& row, int& col, char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                row = i;
                col = j;
                return;
            }
        }
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer = 'X';
    int row, col;
    int gameMode;

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Choose a game mode:" << endl;
    cout << "1. Player vs. Player" << endl;
    cout << "2. Player vs. Computer" << endl;
    cout << "Enter the mode number (1 or 2): ";
    cin >> gameMode;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    while (true) {
        printBoard(board);

        char winner = checkWinner(board);
        if (winner != ' ') {
            cout << "Player " << winner << " wins!" << endl;
            break;
        }
        else if (isBoardFull(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        if (gameMode == 1 || (gameMode == 2 && currentPlayer == 'X')) {
            cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
            cin >> row >> col;
        }
        else {
            getComputerMove(row, col, board);
            cout << "Computer chooses row " << row << " and column " << col << endl;
        }

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

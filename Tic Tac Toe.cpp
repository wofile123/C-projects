#include <iostream>
using namespace std;

const string RESET = "\033[0m";
const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string B_BLACK = "\033[90m";
const string B_RED = "\033[91m";
const string B_GREEN = "\033[92m";
const string B_YELLOW = "\033[93m";
const string B_BLUE = "\033[94m";
const string B_MAGENTA = "\033[95m";
const string B_CYAN = "\033[96m";
const string B_WHITE = "\033[97m";

void front(){
    system("cls");
    cout << B_GREEN << "************************************" << RESET << endl;
    cout << B_GREEN << "||        \033[93mTIC-TAC-TOE GAME\033[0m\033[92m        ||" << RESET << endl;
    cout << B_GREEN << "************************************" << RESET << "\n\n";
}


void printBoard(char board[]) {
    cout <<B_BLUE<< "-------------" <<RESET<< endl;
     for (int i = 0; i < 9; ++i) {
        cout <<B_BLUE<< "| " <<RESET;
        if (board[i] == 'X' ) {
            cout <<B_GREEN<< board[i] << " " <<RESET;
        } 
       else if (board[i] == 'O' ) {
            cout <<B_YELLOW<< board[i] << " " <<RESET;
        } else {
            cout <<B_BLACK<< board[i] << " " <<RESET;
        }
        if ((i + 1) % 3 == 0) {
            cout <<B_BLUE<< "|" <<RESET<< endl;
            cout <<B_BLUE<< "-------------" <<RESET<< endl;
        }
    }
}

bool checkWin(char board[], char player) {
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i*3] == player && board[i*3+1] == player && board[i*3+2] == player) ||
            (board[i] == player && board[i+3] == player && board[i+6] == player)) {
            return true;
        }
    }
    
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(char board[]) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}

bool placeMarker(char board[], int position, char marker) {
  
    if (board[position - 1] == 'X' || board[position - 1] == 'O') {
        return false;
    }
    board[position - 1] = marker;
    return true; 
    
}

int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int currentPlayer = 1;  
    char marker = 'X';      
    bool gameRunning = true;
    int position;

    while (gameRunning) {
        front();
        printBoard(board);

        cout <<B_MAGENTA<< "\nPlayer " << currentPlayer << ", enter a number (1-9): "<<RESET;
        cin >> position;
        system("clear");

            if (position < 1 || position > 9 || board[position - 1] == 'X' || board[position - 1] == 'O') {
            cout <<B_RED<< "Invalid input or spot already taken. Please choose another." <<RESET<< endl;
            continue;
        }

        if (!placeMarker(board, position, marker)) {
            cout <<B_RED<< "That spot is already taken. Please choose another." <<RESET<< endl;
            continue;
        }

        if (checkWin(board, marker)) {
            front();
            printBoard(board);
            cout <<MAGENTA<< "\nPlayer " << currentPlayer << " wins!" <<RESET<< endl;
            gameRunning = false;
        } else if (checkDraw(board)) {
            front();
            printBoard(board);
            cout <<B_CYAN<< "\nIt's a draw!" <<RESET<< endl;
            gameRunning = false;
        } else {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
            marker = (marker == 'X') ? 'O' : 'X'; 
        }
    }
system("PAUSE");
    return 0;
}



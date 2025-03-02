#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 3;
void drawBoard(vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool checkWin(vector<vector<char>>& board, char player) {
    for (int i = 0; i < SIZE; i++) {
        bool rowWin = true;
        bool colWin = true;
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != player) {
                rowWin = false;
            }
            if (board[j][i] != player) {
                colWin = false;
            }
        }
        if (rowWin || colWin) {
            return true;
        }
    }
    bool diag1Win = true;
    bool diag2Win = true;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] != player) {
            diag1Win = false;
        }
        if (board[i][SIZE - i - 1] != player) {
            diag2Win = false;
        }
    }
    return diag1Win || diag2Win;
}
bool checkDraw(vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}
int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, '-'));
    char player = 'X';
    while (true) {
        drawBoard(board);
        cout << "it's player " << player << "'s turn. Enter your row and column (1-3)\n";
        int row, col;
        cout << "Enter row no : ";
        cin >> row ;
        cout << "Enter column no : ";
        cin >> col ;
        row--; col--; 
        if (board[row][col] != '-') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[row][col] = player;
        if (checkWin(board, player)) {
            drawBoard(board);
            cout << " Congratulation player " << player << " wins!" << endl;
            break;
        } else if (checkDraw(board)) {
            drawBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    cout << "Play again? (y/n): ";
    char response;
    cin >> response;
    if (response == 'y') {
        main();
    }

    return 0;
}


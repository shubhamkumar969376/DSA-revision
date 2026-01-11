#include <bits/stdc++.h>
using namespace std;

int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(0));

    unordered_map<int, int> board;

    // Ladders
    board[2] = 38;
    board[7] = 14;
    board[8] = 31;
    board[15] = 26;
    board[28] = 84;

    // Snakes
    board[16] = 6;
    board[46] = 25;
    board[49] = 11;
    board[62] = 19;
    board[64] = 60;

    int p1 = 0, p2 = 0;
    int turn = 1;

    cout << "===== SNAKE AND LADDER GAME =====\n";

    while (true) {
        int dice = rollDice();

        if (turn == 1) {
            cout << "\nPlayer 1 turn";
            cout << "\nDice rolled: " << dice;

            int oldPos = p1;
            if (p1 + dice <= 100)
                p1 += dice;

            if (board.count(p1)) {
                cout << "\nSnake/Ladder jump from " << p1;
                p1 = board[p1];
                cout << " to " << p1;
            }

            cout << "\nPlayer 1: " << oldPos << " -> " << p1 << endl;

            if (p1 == 100) {
                cout << "\n🎉 Player 1 WINS 🎉\n";
                break;
            }
            turn = 2;
        }
        else {
            cout << "\nPlayer 2 turn";
            cout << "\nDice rolled: " << dice;

            int oldPos = p2;
            if (p2 + dice <= 100)
                p2 += dice;

            if (board.count(p2)) {
                cout << "\nSnake/Ladder jump from " << p2;
                p2 = board[p2];
                cout << " to " << p2;
            }

            cout << "\nPlayer 2: " << oldPos << " -> " << p2 << endl;

            if (p2 == 100) {
                cout << "\n🎉 Player 2 WINS 🎉\n";
                break;
            }
            turn = 1;
        }

        cout << "\nCurrent Positions:";
        cout << "\nPlayer 1 = " << p1;
        cout << "\nPlayer 2 = " << p2;
        cout << "\n-----------------------------\n";
    }

    return 0;
}

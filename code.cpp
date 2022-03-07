#include <iostream>
using namespace std;
int freq[] = { 1,1,1,1,1,1,1,1,1 };

void printGame(int game[]) {
    cout << "$$$$$$$$$$$" << '\n';
    for (int i = 0; i < 9; i++) {
        cout << '|' << game[i] << "| ";
        if ((i + 1) % 3 == 0)cout << '\n';
    }
    cout << "$$$$$$$$$$$" << '\n';
}

int possible_moves(int game[], char possibleMove[]) {
    for (int i = 0; i < 9; i++) {
        if (game[i] == 0) {
            if (i < 3)possibleMove[1] = ' ';
            if (i > 5)possibleMove[0] = ' ';
            if (i % 3 == 0)possibleMove[2] = ' ';
            if (i % 3 == 2)possibleMove[3] = ' ';
            cout << "Your possible moves ";
            for (int i = 0; i < 4; i++)cout << possibleMove[i] << ' ';
            return i;
        }
    }
}

void movegame(int game[], int temp, int move) {
    int x;
    if (move == 'v') {
        x = game[temp];
        game[temp] = game[temp + 3];
        game[temp + 3] = x;
    }
    else if (move == '>') {
        x = game[temp];
        game[temp] = game[temp + 1];
        game[temp + 1] = x;
    }
    else if (move == '<') {
        x = game[temp];
        game[temp] = game[temp - 1];
        game[temp - 1] = x;
    }
    else if (move == '^') {
        x = game[temp];
        game[temp] = game[temp - 3];
        game[temp - 3] = x;
    }
    else {
        cout << "it's not a move" << '\a';
    }
}

bool truemove(char move, char PossiableMove[]) {
    for (int i = 0; i < 4; i++)
        if (PossiableMove[i] == move)
            return true;
    return false;
}

bool correct(int game[]) {
    for (int i = 0; i < 9; i++) {
        if (game[i] != i)
            return false;
    }
    return true;
}

void initRandom(int game[]) {
    for (int i = 0; i < 9; i++) {
        int random;
        while (true) {
            random = (rand() % 9);
            if (freq[random] == 1) {
                freq[random] = 0;
                break;
            }
        }
        game[i] = random;
    }
}


int main() {
    int zeroPlace, game[9] = { 7 ,6 ,2 ,3 ,1 ,0 ,4 ,5 ,8 };
    initRandom(game);
    while (true) {
        char PossiableMove[4] = { 'v','^','<','>' }, move;
        printGame(game);
        zeroPlace = possible_moves(game, PossiableMove);
        cout << '\n';
        cin >> move;
        if (!truemove(move, PossiableMove)) {
            cout << "You Lose :( \a";
            break;
        }
        movegame(game, zeroPlace, move);
        if (correct(game)) {
            cout << "YOU WIN! \a";
            break;
        }
    }
}


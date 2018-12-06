// author: Karol Baraniecki

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static char board[3][3] = {
    { '1', '2', '3' },
    { '4', '5', '6' },
    { '7', '8', '9' }
};

static void disp(void) {
    for(int row = 0; row < 3; row++) {
        printf(" %c | %c | %c\n", board[row][0], board[row][1], board[row][2]);
        printf("%s\n", (row < 2) ? "___|___|___" : "   |   |  ");
    }
}

static int input(char *name, char symbol) {
    int i = -1;
    while(i < 1 || i > 9) {
        printf("%s put your %c [1, 9]:\n", name, symbol);
        if(scanf("%d", &i) != 1) {
            puts("Not a number!");
            exit(0);
        }
    }
    return i;
}


static bool eq3(char a, char b, char c) {
    return a == b && a == c;
}

// ' ' for a non win
// 'X' or 'O' when 
static char checkwin() {
    for(int row = 0; row < 3; row++) {
        if(eq3(board[row][0], board[row][1], board[row][2]))
            return board[row][0];
    }
    for(int col = 0; col < 3; col++) {
        if(eq3(board[0][col], board[1][col], board[2][col]))
            return board[col][0];
    }
    if(eq3(board[0][0], board[1][1], board[2][2]))
        return board[0][0];
    if(eq3(board[0][2], board[1][1], board[2][0]))
        return board[0][2];

    return ' ';
}

static char turn2symbol(int turn) {
    return turn ? 'O' : 'X';
}

static bool emptySpace(void) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == ' ')
                return true;
    return false;
}

int main() {
    char player[2][32];

    printf("Name of player 1:\n");
    scanf("%s", player[0]);

    printf("Name of player 2:\n");
    scanf("%s", player[1]);

    printf("Welcome %s and %s\n", player[0], player[1]);
    disp();

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    int turn = 1;

    char win;
    while((win = checkwin()) == ' ' && emptySpace()) {
        turn = !turn;

        int in;
        do {
            in = input(player[turn], turn2symbol(turn)) - 1;
            if(in < 0)
                goto end;
        } while(board[in / 3][in % 3] != ' ');
        
        //printf("%d %d\n", in / 3, in % 3);
        board[in / 3][in % 3] = turn2symbol(turn);
        
        disp();
    }
end:
    if(checkwin() != ' ')
        printf("%s (%c) won!\n", player[turn], turn2symbol(turn));
    else
        printf("Neigher %s nor %s won, it's a draw!\n", player[0], player[1]);

    return 0;
}

/*

Name of player 1:
Name of player 2:
Welcome Liwko and Baton
 1 | 2 | 3
___|___|___
 4 | 5 | 6
___|___|___
 7 | 8 | 9
   |   |  
Liwko put your X [1, 9]:
   |   |  
___|___|___
   | X |  
___|___|___
   |   |  
   |   |  
Baton put your O [1, 9]:
   |   | O
___|___|___
   | X |  
___|___|___
   |   |  
   |   |  
Liwko put your X [1, 9]:
   |   | O
___|___|___
   | X |  
___|___|___
 X |   |  
   |   |  
Baton put your O [1, 9]:
   |   | O
___|___|___
   | X |  
___|___|___
 X |   | O
   |   |  
Liwko put your X [1, 9]:
 X |   | O
___|___|___
   | X |  
___|___|___
 X |   | O
   |   |  
Baton put your O [1, 9]:
Baton put your O [1, 9]:
 X |   | O
___|___|___
   | X | O
___|___|___
 X |   | O
   |   |  
Baton (O) won!
*/

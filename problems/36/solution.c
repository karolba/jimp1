// author: Karol Baraniecki

#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

static int tetrimoses = 0;

static void disp(int width, int height, bool board[height][width]) {
    static int itercnt = 0;
    printf("Iteration: %d, tetrimoses: %d\n", itercnt++, tetrimoses);

    printf("-");
    for(int i = 0; i < width; i++)
        printf("%c", (char) '1' + i);
    printf("-\n");

    for(int h = 0; h < height; h++) {
        printf("|");
        for(int w = 0; w < width; w++)
            printf("%c", board[h][w] ? '*' : ' ');
        printf("|\n");
    }
    
    for(int i = 0; i < width + 2; i++)
        printf("-");

    puts("");
}

static bool fall(int width, int height, bool board[height][width]) {
    for(int h = 0; h < height - 1; h++) {
        for(int w = 0; w < width; w++) {
            if(board[h][w] && !board[h + 1][w]) {
                board[h + 1][w] = true;
                board[h][w] = false;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int width, height;
    scanf("%d", &width);
    scanf("%d", &height);
    width -= 2;
    height -= 2;

    bool board[height][width];
    bzero(board, sizeof(bool) * height * width);

    disp(width, height, board);
    int row;
    while(scanf("%d", &row) == 1) {
        tetrimoses += 1;
        row -= 1;

        // ??
        int starting_h = (height <= 1 || tetrimoses != 1) ? 0 : 1;

        if(board[starting_h][row]) {
            puts("Game over!");
            return 0;
        }

        board[starting_h][row] = true;
        
        if(height != 1 || tetrimoses != 1) // ??
            disp(width, height, board);

        while(fall(width, height, board)) {
            disp(width, height, board);
        }
    }

    return 0;
}

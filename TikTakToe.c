#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 8 // Max board size is 10x10.

// Global variables
unsigned int b[MAXSIZE][MAXSIZE]; // Declaration of the board.
unsigned int bsize; // Actual size of the game board.

// Function to zero the board with empty fields.
// No args, no return.
void ZeroBoard() {

    int x,y; // Local variables for walking through the board. Upper, left corner is [0,0].

    // Going through the board, line by line (from top to bottom), left to right in each line.
    for (y = 0; y < bsize; ++y) {
        for (x = 0; x < bsize; ++x) {
            b[x][y] = 0;
        }
    }
}

// Function to show the board.
void ShowBoard() {

    int x,y; // Local variables for walking through the board. Upper, left corner is [0,0].
    char letters[MAXSIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    
    int i;

    // First two board lins.
    printf("\n");
    printf("  "); for (i = 0; i < bsize; ++i) { printf("%c", letters[i]); } printf("  \n");
    printf("  "); for (i = 0; i < bsize; ++i) { printf("-"); } printf("  \n");

    // Going through the board, line by line (from top to bottom), left to right in each line.
    for (y = 0; y < bsize; ++y) {
        // Beginning of the line.
        printf("%d|", y+1);
        // Content of the board (current line).
        for (x = 0; x < bsize; ++x) {
            switch(b[x][y]) {
                case 1:
                    printf("O");
                    break;
                case 2:
                    printf("X");
                    break;
                default:
                    printf(" ");
                    break;
            }
        }
        // Line ending.
        printf("|%d\n", y+1);
    }

    // Last two lines.
    printf("  "); for (i = 0; i < bsize; ++i) { printf("-"); } printf("  \n");
    printf("  "); for (i = 0; i < bsize; ++i) { printf("%c", letters[i]); } printf("  \n");
    printf("\n");
}


// Function to check if there is any free spaces on the board.
int IsBoardFree() {

    int x,y;

        // Going through the board, line by line (from top to bottom), left to right in each line.
    for (y = 0; y < bsize; ++y) {
        for (x = 0; x < bsize; ++x) {
            if (b[x][y] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Function which makes computer's move, assuming there is free space left on the board.
void ComputerMove() {

    int x,y;

    while(1) {
        // Lets pick some random spot on the board
        x = rand() % bsize;
        y = rand() % bsize;

        if (b[x][y] == 0) break; // Exit the loop, if the spot is free.
    } 

    // Fill the spot with X
    b[x][y] = 2;
}


//
// MAIN PROGRAM
//
int main() {

    unsigned int player_starts; // Keeps info who starts the game.
    unsigned int player_moves; // 0 --> computer, 1 --> player

    // Welcome message.
    printf("\n\nWelcome to Tic Tac Toe game!\n\n");
    printf("Let's see who starts... ");
    // !!! delay
    // Start the lottery.
    srand(time(NULL)); // Initialize random seed.
    // whostarts = 0 --> computer starts
    // whostarts = 1 --> player starts
    player_starts = rand() % 2;
    if (player_starts) {
        printf("YOU START! and you have Os\n");
        player_moves = 1;
    }
    else {
        printf("I WILL START! and I have Xs\n");
        player_moves = 0;
    }
    
    // !!! Here ask for board size.
    bsize = 3;

    // Zero the board.
    ZeroBoard();

    // Set some Xs and Os:
    // 0 = empty, 1 = O, 2 = X.
    // b[0][4] = 2;
    // b[4][1] = 2;
    // b[2][2] = 1;
    // b[3][3] = 1;

    // if (!player_starts) {
    //     // Computer moves.
    //     ComputerMove();
    // }

    ShowBoard();

    // Show the board.
    while(1) {
        
        if (player_moves) {
            printf("Your turn, i.e. A3: ");
            // !!!
            printf("\n");
            player_moves = 0;
        }
        else {
            ComputerMove();
            player_moves = 1;
        }

        ShowBoard();

        // Check end conditions (board full or someone wins).
        // !!! check if someone wins.
        if (!IsBoardFree()) {
            printf("The board is full. GAME OVER!\n");
            break;
        }

    }
    
}
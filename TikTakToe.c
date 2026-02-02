#include <stdio.h>

#define MAXSIZE 8 // Max board size is 10x10.
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
}


//
// MAIN PROGRAM
//
int main() {

    // Welcome message.
    // !!!
    
    // !!! Here ask for board size.
    bsize = 8;

    // Zero the board.
    ZeroBoard();

    // Set some Xs and Os:
    // 0 = empty, 1 = O, 2 = X.
    b[0][4] = 2;
    b[4][1] = 2;
    b[2][2] = 1;
    b[3][3] = 1;

    // Show the board.
    ShowBoard();
}
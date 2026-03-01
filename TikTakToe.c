#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 8 // Max board size is 8x8.

// Global variables
unsigned int b[MAXSIZE][MAXSIZE]; // Declaration of the board, assumed values of fields 0 = empty, 1 = O, 2 = X.
unsigned int bsize;               // Actual size of the game board.

// Function to zero the board with empty fields.
// No args, no return.
void ZeroBoard()
{

    int x, y; // Local variables for walking through the board. Upper, left corner is [0,0].

    // Going through the board, line by line (from top to bottom), left to right in each line.
    for (y = 0; y < bsize; ++y)
    {
        for (x = 0; x < bsize; ++x)
        {
            b[x][y] = 0;
        }
    }
}

// Function to show the board.
void ShowBoard()
{

    int x, y; // Local variables for walking through the board. Upper, left corner is [0,0].
    char letters[MAXSIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    int i;

    // First two board lins.
    printf("\n");
    printf("  ");
    for (i = 0; i < bsize; ++i)
    {
        printf("%c", letters[i]);
    }
    printf("  \n");
    printf("  ");
    for (i = 0; i < bsize; ++i)
    {
        printf("-");
    }
    printf("  \n");

    // Going through the board, line by line (from top to bottom), left to right in each line.
    for (y = 0; y < bsize; ++y)
    {
        // Beginning of the line.
        printf("%d|", y + 1);
        // Content of the board (current line).
        for (x = 0; x < bsize; ++x)
        {
            switch (b[x][y])
            {
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
        printf("|%d\n", y + 1);
    }

    // Last two lines.
    printf("  ");
    for (i = 0; i < bsize; ++i)
    {
        printf("-");
    }
    printf("  \n");
    printf("  ");
    for (i = 0; i < bsize; ++i)
    {
        printf("%c", letters[i]);
    }
    printf("  \n");
    printf("\n");
}

// Function to check if there is any free spaces on the board.
int IsBoardFree()
{

    int x, y;

    // Going through the board, line by line (from top to bottom), left to right in each line.
    for (y = 0; y < bsize; ++y)
    {
        for (x = 0; x < bsize; ++x)
        {
            if (b[x][y] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function which makes computer's move, assuming there is free space left on the board.
void ComputerMove()
{

    int x, y;

    while (1)
    {
        // Lets pick some random spot on the board
        x = rand() % bsize;
        y = rand() % bsize;

        // Exit the loop, if the spot is free.
        if (b[x][y] == 0)
            break;
    }

    // Fill the spot with X
    b[x][y] = 2;
}

void PlayerMove()
{
    char x, y, c;

    while (1)
    {
        // Put in our spot
        printf("Your turn, i.e. A3: ");
    
        scanf("%c%c", &x, &y);
        while ((c = getchar()) != '\n' && c != EOF); // empty input buffer

        // Make sure that the letter is in upper
        if (x >= 97 && x <= 122) { x -= 32; }

        // Make sure that given coordinates are within the board
        if ((x >= 65 && x <= 65 + (bsize - 1)) && (y >= 49 && y <= 49 + (bsize - 1))) // 65 = A (start of X axis), 49 = 1 (start of Y axis)
        {
            x = x - 65;
            y = y - 49;

            // Exit the loop, if the spot is free.
            if (b[x][y] == 0)
            {
                break;
            }
            else {
                printf("This spot is taken, try again!\n");
            }
        }
        else
        {
            printf("Invalid board coordinates, try again!\n");
        }
    }

    // All is good, fill spot with an O
    b[x][y] = 1;
}

int CheckOdd(int n)
{
    return n % 2; // any rest from divide will return true (non-zero)
}

int CheckWin()
{
    int x, y;
    int win;

    // Check rows

    // Check for O's
    for (y = 0; y < bsize; ++y)
    {
        win = 1; // I Assume this row is a winning one
        for (x = 0; x < bsize; ++x)
        {
            if (b[x][y] != 1)
            {
                win = 0; // Assuming there is no O then there is no win.
                break;
            }
        }

        if (win) // Assuming there is a O then then there is win.
        {
            return 1;
        }
    }

    // Check for X's
    for (y = 0; y < bsize; ++y)
    {
        win = 1; // I Assume this row is a winning one
        for (x = 0; x < bsize; ++x)
        {
            if (b[x][y] != 2)
            {
                win = 0; // Assuming there is no  then there is no win.
                break;
            }
        }

        if (win) // Assuming there is a X then then there is win.
        {
            return 1;
        }
    }

    // Check Columns

    // Check for O's
    for (x = 0; x < bsize; ++x)
    {
        win = 1; // I Assume this row is a winning one
        for (y = 0; y < bsize; ++y)
        {
            if (b[x][y] != 1)
            {
                win = 0; // Assuming there is no O then there is no win.
                break;
            }
        }

        if (win) // Assuming there is a O then then there is win.
        {
            return 1;
        }
    }

    // Check for X's
    for (x = 0; x < bsize; ++x)
    {
        win = 1; // I Assume this row is a winning one
        for (y = 0; y < bsize; ++y)
        {
            if (b[x][y] != 2)
            {
                win = 0; // Assuming there is no X then there is no win.
                break;
            }
        }

        if (win) // Assuming there is a X then then there is win.
        {
            return 1;
        }
    }

    // MAIN DIAGONAL

    // Checks for O's
    for (x = 0; x < bsize; ++x)
    {
        win = 1; // I Assume this row is a winning one
        if (b[x][x] != 1)
        {
            win = 0; // Assuming there is no O and no Space then then there is no win.
            break;
        }
    }

    if (win) // Assuming there is a O then then there is win.
    {
        return 1;
    }

    // Checks for X's
    for (x = 0; x < bsize; ++x)
    {
        win = 1; // I Assume this row is a winning one
        if (b[x][x] != 2)
        {
            win = 0; // Assuming there is no X and no Space then then there is no win.
            break;
        }
    }

            if (win) // Assuming there is a X then then there is win.
    {
        return 1;
    }

    // ANTI-MAIN DIAGONAL

    // Checks for O's
        for (x = 0; x < bsize; ++x)
    {
        win = 1; // I Assume this row is a winning one
        if (b[x][bsize - x - 1] != 1)
        {
            win = 0; // Assuming there is no O and no Space then then there is no win.
            break;
        }
    }

    if (win) // Assuming there is a O then then there is win.
    {
        return 1;
    }

    // Checks for X's
    for (x = 0; x < bsize; ++x)
    {
        win = 1; // I Assume this row is a winning one
        if (b[x][bsize - x - 1] != 2)
        {
            win = 0; // Assuming there is no X and no Space then then there is no win.
            break;
        }
    }

    if (win) // Assuming there is a X then then there is win.
    {
        return 1;
    }        

    // There was no win
    return 0;
}

int Points()
{
    int x, y;

    if (b[x][y] == 1)
    {
        printf("You have won.\n");
    }
    if (b[x][y] == 2)
    {
        printf("I have won.\n");
    }
}
//
// MAIN PROGRAM
//
int main()
{

    unsigned int player_starts; // Keeps info who starts the game.
    unsigned int player_moves;  // 0 --> computer, 1 --> player
    int x, y;

    // Welcome message.
    printf("\n\nWelcome to Tic Tac Toe game!\n\n");
    printf("Let's see who starts... ");
    // !!! delay
    // Start the lottery.
    srand(time(NULL)); // Initialize random seed.
    // whostarts = 0 --> computer starts
    // whostarts = 1 --> player starts
    player_starts = rand() % 2;
    if (player_starts)
    {
        printf("YOU START! and you have Os\n");
        player_moves = 1;
    }
    else
    {
        printf("I WILL START! and I have Xs\n");
        player_moves = 0;
    }

    // !!! Ask for bsize
    bsize = 4;

    // Zero the board.
    ZeroBoard();

    // Test, set some Xs and Os:
    // 0 = empty, 1 = O, 2 = X.
    // b[0][0] = 2;
    // b[0][1] = 2;
    // b[0][2] = 0;
    // b[0][3] = 0;
    // ShowBoard();
    // printf("checkboard: %d\n", CheckWin());
    // return 0;

    ShowBoard();

    // Show the board.
    while (1)
    {

        if (player_moves)
        {
            PlayerMove();
            printf("\n");
            player_moves = 0;
        }
        else
        {
            ComputerMove();
            player_moves = 1;
        }

        ShowBoard();

        // Check end conditions (board full or someone wins).
        if (CheckWin())
        {
            if (!player_moves) { // player_moves is reversed in this very moment.
                printf("You won!\n");
            }
            else {
                printf("I won. Ha!\n");
            }
            
            break;
        }
        
        // Check if the board if full.
        if (!IsBoardFree())
        {
            if (!CheckWin()) {
                printf("It is a draw.");
            }
            break;
        }  
    }

    // !!! Print points
}
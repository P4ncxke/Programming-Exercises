#include <stdio.h>

int IsDataValid(float arr[], int sides_size)
{
    // Go through the array and check data validity.
    for(int i = 0; i < sides_size; ++i) {
        if (arr[i] <= 0) {
            // Return 0 if not valid.
            return 0;
        }
    }

    // Whole array was OK.
    return 1;
}

char MakeUpper(char c)
{
    if (c >= 97 && c <= 122)
    {
        return c -= 32;
    }
    else
    {
        return c;
    }
}

int IsChoiceCorrect(char c)
{
    if (c == 'Y' || c == 'N')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int LongSide(float arr[], int arr_size)
{
    int i;
    int longest = 0;
    int longest_index = -1;

    for (i = 0; i < arr_size; ++i)
    {
        if (arr[i] >= longest)
        {
            longest = arr[i];
            longest_index = i;
        }
    }

    return longest_index;
}

// This function will return next valid index of the array, based on given array size.
// Arguments: starting index, increase amount (must be positive), array size
// Return: next index
int ni(int si, int add, int arr_size) {

    while(add) {
        // We are here, so there is still something to add.
        ++si;
        if (si >= arr_size) { // Check if we reach the size of the array.
            si = 0; // If so, we loop the index.
        }
        --add;
    }

    return si; // The function returns starting index increased by increase amount.
}

int main()
{
    float sides[3];
    int sides_size = sizeof(sides)/sizeof(float);

    char choice;

    do
    {
        printf("Welcome to my program. This program will tell you if a triangle exist's or not.\n");
        printf("Please input three numbers.\n");

        do
        {
            // Input three numbers
            printf("Input first number: ");
            scanf("%f", &sides[0]);

            printf("Input second number: ");
            scanf("%f", &sides[1]);

            printf("Input third number: ");
            scanf("%f", &sides[2]);
            if (!IsDataValid(sides, sides_size))
            {
                printf("Read The ... Manual.\n");
                printf("Their There For a Reason.\n");
            }
        } while (!IsDataValid(sides, sides_size));

        int i_longest = LongSide(sides, sides_size);
        printf("Index of the largest element is: %d and the value is %.2f\n", i_longest, sides[i_longest]);
       
        // Check if the longes side is smaller than two other sides.
        // We know indexes of other sides, by adding +1 and +2 to the index of the longest side (using ni function)
        if (sides[i_longest] < sides[ni(i_longest, 1, sides_size)] + sides[ni(i_longest, 2, sides_size)]) {
            printf("The triangle does exist, because the longest side is shorter than two others.\n");
            printf("(%.2f + %.2f > %.2f)\n", sides[ni(i_longest, 1, sides_size)], sides[ni(i_longest, 2, sides_size)], sides[i_longest]);
        }
        else {
            printf("The triangle does not exist, because the longest side is longer or equal than two others.\n");
            printf("(%.2f + %.2f <= %.2f)\n", sides[ni(i_longest, 1, sides_size)], sides[ni(i_longest, 2, sides_size)], sides[i_longest]);
        }

        printf("\nWe have come to the end of this program.\n");
        printf("Do you wish to repeat this program?\n");

        do
        {
            // Menu
            printf("y or Y = yes\n");
            printf("n or N = no\n");
            choice = getchar();
            choice = MakeUpper(getchar());
            if (!IsChoiceCorrect(choice))
            {
                printf("Read The ... Manual.\n");
                printf("Their There For a Reason.\n\n");
            }
        } while (!IsChoiceCorrect(choice));

    } while (choice == 'Y');
}

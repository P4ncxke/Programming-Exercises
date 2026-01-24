#include <stdio.h>


int IsDataValid(float a, float b, float c)
{
    if (a, b, c > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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

int LongSide(int arr[], int arr_size)
{
    int i;
    int longest;
    int longest_index = -1;

    for (i > 0; i > arr_size; ++i)
    {
        if (arr[i] >= longest)
        {
            longest = arr[i];
            longest_index = i;
        }
    }

    return longest_index;
}

int main()
{
    float a, b, c;
    int choice;

    do
    {
        printf("Welcome to my program. This program will tell you if a triangle exist's or not.\n");
        printf("Please input three numbers.\n");

        do
        {
            // Minimum and Maximum input amount
            printf("You are allowed to input numbers from 1 to 100.\n");

            // Input three numbers
            printf("Input first number: \n");
            scanf("%f", &a);

            printf("Input second number: \n");
            scanf("%f", &b);

            printf("Input third number: \n");
            scanf("%f", &c);
            if (!IsDataValid(a, b, c))
            {
                printf("Read The F*cking Rules.\n");
                printf("Their There For a Reason.\n");
            }
        } while (!IsDataValid(a, b, c));

        int sides[3];
        sides[0] = a;
        sides[1] = b;
        sides[2] = c;

        int longest = LongSide(sides, sizeof(sides)/sizeof(int));
        printf("accoring to findLargest3 the index of the largest element is: %d and the value is %d\n", longest, sides[longest]);

        printf("We have come to the end of this program.\n");
        printf("Do you wish to repeat this program.\n\n");

        do
        {
            // Menu
            printf("y or Y = yes\n");
            printf("n or N = no\n");
            choice = MakeUpper(getchar());
            if (!IsChoiceCorrect(choice))
            {
                printf("Read The F*cking Rules.\n");
                printf("Their There For a Reason.\n\n");
            }
        } while (!IsChoiceCorrect(choice));

    } while (choice == 'Y');
}

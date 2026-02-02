#include <stdio.h>

#define DEBUG 1 // Comment whole line if debug is no needed any more

// Funtions
int Add(int a, int b)
{
    return a + b;
}

int Subtract(int a, int b)
{
    return a - b;
}

int Multiply(int a, int b)
{
    return a * b;
}

int Divide(int a, int b)
{
    return a / b;
}

char ToUpper(char c)
{
    if (c >= 97 && c <= 122)
    {
        return c -= 32; // the same as c = c - 32
    }
    else
    {
        return c;
    }
}

// Function to check if the input is valid.
// returns 1 if yes, or 0 if not valid
int isChoiceValid(char c)
{
    if (c == 'A' || c == 'S' || c == 'M' || c == 'D' || c == 'X')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// int Loop(char c)
// {
//     if (c == 'A' || c == 'S' || c == 'M' || c == 'D')
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

int main()
{

    int a, b;
    char choice;

    // Menu

    /* NON PROPER VERSION USING LABELS AND GOTO STATEMENT */
    // menu:
    // printf("\nChoose an operation:\n");
    // printf("u or U - Addition\n");
    // printf("i or I - Subtraction\n");
    // printf("o or O - Multiplication\n");
    // printf("p or P - Division\n");
    // printf("Enter your choice: \n");
    // //scanf(" %c", &choice);
    // choice = ToUpper(getchar());
    // if (!isChoiceValid(choice)) {
    //     printf("\nRTFM!\n\n");
    //     goto menu;
    // }

    do
    {
        do
        {
            printf("\nChoose an operation:\n");
            printf("a or A - Addition\n");
            printf("s or S - Subtraction\n");
            printf("m or M - Multiplication\n");
            printf("d or D - Division\n");
            printf("x or X - Exit\n");
            printf("Enter your choice: \n");
            #ifdef DEBUG
                fflush(stdout);
            #endif
            // scanf(" %c", &choice);
            choice = ToUpper(getchar());
            if (!isChoiceValid(choice))
            {
                printf("\nRTFM!\n\n");
            }
        } while (!isChoiceValid(choice));

        if (choice == 'A')
        {
            printf("Equation: a + b = c = (a + b)\n");
        }

        else if (choice == 'S')
        {
            printf("Equation: a - b = c = (a - b)\n");
        }

        else if (choice == 'M')
        {
            printf("Equation: a * b = c = (a * b)\n");
        }

        else if (choice == 'D')
        {
            printf("Equation: a / b = c = (a / b)\n");
        }

        else if (choice == 'X')
        {
            printf("goodbye");
            return 0;
        }

        else
        {
            printf("You somehow broke the code.\n");
        }

        // Input two numbers
        printf("Type you're first number: \n");
        scanf("%d", &a);

        printf("Type you're second number: \n");
        scanf("%d", &b);

        // Do said action
        if (choice == 'A')
        {
            printf("%d plus %d equals: %d\n", a, b, Add(a, b));
        }
        else if (choice == 'S')
        {
            printf("%d minus %d equals: %d\n", a, b, Subtract(a, b));
        }
        else if (choice == 'M')
        {
            printf("%d times %d equals: %d\n", a, b, Multiply(a, b));
        }
        else if (choice == 'D')
        {
            printf("%d divided by %d equals: %d", a, b, Divide(a, b));
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (1);

    return 0;   
}
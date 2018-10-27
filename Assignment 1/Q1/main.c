#include <stdio.h>

int UserInput ()
{
    int number = 0;

    printf("\nPlease enter a decimal number to proceed or (-1) to end: ");
    scanf("%d", &number);

    return number;
}

int Convert(int number)
{
    return number == 0 ? 0 : number % 2 + 10 * Convert(number / 2);
}

int TotalOnes (int number)
{
    for (int i = 0; i < 8; i++)
    {
        int bit;
        bit = number >> i & 1;
        int counter = 0;
        bit == 1 ? (counter++) : 0;
        return counter;
    }
}

int EvenChecker (int number)
{
    int x = ! (number % 2);
    return x;
}

int main ()
{
    int number;
    number = UserInput();

    while (number != -1)
    {
        int counter;
        int bin;
        bin = Convert(number);
        counter = TotalOnes(number);
        printf("The binary equivalent of %d is %d.\n", number, bin);
        printf("%s", EvenChecker (counter) ? "Even Parity\n" : "odd Parity\n");
        number = UserInput();
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 256
#define ENCRYPTION_KEY 56
#define DECRYPTION_KEY 56

int main()
{
    int i;
    int c;
    char str[MAX_LIMIT];
    char En;

    do
    {
        printf("\nPlease enter your message:");
        fgets(str, MAX_LIMIT, stdin);

        printf("\nPlease choose an option:\n");
        printf("1 = Encrypt the message.\n");
        printf("2 = Decrypt the message.\n");
        scanf(" %d", &c);

        if (c == 1)
        {
            for(i = 0; (i < MAX_LIMIT && str[i] != '\0'); i++)
            {
                str[i] = str[i] + ENCRYPTION_KEY;
            }
            printf("\nEncrypted string:%s\n", str);
        }

        else if(c == 2)
        {
            for(i = 0; (i < MAX_LIMIT && str[i] != '\0'); i++)
            {
                str[i] = str[i] - DECRYPTION_KEY;
            }
            printf("\nDecrypted string:%s\n", str);
        }

        else
        {
            printf("\nWrong choice\n");
        }

        printf("\nDo you want to repeat the operation [Y/N]:\n");
        scanf(" %c", &En);
    }

    while (En == 'y' || En == 'Y');

    return 0;
}
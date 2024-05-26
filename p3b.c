#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void encryptMessage(char *str, int rails);
void decryptMessage(char *str, int rails);
void encryptMessage(char *str, int rails)
{
    int i, j, len, count, code[100][1000];
    len = strlen(str);
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            code[i][j] = 0;
        }
    }
    count = 0;
    j = 0;
    while (j < len)
    {
        if (count % 2 == 0)
        {
            for (i = 0; i < rails; i++)
            {
                if (j < len)
                    code[i][j] = (int)str[j];
                j++;
            }
        }
        else
        {
            for (i = rails - 2; i > 0; i--)
            {
                if (j < len)
                    code[i][j] = (int)str[j];
                j++;
            }
        }
        count++;
    }
    printf("Rail Fence Pattern:\n");
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (code[i][j] != 0)
                printf("%c ", code[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("Encrypted Message: ");
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (code[i][j] != 0)
                printf("%c", (char)code[i][j]);
        }
    }
    printf("\n");
}
void decryptMessage(char *str, int rails)
{
    int i, j, len, count, k, code[100][1000];
    len = strlen(str);
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            code[i][j] = 0;
        }
    }
    count = 0;
    j = 0;
    while (j < len)
    {
        if (count % 2 == 0)
        {
            for (i = 0; i < rails; i++)
            {
                if (j < len)
                    code[i][j] = 1;
                j++;
            }
        }
        else
        {
            for (i = rails - 2; i > 0; i--)
            {
                if (j < len)
                    code[i][j] = 1;
                j++;
            }
        }
        count++;
    }
    k = 0;
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (code[i][j] == 1)
            {
                code[i][j] = (int)str[k];
                k++;
            }
        }
    }
    printf("Decrypted Message: ");
    count = 0;
    j = 0;
    while (j < len)
    {
        if (count % 2 == 0)
        {
            for (i = 0; i < rails; i++)
            {
                if (code[i][j] != 0)
                {
                    printf("%c", (char)code[i][j]);
                    j++;
                }
            }
        }
        else
        {
            for (i = rails - 2; i > 0; i--)
            {
                if (code[i][j] != 0)
                {
                    printf("%c", (char)code[i][j]);
                    j++;
                }
            }
        }
        count++;
    }
    printf("\n");
}
int main()
{
    char str[1000];
    int rails, choice;
    printf("Enter a Secret Message\n");
    gets(str);
    printf("Enter number of rails\n");
    scanf("%d", &rails);
    printf("Choose an option:\n");
    printf("1. Encrypt Message\n");
    printf("2. Decrypt Message\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        encryptMessage(str, rails);
        break;
    case 2:
        decryptMessage(str, rails);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    return 0;
}

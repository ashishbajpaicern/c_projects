#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string); // for checking digits
char rotate(char, int);   // for applying key

int main(int argc, string argv[])
{
    if (argc > 2 || argc < 2) // if more than one arg are typed
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (only_digits(argv[1]) == 0) // if other than digits are used
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int a, i = 0;
        char r;
        a = atoi(argv[1]);
        string text = get_string("plaintext: ");
        printf("ciphertext: ");
        while (text[i] != '\0')
        {
            r = rotate(text[i], a); // calling rotate function
            printf("%c", r);
            i++;
        }
    }
    printf("\n");
}

char rotate(char t, int k)
{
    int var;
    if (islower(t)) // if the alphabet is lowercase
    {
        var = (int)t + k;
        if (var > 96 && var < 123)
        {
            return (char)var;
        }
        else
        {
            var = ((((int)t - 97) + k) % 26) + 97; // if value is more than 122(z)
            return (char)var;
        }
    }
    else if (isupper(t)) // if the alphabet is uppercase
    {
        var = (int)t + k;
        if (var > 64 && var < 91)
        {
            return (char)var;
        }
        else
        {
            var = ((((int)t - 65) + k) % 26) + 65; // if value is more than 90(Z)
            ;
            return (char)var;
        }
    }
    else
    {
        return t;
    }
}

bool only_digits(string arg)
{
    int l = strlen(arg);
    for (int i = 0; i < l; i++) // checking for digits
    {
        if (isdigit(arg[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}
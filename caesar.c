# include<stdio.h>
# include<cs50.h>
# include<ctype.h>
# include<string.h>
# include<stdlib.h>

int encrypt(int key, string plaintext);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    else
    {
        // printf ("%s\n", argv[1]);
        int len = 0;
        len = strlen(argv[1]);
        for (int i = 0; i < len; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return (1);
            }
        }
        int key = atoi(argv[1]);  // turn string into number
        // printf("Success\n");
        // printf("%i\n", key);
        string plaintext = get_string("plaintext: ");
        encrypt(key, plaintext);
        printf("ciphertext: %s\n", plaintext);
    }
}
// Encrypt function definition
int encrypt(int key, string plaintext)
{
    int len_text = strlen(plaintext);
    for (int j = 0; j < len_text; j++)
    {
        if (isalpha(plaintext[j]))
        {
            if (islower(plaintext[j]))
            {
                plaintext[j] = (plaintext[j] - 97 + key) % 26 + 97;  // Wrap around from z to a
            }
            else
            {
                plaintext[j] = (plaintext[j] - 65 + key) % 26 + 65; // Wrap around from Z to A
            }
        }
    }
    return (0);
}
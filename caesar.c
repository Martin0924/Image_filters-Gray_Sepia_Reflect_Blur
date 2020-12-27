# include<stdio.h>
# include<cs50.h>
# include<ctype.h>
# include<string.h>
# include<stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        // printf ("%s\n", argv[1]);
        int len = 0;
        len = strlen(argv[1]);
        for (int i = 0; i < len; i++)
        {
            if (isdigit (argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return (1);
            }
        }
        int key = atoi(argv[1]);
        // printf("Success\n");
        // printf("%i\n", key);
    // Encrypt
        string plaintext = get_string("plaintext: ");
        int len_text = strlen(plaintext);
        for (int j = 0; j < len_text; j++)
        {
            if (isalpha(plaintext[j]))
            {
                char add_key = plaintext[j] + key;
                if (islower(plaintext[j]))
                {
                    if ((add_key) > 122)
                    {
                        plaintext[j] = add_key % 123 + 97;
                    }
                    else
                    {
                        plaintext[j] = add_key;
                    }

                }
                else
                {
                    if ((add_key) > 90)
                    {
                        plaintext[j] = add_key % 91 + 65;
                    }
                    else
                    {
                        plaintext[j] = add_key;
                    }
                }
            }
        }
        printf("ciphertext: %s\n", plaintext);
    }
}
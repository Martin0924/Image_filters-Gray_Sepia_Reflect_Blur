# include <stdio.h>
# include <cs50.h>
# include <ctype.h>
# include <string.h>
# include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    // printf("%i letter(s)\n", count_letters(text));
    // printf("%i word(s)\n", count_words(text));
    // printf("%i sentence(s)\n", count_sentences(text));
    float L, S;
    L = (float) count_letters(text) / (float) count_words(text) * 100;
    S = (float) count_sentences(text) / (float) count_words(text) * 100;
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8); // Coleman-Liau index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count += 1;
        }

    }
    return count;
}

int count_words(string text)
{
    int count_wrd = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            count_wrd += 1;
        }
    }
    return count_wrd + 1;
}

int count_sentences(string text)
{
    int count_stc = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_stc += 1;
        }
    }
    return count_stc;
}
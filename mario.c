# include <cs50.h>
# include <stdio.h>

int main(void)
{
    int height = 1; // set default height as 1
    do
    {
        height = get_int("What is the height?\n");
        // printf("Height: %i\n", height);
    }
    while (height < 1 || height > 8);

    // printf("Stored: %i\n", height);

    for (int i = 0; i < height; i++)   // For rows
    {
        int flag = height - i - 1;// set a flag to indicate when to print #

        for (int j = 0; j <= i; j++)
        {

            while (j < flag)
            {
                printf(" ");     // if the position is before flag, print .
                flag -= 1;      // update the position of flag when "."" is proceding
            }
            printf("#");      // if the position is at and after flag, print #
        }
        printf("")
         for (int k = 0; k <= i; k++)
        {
            printf("#");      // if the position is at and after flag, print #
        }
        printf("\n");
    }
}
# include <stdio.h>
# include <math.h>
# include <cs50.h>

int main(void)
{
    // Prompt for input:
    float owned = 0;
    do
    {
        owned = get_float("How much change owed?\n");
    }
    while (owned < 0);

    // Convert dollar to cents
    int cents = round(owned * 100);
    // printf("Cents owed: %i\n", cents);

    // Count the required minimum coins: 25, 10, 5, 1
    int qt = 0, dm = 0, nk = 0, pn = 0; // Initialization the count # for each coin
    while (cents != 0) // Greedy algorithm
    {
        qt = cents / 25;
        // printf("%i\n", qt);
        cents = cents % 25;
        dm = cents / 10;
        // printf("%i\n", dm);
        cents = cents % 10;
        nk = cents / 5;
        cents = cents % 5;
        // printf("%i\n", nk);
        pn = cents / 1;
        cents = cents % 1;
        // printf("%i\n",pn);
    }

    printf("%i\n", qt + dm + nk + pn);
}
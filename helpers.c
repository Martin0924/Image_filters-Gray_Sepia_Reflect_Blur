#include "helpers.h"
#include <math.h>

void swap(BYTE* x, BYTE * y);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
   int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round(((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed )) / 3.0 );
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaBlue = 0, sepiaGreen = 0, sepiaRed = 0;
    for (int i = 0; i < height; i++)
    {
         for (int j = 0; j < width; j++)
         {
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            // check if value exceeds 255 (maxium pixel value for 1 BYTE) or not
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
         }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int swapBlue = 0, swapGreen = 0, swapRed = 0;
 //   if (width % 2 == 0)
 //   {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width / 2; j++)
            {
                swap(&image[i][j].rgbtBlue, &image[i][width - 1 - j].rgbtBlue);
                swap(&image[i][j].rgbtGreen, &image[i][width - 1 - j].rgbtGreen);
                swap(&image[i][j].rgbtRed, &image[i][width - 1 - j].rgbtRed);
            }
        }

    return;
}

//swap function
void swap(BYTE* x, BYTE * y)
{
    BYTE sp = *x;
    *x = *y;
    *y = sp;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int Blue_avr = 0, Green_avr = 0, Red_avr = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Corner pixels
            if (i == 0 && j == 0)
            {
                Blue_avr =  round ((image[i][j].rgbtBlue +  image[i + 1][j].rgbtBlue +  image[i + 1][j + 1].rgbtBlue +  image[i][j + 1].rgbtBlue) / 4.0);
                Green_avr =  round ((image[i][j].rgbtGreen +  image[i + 1][j].rgbtGreen +  image[i + 1][j + 1].rgbtGreen +  image[i][j + 1].rgbtGreen) / 4.0);
                Red_avr =  round ((image[i][j].rgbtRed +  image[i + 1][j].rgbtRed +  image[i + 1][j + 1].rgbtRed +  image[i][j + 1].rgbtRed) / 4.0);
                image[i][j].rgbtBlue = Blue_avr;
                image[i][j].rgbtGreen = Green_avr;
                image[i][j].rgbtRed = Red_avr;
            }
            else if (i == 0 && j == (width - 1))
            {
                Blue_avr =  round ((image[i][j].rgbtBlue +  image[i + 1][j].rgbtBlue +  image[i + 1][j - 1].rgbtBlue +  image[i][j - 1].rgbtBlue) / 4.0);
                Green_avr =  round ((image[i][j].rgbtGreen +  image[i + 1][j].rgbtGreen +  image[i + 1][j - 1].rgbtGreen +  image[i][j - 1].rgbtGreen) / 4.0);
                Red_avr =  round ((image[i][j].rgbtRed +  image[i + 1][j].rgbtRed +  image[i + 1][j - 1].rgbtRed +  image[i][j - 1].rgbtRed) / 4.0);
                image[i][j].rgbtBlue = Blue_avr;
                image[i][j].rgbtGreen = Green_avr;
                image[i][j].rgbtRed = Red_avr;
            }
            else if (i == (height - 1) && j == 0)
            {
                Blue_avr =  round ((image[i][j].rgbtBlue +  image[i - 1][j].rgbtBlue +  image[i - 1][j + 1].rgbtBlue +  image[i][j + 1].rgbtBlue) / 4.0);
                Green_avr =  round ((image[i][j].rgbtGreen +  image[i - 1][j].rgbtGreen +  image[i - 1][j + 1].rgbtGreen +  image[i][j + 1].rgbtGreen) / 4.0);
                Red_avr =  round ((image[i][j].rgbtRed +  image[i - 1][j].rgbtRed +  image[i - 1][j + 1].rgbtRed +  image[i][j + 1].rgbtRed) / 4.0);
                image[i][j].rgbtBlue = Blue_avr;
                image[i][j].rgbtGreen = Green_avr;
                image[i][j].rgbtRed = Red_avr;
            }
            else if (i == (height - 1) && j == (width - 1))
            {
                Blue_avr =  round ((image[i][j].rgbtBlue +  image[i - 1][j].rgbtBlue +  image[i - 1][j - 1].rgbtBlue +  image[i][j - 1].rgbtBlue) / 4.0);
                Green_avr =  round ((image[i][j].rgbtGreen +  image[i - 1][j].rgbtGreen +  image[i - 1][j - 1].rgbtGreen +  image[i][j - 1].rgbtGreen) / 4.0);
                Red_avr =  round ((image[i][j].rgbtRed +  image[i - 1][j].rgbtRed +  image[i - 1][j - 1].rgbtRed +  image[i][j - 1].rgbtRed) / 4.0);
                image[i][j].rgbtBlue = Blue_avr;
                image[i][j].rgbtGreen = Green_avr;
                image[i][j].rgbtRed = Red_avr;
            }
            // Edge pixels
            else if (i == 0)
            {
                Blue_avr =  round ((image[i][j].rgbtBlue +  image[i][j - 1].rgbtBlue +  image[i + 1][j - 1].rgbtBlue +  image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue+ image[i][j + 1].rgbtBlue) / 6.0);
                Green_avr =  round ((image[i][j].rgbtGreen +  image[i][j - 1].rgbtGreen +  image[i + 1][j - 1].rgbtGreen +  image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen+ image[i][j + 1].rgbtGreen) / 6.0);
                Red_avr =  round ((image[i][j].rgbtRed +  image[i][j - 1].rgbtRed +  image[i + 1][j - 1].rgbtRed +  image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed+ image[i][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtBlue = Blue_avr;
                image[i][j].rgbtGreen = Green_avr;
                image[i][j].rgbtRed = Red_avr;
            }
            else if (i == (height - 1))
            {
                Blue_avr =  round ((image[i][j].rgbtBlue +  image[i][j - 1].rgbtBlue +  image[i - 1][j - 1].rgbtBlue +  image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue+ image[i][j + 1].rgbtBlue) / 6.0);
                Green_avr =  round ((image[i][j].rgbtGreen +  image[i][j - 1].rgbtGreen +  image[i - 1][j - 1].rgbtGreen +  image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen+ image[i][j + 1].rgbtGreen) / 6.0);
                Red_avr =  round ((image[i][j].rgbtRed +  image[i][j - 1].rgbtRed +  image[i - 1][j - 1].rgbtRed +  image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed+ image[i][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtBlue = Blue_avr;
                image[i][j].rgbtGreen = Green_avr;
                image[i][j].rgbtRed = Red_avr;
            }
            else if (j == 0)
            {
                Blue_avr =  round ((image[i][j].rgbtBlue +  image[i - 1][j].rgbtBlue +  image[i - 1][j + 1].rgbtBlue +  image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue+ image[i + 1][j].rgbtBlue) / 6.0);
                Green_avr =  round ((image[i][j].rgbtGreen +  image[i - 1][j].rgbtGreen +  image[i - 1][j + 1].rgbtGreen +  image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen+ image[i + 1][j].rgbtGreen) / 6.0);
                Red_avr =  round ((image[i][j].rgbtRed +  image[i - 1][j].rgbtRed +  image[i - 1][j + 1].rgbtRed +  image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed+ image[i + 1][j].rgbtRed) / 6.0);
                image[i][j].rgbtBlue = Blue_avr;
                image[i][j].rgbtGreen = Green_avr;
                image[i][j].rgbtRed = Red_avr;
            }
            else if (j == (width - 1))
            {
                Blue_avr =  round ((image[i][j].rgbtBlue +  image[i - 1][j].rgbtBlue +  image[i - 1][j - 1].rgbtBlue +  image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue+ image[i + 1][j].rgbtBlue) / 6.0);
                Green_avr =  round ((image[i][j].rgbtGreen +  image[i - 1][j].rgbtGreen +  image[i - 1][j - 1].rgbtGreen +  image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen+ image[i + 1][j].rgbtGreen) / 6.0);
                Red_avr =  round ((image[i][j].rgbtRed +  image[i - 1][j].rgbtRed +  image[i - 1][j - 1].rgbtRed +  image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed+ image[i + 1][j].rgbtRed) / 6.0);
                image[i][j].rgbtBlue = Blue_avr;
                image[i][j].rgbtGreen = Green_avr;
                image[i][j].rgbtRed = Red_avr;
            }
            // Middle pixels
            else
            {
                Blue_avr =  round ((image[i][j].rgbtBlue +  image[i - 1][j].rgbtBlue +  image[i - 1][j - 1].rgbtBlue +  image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue+ image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 9.0);
                Green_avr =  round ((image[i][j].rgbtGreen +  image[i - 1][j].rgbtGreen +  image[i - 1][j - 1].rgbtGreen +  image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen+ image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 9.0);
                Red_avr =  round ((image[i][j].rgbtRed +  image[i - 1][j].rgbtRed +  image[i - 1][j - 1].rgbtRed +  image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed+ image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed) / 9.0);
                image[i][j].rgbtBlue = Blue_avr;
                image[i][j].rgbtGreen = Green_avr;
                image[i][j].rgbtRed = Red_avr;
            }

        }


    }


     return;
}





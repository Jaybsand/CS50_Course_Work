#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int ave;
    for (int h = 0; h < height; h++) //iterating through height and width using for loop
    {
        for (int w = 0; w < width; w++)
        {
            // converting image to grayscale rounding the average of colors
            int red = image[h][w].rgbtRed;
            int green = image[h][w].rgbtGreen;
            int blue = image[h][w].rgbtBlue;
            ave = round(((float)red + (float)green + (float)blue) / 3);
            image[h][w].rgbtRed = ave;
            image[h][w].rgbtGreen = ave;
            image[h][w].rgbtBlue = ave;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepRed, sepBlue, sepGreen; // delcaring sepia variables
    for (int h = 0; h < height; h++) // iterating through height and width using for loop
    {
        for (int w = 0; w < width; w++)
        {
            // converting image to sepia
            sepRed = round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue);
            sepGreen = round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue);
            sepBlue = round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue);
            image[h][w].rgbtRed = sepRed > 255 ? 255 : sepRed;
            image[h][w].rgbtGreen = sepGreen > 255 ? 255 : sepGreen;
            image[h][w].rgbtBlue = sepBlue > 255 ? 255 : sepBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++) //creating loop for relect imaging
    {
        for (int w = 0; w < (width / 2); w++)
        {
            // creating reflect image
            int red = image[h][w].rgbtRed;
            int green = image[h][w].rgbtGreen;
            int blue = image[h][w].rgbtBlue;
            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;
            image[h][width - w - 1].rgbtRed = red;
            image[h][width - w - 1].rgbtGreen = green;
            image[h][width - w - 1].rgbtBlue = blue;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blur[height][width]; // Creating an image to apply the blurring effect to the original image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++) // iterating through height and width
        {
            int red, green, blue;
            red = green = blue = 0;
            float c = 0.00;
            for (int x = -1; x < 2; x++) //finding the neighbouring pixels using for loop
            {
                for (int y = -1; y < 2; y++)
                {
                    int nowX = h + x;
                    int nowY = w + y;
                    if (nowX < 0 || nowX > (height - 1) || nowY < 0 || nowY > (width - 1))
                    {
                        continue;
                    }
                    red += image[nowX][nowY].rgbtRed;
                    blue += image[nowX][nowY].rgbtBlue;
                    green += image[nowX][nowY].rgbtGreen;
                    c++;
                }
                blur[h][w].rgbtRed = round(red / c);
                blur[h][w].rgbtBlue = round(blue / c);
                blur[h][w].rgbtGreen = round(green / c);
            }
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++) //copying blurred image to the original image using loop
        {
            image[h][w].rgbtRed = blur[h][w].rgbtRed;
            image[h][w].rgbtBlue = blur[h][w].rgbtBlue;
            image[h][w].rgbtGreen = blur[h][w].rgbtGreen;
        }
    }
    return;
}

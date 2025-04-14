#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepBlue;
    int sepGreen;
    int sepRed;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen +
                           0.189 * image[i][j].rgbtBlue);
            sepGreen = round(.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen +
                             0.168 * image[i][j].rgbtBlue);
            sepBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen +
                            0.131 * image[i][j].rgbtBlue);

            if (sepBlue > 255)
                sepBlue = 255;
            if (sepGreen > 255)
                sepGreen = 255;
            if (sepRed > 255)
                sepRed = 255;

            image[i][j].rgbtBlue = sepBlue;
            image[i][j].rgbtGreen = sepGreen;
            image[i][j].rgbtRed = sepRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half = width / 2;
    int inhalf;
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        inhalf = width - 1;

        for (int j = 0; j < half; j++)
        {
            temp[i][j] = image[i][j];
            image[i][j] = image[i][inhalf];
            image[i][inhalf] = temp[i][j];

            inhalf -= 1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE im_copy[height + 2][width + 2];
    int r_sum = 0;
    int g_sum = 0;
    int b_sum = 0;

    float value[height + 2][width + 2];
    float count[height][width];

    RGBTRIPLE buffer;

    for (int i = 0; i <= height + 1; i++)
    {
        for (int j = 0; j <= width + 1; j++)
        {
            if (i == 0 || j == 0 || i > height || j > width)
            {
                im_copy[i][j].rgbtBlue = 0;
                im_copy[i][j].rgbtGreen = 0;
                im_copy[i][j].rgbtRed = 0;
                value[i][j] = 0.0;
            }
            else
            {
                im_copy[i][j] = image[i - 1][j - 1];
                value[i][j] = 1.0;
            }
        }
    }

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            count[i - 1][j - 1] = value[i - 1][j - 1] + value[i - 1][j] + value[i - 1][j + 1] +
                                  value[i][j - 1] + value[i][j] + value[i][j + 1] +
                                  value[i + 1][j - 1] + value[i + 1][j] + value[i + 1][j + 1];
        }
    }

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            r_sum = im_copy[i - 1][j - 1].rgbtRed + im_copy[i - 1][j].rgbtRed +
                    im_copy[i - 1][j + 1].rgbtRed + im_copy[i][j - 1].rgbtRed +
                    im_copy[i][j].rgbtRed + im_copy[i][j + 1].rgbtRed +
                    im_copy[i + 1][j - 1].rgbtRed + im_copy[i + 1][j].rgbtRed +
                    im_copy[i + 1][j + 1].rgbtRed;
            g_sum = im_copy[i - 1][j - 1].rgbtGreen + im_copy[i - 1][j].rgbtGreen +
                    im_copy[i - 1][j + 1].rgbtGreen + im_copy[i][j - 1].rgbtGreen +
                    im_copy[i][j].rgbtGreen + im_copy[i][j + 1].rgbtGreen +
                    im_copy[i + 1][j - 1].rgbtGreen + im_copy[i + 1][j].rgbtGreen +
                    im_copy[i + 1][j + 1].rgbtGreen;
            b_sum = im_copy[i - 1][j - 1].rgbtBlue + im_copy[i - 1][j].rgbtBlue +
                    im_copy[i - 1][j + 1].rgbtBlue + im_copy[i][j - 1].rgbtBlue +
                    im_copy[i][j].rgbtBlue + im_copy[i][j + 1].rgbtBlue +
                    im_copy[i + 1][j - 1].rgbtBlue + im_copy[i + 1][j].rgbtBlue +
                    im_copy[i + 1][j + 1].rgbtBlue;

            image[i - 1][j - 1].rgbtRed = round(r_sum / count[i - 1][j - 1]);
            image[i - 1][j - 1].rgbtGreen = round(g_sum / count[i - 1][j - 1]);
            image[i - 1][j - 1].rgbtBlue = round(b_sum / count[i - 1][j - 1]);
        }
    }

    return;
}

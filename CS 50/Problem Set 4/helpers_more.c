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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE im_copy[height + 2][width + 2];

    int Gx_rsum, Gy_rsum, Gx_gsum, Gy_gsum, Gx_bsum, Gy_bsum;

    int Gr, Gg, Gb;

    int R, G, B;

    float value[height + 2][width + 2];

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
            Gx_rsum = im_copy[i - 1][j + 1].rgbtRed - im_copy[i - 1][j - 1].rgbtRed +
                      2 * im_copy[i][j + 1].rgbtRed - 2 * im_copy[i][j - 1].rgbtRed +
                      im_copy[i + 1][j + 1].rgbtRed - im_copy[i + 1][j - 1].rgbtRed;
            Gy_rsum = im_copy[i + 1][j + 1].rgbtRed + 2 * im_copy[i + 1][j].rgbtRed +
                      im_copy[i + 1][j - 1].rgbtRed - im_copy[i - 1][j - 1].rgbtRed -
                      2 * im_copy[i - 1][j].rgbtRed - im_copy[i - 1][j + 1].rgbtRed;

            Gx_gsum = im_copy[i - 1][j + 1].rgbtGreen - im_copy[i - 1][j - 1].rgbtGreen +
                      2 * im_copy[i][j + 1].rgbtGreen - 2 * im_copy[i][j - 1].rgbtGreen +
                      im_copy[i + 1][j + 1].rgbtGreen - im_copy[i + 1][j - 1].rgbtGreen;
            Gy_gsum = im_copy[i + 1][j + 1].rgbtGreen + 2 * im_copy[i + 1][j].rgbtGreen +
                      im_copy[i + 1][j - 1].rgbtGreen - im_copy[i - 1][j - 1].rgbtGreen -
                      2 * im_copy[i - 1][j].rgbtGreen - im_copy[i - 1][j + 1].rgbtGreen;

            Gx_bsum = im_copy[i - 1][j + 1].rgbtBlue - im_copy[i - 1][j - 1].rgbtBlue +
                      2 * im_copy[i][j + 1].rgbtBlue - 2 * im_copy[i][j - 1].rgbtBlue +
                      im_copy[i + 1][j + 1].rgbtBlue - im_copy[i + 1][j - 1].rgbtBlue;
            Gy_bsum = im_copy[i + 1][j + 1].rgbtBlue + 2 * im_copy[i + 1][j].rgbtBlue +
                      im_copy[i + 1][j - 1].rgbtBlue - im_copy[i - 1][j - 1].rgbtBlue -
                      2 * im_copy[i - 1][j].rgbtBlue - im_copy[i - 1][j + 1].rgbtBlue;

            Gr = (int) (pow(Gx_rsum, 2) + pow(Gy_rsum, 2));
            Gg = (int) (pow(Gx_gsum, 2) + pow(Gy_gsum, 2));
            Gb = (int) (pow(Gx_bsum, 2) + pow(Gy_bsum, 2));

            R = (int) round(sqrt(Gr));
            G = (int) round(sqrt(Gg));
            B = (int) round(sqrt(Gb));

            if (R > 255)
                image[i - 1][j - 1].rgbtRed = 255;
            else
                image[i - 1][j - 1].rgbtRed = R;

            if (G > 255)
                image[i - 1][j - 1].rgbtGreen = 255;
            else
                image[i - 1][j - 1].rgbtGreen = G;

            if (B > 255)
                image[i - 1][j - 1].rgbtBlue = 255;
            else
                image[i - 1][j - 1].rgbtBlue = B;
        }
    }

    return;
}

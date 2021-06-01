#include "helpers.h" 
#include <math.h>
#include <cs50.h>

void move_pixel(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2);
RGBTRIPLE blur_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width]);


// Convert image to grayscale* 
void grayscale(int height, int width, RGBTRIPLE image[height][width]) 
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((float) (pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue)/3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            int specia_R = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int specia_G = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int specia_B = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            image[i][j].rgbtRed = specia_R >= 255 ? 255 : specia_R;
            image[i][j].rgbtGreen = specia_G >= 255 ? 255 : specia_G;
            image[i][j].rgbtBlue = specia_B >= 255 ? 255 : specia_B;
        }
    }
    return;
}



// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            move_pixel (&image[i][j], &image[i][width - 1 - j]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // making a new image to calculate the blur pixels
    RGBTRIPLE blur_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blur_image[i][j] = blur_pixel(i, j, height, width, image);
        }
    }

    // copying the blur pixels received back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blur_image[i][j];
        }
    }
    return;
}






//Self defined functions

//for the reflect part
void move_pixel (RGBTRIPLE *pixel1 , RGBTRIPLE *pixel2)
{
    RGBTRIPLE move = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = move;
}


//for the blur part
RGBTRIPLE blur_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int pixel_iterations = 0;
    int total_red = 0, total_green = 0, total_blue = 0;
    for (int change_in_i = -1; change_in_i < 2; change_in_i++)
    {
        for (int change_in_j = -1; change_in_j < 2; change_in_j++)
        {
            int moved_i = i + change_in_i;
            int moved_j = j + change_in_j;
            if (moved_i >= 0 && moved_i < height && moved_j >= 0 && moved_j < width)
            {
                pixel_iterations++;
                // getting total red, green, blue
                total_red += image[moved_i][moved_j].rgbtRed;
                total_green += image[moved_i][moved_j].rgbtGreen;
                total_blue += image[moved_i][moved_j].rgbtBlue;
            }
        }
    }
    RGBTRIPLE return_pixel_blur;
    return_pixel_blur.rgbtRed = round((float)total_red / pixel_iterations);
    return_pixel_blur.rgbtGreen = round((float)total_green / pixel_iterations);
    return_pixel_blur.rgbtBlue = round((float)total_blue / pixel_iterations);
    return return_pixel_blur;
}

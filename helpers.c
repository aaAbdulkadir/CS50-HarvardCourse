#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each pixel i.e. rows and columns of the image and average the colour to gray. All rgb must be equal.
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width ; column++)
        {   
            float gray_average = (image[row][column].rgbtRed + image[row][column].rgbtGreen + image[row][column].rgbtBlue)/3.000;
            int average = round(gray_average);

            // make calculated average the new value for each pixel
            image[row][column].rgbtRed = average;
            image[row][column].rgbtGreen = average;
            image[row][column].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //do the same but rather than using the average, apply formulas
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width ; column++)
        {   
            int sepiaRed = round(.393 * image[row][column].rgbtRed + .769 * image[row][column].rgbtGreen + .189 * image[row][column].rgbtBlue);
            int sepiaGreen = round(.349 * image[row][column].rgbtRed + .686 * image[row][column].rgbtGreen + .168 * image[row][column].rgbtBlue);
            int sepiaBlue = round(.272 * image[row][column].rgbtRed + .534 * image[row][column].rgbtGreen + .131 * image[row][column].rgbtBlue);

            //stop value from going over 255. If so, each pixel will be set to 255.
            if (sepiaRed > 255)
            {
                image[row][column].rgbtRed = 255;
            }
            else
            {
                image[row][column].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[row][column].rgbtGreen = 255;
            }
            else
            {
                image[row][column].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[row][column].rgbtBlue = 255;
            }
            else
            {
                image[row][column].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{   
    // the rows stay in the same order but the columns switch places to get a mirror image
    for (int row = 0; row < height; row++)
    {   
        // iterate until you get to middle to not cancel it out
        for (int column = 0; column < width/2 ; column++)
        { 
            // swap occurs in each column pixel

            // Hold the first position color in place holder 
            int switchColumnHolderRed = image[row][column].rgbtRed;
            // make first position = last position 
            // Add the -1
            image[row][column].rgbtRed = image[row][width-column-1].rgbtRed;
            // make last position = first position
            image[row][width-column-1].rgbtRed = switchColumnHolderRed;

            int switchColumnHolderGreen = image[row][column].rgbtGreen;
            image[row][column].rgbtGreen = image[row][width-column-1].rgbtGreen;
            image[row][width-column-1].rgbtGreen = switchColumnHolderGreen;

            int switchColumnHolderBlue = image[row][column].rgbtBlue;
            image[row][column].rgbtBlue = image[row][width-column-1].rgbtBlue;
            image[row][width-column-1].rgbtBlue = switchColumnHolderBlue;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE copyImage[height][width];
	float averageRed;
	float averageGreen;
	float averageBlue;

	//create a copy of original image to save original pixel values
	for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
			copyImage[row][column].rgbtRed = image[row][column].rgbtRed;
			copyImage[row][column].rgbtGreen = image[row][column].rgbtGreen;
			copyImage[row][column].rgbtBlue = image[row][column].rgbtBlue;
		}
	}

	for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
			// top left corner
			if (column == 0 && row == 0)
			{
				averageRed = (float)(copyImage[row][column].rgbtRed + copyImage[row][column+1].rgbtRed + copyImage[row+1][column].rgbtRed + copyImage[row+1][column+1].rgbtRed) / 4;

				averageGreen = (float)(copyImage[row][column].rgbtGreen + copyImage[row][column+1].rgbtGreen + copyImage[row+1][column].rgbtGreen + copyImage[row+1][column+1].rgbtGreen) / 4;

				averageBlue = (float)(copyImage[row][column].rgbtBlue + copyImage[row][column+1].rgbtBlue + copyImage[row+1][column].rgbtBlue + copyImage[row+1][column+1].rgbtBlue) / 4;
				averageRed = round(averageRed);
				averageBlue = round(averageBlue);
				averageGreen = round(averageGreen);

				image[row][column].rgbtRed = averageRed;
				image[row][column].rgbtGreen = averageGreen;
				image[row][column].rgbtBlue = averageBlue;
			}

			// bottom left corrner
			else if (column == 0 && row == (height - 1))
			{
				averageRed =(float)(copyImage[row-1][column].rgbtRed + copyImage[row-1][column+1].rgbtRed + copyImage[row][column].rgbtRed + copyImage[row][column+1].rgbtRed) / 4;

				averageGreen = (float)(copyImage[row-1][column].rgbtGreen + copyImage[row-1][column+1].rgbtGreen + copyImage[row][column].rgbtGreen + copyImage[row][column+1].rgbtGreen) / 4;

				averageBlue = (float)(copyImage[row-1][column].rgbtBlue + copyImage[row-1][column+1].rgbtBlue + copyImage[row][column].rgbtBlue + copyImage[row][column+1].rgbtBlue) / 4;
				averageRed = round(averageRed);
				averageGreen = round(averageGreen);
				averageBlue = round(averageBlue);

				image[row][column].rgbtRed = averageRed;
				image[row][column].rgbtGreen = averageGreen;
                                image[row][column].rgbtBlue = averageBlue;
			}

			// top right corner
			else if (row == 0 && column == (width - 1))
			{
				averageRed = (float)(copyImage[row][column-1].rgbtRed + copyImage[row][column].rgbtRed + copyImage[row+1][column-1].rgbtRed + copyImage[row+1][column].rgbtRed)/ 4;

				averageGreen = (float)(copyImage[row][column-1].rgbtGreen + copyImage[row][column].rgbtGreen + copyImage[row+1][column-1].rgbtGreen + copyImage[row+1][column].rgbtGreen) / 4;

				averageBlue = (float)(copyImage[row][column-1].rgbtBlue + copyImage[row][column].rgbtBlue + copyImage[row+1][column-1].rgbtBlue + copyImage[row+1][column].rgbtBlue) / 4;

				averageRed = round(averageRed);
				averageGreen = round(averageGreen);
				averageBlue = round(averageBlue);

				image[row][column].rgbtRed = averageRed;
				image[row][column].rgbtGreen = averageGreen;
                image[row][column].rgbtBlue = averageBlue;
			}

			// bottom right corner
			else if(row == (height - 1) && column == (width - 1))
			{
				averageRed = (float)(copyImage[row-1][column-1].rgbtRed + copyImage[row-1][column].rgbtRed + copyImage[row][column-1].rgbtRed + copyImage[row][column].rgbtRed) / 4;

		 		averageBlue = (float)(copyImage[row-1][column-1].rgbtBlue + copyImage[row-1][column].rgbtBlue + copyImage[row][column-1].rgbtBlue + copyImage[row][column].rgbtBlue) / 4;

				averageGreen = (float)(copyImage[row-1][column-1].rgbtGreen + copyImage[row-1][column].rgbtGreen + copyImage[row][column-1].rgbtGreen + copyImage[row][column].rgbtGreen) / 4;

				averageRed = round(averageRed);
				averageGreen = round(averageGreen);
				averageBlue = round(averageBlue);

				image[row][column].rgbtRed = averageRed;
				image[row][column].rgbtGreen = averageGreen;
                image[row][column].rgbtBlue = averageBlue;
			}
       // left edge

			else if (column == 0 && (row > 0 && row < height - 1))
			{
				averageRed = (float)(copyImage[row-1][column].rgbtRed + copyImage[row-1][column+1].rgbtRed + copyImage[row][column].rgbtRed + copyImage[row][column+1].rgbtRed + copyImage[row+1][column].rgbtRed + copyImage[row+1][column+1].rgbtRed) / 6;

				averageGreen = (float)(copyImage[row-1][column].rgbtGreen + copyImage[row-1][column+1].rgbtGreen + copyImage[row][column].rgbtGreen + copyImage[row][column+1].rgbtGreen + copyImage[row+1][column].rgbtGreen + copyImage[row+1][column+1].rgbtGreen) / 6;

				averageBlue = (float)(copyImage[row-1][column].rgbtBlue + copyImage[row-1][column+1].rgbtBlue + copyImage[row][column].rgbtBlue + copyImage[row][column+1].rgbtBlue + copyImage[row+1][column].rgbtBlue + copyImage[row+1][column+1].rgbtBlue) / 6;

				averageRed = round(averageRed);
				averageGreen = round(averageGreen);
				averageBlue = round(averageBlue);

				image[row][column].rgbtRed = averageRed;
				image[row][column].rgbtGreen = averageGreen;
				image[row][column].rgbtBlue = averageBlue;
			}
      // right edge
			else if (column == (width - 1) && (row > 0 && row < height - 1))
			{
				averageRed = (float)(copyImage[row-1][column-1].rgbtRed + copyImage[row-1][column].rgbtRed + copyImage[row][column-1].rgbtRed + copyImage[row][column].rgbtRed + copyImage[row+1][column-1].rgbtRed + copyImage[row+1][column].rgbtRed) / 6;

				averageGreen = (float)(copyImage[row-1][column-1].rgbtGreen + copyImage[row-1][column].rgbtGreen + copyImage[row][column-1].rgbtGreen + copyImage[row][column].rgbtGreen + copyImage[row+1][column-1].rgbtGreen + copyImage[row+1][column].rgbtGreen) / 6;

				averageBlue = (float)(copyImage[row-1][column-1].rgbtBlue + copyImage[row-1][column].rgbtBlue + copyImage[row][column-1].rgbtBlue + copyImage[row][column].rgbtBlue + copyImage[row+1][column-1].rgbtBlue + copyImage[row+1][column].rgbtBlue) / 6;

				averageRed = round(averageRed);
				averageGreen = round(averageGreen);
				averageBlue = round(averageBlue);

				image[row][column].rgbtRed = averageRed;
                                image[row][column].rgbtGreen = averageGreen;
				image[row][column].rgbtBlue = averageBlue;
			}
       // upper edge
			else if (row == 0 && (column > 0 &&  column < width - 1))
			{
				averageRed = (float)(copyImage[row][column-1].rgbtRed + copyImage[row][column].rgbtRed + copyImage[row][column+1].rgbtRed + copyImage[row+1][column-1].rgbtRed + copyImage[row+1][column].rgbtRed + copyImage[row+1][column+1].rgbtRed) / 6;

				averageGreen = (float)(copyImage[row][column-1].rgbtGreen + copyImage[row][column].rgbtGreen + copyImage[row][column+1].rgbtGreen + copyImage[row+1][column-1].rgbtGreen + copyImage[row+1][column].rgbtGreen + copyImage[row+1][column+1].rgbtGreen) / 6;

				averageBlue = (float)(copyImage[row][column-1].rgbtBlue + copyImage[row][column].rgbtBlue + copyImage[row][column+1].rgbtBlue + copyImage[row+1][column-1].rgbtBlue + copyImage[row+1][column].rgbtBlue + copyImage[row+1][column+1].rgbtBlue) / 6;

				averageRed = round(averageRed);
				averageGreen = round(averageGreen);
				averageBlue = round(averageBlue);

				image[row][column].rgbtRed = averageRed;
				image[row][column].rgbtGreen = averageGreen;
				image[row][column].rgbtBlue = averageBlue;
			}
       // lower edge
			else if  (row == height - 1 && (column > 0 && column < width - 1))
			{
				averageRed = (float)(copyImage[row-1][column-1].rgbtRed + copyImage[row-1][column].rgbtRed + copyImage[row-1][column+1].rgbtRed + copyImage[row][column-1].rgbtRed + copyImage[row][column].rgbtRed + copyImage[row][column+1].rgbtRed) / 6;

				averageGreen = (float)(copyImage[row-1][column-1].rgbtGreen + copyImage[row-1][column].rgbtGreen + copyImage[row-1][column+1].rgbtGreen + copyImage[row][column-1].rgbtGreen + copyImage[row][column].rgbtGreen + copyImage[row][column+1].rgbtGreen) / 6;
				averageBlue = (float)(copyImage[row-1][column-1].rgbtBlue + copyImage[row-1][column].rgbtBlue + copyImage[row-1][column+1].rgbtBlue + copyImage[row][column-1].rgbtBlue + copyImage[row][column].rgbtBlue + copyImage[row][column+1].rgbtBlue) / 6;

				averageRed = round(averageRed);
				averageGreen = round(averageGreen);
				averageBlue = round(averageBlue);

				image[row][column].rgbtRed = averageRed;
				image[row][column].rgbtGreen = averageGreen;
				image[row][column].rgbtBlue = averageBlue;
			}
      // inside pixels
			else
			{
				averageRed = (float)(copyImage[row-1][column-1].rgbtRed + copyImage[row-1][column].rgbtRed + copyImage[row-1][column+1].rgbtRed + copyImage[row][column-1].rgbtRed + copyImage[row][column].rgbtRed + copyImage[row][column+1].rgbtRed + copyImage[row+1][column-1].rgbtRed + copyImage[row+1][column].rgbtRed + copyImage[row+1][column+1].rgbtRed) / 9;
				averageGreen = (float)(copyImage[row-1][column-1].rgbtGreen + copyImage[row-1][column].rgbtGreen + copyImage[row-1][column+1].rgbtGreen + copyImage[row][column-1].rgbtGreen + copyImage[row][column].rgbtGreen + copyImage[row][column+1].rgbtGreen + copyImage[row+1][column-1].rgbtGreen + copyImage[row+1][column].rgbtGreen + copyImage[row+1][column+1].rgbtGreen) / 9;

				averageBlue = (float)(copyImage[row-1][column-1].rgbtBlue + copyImage[row-1][column].rgbtBlue + copyImage[row-1][column+1].rgbtBlue + copyImage[row][column-1].rgbtBlue + copyImage[row][column].rgbtBlue + copyImage[row][column+1].rgbtBlue + copyImage[row+1][column-1].rgbtBlue + copyImage[row+1][column].rgbtBlue + copyImage[row+1][column+1].rgbtBlue) / 9;

				averageRed = round(averageRed);
				averageGreen = round(averageGreen);
				averageBlue = round(averageBlue);

				image[row][column].rgbtRed = averageRed;
				image[row][column].rgbtGreen = averageGreen;
				image[row][column].rgbtBlue = averageBlue;
			}

		}
	}
    return;
}

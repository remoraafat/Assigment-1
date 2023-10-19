/* Name                                     Id                      Email
 *
 * Hussam Eldin Hesham Ahmed                20220109                hussamhesham46@gmail.com
 *
 * Remon Raafat Nassif                      20220139                remoraafat2004@gmail.com
 *
 *Abdelmonaem Mahmoud Abdelmonaem           20220206                abdoadwy208@gmail.com
 *
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char mergedImage[SIZE][SIZE];
unsigned char outputImage[SIZE][SIZE];

void loadImage ();
void loadImage2();
void saveImage ();
void saveImage2 ();
void menu ();
void BW ();
void Invert ();
void Merge ();
void Flip ();
void Rotate ();
void DAL ();
void DIE ();
void Enlarge ();
void Shrink ();
void Mirror_Half();
void Shuffle ();
void Blur ();
void Crop ();
void SkewImageRight();
void SkewImageUp();

int main()
{
    menu();
    return 0;
}

void menu () {


    char The_chosen_char ;


    cout <<"Please select a filter to apply or 0 to exit:\n\n" // To choose the Filters
           "1 - Black & White Filter\n"
           "2 - Invert Filter\n"
           "3 - Merge Filter \n"
           "4 - Flip Image\n"
           "5 - Rotate Image \n"
           "6 - Darken and Lighten Image \n"
           "7 - Detect Image Edges\n"
           "8 - Enlarge Image\n"
           "9 - Shrink Image\n"
           "a - Mirror 1/2 image\n"
           "b - Shuffle Image\n"
           "c - Blur Image\n"
           "d - Crop Image\n"
           "e - Skew Image Right\n"
           "f - Skew Image Up\n"
           "s - Save the image to a file\n"
           "0 - Exit \n\n"
           "Your Choose : ";

    cin >> The_chosen_char ; // to save the selected number

    if (The_chosen_char == '1')
    {

        BW();

    }
    else if (The_chosen_char == '2')
    {

        Invert();

    }
    else if (The_chosen_char == '3')
    {

        Merge();

    }
    else if (The_chosen_char == '4')
    {

        Flip();

    }
    else if (The_chosen_char == '5')
    {

        Rotate();

    }
    else if (The_chosen_char == '6')
    {

        DAL();

    }
    else if (The_chosen_char == '7')
    {

        DIE ();

    }
    else if (The_chosen_char == '8')
    {

        Enlarge ();

    }
    else if (The_chosen_char == '9')
    {

        Shrink();

    }
    else if (The_chosen_char == 'a' || The_chosen_char == 'A')
    {

        Mirror_Half();

    }
    else if (The_chosen_char == 'b' || The_chosen_char == 'B')
    {

        Shuffle ();

    }
    else if (The_chosen_char == 'c' || The_chosen_char == 'C')
    {

        Blur ();

    }
    else if (The_chosen_char == 'd' || The_chosen_char == 'D')
    {

        Crop();

    }
    else if (The_chosen_char == 'e' || The_chosen_char == 'E')
    {

        SkewImageRight();

    }
    else if (The_chosen_char == 'f' || The_chosen_char == 'F')
    {

        SkewImageUp();

    }
    else if (The_chosen_char == 's' || The_chosen_char == 'S')
    {

        loadImage();
        saveImage();

    }
    else if (The_chosen_char == '0') // If you choose to exit
    {

    }
    else // If a number is chosen that is not in the options
    {

        cout << "\nPlease Choose Number Form the List . \n\n";
        menu();

    }


}

void loadImage ()
{
    char imageFileName[100];

    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void loadImage2 ()
{
    char imageFileName2[100];

    cout << "Enter the second source image file name: ";
    cin >> imageFileName2;

    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);

}

void saveImage ()
{
    char imageFileName[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void saveImage2 ()
{

    char imageFileName2[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName2;

    strcat (imageFileName2, ".bmp");
    writeGSBMP(imageFileName2, mergedImage);
}

void saveImage3 ()
{

    char imageFileName3[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName3;

    strcat (imageFileName3, ".bmp");
    writeGSBMP(imageFileName3, outputImage);

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {

            outputImage[i][j] = 0;

        }

    }
}

void BW () {

    loadImage();

    for (int i = 0; i < SIZE; i++)// for loop to iterate  all rows in image
    {
        for (int j = 0; j< SIZE; j++)// for loop to iterate all the columns in the image
        {
            // If the pixel bigger than 130 make it equal 255
            if (image[i][j] > 130)
            {
                image[i][j] = 255;
            }
            else // If not, make it equal 0
            {
                image[i][j] = 0;
            }
        }
    }

    saveImage();
    menu();

}

void Invert () {

    loadImage();

    for (int i = 0; i < SIZE; i++)// for loop to iterate  all rows in image
    {
        for (int j = 0; j< SIZE; j++)// for loop to iterate all the columns in the image
        {
            // Subtract the pixel value from 255 to invert the colors
            image[i][j] = 255 - image[i][j];

        }
    }

    saveImage();
    menu();

}

void Merge () {

    // To save the first image
    loadImage ();
    // To save the second image
    loadImage2 ();

    for (int i = 0; i < SIZE; i++)// for loop to iterate  all rows in image
    {
        for (int j = 0; j < SIZE; j++)// for loop to iterate all the columns in the image
        {
            // Add the pixel value in the first and second images, then divide the number by 2 to merge the images
            int pixelValue = (image[i][j] + image2[i][j]) / 2;
            mergedImage[i][j] = pixelValue ;

        }
    }
    // To save the maged image not one of the original image
    saveImage2();
    menu();

}

void Flip() {

    loadImage();

    cout << "\n1 - Flip Horizontal \n"
            "2 - Flip Vertical\n"
            "0 - Back To Menu\n\n"
            "Your Choose : "; //to choose from Horizontal and Vertical

    int The_chosen_number;


    cin >> The_chosen_number;


    if (The_chosen_number == 1) // in case Horizontal
    {
        for (int i = 0; i < SIZE; i++) // for loop to iterate  all rows in image
        {
            for (int j = 0; j < SIZE / 2; j++) // for loop to iterate half of the columns in the image
            {
                unsigned char temp = image[i][j]; // creat unsigned char to store the pixel of the upper part to put it in the lower pixel

                image[i][j] = image[i][SIZE - 1 - j]; // put the lower pixel in the upper pixel

                image[i][SIZE - 1 - j] = temp; // put the upper pixel to the lower pixel

            }
        }

        saveImage();

    } else if (The_chosen_number == 2) {
        for (int i = 0; i < SIZE / 2; i++)// for loop to iterate  half of the rows in image
        {
            for (int j = 0; j < SIZE; j++)// for loop to iterate all the columns in the image
            {
                unsigned char temp = image[i][j];// creat unsigned char to store the pixel of the left part to put it in the right pixel

                image[i][j] = image[SIZE - 1 - i][j];// put the right pixel in the left pixel

                image[SIZE - 1 - i][j] = temp;// put the left pixel to the right pixel

            }
        }

        saveImage(); // to save image

    }
    else if (The_chosen_number == 0)//return to menu
    {

        menu();

    }
    else // If a number is chosen that is not in the options
    {

        cout << "\nPlease Choose Number Form the List . \n\n";
        Flip();

    }
}

void Rotate() {

    loadImage();

    int The_chosen_number ;

    cout<<"\n 1 - Rotate 90 degrees \n"
          " 2 - Rotate 180 degrees \n"
          " 3 - Rotate 270 degrees \n"
          " 0 - Back to menu\n\n"
          "Your Choose : ";


    cin >> The_chosen_number ;


    if( The_chosen_number == 1 )
    {

        unsigned char tempImage[SIZE][SIZE];

        memcpy(tempImage, image, SIZE * SIZE * sizeof(unsigned char));

        for (int i = 0; i < SIZE; i++)// for loop to iterate  all rows in image
        {
            for (int j = 0; j < SIZE; j++)// for loop to iterate all the columns in the image
            {

                image[j][SIZE - 1 - i] = tempImage[i][j];

            }
        }

        saveImage();
        menu();

    }
    else if( The_chosen_number == 2 )
    {

        unsigned char tempImage2[SIZE][SIZE];

        memcpy(tempImage2, image, SIZE * SIZE * sizeof(unsigned char));

        for (int i = 0; i < SIZE; i++)// for loop to iterate  all rows in image
        {
            for (int j = 0; j < SIZE; j++)// for loop to iterate all the columns in the image
            {

                image[SIZE - 1 - i][SIZE - 1 - j] = tempImage2[i][j];

            }
        }

        saveImage();
        menu();

    }
    else if( The_chosen_number == 3 )
    {

        unsigned char tempImage3[SIZE][SIZE];

        memcpy(tempImage3, image, SIZE * SIZE * sizeof(unsigned char));

        for (int i = 0; i < SIZE; i++)// for loop to iterate  all rows in image
        {
            for (int j = 0; j < SIZE; j++)// for loop to iterate all the columns in the image
            {

                image[SIZE - 1 - j][i] = tempImage3[i][j];

            }
        }

        saveImage();
        menu();

    }
    else if ( The_chosen_number == 0 ) //Return to Menu
    {

        menu();

    }
    else // If a number is chosen that is not in the options
    {

        cout << "\nPlease Choose Number Form the List . \n\n";
        Rotate();

    }

}

void DAL () {

    loadImage();

    int The_chosen_number;


    cout << "Choose an operation:\n"
            "1 - Darken\n"
            "2 - Lighten\n"
            "0 - Back Menu\n\n"
            "Your Choose :";


    cin >> The_chosen_number;

    if (The_chosen_number == 1 )
    {
        for (int i = 0; i < SIZE; i++)// for loop to iterate  all rows in image
        {
            for (int j = 0; j < SIZE; j++)// for loop to iterate all the columns in the image
            {

                // subtract the pixel from 100 to darken the image, provided that it is not less than zero. If it becomes less than zero, I change the pixel value to zero.
                image[i][j] = max(image[i][j] - 100, 0);

            }
        }

        saveImage();
        menu();

    }
    else if (The_chosen_number == 2 )
    {
        for (int i = 0; i < SIZE; i++)// for loop to iterate  all rows in image
        {
            for (int j = 0; j < SIZE; j++)// for loop to iterate all the columns in the image
            {

                // add 100 to the pixel to increase the light of the image, provided that it does not exceed 255. If it exceeds 255, I change the pixel value to 255.
                image[i][j] = min(image[i][j] + 100, 255);

            }
        }

        saveImage();
        menu();

    }
    else if (The_chosen_number == 0 ) //Return to Menu
    {

        menu();

    }
    else // If a number is chosen that is not in the options
    {

        cout << "\nPlease Choose Number Form the List . \n\n";
        DAL();

    }

}

void DIE () {

    loadImage();

    int sobelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int sobelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    unsigned char tempImage[SIZE][SIZE];
    memcpy(tempImage, image, SIZE * SIZE);

    for (int i = 1; i < SIZE - 1; ++i) {
        for (int j = 1; j < SIZE - 1; ++j) {
            int gradientX = 0, gradientY = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    gradientX += tempImage[i + x][j + y] * sobelX[1 + x][1 + y];
                    gradientY += tempImage[i + x][j + y] * sobelY[1 + x][1 + y];
                }
            }
            int gradientMagnitude = sqrt(gradientX * gradientX + gradientY * gradientY);

            // Threshold the gradient magnitude to create a binary edge image
            image[i][j] = (gradientMagnitude > 128) ? 0 : 255; // Edges are black (0), background is white (255)



        }
    }
    saveImage();
    menu();
}

void Enlarge (){
    loadImage();
    unsigned char enlargedImage[SIZE][SIZE];
    memcpy(enlargedImage, image, SIZE * SIZE * sizeof(unsigned char));


    int quarterSize = SIZE / 2;
    int quarterRow, quarterCol;

    cout << "Enter the quarter to enlarge\n "
            " 1: Top-Left\n"
            " 2: Top-Right\n"
            " 3: Bottom-Left\n"
            " 4: Bottom-Right\n "
            " choose : ";
    int choice;
    cin >> choice;

    if(choice == 1)
    {
        quarterRow = 0;
        quarterCol = 0;
        for (int i = quarterRow; i < quarterRow + quarterSize; i++)
        {
            for (int j = quarterCol; j < quarterCol + quarterSize; j++)
            {
                enlargedImage[2 * i][2 * j] = image[i][j];
                enlargedImage[2 * i][2 * j + 1] = image[i][j];
                enlargedImage[2 * i + 1][2 * j] = image[i][j];
                enlargedImage[2 * i + 1][2 * j + 1] = image[i][j];
            }
        }


        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = enlargedImage[ i][ j];
            }
        }
    }
    else if(choice == 2)
    {
        quarterRow = 0;
        quarterCol = quarterSize;
        for (int i = quarterRow; i < quarterRow + quarterSize; i++)
        {
            int k=0;
            for (int j = quarterCol; j < quarterCol + quarterSize; j++)
            {
                enlargedImage[2 * i][2 * k] = image[i][j];
                enlargedImage[2 * i][2 * k + 1] = image[i][j];
                enlargedImage[2 * i + 1][2 * k] = image[i][j];
                enlargedImage[2 * i + 1][2 * k + 1] = image[i][j];
                if(k<quarterSize) k++;

            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = enlargedImage[ i][ j];
            }
        }
    }
    else if(choice == 3)
    {
        quarterRow = quarterSize;
        quarterCol = 0;
        int k=0;
        for (int i = quarterRow; i < quarterRow + quarterSize; i++)
        {
            for (int j = quarterCol; j < quarterCol + quarterSize; j++)
            {
                enlargedImage[2 * k][2 * j] = image[i][j];
                enlargedImage[2 * k][2 * j + 1] = image[i][j];
                enlargedImage[2 * k + 1][2 * j] = image[i][j];
                enlargedImage[2 * k + 1][2 * j + 1] = image[i][j];

            }
            if(k<quarterSize) k++;
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = enlargedImage[ i][ j];
            }
        }
    }
    else if(choice == 4)
    {
        quarterRow = quarterSize;
        quarterCol = quarterSize;
        int k=0 ;
        for (int i = quarterRow; i < quarterRow + quarterSize; i++)
        {
            int q=0;
            for (int j = quarterCol; j < quarterCol + quarterSize; j++)
            {
                enlargedImage[2 * k][2 * q] = image[i][j];
                enlargedImage[2 * k][2 * q + 1] = image[i][j];
                enlargedImage[2 * k + 1][2 * q] = image[i][j];
                enlargedImage[2 * k + 1][2 * q + 1] = image[i][j];
                if(q<quarterSize) q++;

            }
            if(k<quarterSize) k++;
        }


        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = enlargedImage[ i][ j];
            }
        }
    }
    else
    {
        cout << "Invalid choice" << endl;
        quarterRow = 0;
        quarterCol = 0;
        menu();
    }

    saveImage();
    menu();
}

void Shrink () {

    loadImage();

    int The_Chosen_Number;


    cout << "\nPlease choose the reduction ratio for the image.\n\n"
            " 1 - shrink the image dimensions to 1/2\n"
            " 2 - shrink the image dimensions to 1/3\n"
            " 3 - shrink the image dimensions to 1/4\n"
            " 0 - Back to Menu\n\n"
            " Your Choose : ";

    cin >> The_Chosen_Number;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {

            outputImage[i][j] = 255;

        }

    }

    if (The_Chosen_Number == 1)
    {

        int reduction_ratio = 2;
        int newWidth = SIZE / reduction_ratio;
        int newHeight = SIZE / reduction_ratio;

        for (int i = 0; i < newHeight; i++)
        {
            for (int j = 0; j < newWidth; j++)
            {

                int sum = 0;

                for (int x = 0; x < reduction_ratio; x++)
                {
                    for (int y = 0; y < reduction_ratio; y++)
                    {

                        sum += image[i * reduction_ratio + x][j * reduction_ratio + y];

                    }
                }

                outputImage[i][j] = sum / (reduction_ratio * reduction_ratio);

            }
        }

        saveImage3();
        menu();
    }
    else if (The_Chosen_Number == 2)
    {

        int reduction_ratio = 3;
        int newWidth = SIZE / reduction_ratio;
        int newHeight = SIZE / reduction_ratio;

        for (int i = 0; i < newHeight; i++)
        {
            for (int j = 0; j < newWidth; j++)
            {

                int sum = 0;

                for (int x = 0; x < reduction_ratio; x++)
                {
                    for (int y = 0; y < reduction_ratio; y++)
                    {

                        sum += image[i * reduction_ratio + x][j * reduction_ratio + y];

                    }
                }

                outputImage[i][j] = sum / (reduction_ratio * reduction_ratio);

            }
        }

        saveImage3();
        menu();
    }
    else if (The_Chosen_Number == 3)
    {

        int reduction_ratio = 4;
        int newWidth = SIZE / reduction_ratio;
        int newHeight = SIZE / reduction_ratio;

        for (int i = 0; i < newHeight; i++)
        {
            for (int j = 0; j < newWidth; j++)
            {

                int sum = 0;

                for (int x = 0; x < reduction_ratio; x++)
                {
                    for (int y = 0; y < reduction_ratio; y++)
                    {

                        sum += image[i * reduction_ratio + x][j * reduction_ratio + y];

                    }
                }

                outputImage[i][j] = sum / (reduction_ratio * reduction_ratio);

            }
        }

        saveImage3();
        menu();
    }
    else if (The_Chosen_Number == 0)
    {

        menu();

    }
    else // If a number is chosen that is not in the options
    {

        cout << "\nPlease Choose Number Form the List . \n\n";
        Shrink();

    }

}

void Mirror_Half(){

    loadImage();

    char choice;
    cout << "Choose an operation:\n"
         << "1 - Mirror Image Left\n"
         << "2 - Mirror Image Right\n"
         << "3 - Mirror Image Upper\n"
         << "4 - Mirror Image Lower\n";
    cin>>choice;

    if (choice=='1'){
        for (int i = 0; i < SIZE; i++) {
            int x=1;
            for (int j = SIZE/2; j< SIZE; j++) {
                image[i][j]=image[i][j-x];
                x=x+2;
            }
        }
    }
    else if (choice=='2'){
        for (int i = 0; i < SIZE; ++i) {
            int x=255;
            for (int j = 0; j < SIZE/2; ++j) {
                image[i][j]=image[i][x];
                x--;
            }
        }
    }
    else if (choice=='3'){
        for (int i = 0; i < SIZE; i++) {
            int x=1;
            for (int j = SIZE/2; j< SIZE; j++) {
                image[j][i]=image[j-x][i];
                x=x+2;
            }
        }
    }
    else{
        for (int i = 0; i < SIZE; ++i) {
            int x=255;
            for (int j = 0; j < SIZE/2; ++j) {
                image[j][i]=image[x][i];
                x--;
            }
        }
    }

    saveImage();
    menu();

}

void Shuffle (){
    loadImage();
    unsigned char temp[SIZE][SIZE];
    memcpy(temp, image, SIZE * SIZE);

    int order[4];

    cout << "Enter the order of quarters (1, 2, 3, 4):\n";
    for (int i = 0; i < 4; ++i) {
        cin >> order[i];
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int quarter;
            if (i < SIZE / 2) {
                if (j < SIZE / 2) {
                    quarter = order[0];
                } else {
                    quarter = order[1];
                }
            } else {
                if (j < SIZE / 2) {
                    quarter = order[2];
                } else {
                    quarter = order[3];
                }
            }

            int rowOffset = (i % (SIZE / 2)) + ((quarter - 1) / 2) * (SIZE / 2);
            int colOffset = (j % (SIZE / 2)) + ((quarter - 1) % 2) * (SIZE / 2);

            image[i][j] = temp[rowOffset][colOffset];
        }
    }
    saveImage();
}

void Blur (){
    loadImage();

    unsigned char imageBLUR[SIZE][SIZE];

    for (int i = 1; i < SIZE ; i++)
    {
        for (int j = 1; j < SIZE ; j++)
        {
            int sum = 0;

            for (int m = -1; m <= 1; m++)
            {
                for (int n = -1; n <= 1; n++)
                {
                    sum += image[i + m][j + n];
                }
            }

            imageBLUR[i][j] = sum / 15;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = imageBLUR[i][j];
        }
    }

    saveImage();
    menu();

}

void Crop (){

    loadImage();
    int x,y,l,w;
    cout<<"Enter position x , position y , length and Width:"<<endl;
    cin>>x>>y>>l>>w;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image2[i][j]=255;
        }
    }
    for (int i = x; i < l; ++i) {
        for (int j = y; j < w; ++j) {
            image2[i][j]=image[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=image2[i][j];
        }
    }

    saveImage();
    menu();

}

void SkewImageRight()
{
    loadImage();

    double rad;
    cout << "Enter degree: ";
    cin >> rad;
    rad = (rad * 22) / (180 * 7);
    double mov = tan(rad) * 256;
    double step = mov / SIZE;
    unsigned char img_in[SIZE][SIZE + (int)mov];
    int x=(tan(rad)*256)/(tan(rad)+1);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            img_in[i][j] = 255;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE ; j++) {

            img_in[i][((((j+ (int)mov) * x ))/(int)(SIZE*(tan(rad))))] = image[i][j];
        }
        mov -= step;
    }

    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {

            image[i][j]=img_in[i][j];

        }
    }

    saveImage();
    menu();
}

void SkewImageUp()
{

    loadImage();

    double rad;
    cout << "Enter degree: ";
    cin >> rad;
    rad = (rad * 22) / (180 * 7);
    double mov = tan(rad) * 256;
    double step = mov / SIZE;
    unsigned char img_in[SIZE+ (int)mov][SIZE];
    int x=(tan(rad)*256)/(tan(rad)+1);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            img_in[i][j] = 255;

    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE ; i++) {
            img_in[(((i+(int)mov)*x))/(int)(SIZE*(tan(rad)))][j] = image[i][j];
        }
        mov -= step;
    }

    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {

            image[i][j]=img_in[i][j];

        }
    }

    saveImage();
    menu();
}



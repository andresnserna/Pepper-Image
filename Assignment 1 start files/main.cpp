#include <iostream>
#include <fstream>
using namespace std;

/************************************************************************************************************
 * read an image from a given file, the file contains data in the following format:
 *              string_representing_an_identifier
 *              int_for_image_width int_for_image_height
 *              int_for_max_pixel_value
 *              2D_array_representing_pixel_values
 *
 * parameters: 
 *              filename: a string representing the name of the file containing the image
 *              image: a 2D array that holds the pixel values
 *              col: an integer that represents the width of an image (no. of pixels per row)
 *              row: an integer that represents the height of an image (no. of pixels per col)
 *              maxVal: an integer that represents the maximum pixel value
 *              p_val: a string that represents the image identifier
 *
 * return: no return values
 ************************************************************************************************************/
void readImage(char filename[], int image[700][700], int &col, int &row, int &maxVal, char p_val[]){
    
    ifstream myImage;
    myImage.open(filename);
    if ( !myImage.is_open() ) {
        cout << "The file could not be opened." << endl;
    }
    
    myImage >> p_val;
    myImage >> col;
    myImage >> row;
    myImage >> maxVal;
    
//    cout << "p_val is " << p_val << endl;
//    cout << "col is: " << col << endl;
//    cout << "row is: " << row << endl;
//    cout << "maxVal is: " << maxVal << endl;
    
    myImage.close();
}

/***************************************************************************************************************
 * saves an image to a given file, the file should contain data in the following format:
 *              string_representing_an_identifier
 *              int_for_image_width int_for_image_height
 *              int_for_max_pixel_value
 *              2D_array_representing_pixel_values
 *
 * parameters:
 *              filename: a string representing the name of the file into which the image should be saved
 *              pepper: a 2D array that holds the pixel values of the processed image
 *              col: an integer that represents the width of an image (no. of pixels per row)
 *              row: an integer that represents the height of an image (no. of pixels per col)
 *              maxVal: an integer that represents the maximum pixel value
 *              p_val: a string that represents the image identifier
 *
 * return: no return values
 ************************************************************************************************************/
void saveImage(char filename[], int pepper[700][700], int col, int row, int maxVal, char p_val[]){
    
    ofstream myImage;
    myImage.open (filename);
    
//    cout << "p_val is " << p_val << endl;
//    cout << "col is: " << col << endl;
//    cout << "row is: " << row << endl;
//    cout << "maxVal is: " << maxVal << endl;
    
    myImage << p_val << endl;
    myImage << col << " " << row << endl;
    myImage << maxVal << endl;
    
     for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
            myImage << pepper[i][j] << " ";
        }
        myImage << "\n";
    }
    myImage.close();

}

void sumArray(int image[700][700], int sum[][700], int row, int col){

}


void averageArray(int sum[700][700], double avg[][700], int col, int row){

}

void pepperImage(int image[700][700], double avg[][700], int col, int row){
    
}

int main () {
    
    // TODO: Read the image
    
    // TODO: Find the sum of pixels
    
    // TODO: Find the average of pixels
    
    // TODO: Pepper the image
    
    // TODO: Save the reulting image to peppered_image.pgm
    
    return 0;
}


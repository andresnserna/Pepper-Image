//
//  main.cpp
//  HW1_1436_testing
//
//  Created by Andrés Serna on 1/31/24.
//

#include <iostream>
#include <fstream>
using namespace std;

/******************************************************************************************
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
 *****************************************************************************************/

void readImage(char filename[], int image[590][590], int &col, int &row, int &maxVal, char p_val[]) {
    //STEP 1: open the sample image
    ifstream myImage;

    myImage.open(filename);
    
    if (!myImage.is_open()) {
      cout << "The file could not be opened." << endl;
    } else {
        cout << "Successfully opened file" <<endl;
    }
    
    // STEP 2: read the values from it
    myImage.getline(p_val, 5900);  // Read the entire line into p_val
    myImage >> col;
    myImage >> row;
    myImage >> maxVal;
//    // CHECK that the values were read
//    cout << "p_val is " << p_val << endl;
//    cout << "col is: " << col << endl;
//    cout << "row is: " << row << endl;
//    cout << "maxVal is: " << maxVal << endl;
//    // CHECK the array, display it
//    cout << endl;
    
//    cout <<"this is our original array" <<endl;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        myImage >> image[i][j];
//        cout<< image[i][j] << "  ";
      }
      //myImage << "\n";
//      cout << endl;
    }
//    cout << endl;
    
    myImage.close();
}

void sumArray(int image[590][590], int sum[590][590], int row, int col, int tempImage[590][590]) {
    // STEP 1: Copy the original image to the tempImage array
    // i passed the variable tempImage into this function because Xcode wouldn't run this function correctly if i declared it as a local variable.
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        tempImage[i][j] = image[i][j];
      }
    }
    // STEP 2: Perform the sum operation

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
          sum[i][j] = 0;
        if (i - 1 >= 0 && j - 1 >= 0) {
          sum[i][j] += tempImage[i - 1][j - 1];
        } else {
          sum[i][j] += tempImage[i][j];
        }
      //
        if (i - 1 >= 0) {
          sum[i][j] += tempImage[i - 1][j];
        } else {
          sum[i][j] += tempImage[i][j];
        }
      //
        if (i - 1 >= 0 && j + 1 < col) {
          sum[i][j] += tempImage[i - 1][j + 1];
        } else {
          sum[i][j] += tempImage[i][j];
        }
      //
        if (j - 1 >= 0) {
          sum[i][j] += tempImage[i][j - 1];
        } else {
          sum[i][j] += tempImage[i][j];
        }
      //
        if (j + 1 < col) {
          sum[i][j] += tempImage[i][j + 1];
        } else {
          sum[i][j] += tempImage[i][j];
        }
      //
        if (i + 1 < row && j - 1 >= 0) {
          sum[i][j] += tempImage[i + 1][j - 1];
        } else {
          sum[i][j] += tempImage[i][j];
        }
      //
        if (i + 1 < row) {
          sum[i][j] += tempImage[i + 1][j];
        } else {
          sum[i][j] += tempImage[i][j];
        }
      //
        if (i + 1 < row && j + 1 < col) {
          sum[i][j] += tempImage[i + 1][j + 1];
        } else {
          sum[i][j] += tempImage[i][j];
        }
      //
      }
    }
  
      //display our new sum[][]
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
//          cout << sum[i][j] << "  ";
        }
//        cout << endl;
      }
  }

void averageArray(int sum[590][590], double avg[590][590], int col, int row) {
    
    // STEP 1: Calculate the average values
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
      // Divide each element by 8 and store it in the "avg" array
      avg[i][j] = static_cast<double>(sum[i][j]) / 8;
    }
  }
    
    
}

void pepperImage(int image[590][590], double avg[590][590], int pepper[590][590], int col, int row) {
    
    // STEP 1: Copy the original image to the pepper array
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        pepper[i][j] = image[i][j];
      }
    }
    // STEP 2: Pepper the image based on the average values
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      // Compare "avg" element with corresponding "image" element
      if (avg[i][j] < static_cast<double>(image[i][j])) {
        // If "avg" is greater, set "pepper" to black (0)
        pepper[i][j] = 0;
      }
    }
  }
    
}

void saveImage(char filename[], int pepper[590][590], int col, int row, int maxVal, char p_val[]) {
  // STEP 1: Open the file for writing
  ofstream myImage;
  myImage.open(filename);

  // STEP 2: Write the header information to the file
  myImage << p_val << endl;
  myImage << col << " " << row << endl;
  myImage << maxVal << endl;

  // STEP 3: Write the pixel values to the file
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      myImage << pepper[i][j] << "  ";
    }
    myImage << "\n";
  }
//
//  cout << endl;
//  cout << "p_val is " << p_val << endl;
//  cout << "col is: " << col << endl;
//  cout << "row is: " << row << endl;
//  cout << "maxVal is: " << maxVal << endl;

  // Close the file
  myImage.close();
}

int main() {
    int col, row, maxVal;
    int image[590][590], sum[590][590], tempImage[590][590], pepper[590][590];
    double avg[590][590];
    char p_val[100], filename[100] = "";
    
    // STEP 1: Open the sample image
    //ask user for file name

    while (true) {
        cout << "Enter the absolute file path for the image you want to pepper: ";
        cin.getline(filename, sizeof(filename)); // reads whole line (handles spaces)

        // Remove surrounding quotes if user dragged a quoted path (e.g. "/Users/..../file name.pgm")
        size_t len = strlen(filename);
        if (len >= 2 && ((filename[0] == '"' && filename[len-1] == '"') ||
                         (filename[0] == '\'' && filename[len-1] == '\''))) {
            // shift left by 1 and terminate
            for (size_t i = 0; i < len - 2; ++i) filename[i] = filename[i + 1];
            filename[len - 2] = '\0';
        }

        ifstream test(filename);
        if (test.is_open()) {
            test.close();
            break; // success — exit loop
        } else {
            cerr << "Could not open file: " << filename << "\nPlease try again.\n";
        }
    }
        
    // STEP 2: read the values from it
    
    // CHECK: list the values
    
    // CHECK: display the array
    
    readImage(filename, image, col, row, maxVal, p_val);
    
    // STEP 3: perform the sum array function
    
//    cout <<"this is our sum array" <<endl;
    sumArray(image, sum, row, col, tempImage);
//    cout <<endl;
//    
//    // spits out the sum array along with the ID values
//    
//    // STEP 4: take the sum[][] and average it out and store those values into avg[][]
//    
//    cout <<"this is our avg array" <<endl;
    averageArray(sum, avg, col, row);
//    cout <<endl;
//
//    // STEP 5: pepper the image
//    cout <<"this is our pepper array" <<endl;
    pepperImage(image, avg, pepper, col, row);
//    cout <<endl;

    // STEP 6: save the image
    
    //update the filename so that way it's saved under it
    char outFilename[200];  // bigger buffer

    // Find last '.' in filename
    char *dot = strrchr(filename, '.');
    if (dot) {
        // Copy everything up to the dot
        size_t baseLen = dot - filename;
        strncpy(outFilename, filename, baseLen);
        outFilename[baseLen] = '\0';

        strcat(outFilename, "_peppered");
        strcat(outFilename, dot); // add the extension back
    } else {
        // No extension
        strcpy(outFilename, filename);
        strcat(outFilename, "_peppered");
    }

    // Now save to new path
    saveImage(outFilename, pepper, col, row, maxVal, p_val);


}



//
//  main.cpp
//  HW1_1436_testing
//
//  Created by Andrés Serna on 1/31/24.
//

#include <iostream>
using namespace std;
int largestNumber(int, int, int);
void displayLargest(int&);

int main (){
    int num1 = 3, num2 = 6, num3 = 10;
    
    int lrgst = largestNumber(num1, num2, num3);
    
    displayLargest(lrgst);
    
    return 0;
}

int largestNumber(int num1, int num2, int num3) {
    int largest = num1;
    
    if (num2 > largest) {
        largest = num2;
    }
    
    if (num3 > largest) {
        largest = num3;
    }
    
    return largest;
}

void displayLargest(int &lrgst){
    //it will not return anything to main() function, but when it's called it will display the largest of the three integers we defined.
    cout <<endl <<lrgst;
}

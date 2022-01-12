#include <iostream>
#include <ctime>

// Find the sum of all elements in an array.
int sumArray(int arg[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arg[i];
    }
    return sum;
}

// Finds the sums of two arrays and compares them.
int CompareSum(int arg1[], int arg2[], int size1, int size2){
    int sum1 = sumArray(arg1, size1);
    int sum2 = sumArray(arg2, size2);
    if (sum1 > sum2){
        return -1;
    }
    else if (sum2 > sum1){
        return 1;
    }
    else return 0;
}

/* Fills an array with random numbers 1-100.
I got the code for this function from http://www.cplusplus.com/forum/beginner/5527/
because I wasn't sure how random functions work in C++. */
void genArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        arr[i] = (rand()%100) + 1;
    }
}

// Prints all elements of an array.
void printArray(int arg[], int size){
    for (int i = 0; i < size; i++){
        std::cout << arg[i] << ' ';
    }
    std::cout << '\n';
}

// Generates a pair of arrays, compares their sums, and prints the results.
void arrPair(){
    
    // Picks a random number 1-10 for the size of each array.
    int size1 = (rand()%10) + 1;
    int size2 = (rand()%10) + 1;
    
    // Initializes 2 arrays, then fills them with random numbers.
    int arr1[size1];
    int arr2[size2];
    genArray(arr1, size1);
    genArray(arr2, size2);
    
    // Compares the sums of the arrays and stores the result.
    int compSum = CompareSum(arr1, arr2, size1, size2);
    
    // Prints the contents of both arrays and the result of the comparison.
    std::cout << "Array 1: ";
    printArray(arr1, size1);
    std::cout << "Array 2: ";
    printArray(arr2, size2);
    if (compSum == -1){
        std::cout << "The sum of Array 1 is greater.";
    }
    else if (compSum == 1){
        std::cout << "The sum of Array 2 is greater.";
    }
    else std::cout << "The sums are equal.";
    std::cout << '\n';
}

int main(){
    /* I was getting the same "randomly" generated numbers each time, so I went to
    https://stackoverflow.com/questions/7748071/same-random-numbers-every-time-i-run-the-program
    and found out that c++ uses pseudorandom number generation, and that I needed to use srand(time(NULL))
    to get different numbers each time i run the program. */
    srand(time(NULL));
    
    // Generates two pairs of arrays.
    arrPair();
    arrPair();
}
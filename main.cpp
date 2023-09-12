#include <iostream>
#include <string>
#include <fstream>
#include "Functions.h"

using namespace std;

int main() {
  //open file
  ifstream inFile;
  inFile.open("numbers.txt");
  if (!inFile.is_open()){
    cout << "File did not open\n";
    exit(0);
  }
  
  //create array, read in file values
  int arr[100], size = 100, smallArr[99], largeArr[101], choice;
  fillArray(inFile, arr, size);
  inFile.close();

  //Menu for what to do to the array
  cout << "\nMenu:\n\t1) Check if integer exists\n\t2) Change value in the array\n\t3) Add integer to end of array\n\t4) Set value to 0, or delete value if 0\n\nWhat number would you like to do?: ";
  cin >> choice;
  //Calls the function that the user chose to perform
  if (choice == 1){
    findInt(arr, size);
  }
  else if (choice == 2){
    changeVal(arr, size);
  }
  if (choice == 3){
    addVal(arr, size, largeArr);
  }
  if (choice == 4){
    removeVal(arr, size, smallArr);
  }
}
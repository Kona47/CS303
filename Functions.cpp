#include "Functions.h"

//Create the array from the values in the file
void fillArray(ifstream &inFile, int arr[100], int size) {
  for (int r = 0; r < size; r++) {
      inFile >> arr[r];
  }
}

/* A function to check if a certain integer exists in the array and prints out all the indexes the number is present. */
void findInt(int arr[100], int size){
  int intToFind;
  cout << "\nWhat integer would you like to look for: ";
  cin >> intToFind;
  int total = 0;
  for(int i = 0; i < size; i++){
    if (arr[i] == intToFind){
      total++;
      cout << "The value is at index " << i << endl;
    }
  }
  if (total == 0)
    cout << "Value not found in the array.";
}
/*changes the value in an array by taking in the new value and the index*/
void changeVal(int arr[100], int size){
  int oldInt, newInt, index;
  try{
    cout << "\nEnter an index value (0-99): ";
    cin >> index;
    cout << "\nEnter a number value to put there: ";
    cin >> newInt;
    if(index < 0)
      throw("");
    oldInt = arr[index];
  }
  //Catches errors if the user entered an index above 100 or below 0, and ensures they are integer values. 
  catch(runtime_error){
    cout << "\nInvalid, enter an index lower than 100: ";
    changeVal(arr, size);;
  }
  catch(...){
    cout << "\nEnter a valid number: ";
    changeVal(arr, size);
  }
  arr[index] = newInt;
  cout << "Old value at index " << index << ": " << oldInt;
  cout << "\nNew value: " << arr[index];
}
/*Adds a value to the back of the array*/
void addVal(int arr[100], int size, int newArr[size+1]){
  //copies a new array that is one larger
  for(int i = 0; i < size; i++){
    newArr[i] = arr[i];
  }
  //tries and catches if the value is an integer, if not, calls function again
  try{
    int newValue;
    cout << "\nEnter value to add: ";
    cin >> newValue;
    newArr[size] = newValue;
  }
  catch(...){
    cout << "Enter a valid number: ";
    addVal(arr, size, newArr);
  }
    
}
/*this function takes an array, the size, and another array if needed. 
It takes in the index to be changed, and then checks to see if the value at that index is 0 or another value */
void removeVal(int arr[100], int size, int newArr[size-1]){
  int index;
  cout << "\nEnter an index to change: ";
  cin >> index;
  //if value at the index is not 0, set the value to 0
  //else we delete the value by copying every value of the array   //except the one chosen by the user into the new array. 
  if (arr[index] != 0)
    arr[index] = 0;
  else{
    for(int i = 0; i < size; i++){
      if (i != index)
        newArr[i] = arr[i];
    }
  }
}



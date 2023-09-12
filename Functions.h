#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void fillArray(ifstream &inFile, int arr[100], int size);

void findInt(int arr[100], int size);

void changeVal(int arr[100], int size);

void addVal(int arr[100], int size, int newArr[size+1]);

void removeVal(int arr[100], int size, int newArr[size-1]);
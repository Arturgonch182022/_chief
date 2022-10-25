#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
int ConcoleReaderInteger(string msg);
bool IsNonDecreasingOrder(int k);
void FindIterms(vector<int>& vec, int a, int b);

void FileWriter(string filePart, vector<int> vect, int n);
void SortCollection(vector<int> & vec, vector <int> & vect);
string ConsoleReadingString(string msg);
bool IsNondecresingOrder(string str);
vector<string> FileReader(string input_file);
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iomanip>
#include "function.h"
using namespace std;
int ConcoleReaderInteger(string msg) {
	cout << msg << endl;
	int k;
	cin >> k;
	return k;
}
//----------------------------------------------------------------------
bool IsNonDecreasingOrder(int k) {
	k = abs(k);
	int temp = k % 10;
	bool f = true;
	k /= 10;
	while (k && f)
	{
		if (k % 10 > temp)
		{
			f = false;
		}

		temp = k % 10;
		k /= 10;
	}

	if (f)
		return true;
	else
		return false;
}

//---------------------------------------------------------------------------
void FindIterms(vector<int>& vec, int a=0, int b=0) {
	cout << "Enter the beginning of the gap" << endl;
	cin >> a;
	cout << "Enter the end of the gap " << endl;
	cin >> b;
	for ( int j = a; j < b; j++) {
		if (IsNonDecreasingOrder(j)) vec.push_back(j);
	}
}
//------------------------------------------------------------------------
void FileWriter(string filePart,vector<int> vect,int n) {
/*	int n;
	cout << "Enter the number of numbers in the line" << endl;
	cin >> n;
	ofstream output_file("C:\\Users\\Маша\\source\\repos\\Project1\\kr1_gr1b_v1\\output.txt");
	
	FindIterms(vect, -k, k);
	int c = 0; // counter
	for (int j = 0; j <= vect.size(); j++) {
		if (c == n) {
			output_file << endl;
			c = 0;
		}
		c++;
		output_file << vect[j] << "  ";
	}*/

	ofstream fout(filePart);
	for(int i=0;i < vect.size();i++){
	 for(int j=0;j < n;j++){
		
			fout << setw(6) << vect[i] << " ";
			
		}
		fout << endl;
	}
}







	
//-----------------------------------------------------------------------------


void  SortCollection(vector<int> & vec, vector <int> & vect) {
	int n;
	cout << "Please, enter number of digits of the number to sort" << endl;
	cin >> n;
	for (int j = 0; j < n; j++) {
		vect.push_back(vec[j]);
	}
	sort(vect.begin(), vect.end(), [](int a, int b) { return b >= a; });

}
//------------------------------------------------------------------------------
template <typename T>
void  SortCollection(vector<T> & vec, vector <T> & vect) {
	int n;
	cout << "Please, enter number of digits of the number to sort" << endl;
	cin >> n;
	for (int j = 0; j < n; j++) {
		vect.push_back(vec[j]);
	}
	sort(vect.begin(), vect.end(), [](int a, int b) { return b >= a; });

}



//---------------------------------------------------------------------
string ConsoleReadingString(string msg) {
	cout << "Please, enter string" << endl;
	cin >> msg;
	return msg;
}

//--------------------------------------------------------
/*bool IsNondecresingOrder(string str) {
	string str1 = " ";
	for (int j = 0; j < str.size(); j++) {
		str.substr(str.begin() + j, str.begin() + j + 1);
	}
}
*/
bool IsNotIncreasingOrder(string str) {
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] >= str[i + 1]) return false; //compare elements in adjacent positions
	}
	return true;
}


vector<string> FileReader(string input_file) {
	string tmp;
	vector<string> result;
	ifstream fin(input_file);
	while (getline(fin, tmp)) {
		result.push_back(tmp);
	}
	return result;
}






int main() {
	
	vector<int> vec;
	int a;
	int b;
	int k = ConcoleReaderInteger("Please, enter the number(k) ");
	if (IsNonDecreasingOrder(k)) {
    cout << "All numbers are in non-decreasing order" << endl;
	}
	else {
		cout << " Not all numbers are in non-decreasing order" << endl;
	}
	FindIterms(vec);
	for (int j = 0; j < vec.size(); j++) {
		cout << vec[j] << "  ";
	}
	//--------------------------------------------------------------------------
	vector <int> vect;
	int n= ConcoleReaderInteger("Please, enter n" );
	FileWriter("sort_output.txt",vect,n);
	SortCollection(vec,vect);

	string msg;
	string str = ConsoleReadingString( msg);
	system("pause");
	return 0;
}


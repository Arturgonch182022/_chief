#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

template <typename T >
void FileWriter(vector <T> res) {
	ofstream fout("TextFile2.txt");
	for (const auto& i : res) {
		fout << i << " ";
	}
}
int main() {
	// THE FOLDER data SHOULD BE EXIST IN THE FOLDER OF THE PROJECT
	const string filepath = "TextFile1";
	vector <string> res;
	res = FileReader(filepath);

	for (const auto& i : res) {
		cout << i << " ";
	}

	FileWriter(res);
	return 0;
}
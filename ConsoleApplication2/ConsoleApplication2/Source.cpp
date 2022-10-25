#include <vector>
#include <cstring>
#include <fstream>
#include "Header.h"

using namespace std;
vector < string > FileReader(string a) {
	ifstream fin(a);
	vector < string > v1;
	string s;

	while (!fin.eof()) {
		getline(fin, s, ' ');
		v1.push_back(s);
	}
	return v1;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
string ConsoleReader(string& msg) {
	cin >> msg;
	return msg;
}
bool IsNonIncreasingOrder(string& msg) {
	for (int i = 0; i + 2 < msg.size(); i += 2) {
		if (msg[i] > msg[i + 2]) {
			return false;
		}
	}
	return true;
}
vector<string> FileReader(string& a) {
	ifstream input(a);
	vector<string> v1;
	string s;
	int i = 0;
	while (!input.eof()) {
		getline(input, s);
		v1.push_back(s);
	}
	return v1; 
}
vector<string> WordParser(vector<string> lines, string& a) {
	vector<string> v;
	string s;
	for (int i = 0; i < lines.size(); i++) {
		for (int j=0; j < lines[i].size(); j++) {
			if (lines[i][j] == ' ') {
				v.push_back(s);
				s = "";
				j++;
			}
			s += lines[i][j];
		}
		v.push_back(s);
		s = "";
	}
	return v;
}
vector<string>FindItems(vector<string> v) {
	vector<string> v1;
	for (auto& x : v) {
		if (IsNonIncreasingOrder(x)) {
			v1.push_back(x);
		}
	}
	return v1;
}
int WordWeight(string s) {
	int w=0;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] & 1)!=0 && ((s[i] >> 2) & 1)!=0) //Под первым я понимал - с номером 0,под третьим - с номером 2
			w+=s[i];
	}
	return w;
}
template< typename T1, typename T2 > //Например для char и bool
void FileWriter(map<T1, T2> M) {
	ofstream fout("output_file.txt");
	for (auto it = M.begin(); it != M.end(); ++it)
	{
		fout << (*it).first << "  " << (*it).second << endl;
	}
}
vector<string> SortCollection(vector<string> v) {
	sort(v.begin(), v.end(), [](string a, string d) {return (WordWeight(a) < WordWeight(d)); }); 
	return v;
}
int WordWeight(vector<string> v) {
	int w = 0;
	for(int j=0;j < v.size();j++)
	for (int i = 0; i < v[j].size(); i++) {
		if ((v[j][i] & 1) != 0 && ((v[j][i] >> 2) & 1) != 0) 
			w += v[j][i];
	}
	return w;
}
void Encryption(string file_path, unsigned char key) {
	ifstream fin(file_path + ".txt");
	ofstream fout(file_path + "_encr" + ".txt");
	char c;
	char c1;
	while (true) {
		fin >> c;
		c1 = c ^ key;
		if (fin.eof()) break;
		fout << c1;
	}
}
int main()
{
	string msg;
	msg = ConsoleReader(msg);
	for (auto& x : FindItems(WordParser(FileReader(msg), msg))) {
		cout << x << endl;
	}
	map<string, int>  word_weight_map; //заполнение происходит map в main
	for (int i = 0;i < FindItems(WordParser(FileReader(msg), msg)).size(); i++)
	{
		word_weight_map.insert(pair<string, int>(FindItems(WordParser(FileReader(msg), msg))[i], WordWeight(FindItems(WordParser(FileReader(msg), msg))[i])));
	}
	cout << endl;
	FileWriter(word_weight_map);
	for (int i = 0; i < SortCollection(FindItems(WordParser(FileReader(msg), msg))).size(); i++)
	{
		cout << SortCollection(FindItems(WordParser(FileReader(msg), msg)))[i] << endl;
	}
	cout << WordWeight(FindItems(WordParser(FileReader(msg), msg)));
	Encryption("output_file", 'A');
	Encryption("output_file_encr", 'A');
	Encryption("output_file_encr_encr", 'A');
}

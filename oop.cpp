#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Eng_club
{
    public:
    void levol(){
        cout << "What is your level of English ?" << endl;
    }
    string level;
    void A(){
        cout << "You should improve English" << endl;
    }
    void B(){
        cout << "Be even better " << endl;
    }
    void C(){
        cout << "You are successful" << endl;
    }
};
int main()
{
    Eng_club Eng;

    cin >> Eng.level;

    if (Eng.level[0]=='A') {
        Eng.A();
    }

    if (Eng.level[0]=='B') {
        Eng.B();
    }
    Eng_club *t = &Eng;

    if (Eng.level[0]=='C') {
        t->C();
    }
    return 0;
}

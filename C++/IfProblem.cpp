#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    bool t = true;
    
    while(t) {
        cin >> s;
        if(s == "end") t = false;
        else if(s == "animal") cout << "Panthera tigris" << endl;
        else if(s == "flower") cout << "Forsythia koreana" << endl;
        else if(s == "tree") cout << "Pinus densiflora" << endl;
    }

    return 0;
}
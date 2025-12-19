#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cin >> n;
    
    if(10000 >= n) cout << "Accepted";
    else cout << "Time limit exceeded";

    return 0;
}
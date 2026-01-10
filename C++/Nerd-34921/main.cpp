#include <iostream>

using namespace std;

int main()
{
    int a, t;
    
    cin >> a >> t;
    
    int p = 10 + 2 * (25 - a + t);
    
    cout << (p > 0 ? p : 0);

    return 0;
}
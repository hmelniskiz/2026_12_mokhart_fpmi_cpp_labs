#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=min(n, m); i++){
        if((m%i==0) && (n%i==0))
            cout << i << endl;
    }
    return 0;
}

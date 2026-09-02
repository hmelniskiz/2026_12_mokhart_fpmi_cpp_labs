#include <iostream>

using namespace std;

int main()
{
    int n, fib, fib1=0, fib2=1;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << fib1 << endl;
        fib = fib1+fib2;
        fib1=fib2;
        fib2=fib;
    }
    return 0;
}

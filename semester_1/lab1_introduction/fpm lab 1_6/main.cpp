#include <iostream>

using namespace std;

int main()
{
    int a, b, d;
    cin >> a >> b >> d;
    while(a<=b){
        if(a%3==0)
            cout << a << endl;
        a=a+d;
    }
    return 0;
}

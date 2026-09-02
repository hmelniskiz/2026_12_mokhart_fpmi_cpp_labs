#include <iostream>

using namespace std;

int main()
{
    int num, cifr1, cifr2, cifr3, cifr4;
    cin >> num;
    cifr1 = num/1000;
    cifr2 = num/100%10;
    cifr3 = num/10%10;
    cifr4 = num%10;
    if(cifr1==cifr4 && cifr2==cifr3)
        cout << "palindrom" << endl;
    else
        cout << "ne palindrom" << endl;
    return 0;
}

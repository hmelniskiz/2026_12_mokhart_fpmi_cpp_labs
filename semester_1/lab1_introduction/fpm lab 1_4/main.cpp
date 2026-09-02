#include <iostream>

using namespace std;

int main()
{
    int num, perv_sum, vtor_sum;
    cin >> num;
    int perv_half=num/1000, vtor_half=num%1000;
    perv_sum=perv_half/100+perv_half/10%10+perv_half%10;
    vtor_sum=vtor_half/100+vtor_half/10%10+vtor_half%10;
    if(perv_sum==vtor_sum)
        cout << "happy number";
    else
        cout << "not happy number";
    return 0;
}

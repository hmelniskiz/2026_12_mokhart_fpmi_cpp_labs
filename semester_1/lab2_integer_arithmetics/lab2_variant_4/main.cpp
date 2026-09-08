#include <iostream>


int main()
{
    int n;
    std::cin >> n;
    for(int i=2; i<n; i++){
        int sovershen=0;
        for(int j=1; j<i; j++)
            if(i%j==0)
                sovershen+=j;
            if(sovershen==i)
            std::cout << i << " ";
    }
    return 0;
}

#include <iostream>


int main()
{
    int n;
    if(!(std::cin >> n)){
            std::cout << "ne chislo";
        return 1;
     }
    for(int i=2; i<=n; i++){
        int sovershen=0;
        for(int j=1; j<=i/2; j++){
            if(i%j==0)
                sovershen+=j;
                }
            if(sovershen==i)
            std::cout << i << " ";
    }
    return 0;
}

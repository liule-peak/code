//can be evaluated at compile time.

#include<iostream>
#include<array>
#include<cassert>
using std::cout;
using std::endl;

constexpr int factorial(int n){
    if(n==0){
        return 1;
    }else{
        return n * factorial(n - 1);
    }
}

int main(){


    static_assert(factorial(4) == 24, "factorial(4) shoul be 24");
   /* assert(f == 6);
    cout << "3! = " << f << endl;
    */
    std::array<int, factorial(4)> a;
    cout << a.size();
    
    return (0);
}
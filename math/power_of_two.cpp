#include "./../lc.h"

// iterative
bool solution_1(int n) {
    if(n == 0)
        return false;
    while(n % 2 == 0)
        n /= 2;
    return n == 1;
}

// bit operation
bool solution_2(int n) {
    return n > 0 && ((n & (n - 1)) == 0) ;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
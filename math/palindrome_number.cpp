#include "./../lc.h"

bool solution(int x) {
    if(x < 0 || (x != 0 && x % 10 == 0))
        return false;
    int sum = 0;
    while(x > sum) {
        sum = sum * 10 + x % 10;
        x = x / 10;
    }
    return x == sum || x == sum / 10;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
#include "./../lc.h"

int solution(int n) {
    int result = 0;
    for(; n != 0; n /= 5)
        result += n / 5;
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
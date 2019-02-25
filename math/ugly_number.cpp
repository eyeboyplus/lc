#include "./../lc.h"

bool solution(int num) {
    for(int i = 2; i < 6 && num; i++)
        while(num % i == 0)
            num /= i;
    return num == 1;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
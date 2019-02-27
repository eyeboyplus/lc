#include "./../lc.h"

int solution(int num) {
    return (num == 0) ? 0 : (num - 1) % 9 + 1;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
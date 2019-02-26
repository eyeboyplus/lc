#include "./../lc.h"

int solution(int x) {
    int result = 0;
    while(x != 0) {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if((newResult - tail) / 10 != result)   // 判断是否溢出
            return 0;
        result = newResult;
        x /= 10;
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
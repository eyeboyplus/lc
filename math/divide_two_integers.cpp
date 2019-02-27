#include "./../lc.h"

int solution(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1)    // 负数比整数多一个数，会溢出
        return INT_MAX;
    long dvd = labs(dividend), dvs = labs(divisor), result = 0;
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    while(dvd >= dvs) {
        long tmp = dvs, m = 1;
        while(dvd >= (tmp << 1)) {
            tmp <<= 1;
            m <<= 1;
        }
        dvd -= tmp;
        result += m;
    }
    return sign * result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
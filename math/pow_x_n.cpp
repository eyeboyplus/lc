#include "./../lc.h"

double solution(double x, int n) {
    if(n == 0) return 1;
    if(n == INT_MIN)        // 处理INT_MIN取反溢出问题
        return solution(x * x, n / 2);
    
    if(n < 0) {
        n = -n;
        x = 1 / x;
    }
    return (n % 2 == 0) ? solution(x * x, n / 2) : x * solution(x * x, n / 2);
}

double solution_1(double x, int n) {
    if(n == 0) return 1;

    long p = labs(n);
    double power = solution_1(x * x, p / 2) * (p % 2 ? x : 1);
    return n > 0 ? power : 1 / power;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
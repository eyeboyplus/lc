#include "./../lc.h"

int solution(int x) {
    int i = 1, j = x;
    int result = 0;
    while(i <= j) {
        int mid = (i + j) / 2;      // mid = (i + j) / 2 溢出
        if(mid <= x / mid) {        // mid * mid <= x 溢出
            i = mid + 1;
            result = mid;
        } else {
            j = mid - 1;
        }
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
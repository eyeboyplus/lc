#include "./../lc.h"

int solution(int x) {
    int i = 1, j = x;
    int ret = 0;
    while(i <= j) {
        int mid = i + (j - i) / 2;
        if(mid <= x / mid) {
            i = mid + 1;
            ret = mid;
        } else {
            j = mid - 1;
        }
    }
    return ret;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
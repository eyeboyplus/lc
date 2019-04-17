#include "./../lc.h"

int solution(int n) {
    int l = 1, r = n;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(isBadVersion(mid)) {
            if(mid <= 1) return mid;
            if(mid > 1 && !isBadVersion(mid - 1))
                return mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
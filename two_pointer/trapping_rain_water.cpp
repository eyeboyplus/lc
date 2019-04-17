#include "./../lc.h"

int solution(vector<int> &height) {
    int l = 0, r = height.size() - 1;
    int lmax = 0, rmax = 0, ret = 0;
    while(l <= r) {
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);
        if(lmax < rmax) {
            ret += lmax - height[l];
            l++;
        } else {
            ret += rmax - height[r];
            r--;
        }
    }
    return ret;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
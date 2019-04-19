#include "./../lc.h"

int recursive(const vector<int> &heights, int start, int end) {
    if(start > end)
        return 0;
    if(start == end) 
        return heights[start];

    int min_idx = start, min = heights[start];
    for(int i = start; i <= end; i++) {
        if(heights[i] < min) {
            min_idx = i;
            min = heights[i];
        }
    }
    int lmax = recursive(heights, start, min_idx - 1);
    int rmax = recursive(heights, min_idx + 1, end);
    int cur = min * (end - start + 1);
    return max(lmax, max(rmax, cur));
}

int solution(vector<int> &heights) {
    if(heights.empty())
        return 0;
    return recursive(heights, 0, heights.size() - 1);
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
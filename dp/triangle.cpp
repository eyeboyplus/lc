#include "./../lc.h"

int solution(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<int> minpath (triangle.back());
    for(int i = n - 2; i >= 0; --i) {
        for(int j = 0; j <=i; ++j) {
            minpath[i] = min(minpath[i], minpath[i + 1]) + triangle[i][j];
        }
    }
    return minpath[0];
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
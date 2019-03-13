#include "./../lc.h"

int solution(vector<int> &nums) {
    unordered_map<int, int> map;
    for(vector<int>::const_iterator it = nums.cbegin();
    it != nums.cend(); it++) {
        map[*it] ++;
    }
    for(auto pair : map) {
        if(pair.second == 1)
            return pair.first;
    }
    return 0;
}

// bit operation
int solution_1(vector<int> &nums) {
    int result = 0;
    for(vector<int>::const_iterator it = nums.cbegin();
    it != nums.cend(); it++) {
        result ^= (*it);
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
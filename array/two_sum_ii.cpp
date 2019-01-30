#include "./../lc.h"

vector<int> solution(vector<int> &numbers, int target) {
    int left = 0, right = numbers.size() - 1, sum = 0;
    vector<int> result;
    while(left < right) {
        sum = numbers[left] + numbers[right];
        if(sum == target) {
            result.push_back(left + 1);
            result.push_back(right + 1);
            return result;
        } else if(sum < target) {
            left ++;
        } else {
            right --;
        }
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
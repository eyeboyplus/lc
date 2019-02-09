#include "./../lc.h"

vector<string> solution(vector<int> &nums) {
    vector<string> result;
    vector<int>::const_iterator left = nums.cbegin();
    for (vector<int>::const_iterator right = nums.cbegin();
         right != nums.cend(); right++)
    {
        if (right + 1 != nums.cend() && (*right) + 1 == *(right + 1))
            continue;
        
        if (left != right)
        {
            result.push_back(to_string(*left) + "->" + to_string(*right));
            left = right + 1;
        }
        else
        {
            result.push_back(to_string(*left));
            left = right + 1;
        }
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
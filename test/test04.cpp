#include "./../lc.h"

    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int n = num.size();
        int cnt = (size >= n ? 1 : n - size + 1);
        vector<int> result(cnt, INT_MIN);
        for(int i = 0; i < cnt; i++) {
            if(i > 0 && result[i - 1] != num[i - 1]) {
              result[i] = max(result[i - 1], num[i]);  
            } else {
                int mx = INT_MIN;
                for(int j = i; j < size + i; j++)
                    mx = max(num[j], mx);
                result[i] = mx;
            }
        }
        return result;
    }

int main(int argc, char **argv) {
    
    vector<int> vec = {2,3,4,2,6,2,5,1};
    vector<int> res = maxInWindows(vec, 3);


    std::cout << "done.";
    return 0;
}
#include "./../lc.h"

int solution(vector<int> &citations) {
    sort(citations.begin(), citations.end());
    int length = citations.size();

    int ret = INT_MIN;
    for(int N = 0; N <= length; N++) {
        int h;
        if(N == 0)
            h = citations[length - 1] + 1;
        else
            h = citations[length - N];
        if(length - N - 1 >= 0 && citations[length - N - 1] < h)
            ret = max(ret, h);
    }
    return ret;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
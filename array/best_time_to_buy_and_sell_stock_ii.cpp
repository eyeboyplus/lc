#include "./../lc.h"

int solution(vector<int> &prices) {
    int result = 0, size = prices.size();
    for(int i = 0; i < size - 1; ++i) {
        int diff = prices[i + 1] - prices[i];
        result += diff > 0 ? diff : 0;
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
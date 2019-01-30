#include "./../lc.h"

int solution(vector<int> &prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for(vector<int>::const_iterator it = prices.cbegin();
    it != prices.cend(); it++) {
        minPrice = min(*it, minPrice);
        maxProfit = max(maxProfit, *it - minPrice);
    }
    return maxProfit;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
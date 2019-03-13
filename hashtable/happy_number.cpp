#include "./../lc.h"

bool solution(int n) {
    unordered_set<int> set;
    while(n != 1) {
        if(set.find(n) == set.end())
            set.insert(n);
        else
            return false;
        
        int sum = 0;
        while(n != 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        n = sum;
    }
    return true;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
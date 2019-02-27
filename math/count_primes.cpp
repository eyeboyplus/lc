#include "./../lc.h"

int solution(int n) {
    vector<bool> isPrime (n, true);
    int result = 0;
    for(int i = 2; i < n; ++i) {
        if(isPrime[i]) {
            result ++;
            for(int j = 2; i * j < n; j++)
                isPrime[i * j] = false;
        }
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
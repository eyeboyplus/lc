#include "./../lc.h"

string solution(int n) {
    string result;
    if(n == 0) 
        return result;
    
    while(n != 0) {
        --n;
        result.insert(result.begin(), char('A' + n % 26));
        n /= 26;
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
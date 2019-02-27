#include "./../lc.h"

string solution(int numerator, int denominator) {
    if(numerator == 0) return "0";

    string result;
    if(numerator < 0 ^ denominator < 0)
        result += "-";
    long numer = labs(numerator);
    long denom = labs(denominator);
    result += to_string(numer / denom);

    long remainder = numer % denom;
    if(remainder == 0)
        return  result;
    result += ".";
    remainder *= 10;
    unordered_map<long, long> map;
    while(remainder){
        long quotient = remainder / denom;
        if(map.find(remainder) != map.end()) {
            result.insert(map[remainder], 1, '(');
            result += ")";
            break;
        }
        map[remainder] = result.size();
        result += to_string(quotient);
        remainder = (remainder % denom) * 10;
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
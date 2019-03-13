#include "./../lc.h"

vector<string> solution(string s) {
    vector<string> ret;
    int n = s.length();

    map<string, int> map;
    for(int i = 0; i <= n - 10; i ++)
        map[s.substr(i, 10)] ++;
    for(auto pair : map)
        if(pair.second > 1)
            ret.push_back(pair.first);
    return ret;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}
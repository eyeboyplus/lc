#include "./../lc.h"

string solution(string path) {
    istringstream iss(path);
    string s;
    stack<string> stk;
    while(getline(iss, s, '/')) {
        if(s.empty() || s == ".")
            continue;
        else if(s == "..") {
            if(!stk.empty())
                stk.pop();
        } else {
            stk.push(s);
        }
    }

    string ret;

    while(!stk.empty()) {
        if(ret.empty())
            ret = stk.top();
        else
            ret = stk.top() + "/" + ret;
        stk.pop();
    }
    return  "/" + ret;
}

int main(int argc, char **argv) {
    
    string res1 = solution("/home/");
    string res2 = solution("/../");
    string res3 = solution("/home//foo/");
    string res4 = solution("/a/./b/../../c/");
    string res5 = solution("/a/../../b/../c//.//");
    string res6 = solution("/a//b////c/d//././/..");

    std::cout << "done.";
    return 0;
}
#include "./../lc.h"

string solution(string path) {
    int length = path.length();
    stack<string> stack;
    string result;
    for(int i = 0; i < length;) {
        while(i < length && path[i] == '/') i ++;
        int start = -1;
        if(i < length)
            start = i;
        else
            break;

        while(i < length && path[i] != '/') i ++;
        if(i == length && start == -1)
            break;
        int end = i;

        string s = path.substr(start, end - start);
        if(s == ".")
            continue;
        if(s == "..") {
            if(!stack.empty())
                stack.pop();
            continue;        
        }
        stack.push(s);
    }

    if(stack.empty()) return "/";

    while(!stack.empty()) {
        result = stack.top() + "/" + result;
        stack.pop();
    }
    return "/" + result.substr(0, result.length() - 1);
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
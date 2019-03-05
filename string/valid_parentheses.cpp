#include "./../lc.h"

bool solution(string s) {
    int n = s.size();
    stack<char> stack;
    for(int i = 0; i < n; ++i) {
        switch (s[i])
        {
            case '(':
            case '[':
            case '{':
                stack.push(s[i]);
                break;
            case ')':
                if(stack.empty() || stack.top() != '(')
                    return false;
                stack.pop();
                break;
            case ']':
                if(stack.empty() || stack.top() != '[')
                    return false;
                stack.pop();
                break;
            case '}':
                if(stack.empty() || stack.top() != '{')
                    return false;
                stack.pop();
                break;
        }
    }
    if(stack.empty())
        return true;
    return false;
}

int main(int argc, char **argv) {
    bool res1 = solution("()[]{}");
    std::cout << "done.";
    return 0;
}
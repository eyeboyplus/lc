#include "./../lc.h"

int solution(string s) {
    stack<char> opt;
    stack<int> nums;
    
    int n = s.size();
    for(int i = 0; i < n;) {
        if(s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            while(i < n && s[i] >= '0' && s[i]<='9') 
                num = num * 10 + (s[i++] - '0');
            nums.push(num);
            if(i == n)
                break;
        } else if(s[i] == '+' || s[i] == '-') {
            if(opt.empty())
                opt.push(s[i]);
            else {
                if(opt.top() == '(')
                    opt.push(s[i]);
                else {
                    while(!opt.empty() && opt.top() != '(') {
                        char op = opt.top();
                         opt.pop();
                         int v1 = nums.top();
                         nums.pop();
                         int v2 = nums.top();
                         nums.pop();
                         int x = 0;
                         if(op == '+')
                             x = v1 + v2;
                         else if(op == '-')
                             x = v2 - v1;
                         nums.push(x);
                    }
                    opt.push(s[i]);
                }
            }
            i++;
        } else if(s[i] == '(') {
            opt.push(s[i++]);
        } else if(s[i] == ')') {
            while(!opt.empty() && opt.top() != '(') {
                char op = opt.top();
                opt.pop();
                int v1 = nums.top();
                nums.pop();
                int v2 = nums.top();
                nums.pop();
                int x = 0;
                if(op == '+')
                    x = v1 + v2;
                else if(op == '-')
                    x = v2 - v1;
                nums.push(x);
            }
            opt.pop();
            i++;
        } else {
            i++;
        }
    }
    while(!opt.empty()) {
        char op = opt.top();
        opt.pop();
        int v1 = nums.top();
        nums.pop();
        int v2 = nums.top();
        nums.pop();
        int x = 0;
        if(op == '+')
            x = v1 + v2;
        else if(op == '-')
            x = v2 - v1;
        nums.push(x);
    }   
    return nums.top();
}

int main(int argc, char **argv) {
    int res1 = solution("1 + 1");
    int res2 = solution("(1 + 2) - (1 + 1)");
    int res3 = solution("2 - 1 + 2");
    std::cout << "done.";
    return 0;
}
#include "./../lc.h"

int op(char op, int num1, int num2) {
    int result = 0;
    switch (op)
    {
        case '+' : result = num1 + num2; break;
        case '-' : result = num1 - num2; break;
        case '*' : result = num1 * num2; break;
        case '/' : result = num1 / num2; break;
    }
    return result;
}

bool isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int solution(string s) {
    int len = s.length();
    stack<int> numstk;
    stack<char> opstk;
    unordered_map<char, int> weight = {
        {'+', 0},
        {'-', 0},
        {'*', 1},
        {'/', 1}
    };
    for(int i = 0; i < len;) {
        if(isdigit(s[i])) {
            int num = 0;
            do {
                num = num * 10 + (s[i] - '0');
                i++;
           } while(i < len && isdigit(s[i]));
           numstk.push(num);
        } else if(isOp(s[i])) {
            while(!opstk.empty() && weight[s[i]] <= weight[opstk.top()]) {
                int num2 = numstk.top();
                numstk.pop();
                int num1 = numstk.top();
                numstk.pop();
                numstk.push(op(opstk.top(), num1, num2));
                opstk.pop();    
            }
            opstk.push(s[i]);
            i++;
        } else {
            i++;
        }
    }
    while(!opstk.empty()) {
        int num2 = numstk.top();
        numstk.pop();
        int num1 = numstk.top();
        numstk.pop();
        numstk.push(op(opstk.top(), num1, num2));
        opstk.pop();
    }
    return numstk.top();
}

int main(int argc, char **argv) {
    int res1 = solution("3+2*2");
    int res2 = solution(" 3/2 ");
    int res3 = solution(" 3+5 / 2 ");
    std::cout << "done.";
    return 0;
}
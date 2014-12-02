#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;
stack<char> s;
/**
    http://scanftree.com/Data_Structure/infix-to-prefix
**/
int precedence(char c)
{
    int i = 10;
    if (c == '/') {
        return i;
    } else if (c == '*') {
        return i-1;
    } else if (c == '+') {
        return i - 2;
    } else if (c == '-') {
        return i - 3;
    } else {
        return 0;
    }

}

string infix_postfix(string infix)
{
    string ans = "";
    for(int i = 0; i < infix.size(); i++) {
        if(isalpha(infix[i]) || isdigit(infix[i])) {
            cout << infix[i];
            ans += infix[i];
        } else if (infix[i] ==')'){
            char c = s.top();
            s.pop();
           // cout << c << endl;
            while (c != '(') {
                cout << c;
                ans += c;
                if (!s.empty()) {
                    c = s.top();
                    s.pop();
                } else {
                    cout << "wrong expression" << endl;
                    ans = "wrong expression";
                    return ans;
                }

            }

        } else if (infix[i] == '('){
            s.push(infix[i]);
        } else {
            // an operator is encountered
            while (!s.empty() && (precedence(infix[i]) <= precedence(s.top())) ) {
                cout << s.top();
                ans += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    // empty stack
    while (!s.empty()) {
        cout << s.top();
        ans += s.top();
        s.pop();
    }
     cout << endl;
    return ans;
}

stack<string> stck;
void postfix_infix(string postfix)
{
    string str = "";
    for (int i = 0; i < postfix.size(); i++) {
        if (isalpha(postfix[i]) || isdigit(postfix[i])) {
            str = postfix[i];
            stck.push(str);
        } else {
            if (stck.empty()) {
                cout << "\nwrong expression";
                return;
            }
            string op1 = stck.top();
            stck.pop();
            if (stck.empty()) {
                cout << "\nwrong expression";
                return;
            }
            string op2 = stck.top();
            stck.pop();
            str = op2 + postfix[i] + op1;
            stck.push(str);
        }
    }
    cout << stck.top() << endl;
    stck.pop();
    if (!stck.empty()) {
        cout << "\nwrong expression";
        return;
    }

}


string infix_prefix(string prefix)
{
    string ss = "";
    for (int i =  prefix.size() - 1; i >= 0; i--) {
        if (prefix[i] == ')') {
            prefix[i] = '(';
        } else if (prefix[i] == '(') {
            prefix[i] = ')';
        }
        ss += prefix[i];
    }
    prefix = infix_postfix(ss);
    ss = "";
    for (int i =  prefix.size() - 1; i >= 0; i--) {
        if (prefix[i] == ')') {
            prefix[i] = '(';
        } else if (prefix[i] == '(') {
            prefix[i] = ')';
        }
        ss += prefix[i];
    }
    cout << "after conversion  " << ss << endl;
    return ss;
}

stack<string> prefix;
string prefix_infix(string prefix)
{
    // reverse the string

}

int main()
{
    string s = "abc++";
    //infix_postfix(s);

    //postfix_infix(s);
    infix_prefix("a+(b+c)");
    return 0;
}

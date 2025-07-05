#include<bits/stdc++.h>
class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<int> l;
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (stk.empty()) {
                l.push_back(i);
                stk.push(s[i]);
                continue;
            }
            if (stk.top() == '(' && s[i] == ')') {
                stk.pop();
                if (stk.empty()) l.push_back(i);
            } else if (stk.top() == ')' && s[i] == '(') {
                stk.pop();
                if (stk.empty()) l.push_back(i);
            } else {
                stk.push(s[i]);
            }
        }
        string sb;
        for (int i = 0; i < l.size(); i += 2) {
            sb.append(s.substr(l[i] + 1, l[i + 1] - l[i] - 1));
        }
        return sb;
    }
};

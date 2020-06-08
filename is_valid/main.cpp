/**
 * 判断括号合法性
 * 主要研究的是栈的使用方法
 * 解题思路：
 * 将左括号压入栈中，遇到第一个右括号时，与栈中第一个左括号进行匹配，若不匹配则判定不合理．
*/


#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 处理单一符号
bool isValid(string& str);

// 处理三种符号
bool isValidMulti(string& str);

// 查询对应右括号
char leftOf(char c);

int main(int argc, char** argv) {

    string str = "(()";
    if (isValid(str)) {
        cout << "input is " << str << ", and we get the valid result." << endl;
    }
    else {
        cout << "input is " << str << ", and we get the invalid result." << endl;
    }

    string str2 = "{(())[]}";
    bool valid = isValidMulti(str2);
    if (valid) {
        cout << "input is " << str2 << ", and we get the valid result." << endl;
    }
    else {
        cout << "input is " << str2 << ", and we get the invalid result." << endl;
    }

    return 0;
}

// 处理单一符号
bool isValid(string& str) {
    if (str.empty()) return true;

    int left = 0;
    for (char c : str) {
        if (c == '(') {
            ++left;
        }
        else {
            --left;
        }

        if (left < 0) return false;
    }

    return left == 0;
}

// 处理三种符号
bool isValidMulti(string& str) {
    if (str.empty()) return true;

    stack<char> left;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            left.push(c);
        }
        else {
            if (!left.empty() && leftOf(c) == left.top()) {
                left.pop();
            }
            else {
                return false;
            }
        }
    }
    return left.empty();
}

// 查询对应右括号
char leftOf(char c) {
    if (c == '}') {
        return '{';
    }
    else if (c == ')') {
        return '(';
    }
    else if (c == ']') {
        return '[';
    }
    else {
        return ' ';
    }
}
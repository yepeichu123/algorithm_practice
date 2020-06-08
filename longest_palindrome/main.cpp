/*
 * 题目： 寻找最长回文字符
 * 回文串就是正着读和反着读都一样的字符．
 * 解题思路：
 * 利用双指针以当前字符为中心，向两边辐射，直到回文查找结束为止．
 * for 0 <= i <= len(s)
 *      找到以s[i]为中心的回文串
 *      找到以s[i]和s[i+1]为中心的回文串
 *      更新答案
*/

#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(const string& s);

string palindrome(const string& s, int left, int right);

int main(int argc, char** argv) {

    string s1 = "babad";
    string out_s = longestPalindrome(s1);
    cout << "input is : " << s1 << ", output is : " << out_s << endl;

    string s2 = "cbbd";
    out_s = longestPalindrome(s2);
    cout << "input_2 is : " << s2 << ", output is : " << out_s << endl;
    
    return 0;
}

string longestPalindrome(const string& s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
        string s1 = palindrome(s, i, i);
        string s2 = palindrome(s, i, i+1);
        res = res.size() > s1.size() ? res : s1;
        res = res.size() > s2.size() ? res : s2;
    }
    return res;
}

string palindrome(const string& s, int left, int right) {
    if (s.size() == 0) return string("");
    if (left < 0 || right < 0) return string("");

    while (left >= 0 && right <= s.size()-1 && s[left] == s[right]) {
        --left;
        ++right;
    }
    return s.substr(left + 1, right - left - 1);    
}
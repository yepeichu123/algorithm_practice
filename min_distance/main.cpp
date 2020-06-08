/*
 * 距离编辑问题
 * 给定两个字符串s1和s2，计算出将s1转换成s2所使用的最少操作数．
 * 可进行的操作包括：跳过，插入一个字符串，删除一个字符串和替换一个字符串
 * 解题思路：
 * 创建一个dp table，用来记录不同路径需要的距离
 * 给定基础条件，其他的距离由之前的数值加增量得到
*/

#include <iostream>
#include <string>

using namespace std;


int min_distance(const string& s1, const string& s2);

int min(int a, int b, int c);

int main(int argc, char** argv) {

    string s1 = "horse";
    string s2 = "ros";
    cout << "intput is : " << s1 << ", " << s2 << endl;
    int min_dist = min_distance(s1, s2);
    cout << "min_dist is " << min_dist << endl;

    s1 = "intention";
    s2 = "execution";
    cout << "input_2 is : " << s1 << ", " << s2 << endl;
    min_dist = min_distance(s1, s2);
    cout << "min_dist is " << min_dist << endl;

    return 0;
}

int min_distance(const string& s1, const string& s2) {
    int m = s1.length(); 
    int n = s2.length();
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    int** dp = new int *[m+1];
    for (int i = 0; i < m+1; ++i) {
        dp[i] = new int[n+1];
    }

    //　基础类型
    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // 跳过
            }
            else {
                // 千万不要忘记，每次操作完要对操作次数+1
                dp[i][j] = min(
                    dp[i-1][j-1] + 1, // 替换
                    dp[i-1][j] + 1, // 删除
                    dp[i][j-1] + 1// 增加
                );
            }
        }
    }

    int min_dist = dp[m][n];
    
    // 释放new的内存，不然会导致内存泄露
    for (int i = 0; i < m+1; ++i) {
        delete []dp[i];
    }

    return min_dist;
}

int min(int a, int b, int c) {
    return min(a, min(b, c));
}
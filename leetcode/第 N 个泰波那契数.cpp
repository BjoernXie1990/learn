class Solution {
public:
    int tribonacci(int n) {
        int f[40];
        f[0] = 0;
        f[1] = 1;
        f[2] = 1;

        for(int i = 3; i <= n; i++) {
            f[i] = f[i-3] + f[i-2] + f[i-1];
        }

        return f[n];
    }
};


泰波那契序列?Tn?定义如下：?

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0?的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数?n，请返回第 n 个泰波那契数?Tn 的值。

?

示例 1：

输入：n = 4
输出：4
解释：
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
示例 2：

输入：n = 25
输出：1389537
?

提示：

0 <= n <= 37
答案保证是一个 32 位整数，即?answer <= 2^31 - 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-th-tribonacci-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


在无限的整数序列?1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第?n?个数字。

注意:
n?是正数且在32位整数范围内?(?n < 231)。

示例 1:

输入:
3

输出:
3
示例 2:

输入:
11

输出:
0

说明:
第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nth-digit
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        long le = 1;
        long ri = 9;
        int len = 0;
        //le                    ri
        //1 - [1,9]             9
        //2 - [10,99]          90
        //3 - [100,999]       900
        //4 - [1000,9999]    9000
        while(len + le * ri < n) {
            len += le * ri;
            ri *= 10;
            le++;
        }

        long num = pow(10,le-1) + (n-len-1)/le;
        long index = (n-len-1) % le;
        return to_string(num)[index] - '0';
    }
};

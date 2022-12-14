class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int res = 0, le = 0, cnt = 0;

        for(int i = 0; i < n; i++) {
            if(A[i] == 0) {
                A[i] = 2;
                cnt ++;
            }

            while(le <= i && cnt > K) {
                if(A[le] == 2) {
                    A[le] = 0;
                    cnt --;
                }
                le ++;
            }

            res = max(res,i - le + 1);
        }

        return res;
    }
};


给定一个由若干 0 和 1 组成的数组?A，我们最多可以将?K?个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。

?

示例 1：

输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释： 
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
?

提示：

1 <= A.length <= 20000
0 <= K <= A.length
A[i] 为?0?或?1?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

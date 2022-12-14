//如果一个由?'0' 和 '1'?组成的字符串，是以一些 '0'（可能没有 '0'）
//后面跟着一些 '1'（也可能没有 '1'）的形式组成的，那么该字符串是单调递增的。

//我们给出一个由字符 '0' 和 '1'?组成的字符串?S，
//我们可以将任何?'0' 翻转为?'1'?或者将?'1'?翻转为?'0'。

//返回使 S 单调递增的最小翻转次数。

//?

//示例 1：

//输入："00110"
//输出：1
//解释：我们翻转最后一位得到 00111.
//示例 2：

//输入："010110"
//输出：2
//解释：我们翻转得到 011111，或者是 000111。
//示例 3：

//输入："00011000"
//输出：2
//解释：我们翻转得到 00000000。



class Solution {
public:
    //空间复杂度O(n)
    int minFlipsMonoIncr1(string S) {
        int len = S.size();
        int* dp = new int[len];
        int oneNum = 0;//统计当前位置前面 1出现的次数

        for(int i = 0; i < len; i++)
        {
            //如果这个位置是1 
            //如果前面排序都是把1 --> 0   , 这个1就是第一个1，可以暂时不用管
            //如果前面排序是把 0 --> 1,  这个1 也不用管
            if(S[i] == '1')
            {
                oneNum++;
                //dp[i] = (i == 0) ? 0 : min(dp[i-1],oneNum);
                dp[i] = (i == 0) ? 0 : dp[i-1];
            }
            else
            {
                //如果这个位置是0
                //前面的排序是把1 --> 0 ， 
                //前面排序是把 0 --> 1 ， 这里就需要判断前面出现的0 和 1 的数量
                // 0的数量就是 dp[i-1] + 1     1 的数量就用我们记录的 oneNum
                dp[i] = (i == 0) ? 0 : min(dp[i-1] + 1, oneNum);
            }
        }
        int ans = dp[len - 1];
        delete[] dp;
        return ans;
    }

     //空间复杂度O(1)
    int minFlipsMonoIncr(string S) {
        int len = S.size();
        int ans = 0;
        int oneNum = 0;//统计当前位置前面 1出现的次数

        for(int i = 0; i < len; i++)
        {
            //如果这个位置是1 
            //如果前面排序都是把1 --> 0   , 这个1就是第一个1，可以暂时不用管
            //如果前面排序是把 0 --> 1,  这个1 也不用管
            if(S[i] == '1')
            {
                oneNum++;
            }
            else
            {
                //如果这个位置是0
                //前面的排序是把1 --> 0 ， 
                //前面排序是把 0 --> 1 ， 这里就需要判断前面出现的0 和 1 的数量
                // 0的数量就是 dp[i-1] + 1     1 的数量就用我们记录的 oneNum
                ans = (i == 0) ? 0 : min(ans + 1, oneNum);
            }
        }
        return ans;
    }
};


有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组?nums?中。

现在要求你戳破所有的气球。如果你戳破气球 i ，就可以获得?nums[left] * nums[i] * nums[right]?个硬币。?这里的?left?和?right?代表和?i?相邻的两个气球的序号。注意当你戳破了气球 i 后，气球?left?和气球?right?就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:

你可以假设?nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:

输入: [3,1,5,8]
输出: 167 
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
?    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


class Solution {
public:
    vector<vector<int> > rec;
    vector<int> val;
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        val.resize(len+2);

        for(int i = 1; i <= len; i++)
            val[i] = nums[i-1];
        val[0] = val[len+1] = 1;

        rec.resize(len+2,vector<int>(len+2,-1));
        return slove(0,len+1);
    }

    int slove(int le,int ri)
    {
        if(le >= ri-1)
            return 0;
        
        if(rec[le][ri] != -1)
            return rec[le][ri];
        
        for(int i = le + 1; i < ri; i++)
        {
            int num = val[le] * val[i] * val[ri];
            num += slove(le,i) + slove(i,ri);
            rec[le][ri] = max(rec[le][ri],num);
        }
        return rec[le][ri];
    }
};

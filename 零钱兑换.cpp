//������ͬ����Ӳ�� coins ��һ���ܽ�� amount����дһ��������������Դճ��ܽ����������ٵ�Ӳ�Ҹ��������û���κ�һ��Ӳ�����������ܽ�����?-1��

//?

//ʾ��?1:

//����: coins = [1, 2, 5], amount = 11
//���: 3 
//����: 11 = 5 + 5 + 1
//ʾ�� 2:

//����: coins = [2], amount = 3
//���: -1
//?

//˵��:
//�������Ϊÿ��Ӳ�ҵ����������޵ġ�



class Solution {
public:
    int coinChange1(vector<int>& coins, int amount) {
        vector<int> ans(amount+1,amount+1);
        ans[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(auto& eoch : coins)
            {
                if(eoch > i) continue;
                ans[i] = min(ans[i],ans[i-eoch] + 1);
            }
        }
        return ans[amount]==amount+1 ? -1 : ans[amount];
    }
    //����
    int coinChange(vector<int>& coins, int amount) 
    {
        sort(coins.begin(),coins.end());
        int ans = INT_MAX;
        dfs(coins,amount,0,ans,coins.size()-1);
        return ans == INT_MAX ? -1 : ans;
    } 
    //amount ��Ҫ�ļ�ֵ  value��ǰ��ֵ
    void dfs(vector<int>& coins, int amount,int value,int& ans,int index)
    {
        if(index < 0 || value + amount / coins[index] >= ans)
            return;
        if(amount % coins[index] == 0)
        {
            ans = min(ans,value + amount / coins[index]);
            return ;
        }

        for(int i = amount / coins[index]; ~i; i--)
            dfs(coins,amount-i*coins[index],value+i,ans,index-1);
    }
};

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        using key = pair<int,int>;
        vector<key> nums;
        int n = scores.size();
        for(int i = 0; i < n; i++) {
            nums.push_back(make_pair(ages[i],scores[i]));
        }

        // �������򣬵÷�����
        sort(nums.begin(),nums.end(),[](const key& a,const key& b)->bool{
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        // ����������������
        int dp[n];
        memset(dp,0x00,sizeof dp);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            dp[i] = nums[i].second;
            for(int j = 0; j < i; j++) 
                if(nums[j].second <= nums[i].second) dp[i] = max(dp[i],dp[j] + nums[i].second);
            
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};

����������ӵľ������ڼ��������Ľ��������������һ֧����÷���ߵ���ӡ���ӵĵ÷��������������Ա�ķ��� �ܺ� ��

Ȼ��������е�ì�ܻ�������Ա�ķ��ӣ����Ա���ѡ��һ֧ û��ì�� ����ӡ����һ�������С��Ա�ķ��� �ϸ���� һ������ϴ����Ա�������ì�ܡ�ͬ����Ա֮�䲻�ᷢ��ì�ܡ�

���������б� scores �� ages������ÿ�� scores[i] �� ages[i] ��ʾ�� i ����Ա�ķ��������䡣���㷵�� ���п��ܵ���ì������е÷������֧�ķ��� ��

?

ʾ�� 1��

���룺scores = [1,3,5,10,15], ages = [1,2,3,4,5]
�����34
���ͣ������ѡ��������Ա��
ʾ�� 2��

���룺scores = [4,5,6,5], ages = [2,1,2,1]
�����16
���ͣ���ѵ�ѡ���Ǻ� 3 ����Ա��ע�⣬�����ѡ�ж��ͬ����Ա��
ʾ�� 3��

���룺scores = [1,2,3,5], ages = [8,9,10,1]
�����6
���ͣ���ѵ�ѡ����ǰ 3 ����Ա��
?

��ʾ��

1 <= scores.length, ages.length <= 1000
scores.length == ages.length
1 <= scores[i] <= 106
1 <= ages[i] <= 1000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/best-team-with-no-conflicts
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

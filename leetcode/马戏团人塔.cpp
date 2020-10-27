class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int n = height.size();
        using key = pair<int,int>;
        vector<key> nums;
        for(int i = 0; i < n; i++) nums.push_back(make_pair(height[i],weight[i]));
        
        // �����������У���ͬ���ذ�װ��߽���
        // ÿ�ζ����ҵ�һ�����Լ����
        sort(nums.begin(),nums.end(),[](const key& a,const key& b)->bool{
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        
        vector<int> dp;
        dp.push_back(nums[0].second);

        for(int i = 1; i < n; i++) {    // ����������������г���
        int l = 0, r = dp.size() - 1, w = nums[i].second;
            if(dp.back() < w) {     // �ų�����ͱ����һ���ص����
                dp.push_back(w);
                continue;
            }

            // �ҵ�һ�����Լ��ص�
            while(l < r) {
                int mid = (l + r) >> 1;
                if(dp[mid] < w)   l = mid + 1;
                else if(dp[mid] >= w)  r = mid;
            }
            dp[l] = w;

        }
        return dp.size();

        // n ^ 2
        // int ans = 0;
        // for(int i = 0; i < n; i++) {
        //     dp[i] = 1;
        //     for(int j = 0; j < i; j ++) 
        //         if(nums[i].first > nums[j].first && nums[i].second > nums[j].second)    // i �� j �ߣ���
        //             dp[i] = max(dp[i],dp[j] + 1);
        //     ans = max(ans, dp[i]);
        // }

        // return ans;
    }
};

�и���Ϸ��������Ƶ��޺��ı��ݽ�Ŀ��һ����Ҫվ����һ�˵ļ���ϡ�����ʵ�ʺ����۵Ŀ��ǣ����������Ҫ��������˰�һ������һ�㡣��֪��Ϸ��ÿ���˵���ߺ����أ����д���������޺�����ܵ������ˡ�

ʾ����

���룺height = [65,70,56,75,60,68] weight = [100,150,90,190,95,110]
�����6
���ͣ����������������޺�����ܵ� 6 �㣺(56,90), (60,95), (65,100), (68,110), (70,150), (75,190)
��ʾ��

height.length == weight.length <= 10000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/circus-tower-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

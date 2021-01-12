class Solution {
public:
    vector<int> nums;
    vector<int> job;
    int res = INT_MAX;

    int minimumTimeRequired(vector<int>& jobs, int k) {
        job = jobs;
        nums.resize(k,0);
        dfs(0,0,0);
        return res;
    }

    void dfs(int id,int n,int c) {
        if(res < c) return ;
        if(id == job.size()) {
            res = c;
            return ;
        }

        for(int i = 0; i < n; i++) {
            nums[i] += job[id];
            dfs(id+1,n,max(c,nums[i]));
            nums[i] -= job[id];
        }
        if(n < nums.size()) {
            nums[n] = job[id];
            dfs(id+1,n+1,max(c,nums[n]));
            nums[n] = 0;
        }
    }
};

����һ���������� jobs ������ jobs[i] ����ɵ� i ���Ҫ���ѵ�ʱ�䡣

���㽫��Щ��������� k λ���ˡ����й�����Ӧ�÷�������ˣ���ÿ���ֻ�ܷ����һλ���ˡ����˵� ����ʱ�� ����ɷ�������ǵ����й�������ʱ����ܺ͡��������һ����ѵĹ������䷽����ʹ���˵� �����ʱ�� ���� ��С�� ��

���ط��䷽���о����� ��С �� �����ʱ�� ��

?

ʾ�� 1��

���룺jobs = [3,2,3], k = 3
�����3
���ͣ���ÿλ���˷���һ����������ʱ���� 3 ��
ʾ�� 2��

���룺jobs = [1,2,4,7,8], k = 2
�����11
���ͣ���������ʽ���乤����
1 �Ź��ˣ�1��2��8������ʱ�� = 1 + 2 + 8 = 11��
2 �Ź��ˣ�4��7������ʱ�� = 4 + 7 = 11��
�����ʱ���� 11 ��
?

��ʾ��

1 <= k <= jobs.length <= 12
1 <= jobs[i] <= 107

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

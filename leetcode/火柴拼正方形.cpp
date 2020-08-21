���ǵ�ͯ����������СŮ���������ڣ���֪��СŮ���ж��ٸ�������ҳ�һ����ʹ�����л��ƴ��һ�������εķ����������۶ϻ�񣬿��԰ѻ����������������ÿ�����Ҫ�õ���

����ΪСŮ��ӵ�л�����Ŀ��ÿ��������䳤�ȱ�ʾ�������Ϊ�Ƿ��������еĻ��ƴ�������Ρ�

ʾ��?1:

����: [1,1,2,2,2]
���: true

����: ��ƴ��һ���߳�Ϊ2�������Σ�ÿ���������
ʾ��?2:

����: [3,3,3,3,4]
���: false

����: ���������л��ƴ��һ�������Ρ�
ע��:

�����Ļ�񳤶Ⱥ���?0?��?10^9֮�䡣
�������ĳ��Ȳ�����15��

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false;

        int sum = 0;
        for(auto& num : nums)
            sum += num;
        
        if((sum / 4) * 4 != sum)    return false;
        sort(nums.begin(),nums.end(),[](const int a,const int b)->bool{
            return a > b;
        });
        return dfs(nums,0,n,0,0,0,0,sum/4);
    }

    bool dfs(vector<int>& nums,int idx,int n,int l1,int l2,int l3,int l4,int len)
    {
        if(idx == n)
        {
            if(l1 == l2 && l2 == l3 && l3 == l4 && l4 == len)   return true;
            return false;
        }

        if(l1 > len || l2 > len || l3 > len || l4 > len)    return false;

        return dfs(nums,idx+1,n,l1+nums[idx],l2,l3,l4,len) ||
            dfs(nums,idx+1,n,l1,l2+nums[idx],l3,l4,len) ||
            dfs(nums,idx+1,n,l1,l2,l3+nums[idx],l4,len) ||
            dfs(nums,idx+1,n,l1,l2,l3,l4+nums[idx],len);  
    }
};

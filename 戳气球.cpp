�� n �����򣬱��Ϊ0 �� n-1��ÿ�������϶�����һ�����֣���Щ���ִ�������?nums?�С�

����Ҫ����������е����������������� i ���Ϳ��Ի��?nums[left] * nums[i] * nums[right]?��Ӳ�ҡ�?�����?left?��?right?�����?i?���ڵ������������š�ע�⵱����������� i ������?left?������?right?�ͱ�������ڵ�����

�����ܻ��Ӳ�ҵ����������

˵��:

����Լ���?nums[-1] = nums[n] = 1����ע�����ǲ�����ʵ���ڵ����Բ����ܱ����ơ�
0 �� n �� 500, 0 �� nums[i] �� 100
ʾ��:

����: [3,1,5,8]
���: 167 
����: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
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

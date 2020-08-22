���� 4 ��д�� 1 �� 9 ���ֵ��ơ�����Ҫ�ж��Ƿ���ͨ��?*��/��+��-��(��)?������õ� 24��

ʾ�� 1:

����: [4, 1, 8, 7]
���: True
����: (8-4) * (7-1) = 24
ʾ�� 2:

����: [1, 2, 1, 2]
���: False
ע��:

���������?/?��ʾʵ���������������������������� 4 / (1 - 2/3) = 12 ��
ÿ����������������������㡣�ر������ǲ�����?-?��ΪһԪ����������磬[1, 1, 1, 1]?��Ϊ����ʱ�����ʽ?-1 - 1 - 1 - 1?�ǲ�����ġ�

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> tmp;
        for(int i = 0; i < 4; i++)
            tmp.push_back((double)nums[i]);

        return dfs(tmp);
    }

    bool dfs(vector<double>& nums)
    {
        int n = nums.size();
        if(n == 0)    return false;
        if(n == 1)    return fabs(nums[0] - 24) < 1e-6;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(i == j)  continue;
                vector<double> tmp;
                for(int k = 0; k < n; k++)
                    if(k != i && k != j)    tmp.push_back(nums[k]);

                for(int k = 0; k < 4; k++)
                {
                    if(k == 3 && fabs(nums[j]) < 1e-6 )    continue;
                    if((k == 0 || k == 2) && i > j) continue;

                    double num = check(nums[i],nums[j],k);
                    tmp.push_back(num);
                    if(dfs(tmp))    return true;
                    tmp.pop_back();
                }   
            }
            

        return false;
    }

    double check(double a,double b,int oper)
    {
        if(oper == 0)   return a+b;

        if(oper == 1)   return a-b;

        if(oper == 2)   return a*b;

        return a/b;
    }
};

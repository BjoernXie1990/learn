//����һ���������� cost ��һ������ target �����㷵���������¹�����Եõ��� ��� ������

//����ǰ������һ����λ��i + 1���ĳɱ�Ϊ cost[i] ��cost �����±�� 0 ��ʼ����
//�ܳɱ�����ǡ�õ��� target ��
//��ӵ���λ��û������ 0 ��
//���ڴ𰸿��ܻ�ܴ��������ַ�����ʽ���ء�

//�����������Ҫ���޷��õ��κ����������㷵�� "0" ��
//ʾ�� 1��

//���룺cost = [4,3,2,5,6,7,2,5,5], target = 9
//�����"7772"
//���ͣ������λ '7' �ĳɱ�Ϊ 2 �������λ '2' �ĳɱ�Ϊ 3 ������ "7772" �Ĵ���Ϊ 2*3+ 3*1 = 9 �� "997" Ҳ������Ҫ������֣��� "7772" �ǽϴ�����֡�
// ����     �ɱ�
//  1  ->   4
//  2  ->   3
//  3  ->   2
//  4  ->   5
//  5  ->   6
//  6  ->   7
//  7  ->   2
//  8  ->   5
//  9  ->   5

class Solution {
public:
    
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target+1);
        for(int i = 0; i <= target; i++)
        {
            if(i != 0 && dp[i]=="") continue;
            
            for(int j = 1; j <= 9; j++)
            {
                if(i + cost[j-1] > target) continue;
                auto tmp = dp[i] + to_string(j);
                dp[i + cost[j-1]] = FunB(dp[i + cost[j-1]], tmp) ? dp[i + cost[j-1]] : tmp;
            }
        }
        
        return dp.back()=="" ? "0":dp.back();
    }
    
    bool FunB(string& l,string& r)
    {
        if(l.size() != r.size())
            return l.size() > r.size();
        
        return strcmp(l.c_str(),r.c_str()) > 0;
    }
};

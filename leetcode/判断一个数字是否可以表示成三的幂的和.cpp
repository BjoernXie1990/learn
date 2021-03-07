class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> f;
        int num = 1;
        while(num <= n) {
            f.push_back(num);
            num *= 3;
        }
        
        
        
        return dfs(f,0,n);
    }
    
    bool dfs(vector<int>& f,int id,int n) {
        if(n < 0) return false;
        if(n == 0) return true;
        
        for(int i = id; i < f.size(); i++) {
            n -= f[i];
            if(dfs(f,i + 1,n)) return true;
            n += f[i];
        }
        
        return false;
    }
};


class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n) {
            if(n % 3 == 2) 
                return false;
            n /= 3; 
        }

        return true;
    }
};


����һ������?n?���������Խ�?n?��ʾ�����ɸ���ͬ��������֮�ͣ����㷵��?true?�������뷵�� false?��

����һ������ y?������������� x?���� y == 3x?�����ǳ�������� y?�������ݡ�

?

ʾ�� 1��

���룺n = 12
�����true
���ͣ�12 = 31 + 32
ʾ�� 2��

���룺n = 91
�����true
���ͣ�91 = 30 + 32 + 34
ʾ�� 3��

���룺n = 21
�����false
?

��ʾ��

1 <= n <= 107

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/check-if-number-is-a-sum-of-powers-of-three
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

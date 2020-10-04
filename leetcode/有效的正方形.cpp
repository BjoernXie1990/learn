class Solution {
public:
    using key = pair<int,int>;
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> st;
        vector<key> arr{{p1[0],p1[1]}, {p2[0],p2[1]}, {p3[0],p3[1]}, {p4[0],p4[1]} };
        for(int i = 0; i < 4; i++) 
            for(int j = i + 1; j < 4; j++) {
                int num = check(arr[i],arr[j]);
                if(num == 0) return false;
                st.insert(num);
            }
               
        
        return st.size() == 2;
    }

    int check(const key& a,const key& b) {
        int x = abs(a.first - b.first);
        int y = abs(a.second - b.second);

        return x*x + y*y;
    }
};

������ά�ռ����ĵ�����꣬�����ĵ��Ƿ���Թ���һ�������Ρ�

һ��������꣨x��y����һ�����������������������ʾ��

ʾ��:

����: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
���: True
?

ע��:

���������������� [-10000��10000] ��Χ�ڡ�
һ����Ч�����������ĸ��ȳ����������ĸ��Ƚǣ�90�Ƚǣ���
�����û��˳��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/valid-square
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

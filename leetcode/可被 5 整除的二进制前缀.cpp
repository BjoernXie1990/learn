class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0;
        vector<bool> res;
        for(auto& e : A) {
            num = (num * 2 + e) % 5;
            if(num == 0) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};

����������?0?��?1?��ɵ����� A�����Ƕ���?N_i����?A[0] ��?A[i]?�ĵ� i?�������鱻����Ϊһ�������������������Чλ�������Чλ����

���ز���ֵ�б�?answer��ֻ�е�?N_i?���Ա� 5?����ʱ����?answer[i] Ϊ?true������Ϊ false��

?

ʾ�� 1��

���룺[0,1,1]
�����[true,false,false]
���ͣ�
��������Ϊ 0, 01, 011��Ҳ����ʮ�����е� 0, 1, 3 ��ֻ�е�һ�������Ա� 5 ��������� answer[0] Ϊ�档
ʾ�� 2��

���룺[1,1,1]
�����[false,false,false]
ʾ�� 3��

���룺[0,1,1,1,1,1]
�����[true,false,false,false,true,false]
ʾ��?4��

���룺[1,1,1,0,1]
�����[false,false,false,false,false]
?

��ʾ��

1 <= A.length <= 30000
A[i] Ϊ?0?��?1
ͨ������23,449�ύ����46,072

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/binary-prefix-divisible-by-5
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

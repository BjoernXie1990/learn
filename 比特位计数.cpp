����һ���Ǹ�����?num������?0 �� i �� num ��Χ�е�ÿ������?i?����������������е� 1 ����Ŀ����������Ϊ���鷵�ء�

ʾ�� 1:

����: 2
���: [0,1,1]
ʾ��?2:

����: 5
���: [0,1,1,2,1,2]
����:

����ʱ�临�Ӷ�ΪO(n*sizeof(integer))�Ľ��ǳ����ס��������������ʱ��O(n)����һ��ɨ��������
Ҫ���㷨�Ŀռ临�Ӷ�ΪO(n)��
���ܽ�һ�����ƽⷨ��Ҫ����C++���κ����������в�ʹ���κ����ú������� C++ �е�?__builtin_popcount����ִ�д˲�����


class Solution {
public:
    vector<int> countBits1(int num) {
        vector<int> ans(num+1,0);

        for(int i = 1; i <= num; i++)
            ans[i] = ans[i & (i-1)] + 1;
        
        return ans;
    }


    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);

        //�������ȼ�����
        for(int i = 1; i <= num; i++)
            ans[i] = ans[i >> 1] + (i&1);
        
        return ans;
    }
};

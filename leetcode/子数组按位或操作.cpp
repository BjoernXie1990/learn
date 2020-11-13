class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        int maxNum = 0;
        for(int i = 0; i < n; i++) maxNum |= A[i];  //�������ֵ

        unordered_set<int> hash;    // ȥ��
        hash.insert(maxNum);
        for(int i = 0; i < n; i++) {
            int cur = 0;
            for(int j = i; j >= 0 && cur != maxNum; j--) {
                cur |= A[j];
                if(hash.find(cur) == hash.end()) hash.insert(cur);
            }
        }

        return hash.size();
    }
};

������һ���Ǹ���������?A��

����ÿ���������ģ�������?B =?[A[i], A[i+1], ..., A[j]] ��?i <= j�������Ƕ�?B?�е�ÿ��Ԫ�ؽ��а�λ���������ý��?A[i] | A[i+1] | ... | A[j]��

���ؿ��ܽ���������� ����γ��ֵĽ�������մ��н�����һ�Ρ���

?

ʾ�� 1��

���룺[0]
�����1
���ͣ�
ֻ��һ�����ܵĽ�� 0 ��
ʾ�� 2��

���룺[1,1,2]
�����3
���ͣ�
���ܵ�������Ϊ [1]��[1]��[2]��[1, 1]��[1, 2]��[1, 1, 2]��
�����Ľ��Ϊ 1��1��2��1��3��3 ��
������Ψһֵ�����Դ��� 3 ��
ʾ��?3��

���룺[1,2,4]
�����6
���ͣ�
���ܵĽ���� 1��2��3��4��6���Լ� 7 ��
?

��ʾ��

1 <= A.length <= 50000
0 <= A[i] <= 10^9

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/bitwise-ors-of-subarrays
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

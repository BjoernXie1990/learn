class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n,0);

        for(int i = 0, cur = 1; i < n; i++) {
            ans[i] = cur;
            cur *= a[i];
        }

        for(int i = n - 1, cur = 1; i >= 0; i--) {
            ans[i] *= cur;
            cur *= a[i];
        }

        return ans;
    }
};


����һ������ A[0,1,��,n-1]���빹��һ������ B[0,1,��,n-1]������ B �е�Ԫ�� B[i]=A[0]��A[1]������A[i-1]��A[i+1]������A[n-1]������ʹ�ó�����

?

ʾ��:

����: [1,2,3,4,5]
���: [120,60,40,30,24]
?

��ʾ��

����Ԫ�س˻�֮�Ͳ������ 32 λ����
a.length <= 100000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

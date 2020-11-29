class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = accumulate(array1.begin(),array1.end(),0);
        int sum2 = accumulate(array2.begin(),array2.end(),0);
        
        vector<int> ans;
        if(sum1 == sum2 || (sum1 + sum2) % 2 == 1) return ans;

        int diff = (sum2 - sum1) / 2;   // array2 ����� array1 ��ƫ��
        sort(array2.begin(),array2.end());
        for(auto& e : array1) {
            int le = 0;
            int ri = array2.size() - 1;
            while(le < ri) {
                int mid = le + ri >> 1;
                if(array2[mid] >= diff + e) ri = mid; 
                else le = mid + 1;
            }
            if(le != array2.size() && array2[le] == e + diff) {
                ans = {e,array2[le]};
                break;
            }
        } 

        return ans;
    }
};


���������������飬�뽻��һ����ֵ��ÿ��������ȡһ����ֵ����ʹ��������������Ԫ�صĺ���ȡ�

����һ�����飬��һ��Ԫ���ǵ�һ��������Ҫ������Ԫ�أ��ڶ���Ԫ���ǵڶ���������Ҫ������Ԫ�ء����ж���𰸣���������һ�����ɡ�����������������ֵ�����ؿ����顣

ʾ��:

����: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
���: [1, 3]
ʾ��:

����: array1 = [1, 2, 3], array2 = [4, 5, 6]
���: []
��ʾ��

1 <= array1.length, array2.length <= 100000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-swap-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int num = 0;
        int n = encoded.size();
        for(int i = 1; i <= n + 1; i++) 
            num ^= i;
        for(int i = 1; i < n; i += 2) 
            num ^= encoded[i];
        
        vector<int> res(n+1);
        res[0] = num;
        for(int i = 1; i <= n; i++)
            res[i] = encoded[i - 1] ^ res[i - 1];
        return res;
    }
};

����һ����������?perm?������ǰ?n?�������������У���?n?�Ǹ� ����?��

�������ܳ���һ������Ϊ n - 1?����������?encoded?������?encoded[i] = perm[i] XOR perm[i + 1]?���ȷ�˵�����?perm = [1,3,2]?����ô?encoded = [2,1]?��

����?encoded?���飬���㷵��ԭʼ����?perm?����Ŀ��֤�𰸴�����Ψһ��

?

ʾ�� 1��

���룺encoded = [3,1]
�����[1,2,3]
���ͣ���� perm = [1,2,3] ����ô encoded = [1 XOR 2,2 XOR 3] = [3,1]
ʾ�� 2��

���룺encoded = [6,5,4,6]
�����[2,4,1,5,3]
?

��ʾ��

3 <= n <?105
n?��������
encoded.length == n - 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/decode-xored-permutation
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

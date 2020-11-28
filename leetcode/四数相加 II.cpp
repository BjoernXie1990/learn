class Solution {
public:
    typedef long long LL;
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<LL,int> mp;
        for(auto& a : A)    
            for(auto& b : B) mp[a + b]++;

        int cnt = 0;
        for(auto& c : C)    
            for(auto& d : D) cnt += mp[-c-d];
        return cnt;
    }
};


�����ĸ����������������б�?A , B , C , D ,�����ж��ٸ�Ԫ�� (i, j, k, l)?��ʹ��?A[i] + B[j] + C[k] + D[l] = 0��

Ϊ��ʹ����򵥻������е� A, B, C, D ������ͬ�ĳ���?N���� 0 �� N �� 500 �����������ķ�Χ�� -228 �� 228 - 1 ֮�䣬���ս�����ᳬ��?231 - 1 ��

����:

����:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

���:
2

����:
����Ԫ������:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/4sum-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

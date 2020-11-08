class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> hash;
        int ans = 0;

        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(hash.count(arr[i] - difference) > 0) {
                hash[arr[i]] = hash[arr[i] - difference] + 1;
            } else {
                hash[arr[i]] = 1;
            }

            ans = max(ans,hash[arr[i]]);
        }

        return ans;
    }
};


����һ����������?arr?��һ������?difference�������ҳ�?arr?����������Ԫ��֮��Ĳ���ڸ���?difference?�ĵȲ������У�������������ĵȲ������еĳ��ȡ�

?

ʾ�� 1��

���룺arr = [1,2,3,4], difference = 1
�����4
���ͣ���ĵȲ��������� [1,2,3,4]��
ʾ��?2��

���룺arr = [1,3,5,7], difference = 1
�����1
���ͣ���ĵȲ������������ⵥ��Ԫ�ء�
ʾ�� 3��

���룺arr = [1,5,7,8,5,3,4,2,1], difference = -2
�����4
���ͣ���ĵȲ��������� [7,5,3,1]��
?

��ʾ��

1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

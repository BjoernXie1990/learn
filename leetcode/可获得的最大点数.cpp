class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(auto& e : cardPoints) sum += e;
        int le = 0;
        int mid = 0, res = INT_MAX;
        k = cardPoints.size() - k;
        for(int i = 0; i < cardPoints.size(); i++) {
            mid += cardPoints[i];
            if(i >= k) mid -= cardPoints[i - k];
            if(i >= k - 1) res = min(res,mid);
        }
        return sum - res;
    }
};

���ſ��� �ų�һ�У�ÿ�ſ��ƶ���һ����Ӧ�ĵ������������������� cardPoints ������

ÿ���ж�������Դ��еĿ�ͷ����ĩβ��һ�ſ��ƣ���������������� k �ſ��ơ�

��ĵ����������õ����е����п��Ƶĵ���֮�͡�

����һ���������� cardPoints ������ k�����㷵�ؿ��Ի�õ���������

?

ʾ�� 1��

���룺cardPoints = [1,2,3,4,5,6,1], k = 3
�����12
���ͣ���һ���ж��������������ƣ���ĵ������� 1 �����ǣ��������ұߵĿ��ƽ��������Ŀɻ�õ��������Ų��������ұߵ������ƣ����յ���Ϊ 1 + 6 + 5 = 12 ��
ʾ�� 2��

���룺cardPoints = [2,2,2], k = 2
�����4
���ͣ����������������ſ��ƣ��ɻ�õĵ������� 4 ��
ʾ�� 3��

���룺cardPoints = [9,7,7,9,7,7,9], k = 7
�����55
���ͣ�������������п��ƣ����Ի�õĵ���Ϊ���п��Ƶĵ���֮�͡�
ʾ�� 4��

���룺cardPoints = [1,1000,1], k = 1
�����1
���ͣ����޷��õ��м����ſ��ƣ����Կ��Ի�õ�������Ϊ 1 �� 
ʾ�� 5��

���룺cardPoints = [1,79,80,1,1,1,200,1], k = 3
�����202
?

��ʾ��

1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

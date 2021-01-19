class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        unordered_map<int,int> mp;
        for(auto& e : r) {
            mp[min(e[0],e[1])]++;
        }
        int res = 0;
        int num = 0;
        for(auto& e : mp) {
            if(e.first > num) {
                num = e.first;
                res = e.second;
            }
        }
        
        return res;
    }
};
����һ������ rectangles ������ rectangles[i] = [li, wi] ��ʾ�� i �����εĳ���Ϊ li �����Ϊ wi ��

������� k ͬʱ���� k <= li �� k <= wi ���Ϳ��Խ��� i �������гɱ߳�Ϊ k �������Ρ����磬���� [4,6] �����гɱ߳����Ϊ 4 �������Ρ�

�� maxLen Ϊ���ԴӾ�������?rectangles �зֵõ��� ��������� �ı߳���

���ؿ����г��߳�Ϊ maxLen �������εľ��� ��Ŀ ��

?

ʾ�� 1��

���룺rectangles = [[5,8],[3,9],[5,12],[16,5]]
�����3
���ͣ��ܴ�ÿ���������г�����������α߳��ֱ��� [5,3,5,5] ��
��������εı߳�Ϊ 5 �������� 3 �������зֵõ���
ʾ�� 2��

���룺rectangles = [[2,3],[3,7],[4,3],[3,7]]
�����3
?

��ʾ��

1 <= rectangles.length <= 1000
rectangles[i].length == 2
1 <= li, wi <= 109
li != wi

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-rectangles-that-can-form-the-largest-square
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

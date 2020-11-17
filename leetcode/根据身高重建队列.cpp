class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int>& a,const vector<int>& b)->bool{
            if(a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int n = people.size();
        vector<vector<int> > ans;
        for(int i = 0; i < n; i++) {
            ans.insert(ans.begin() + people[i][1],people[i]);
        }

        return ans;
    }
};

�����д���˳���һȺ��վ��һ�����С� ÿ������һ��������(h, k)��ʾ������h������˵���ߣ�k�����������ǰ������ߴ��ڻ����h�������� ��дһ���㷨���ؽ�������С�

ע�⣺
����������1100�ˡ�

ʾ��

����:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

���:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/queue-reconstruction-by-height
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

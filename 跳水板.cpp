������ʹ��һ��ľ�彨����ˮ�塣���������͵�ľ�壬���г��Ƚ϶̵�ľ�峤��Ϊshorter�����Ƚϳ���ľ�峤��Ϊlonger�����������ʹ��k��ľ�塣��дһ��������������ˮ�����п��ܵĳ��ȡ�

���صĳ�����Ҫ��С�������С�

ʾ����

���룺
shorter = 1
longer = 2
k = 3
����� {3,4,5,6}
��ʾ��

0 < shorter <= longer
0 <= k <= 100000

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0)  return {};
        unordered_set<int> ans;
        
        for(int i = 0; i <= k; i++)
            ans.insert(shorter * i + longer * (k - i));

        vector<int> ret;
        for(auto& num : ans)
            ret.push_back(num);
        sort(ret.begin(),ret.end());
        return ret;
    }
};

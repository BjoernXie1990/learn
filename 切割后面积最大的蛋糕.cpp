//���ε���ĸ߶�Ϊ h �ҿ��Ϊ w������������������ horizontalCuts �� verticalCuts������ horizontalCuts[i] �ǴӾ��ε��ⶥ������? i ��ˮƽ�пڵľ��룬���Ƶأ� verticalCuts[j] �ǴӾ��ε������ൽ�� j ����ֱ�пڵľ��롣

//���㰴���� horizontalCuts �� verticalCuts ���ṩ��ˮƽ����ֱλ���и�������ҳ� ������ ���Ƿݵ��⣬�������� ��� �����ڴ𰸿�����һ���ܴ�����֣������Ҫ������� 10^9 + 7 ȡ��󷵻ء�

//?



class Solution {
public:
    int maxArea(int h, int w, vector<int>& hv, vector<int>& vv) {
        sort(hv.begin(),hv.end());
        sort(vv.begin(),vv.end());
        hv.insert(hv.begin(),0);
        hv.push_back(h);
        vv.insert(vv.begin(),0);
        vv.push_back(w);
        int lenh = hv.size();
        int lenv = vv.size();
        
        int ans = 0;
        int maxh = 0;
        for(int i = 1; i < lenh; i++)
            maxh = max(hv[i]-hv[i-1],maxh);
        
        int maxv = 0;
        for(int i = 1; i < lenv; i++)
            maxv = max(vv[i]-vv[i-1],maxv);
        
        ans = ((long long)maxh * (long long)maxv) % 1000000007;
        return ans;
    }
};

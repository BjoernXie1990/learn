class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int f[100];
        memset(f,0x00,sizeof f);
        int res = 0;
        for(auto& e : dominoes) {
            if(e[0] > e[1]) swap(e[0],e[1]);
            int idx = e[0] * 10 + e[1];
            res += f[idx] ++;
        }

        return res;
    }
};


����һ����һЩ����ŵ������ɵ��б�?dominoes��

�������ĳһ�Ŷ���ŵ���ƿ���ͨ����ת 0?�Ȼ� 180 �ȵõ���һ�Ŷ���ŵ���ƣ����Ǿ���Ϊ���������ǵȼ۵ġ�

��ʽ�ϣ�dominoes[i] = [a, b]?��?dominoes[j] = [c, d]?�ȼ۵�ǰ����?a==c?��?b==d������?a==d ��?b==c��

��?0 <= i < j < dominoes.length?��ǰ���£��ҳ�����?dominoes[i] ��?dominoes[j]?�ȼ۵Ĺ��ƶ� (i, j) ��������

?

ʾ����

���룺dominoes = [[1,2],[2,1],[3,4],[5,6]]
�����1
?

��ʾ��

1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

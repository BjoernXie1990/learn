n?�ʺ������о�������ν� n?���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������



��ͼΪ 8 �ʺ������һ�ֽⷨ��

����һ������ n������ n �ʺ�ͬ�Ľ��������������

ʾ��:

����: 4
���: 2
����: 4 �ʺ������������������ͬ�Ľⷨ��
[
?[".Q..", ?// �ⷨ 1
? "...Q",
? "Q...",
? "..Q."],

?["..Q.", ?// �ⷨ 2
? "Q...",
? "...Q",
? ".Q.."]
]
?

��ʾ��

�ʺ��ǹ��������е����ӣ���ζ�Ź��������ӡ��ʺ�ֻ��һ���£��Ǿ��ǡ����ӡ��������������ԳԵ�����ʱ����Ѹ�ٳ���ȥ�Ե����ӡ���Ȼ�����ᡢ����б������һ�� N-1 �����ɽ����ˡ��������� �ٶȰٿ� - �ʺ� ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/n-queens-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class Solution {
public:
    int col[10];
    int vis[10];
    int ans = 0;

    bool check(int n) {
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(abs(i - j) == abs(col[i] - col[j])) return false;
        return true;
    }

    void dfs(int idx,int n) {
        if(idx == n) {
            if(check(n) == true) ans ++;
            return ;
        }

        for(int i = 0 ; i < n; i++) {
            if(vis[i] == 1) continue;
            col[idx] = i;
            vis[i] = 1;
            dfs(idx + 1,n);
            vis[i] = 0;
            col[idx] = 0;
        }
    }

    int totalNQueens(int n) {
        dfs(0,n);

        return ans;
    }
};

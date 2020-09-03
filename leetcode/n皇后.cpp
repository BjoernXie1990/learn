n?�ʺ������о�������ν� n?���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������



��ͼΪ 8 �ʺ������һ�ֽⷨ��

����һ������ n���������в�ͬ��?n?�ʺ�����Ľ��������

ÿһ�ֽⷨ����һ����ȷ��?n �ʺ���������ӷ��÷������÷����� 'Q' �� '.' �ֱ�����˻ʺ�Ϳ�λ��

?

ʾ����

���룺4
�����[
 [".Q..",  // �ⷨ 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // �ⷨ 2
  "Q...",
  "...Q",
  ".Q.."]
]
����: 4 �ʺ��������������ͬ�Ľⷨ��


class Solution {
public:
    vector<int> col;
    vector<bool> vis;
    vector<vector<string> > ans;
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n,0);
        vis.resize(n,false);

        dfs(0,n);

        return ans;
    }

    void dfs(int idx,int n){
        if(idx == n){
            check(n);
            return ;
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == true)  continue;
            col[i] = idx;
            vis[i] = true;
            dfs(idx+1,n);
            vis[i] = false;
        }
    }

    void check(int n){
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(abs(i-j) == abs(col[i] - col[j]))    return;

        vector<string> tmp;

        for(int i = 0; i < n; i++){
            string str("");
            for(int j = 0; j < n; j++){
                if(j == col[i]) str += 'Q';
                else str += '.';
            }
            tmp.push_back(str);
        }
        ans.push_back(tmp);
    }
};

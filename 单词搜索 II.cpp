//
//����һ����ά����?board?��һ���ֵ��еĵ����б� words���ҳ�����ͬʱ�ڶ�ά������ֵ��г��ֵĵ��ʡ�

//���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ��һ�������в������ظ�ʹ�á�

//ʾ��:

//����: 
//words = ["oath","pea","eat","rain"] and board =
//[
//  ['o','a','a','n'],
//  ['e','t','a','e'],
//  ['i','h','k','r'],
//  ['i','f','l','v']
//]

//���:?["eat","oath"]
//˵��:
//����Լ����������붼��Сд��ĸ a-z?��ɡ�

//��ʾ:

//����Ҫ�Ż������㷨��ͨ�������������Ĳ��ԡ����ܷ����ֹͣ���ݣ�
//�����ǰ���ʲ����������е��ʵ�ǰ׺�У����������ֹͣ���ݡ�ʲô�������ݽṹ������Ч��ִ�������Ĳ�����ɢ�б��Ƿ���У�Ϊʲô�� ǰ׺����Σ��������ѧϰ���ʵ��һ��������ǰ׺�������Ȳ鿴������⣺ ʵ��Trie��ǰ׺������


class Solution {
public:
    const static int N = 100010;
    int son[N][26];
    int idx;
    string key[N];
    int row,col;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto& eoch : words) insert(eoch);
        vector<string> ret;
        row = board.size();
        col = board[0].size();
        vector<vector<int>> visit(row,vector<int> (col,0));

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                visit[i][j] = 1;
                dfs(board,visit,i,j,0,ret);
                visit[i][j] = 0;
            }
        return ret;
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = s;
        //cout<<key[p]<<' '<<p<<endl;
    }

    void dfs(vector<vector<char> >& board,vector<vector<int> >& visit,int x,int y,int p,vector<string>& ret)
    {
        static int dir[4][2] = {-1,0,0,-1,1,0,0,1};
        int u = board[x][y] - 'a';
        //cout<<p<<' '<<board[x][y]<<' ';
        if(!son[p][u]) return;
        p = son[p][u];
        //cout<<p<<' '<<board[x][y]<<' ';
        if(key[p] != "")
        {
            ret.push_back(key[p]);
            key[p] = "";//��ֹ���ֶ��  [["a","a"]]  ["a"]
        }

        for(int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];

            if(tx < 0 || tx >= row || ty < 0 || ty >= col || visit[tx][ty])
                continue;
            
            visit[tx][ty] = 1;
            dfs(board,visit,tx,ty,p,ret);
            visit[tx][ty] = 0;
        }
    }
};

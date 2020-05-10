//����һ����?n?���ڵ�����������ڵ���Ϊ?0?��?n-1?����������һЩ�ڵ���ƻ����ͨ�����ϵ�һ���ߣ���Ҫ���� 1 ���ӡ����?�ڵ� 0?���������㷵��������Ҫ�����룬�����ռ�������ƻ�������ص��ڵ� 0 ��

//�������ı���?edges?����������?edges[i] = [fromi, toi]?����ʾ��һ��������?from?��?toi ���������⣬����һ����������?hasApple ������?hasApple[i] = true?����ڵ�?i?��һ��ƻ�������򣬽ڵ�?i?û��ƻ����

//?




class Solution {
public:
    struct edge
    {
        int to;
        int next;
    };
    
    edge e[200005];
    int head[200005];
    int f[200005];
    int ans = 0;
    
    void add(int from,int to,int len)
    {
        e[len].to = to;
        e[len].next = head[from];
        head[from] = len;
    }
    
    void dfs(vector<int>& visit,int x)
    {
        //�����Ե�ǰ��Ϊ��㣬���Դﵽ�����б�
        for(int i = head[x]; i; i = e[i].next)
            if(e[i].to != f[x])
            {
                f[e[i].to] = x;
                dfs(visit,e[i].to);
                visit[x] += visit[e[i].to];
            }
        
        //��¼���Ե���ĵ�
        if(visit[x]) ans++;
    }
    
    int minTime1(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int len = 0;
        for(auto& eoch : edges)
        {
            add(eoch[1],eoch[0],len++);
            add(eoch[0],eoch[1],len++);
        }
            
        vector<int> visit(200005);
        for(int i = 0; i < n; i++)
            visit[i]= hasApple[i];
        
        dfs(visit,0);
        
        return max(ans,1)*2 - 2;
    }
	
	//������� 
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int> > map(n);

        for(auto& e : edges)
        {
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }

        vector<bool> visit(n);
        PostOrder(map,0,hasApple,visit);
        return max(ans,0) * 2;
    }

    bool PostOrder(vector<vector<int> >& map,int index,vector<bool>& hasApple,vector<bool>& visit)
    {
        visit[index] = true;
        bool flag = hasApple[index];

        for(auto son : map[index])
        {
            if(visit[son]) continue;

            if(PostOrder(map,son,hasApple,visit))
            {
                flag = true;
                ans++;
            }
        }

        return flag;
    }
  
    
};

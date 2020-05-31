//n �����У��� 0 �� n-1 ��ţ���乲�� n-1 ��·�ߡ���ˣ�Ҫ����������ͬ����֮������ֻ��Ψһһ��·�߿ɹ�ѡ��·�����γ�һ��������ȥ�꣬��ͨ���䲿�������¹滮·�ߣ��Ըı佻ͨӵ�µ�״����

//·���� connections ��ʾ������ connections[i] = [a, b] ��ʾ�ӳ��� a �� b ��һ������·�ߡ�

//���꣬���� 0 ����ٰ�һ�����ͱ������ܶ��οͶ���ǰ������ 0 ��

//����������¹滮·�߷���ʹÿ�����ж����Է��ʳ��� 0 ��������Ҫ����������С·������

//��Ŀ���� ��֤ ÿ�����������¹滮·�߷�����ܵ������ 0 ��

//?

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        unordered_map<int,set<int> > map;
        unordered_map<int,set<int> > unmap;
        for(auto& eoch : c)
        {
            map[eoch[0]].insert(eoch[1]);//from --�� to
            unmap[eoch[1]].insert(eoch[0]);//to --�� from
        }
        
        queue<int> que;
        que.push(0);
        vector<int> visit(n,0);//�ж�����·ѡ����
        visit[0]=1;

        int ans = 0;
        
        while(!que.empty())
        {
            int size = que.size();
            
            for(int i = 0; i < size; i++)
            {
                int f = que.front();
                que.pop();
                
                //�����޸ĵ�·
                for(auto& eoch : unmap[f])
                {
                    if(visit[eoch]) continue;
                    que.push(eoch);
                    visit[eoch]=1;
                }
                
                //��Ҫ�޸�
                for(auto& eoch : map[f])
                {
                    if(visit[eoch]) continue;
                    que.push(eoch);
                    visit[eoch]=1;
                    ans++;
                }
                
            }
            
        }
        return ans;
    }
};

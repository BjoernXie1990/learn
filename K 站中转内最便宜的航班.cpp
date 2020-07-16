�� n ������ͨ�� m ���������ӡ�ÿ�����඼�ӳ��� u ��ʼ���Լ۸� w �ִ� v��

���ڸ������еĳ��кͺ��࣬�Լ��������� src ��Ŀ�ĵ� dst������������ҵ��� src �� dst ��ྭ�� k?վ��ת������˵ļ۸� ���û��������·�ߣ������ -1��

?

ʾ�� 1��

����: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
���: 200
����: 
���к���ͼ����


�ӳ��� 0 ������ 2 �� 1 վ��ת���ڵ�����˼۸��� 200����ͼ�к�ɫ��ʾ��
ʾ�� 2��

����: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
���: 500
����: 
���к���ͼ����


�ӳ��� 0 ������ 2 �� 0 վ��ת���ڵ�����˼۸��� 500����ͼ����ɫ��ʾ��
?

��ʾ��

n ��Χ�� [1, 100]�����б�ǩ�� 0 �� n - 1.
����������Χ�� [0, n * (n - 1) / 2].
ÿ������ĸ�ʽ (src, dst, price).
ÿ������ļ۸�Χ�� [1, 10000].
k ��Χ�� [0, n - 1].
����û���ظ����Ҳ����ڻ�·

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int> > > map;
        for(auto& eoch : flights)
            map[eoch[0]].push_back({eoch[1],eoch[2]});
        
        queue<pair<int,int> > que;
        que.push({src,0});
        int m = k;
        int ans = INT_MAX;
        vector<int> visit(n,INT_MAX);
        visit[src] = 0;

        while(m-- >= 0 && !que.empty())
        {
            int size = que.size();
            
            for(int i = 0; i < size; i++)
            {
                auto f = que.front();
                que.pop();

                for(auto& eoch : map[f.first])
                {
                    int next = eoch.first;
                    int money = f.second + eoch.second;
                    if(visit[next] < money) continue;

                    visit[next] = money;
                    if(next == dst)
                        ans = min(ans,money);
                    else
                        que.push({next,money});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

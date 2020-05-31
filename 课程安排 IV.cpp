//���ܹ���Ҫ�� n?�ſΣ��γ̱������Ϊ 0?�� n-1?��

//�еĿλ���ֱ�ӵ����޿γ̣�����������Ͽγ�?0 ����������Ͽγ� 1 ����ô���� [1,0]?���Ե���ʽ�������޿γ����ԡ�

//����γ����� n?��һ��ֱ�����޿γ������б�?prerequisite ��һ����ѯ���б�?queries?��

//����ÿ����ѯ�� queries[i]?�����ж�?queries[i][0]?�Ƿ���?queries[i][1]?�����޿γ̡�

//�뷵��һ������ֵ�б��б���ÿ��Ԫ�����ηֱ��Ӧ queries?ÿ����ѯ�Ե��жϽ����

//ע�⣺����γ�?a?�ǿγ�?b?�����޿γ��ҿγ�?b?�ǿγ�?c?�����޿γ̣���ô�γ�?a?Ҳ�ǿγ�?c?�����޿γ̡�

//?

//ʾ�� 1��



//���룺n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
//�����[false,true]
//���ͣ��γ� 0 ���ǿγ� 1 �����޿γ̣����γ� 1 �ǿγ� 0 �����޿γ̡�
//ʾ�� 2��

//���룺n = 2, prerequisites = [], queries = [[1,0],[0,1]]
//�����[false,false]
//���ͣ�û�����޿γ̶ԣ�����ÿ�ſγ�֮���Ƕ����ġ�
//ʾ�� 3��



//���룺n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
//�����[true,true]
//ʾ�� 4��

//���룺n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
//�����[false,true]
//ʾ�� 5��

//���룺n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
//�����[true,false,true,false]
//?

//��ʾ��

//2 <= n <= 100
//0 <= prerequisite.length <= (n * (n - 1) / 2)
//0 <= prerequisite[i][0], prerequisite[i][1] < n
//prerequisite[i][0] != prerequisite[i][1]
//���޿γ�ͼ��û�л���
//���޿γ�ͼ��û���ظ��ıߡ�
//1 <= queries.length <= 10^4
//queries[i][0] != queries[i][1]


class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        unordered_map<int,set<int> > map;//����·����from --> to
        unordered_map<int,set<int> > unmap;//����  to --> from
        
        for(auto& eoch : p)
        {
            map[eoch[0]].insert(eoch[1]);
            //����unmap ���в��鼯�ĺϲ�
            //����˵ 1--> 2   ���ǾͿ������ÿ��Ե��� 1 �Ľڵ㣬����2�ڵ��������
            Insert(map,unmap,eoch[0],eoch[1]);
            unmap[eoch[1]].insert(eoch[0]);
        }
        
    
        vector<bool> ans;//��Ҫ���ص�����
        for(auto& eoch : q)
        {
            int flag = false;
            for(auto& to : map[eoch[0]])
                if(to == eoch[1]) 
                {
                    flag = true;
                    break;
                }
            ans.push_back(flag);
        }
        return ans;
    }
    
    void Insert(unordered_map<int,set<int> >& map,unordered_map<int,set<int> >& unmap,int u,int v)
    {
        //���û�е���Դﵽ��ʼ�㣬�ͷ��أ�˵������Ҫ�ɳ�
        if(unmap.find(u) == unmap.end()) return ;
        
        for(auto& eoch : unmap[u])
        {
            //ͬ���ɳڵ�ʱ��ҲҪά������ͼ
            map[eoch].insert(v);
            unmap[v].insert(eoch);
        }
    }
};

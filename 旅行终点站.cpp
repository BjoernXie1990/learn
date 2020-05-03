//��һ��������·ͼ������·ͼ�е�������·������ paths ��ʾ������ paths[i] = [cityAi, cityBi] ��ʾ����·����� cityAi ֱ��ǰ�� cityBi �������ҳ�������е��յ�վ����û���κο���ͨ���������е���·�ĳ��С�

//��Ŀ���ݱ�֤��·ͼ���γ�һ��������ѭ������·�����ֻ����һ�������յ�վ��

//?

//ʾ�� 1��

//���룺paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
//�����"Sao Paulo" 
//���ͣ��� "London" ���������ִ��յ�վ "Sao Paulo" ���������е�·���� "London" -> "New York" -> "Lima" -> "Sao Paulo" ��
//ʾ�� 2��

//���룺paths = [["B","C"],["D","B"],["C","A"]]
//�����"A"
//���ͣ����п��ܵ���·�ǣ�
//"D" -> "B" -> "C" -> "A".?
//"B" -> "C" -> "A".?
//"C" -> "A".?
//"A".?
//��Ȼ�������յ�վ�� "A" ��
//ʾ�� 3��

//���룺paths = [["A","Z"]]
//�����"Z"


class Solution {
public:
    int ans = 0;
    string destCity(vector<vector<string>>& paths) 
    {
        vector<vector<int> > map(205);
        int len = paths.size();
        vector<string> str;
        vector<int> visit(1000,0);
        for(int i = 0; i < len; i++)
        {
            int l = FindPos(str,paths[i][0]);
            int r = FindPos(str,paths[i][1]);
            map[l].push_back(r);
        }
        
        
        dfs(map,str,0,visit);
        return str[ans];
    }
    
    void dfs(vector<vector<int> >& map,vector<string>& str,int index,vector<int>& visit)
    {
        if(map[index].size() == 0)
        {
            ans = index;
            return ;
        }
        for(int i = 0; i < map[index].size(); i++)
        {
            if(!visit[map[index][i]])
            {
                visit[map[index][i]] = 1;
                dfs(map,str,map[index][i],visit);
                visit[map[index][i]] = 0;
            }
        }
    }
    
    int FindPos(vector<string>& str,string& s)
    {
        int i = 0;
        for(i = 0; i < str.size(); i++)
        {
            if(str[i] == s) return i;
        }
        str.push_back(s);
        return i;
    }
};

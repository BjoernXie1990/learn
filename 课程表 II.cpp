//�������ܹ��� n �ſ���Ҫѡ����Ϊ?0?��?n-1��

//��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡�?���磬��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ�?1 ��������һ��ƥ������ʾ����: [0,1]

//�����γ������Լ����ǵ��Ⱦ�������������Ϊ��ѧ�����пγ������ŵ�ѧϰ˳��

//���ܻ��ж����ȷ��˳����ֻҪ����һ�־Ϳ����ˡ����������������пγ̣�����һ�������顣

//ʾ��?1:

//����: 2, [[1,0]] 
//���: [0,1]
//����:?�ܹ��� 2 �ſγ̡�Ҫѧϰ�γ� 1������Ҫ����ɿγ� 0����ˣ���ȷ�Ŀγ�˳��Ϊ [0,1] ��
//ʾ��?2:

//����: 4, [[1,0],[2,0],[3,1],[3,2]]
//���: [0,1,2,3] or [0,2,1,3]
//����:?�ܹ��� 4 �ſγ̡�Ҫѧϰ�γ� 3����Ӧ������ɿγ� 1 �Ϳγ� 2�����ҿγ� 1 �Ϳγ� 2 ��Ӧ�����ڿγ� 0 ֮��
//?    ��ˣ�һ����ȷ�Ŀγ�˳����?[0,1,2,3] ����һ����ȷ��������?[0,2,1,3] ��
//˵��:

//������Ⱦ��������ɱ�Ե�б��ʾ��ͼ�Σ��������ڽӾ���������μ�ͼ�ı�ʾ����
//����Լٶ�������Ⱦ�������û���ظ��ıߡ�

class Solution {
public:
    //dfs
    int num = 0;
    vector<int> findOrder1(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int,vector<int> > map;
        for(auto& eoch : prerequisites)
            map[eoch[1]].push_back(eoch[0]);

        vector<int> visit(numCourses,0);
        vector<int> ret;
     
        for(int i = 0; i < numCourses; i++)
            if(!dfs(map,ret,visit,i)) return {};
        reverse(ret.begin(),ret.end());
        return ret;
    }

    static bool dfs(unordered_map<int,vector<int> >& map,vector<int>& ret,vector<int>& visit,int index)
    {
        //˵�������˻�
        if(visit[index] == 1) return false;
        if(visit[index] == -1) return true;//˵��֮ǰ������
        visit[index] = 1;
        
        for(auto& eoch : map[index])
            if(!dfs(map,ret,visit,eoch)) return false;
        
        visit[index] = -1;
        ret.push_back(index);
        return true;
    }
    

    //��������
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int,vector<int> > map;
        vector<int> idx(numCourses,0);//��¼ÿһ��������
        for(auto& eoch : prerequisites)
        {
            map[eoch[1]].push_back(eoch[0]);
            idx[eoch[0]]++;
        }

        queue<int> que;
        for(int i = 0; i < numCourses; i++)
            if(idx[i] == 0) que.push(i);//���Ϊ0�ĵ����
        vector<int> ret;
        while(!que.empty())
        {
            auto it = que.front();
            que.pop();
            ret.push_back(it);
            for(auto& eoch : map[it])
            {
                idx[eoch]--;
                if(idx[eoch] == 0) que.push(eoch);
            }
        }
        vector<int> tmp;
        return ret.size()==numCourses ? ret :tmp;
    }
};

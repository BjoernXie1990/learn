�����ѧ�ڱ���ѡ�� numCourse �ſγ̣���Ϊ?0?��?numCourse-1 ��

��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡�?���磬��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ���ǣ�[0,1]

�����γ������Լ����ǵ��Ⱦ������������ж��Ƿ����������пγ̵�ѧϰ��

?

ʾ�� 1:

����: 2, [[1,0]] 
���: true
����:?�ܹ��� 2 �ſγ̡�ѧϰ�γ� 1 ֮ǰ������Ҫ��ɿγ� 0���������ǿ��ܵġ�
ʾ�� 2:

����: 2, [[1,0],[0,1]]
���: false
����:?�ܹ��� 2 �ſγ̡�ѧϰ�γ� 1 ֮ǰ������Ҫ�����?�γ� 0������ѧϰ�γ� 0 ֮ǰ���㻹Ӧ����ɿγ� 1�����ǲ����ܵġ�
?

��ʾ��

������Ⱦ��������� ��Ե�б� ��ʾ��ͼ�Σ������� �ڽӾ��� ��������μ�ͼ�ı�ʾ����
����Լٶ�������Ⱦ�������û���ظ��ıߡ�
1 <=?numCourses <= 10^5


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,set<int> > map;
        vector<int> vis(numCourses,0);
        for(auto& eoch : prerequisites)
        {
            map[eoch[1]].insert(eoch[0]);
            vis[eoch[0]]++;
        }
        
        queue<int> que;
        for(int i = 0; i < numCourses; i++)
            if(vis[i] == 0)    que.push(i);
        
        int count = 0;
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            count++;

            for(auto& eoch : map[v])
            {
                vis[eoch]--;
                if(vis[eoch] == 0)  que.push(eoch);
            }
        }

        return count == numCourses;
    }
};

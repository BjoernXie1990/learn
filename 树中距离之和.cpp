//����һ��������ͨ������������ N �����Ϊ 0...N-1 �Ľڵ��Լ� N-1?����?��

//�� i �������ӽڵ�?edges[i][0] �� edges[i][1]?��

//����һ����ʾ�ڵ� i ���������нڵ����֮�͵��б� ans��

//ʾ�� 1:

//����: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
//���: [8,12,6,10,10,10]
//����: 
//����Ϊ����������ʾ��ͼ��
//  0
// / \
//1   2
//   /|\
//  3 4 5

//���ǿ��Լ���� dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5) 
//Ҳ���� 1 + 1 + 2 + 2 + 2 = 8�� ��ˣ�answer[0] = 8���Դ����ơ�
//˵��:?1 <= N <= 10000


class Solution {
public:
    vector<int> dis;        //i��������ӽڵ㵽i�ľ���֮��
    vector<int> res;
    vector<int> children;   //��iΪ�������ĺ��ӽڵ��������������ڵ�
    vector<vector<int> > map;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        map = vector<vector<int>>(N,vector<int>());
        dis = vector<int>(N,0);
        res = vector<int>(N,0);
        children = vector<int>(N,1);

        for(auto& e : edges)
        {
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }

        //����0Ϊ���ڵ�ľ���֮�ͣ�������ֱ������iΪ���ڵ�������ڵ�������
        dfs1(0,-1);
        //cout<<children[2];
        dfs2(N,0,-1);
        return res;
    }

    void dfs1(int index,int father)
    {
        for(auto& child : map[index])
            if(child != father)
            {
                dfs1(child,index);

                children[index] += children[child];
                res[index] += res[child] + children[child];
            }
    }

    //��0���µݹ����Ƴ����������������Ƴ���������
    void dfs2(int n,int index,int father)
    {
        for(auto& child : map[index])
            if(child != father)
            {
                //res[index] ���׽ڵ�����ľ���
                //(n - children[child]) �Ӻ��ӽڵ㵽���׽ڵ�ľ���
                //children[child] child�����ӽڵ�ľ���
                res[child] = res[index] + (n - children[child]) - children[child];
                dfs2(n,child,index);
            }
    }
};

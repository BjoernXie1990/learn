��һ���Զ�ά���������ʾ��ͼ����ÿһ��������ʾ��ͼ��������ֵ��С����ֵ�� 0 �� 65535 ֮�䡣

����һ������?(sr, sc)?��ʾͼ����Ⱦ��ʼ������ֵ���� ���У���һ���µ���ɫֵ?newColor������������ɫ���ͼ��

Ϊ�������ɫ�������ӳ�ʼ���꿪ʼ����¼��ʼ��������������ĸ�����������ֵ���ʼ������ͬ���������ص㣬�����ټ�¼���ĸ������Ϸ������������ص������Ƕ�Ӧ�ĸ�����������ֵ���ʼ������ͬ���������ص㣬�������ظ��ù��̡��������м�¼�����ص����ɫֵ��Ϊ�µ���ɫֵ��

��󷵻ؾ�����ɫ��Ⱦ���ͼ��

ʾ�� 1:

����: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
���: [[2,2,2],[2,2,0],[2,0,1]]
����: 
��ͼ������м䣬(����(sr,sc)=(1,1)),
��·�������з������������ص����ɫ�������ĳ�2��
ע�⣬���½ǵ�����û�и���Ϊ2��
��Ϊ�����������������ĸ����������ʼ�����������ص㡣
ע��:

image ��?image[0]?�ĳ����ڷ�Χ?[1, 50] �ڡ�
�����ĳ�ʼ�㽫����?0 <= sr < image.length ��?0 <= sc < image[0].length��
image[i][j] ��?newColor?��ʾ����ɫֵ�ڷ�Χ?[0, 65535]�ڡ�

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int> > ans = image;
        vector<vector<bool> > vis(n,vector<bool> (m,false));
        int num = image[sr][sc];

        queue<pair<int,int> > que;
        que.push({sr,sc});
        vis[sr][sc] = true;
        int dir[4][2] = {1,0,-1,0,0,1,0,-1};

        while(!que.empty())
        {
            auto f = que.front();
            que.pop();
            ans[f.first][f.second] = newColor;

            for(int i = 0; i < 4; i++)
            {
                int x = f.first + dir[i][0];
                int y = f.second + dir[i][1];
                
                if(x < 0 || x >= ans.size() || y < 0 || y >= ans[0].size() || ans[x][y] != num || vis[x][y])
                    continue;
                que.push({x,y});
                vis[x][y] = true;
            }
        }

        return ans;
    }
};

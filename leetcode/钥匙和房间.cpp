�� N �����䣬��ʼʱ��λ�� 0 �ŷ��䡣ÿ�������в�ͬ�ĺ��룺0��1��2��...��N-1�����ҷ����������һЩԿ����ʹ�������һ�����䡣

����ʽ�ϣ�����ÿ������ i ����һ��Կ���б� rooms[i]��ÿ��Կ�� rooms[i][j] �� [0,1��...��N-1] �е�һ��������ʾ������ N = rooms.length�� Կ�� rooms[i][j] = v ���Դ򿪱��Ϊ v �ķ��䡣

������� 0 �ŷ�������������з��䶼����ס��

��������ɵ��ڷ���֮�������߶���

����ܽ���ÿ�����䷵�� true�����򷵻� false��

ʾ�� 1��

����: [[1],[2],[3],[]]
���: true
����:  
���Ǵ� 0 �ŷ��俪ʼ���õ�Կ�� 1��
֮������ȥ 1 �ŷ��䣬�õ�Կ�� 2��
Ȼ������ȥ 2 �ŷ��䣬�õ�Կ�� 3��
�������ȥ�� 3 �ŷ��䡣
���������ܹ�����ÿ�����䣬���Ƿ��� true��
ʾ�� 2��

���룺[[1,3],[3,0,1],[2],[0]]
�����false
���ͣ����ǲ��ܽ��� 2 �ŷ��䡣
��ʾ��

1 <= rooms.length <=?1000
0 <= rooms[i].length <= 1000
���з����е�Կ�������ܼƲ�����?3000��

class Solution {
public:
    vector<bool> vis;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis = vector<bool> (n,false);

        queue<int> que;
        que.push(0);
        vis[0] = true;
        int num = 1;

        while(que.empty() == false){
            int f = que.front();
            que.pop();

            for(int v : rooms[f]){
                if(vis[v] == true)  continue;

                vis[v] = true;
                num++;
                que.push(v);
            }
        }

        return num == n;
    }
};
};

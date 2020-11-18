class Solution {
public:
    static const int N = 2010, M = N * 4;
    int f[M][2];
    typedef pair<int,int> PII;
    int minimumJumps(vector<int>& forbidden, int a, int b, int c) {
        memset(f,-1,sizeof f);
        for(auto idx : forbidden) f[idx][0] = f[idx][1] = 1e8;

        queue<PII> que;
        // 0,0  ��ǰ��0��λ�ã�0 ��ʾ��һ����������Ҳ��������, 1��ʾ��һ��ֻ��������
        que.push(make_pair(0,0));
        f[0][0] = 0;

        while(!que.empty()) {
            PII t = que.front();
            que.pop();

            int x = t.first;
            int y = t.second;
            int d = f[x][y];
            if(x == c) return d;

            // right
            if(x + a < M && f[x+a][0] == -1) {
                f[x + a][0] = d + 1;
                que.push(make_pair(x + a, 0)); 
            }

            // left
            if(y == 0 && x - b >= 0 && f[x - b][0] == -1) {
                f[x - b][1] = d + 1;
                que.push(make_pair(x - b, 1));
            }
        }

        return -1;
    }
};

��һֻ����ļ��������ϵ�λ��?x?���������������λ��?0?�������������ļҡ�

������Ծ�Ĺ������£�

������ ��ǰ ��ǡ�� a?��λ�ã�������������
������ ����?��ǡ�� b?��λ�ã�������������
������ ���� ������ 2 �Ρ�
�����������κ�?forbidden?�����е�λ�á�
���������ǰ�� ����?���ļҵ�λ�ã������� ��������������?��λ�á�

����һ����������?forbidden?������?forbidden[i]?�����鲻��������λ�ã�ͬʱ��������?a��?b?��?x?�����㷵�����鵽�ҵ�������Ծ���������û��ǡ�õ��� x?�Ŀ��з��������㷵�� -1 ��

?

ʾ�� 1��

���룺forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
�����3
���ͣ���ǰ�� 3 �Σ�0 -> 3 -> 6 -> 9��������͵����ˡ�
ʾ�� 2��

���룺forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
�����-1
ʾ�� 3��

���룺forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
�����2
���ͣ���ǰ��һ�Σ�0 -> 16����Ȼ��������һ�Σ�16 -> 7��������͵����ˡ�
?

��ʾ��

1 <= forbidden.length <= 1000
1 <= a, b, forbidden[i] <= 2000
0 <= x <= 2000
forbidden?������λ�û�����ͬ��
λ��?x?���� forbidden?�С�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-jumps-to-reach-home
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

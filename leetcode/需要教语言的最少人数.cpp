class Solution {
public:
    int f[510][510];
    int arr[510];
    int minimumTeachings(int n, vector<vector<int>>& la, vector<vector<int>>& fr) {
        memset(f,0x00,sizeof f);
        int m = la.size();
        for(int i = 1; i <= m; i++) {
            for(auto& e : la[i-1]) f[i][e] = 1;
        }
        
        vector<vector<int> > t;
        for(auto& e : fr) {
            int x = e[0], y = e[1];
            bool ret = false;
            for(int i = 1; i <= n; i++) {
                if(f[x][i] && f[y][i]) {
                    ret = true;
                    break;
                }
            }
            if(!ret) t.push_back(e);
        }
        
        int res = 600;
        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            
            memset(arr,0x00,sizeof arr);
            for(auto& e : t) {
                int x = e[0], y = e[1];
                if(f[x][i] == 0 && arr[x] == 0) {
                    cnt++;
                    arr[x] = 1;
                }
                if(f[y][i] == 0 && arr[y] == 0) {
                    cnt++;
                    arr[y] = 1;
                }
            }
            res = min(res,cnt);
        }
        
        return res;
    }
};

��һ����?m?���û���ɵ��罻��������ǻ�ȡ��һЩ�û�֮��ĺ��ѹ�ϵ�������û�֮������໥��ͨ�����������Ƕ�����ͬһ�����ԡ�

����һ������?n?������?languages?������?friendships?�����ǵĺ������£�

�ܹ���?n?�����ԣ���Ŵ�?1 ��?n?��
languages[i]?�ǵ� i?λ�û����յ����Լ��ϡ�
friendships[i] = [u??????i???, v??????i]?��ʾ?u???????????i????? ��?vi?Ϊ���ѹ�ϵ��
�����ѡ�� һ��?���Բ��̻�һЩ�û���ʹ�����к���֮�䶼�����໥��ͨ���뷵���� ����?��Ҫ�̻�������û���

��ע�⣬���ѹ�ϵû�д����ԣ�Ҳ����˵���?x ��?y?�Ǻ��ѣ���?y?��?z?�Ǻ��ѣ�?x ��?z?��һ���Ǻ��ѡ�
?

ʾ�� 1��

���룺n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
�����1
���ͣ������ѡ����û� 1 �ڶ������ԣ�Ҳ����ѡ����û� 2 ��һ�����ԡ�
ʾ�� 2��

���룺n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
�����2
���ͣ����û� 1 ���û� 3 ���������ԣ���Ҫ�� 2 ���û���
?

��ʾ��

2 <= n <= 500
languages.length == m
1 <= m <= 500
1 <= languages[i].length <= n
1 <= languages[i][j] <= n
1 <= u??????i < v??????i <= languages.length
1 <= friendships.length <= 500
���еĺ��ѹ�ϵ?(u?????i, v??????i)?����Ψһ�ġ�
languages[i]?�а�����ֵ������ͬ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-number-of-people-to-teach
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

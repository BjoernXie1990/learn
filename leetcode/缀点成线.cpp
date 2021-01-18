class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n <= 2) return true;
        int a = coordinates[0][0] - coordinates[1][0];
        int b = coordinates[0][1] - coordinates[1][1];
        for(int i = 2; i < n; i++) {
            int x = coordinates[0][0] - coordinates[i][0];
            int y = coordinates[0][1] - coordinates[i][1];
            if(x * b != y * a) return false;
        }
        return true;
    }
};

��һ��?XY ����ϵ����һЩ�㣬����������?coordinates?���ֱ��¼���ǵ����꣬����?coordinates[i] = [x, y]?��ʾ������Ϊ x��������Ϊ y?�ĵ㡣

�������жϣ���Щ���Ƿ��ڸ�����ϵ������ͬһ��ֱ���ϣ����򷵻� true�������뷵�� false��

?

ʾ�� 1��



���룺coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
�����true
ʾ�� 2��



���룺coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
�����false
?

��ʾ��

2 <=?coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <=?coordinates[i][0],?coordinates[i][1] <= 10^4
coordinates?�в����ظ��ĵ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/check-if-it-is-a-straight-line
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

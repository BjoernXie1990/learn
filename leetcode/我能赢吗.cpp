�� "100 game" �����Ϸ�У������������ѡ��� 1 �� 10 �������������ۼ������ͣ���ʹ���ۼ������ʹﵽ�򳬹� 100 ����ң���Ϊʤ�ߡ�

������ǽ���Ϸ�����Ϊ ����Ҳ����ظ�ʹ�������� �أ�

���磬������ҿ��������ӹ����������г�ȡ�� 1 �� 15 �����������Żأ���ֱ���ۼ������� >= 100��

����һ������?maxChoosableInteger?���������п�ѡ��������������һ������?desiredTotal���ۼƺͣ����ж��ȳ��ֵ�����Ƿ�����Ӯ��������λ�����Ϸʱ��������ѣ���

����Լ���?maxChoosableInteger?������� 20��?desiredTotal?������� 300��

ʾ����

���룺
maxChoosableInteger = 10
desiredTotal = 11

�����
false

���ͣ�
���۵�һ�����ѡ���ĸ�������������ʧ�ܡ�
��һ����ҿ���ѡ��� 1 �� 10 ��������
�����һ�����ѡ�� 1����ô�ڶ������ֻ��ѡ��� 2 �� 10 ��������
�ڶ�����ҿ���ͨ��ѡ������ 10����ô�ۻ���Ϊ 11 >= desiredTotal�����Ӷ�ȡ��ʤ��.
ͬ���أ���һ�����ѡ�����������������ڶ�����Ҷ���Ӯ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/can-i-win
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger) return true;
        if(maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal) return false;

        vector<int> arr(1<<maxChoosableInteger,2);
        return dfs(maxChoosableInteger,desiredTotal,arr,0);
    }

    bool dfs(int maxN,int des,vector<int>& arr,int statu) {
        if(arr[statu] != 2) return arr[statu]==0 ? false : true;

        for(int i = 1; i <= maxN; i++) {
            int cur = 1 << (i - 1);
            if((cur & statu) != 0) continue;

            if(des - i <= 0 ||
                dfs(maxN,des - i,arr,(statu | cur)) == false) {
                    arr[statu] = 1;
                    return true;
                }
        }
        arr[statu] = 0;
        return false;
    }
};

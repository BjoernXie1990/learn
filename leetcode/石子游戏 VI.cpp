class Solution {
public:
    typedef pair<int,int> PII;
    
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n  = a.size();
        vector<int> f(n,0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            f[i] = a[i] + b[i];
            ans += a[i] - b[i];
        }
        
        sort(f.begin(),f.end());
        reverse(f.begin(),f.end());
        
        
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                ans -= f[i];
            } else {
                ans += f[i];
            }
        }
        
        if(ans == 0)return 0;
        return ans < 0 ? -1 : 1;
    }
};

Alice ��?Bob ������һ����Ϸ��Alice ���֡�

һ��ʯ�����ܹ���?n?��ʯ�ӣ��ֵ�ĳ�����ʱ�������� �Ƴ�?һ��ʯ�Ӳ��õ����ʯ�ӵļ�ֵ��Alice �� Bob ��ʯ�Ӽ�ֵ�� ��һ���ĵ����б�׼?��

������������Ϊ n?����������?aliceValues ��?bobValues?��aliceValues[i] ��?bobValues[i]?�ֱ��ʾ Alice �� Bob ��Ϊ��?i?��ʯ�ӵļ�ֵ��

����ʯ�Ӷ���ȡ��󣬵÷ֽϸߵ���Ϊʤ�ߡ����������ҵ÷���ͬ����ôΪƽ�֡���λ��Ҷ������ ���Ų���?������Ϸ��

�����ƶ���Ϸ�Ľ���������µķ�ʽ��ʾ��

��� Alice Ӯ������?1?��
��� Bob Ӯ������?-1?��
�����Ϸƽ�֣�����?0?��
?

ʾ�� 1��

���룺aliceValues = [1,3], bobValues = [2,1]
�����1
���ͣ�
��� Alice ��ʯ�� 1 ���±�� 0��ʼ������ô Alice ���Եõ� 3 �֡�
Bob ֻ��ѡ��ʯ�� 0 ���õ� 2 �֡�
Alice ��ʤ��
ʾ�� 2��

���룺aliceValues = [1,2], bobValues = [3,1]
�����0
���ͣ�
Alice ��ʯ�� 0 �� Bob ��ʯ�� 1 �����ǵ÷ֶ�Ϊ 1 �֡�
��ƽ��
ʾ�� 3��

���룺aliceValues = [2,4,3], bobValues = [1,6,7]
�����-1
���ͣ�
���� Alice ��ô������Bob �����Եõ��� Alice ���ߵĵ÷֡�
�ȷ�˵��Alice ��ʯ�� 1 ��Bob ��ʯ�� 2 �� Alice ��ʯ�� 0 ��Alice ��õ� 6 �ֶ� Bob �÷�Ϊ 7 �֡�
Bob ���ʤ��
?

��ʾ��

n == aliceValues.length == bobValues.length
1 <= n <= 105
1 <= aliceValues[i], bobValues[i] <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/stone-game-vi
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
    typedef pair<int,int> PII;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<PII,vector<PII>,greater<PII> > pq;
        int res = 0;

        int n = apples.size();
        for(int i = 0; i < n || !pq.empty(); i++) {
            if(i < n && apples[i] && days[i])
                pq.push({i + days[i],apples[i]});
            
            // ����Ѿ����˵�ƻ��
            while(!pq.empty() && pq.top().first <= i)
                pq.pop();
            
            if(pq.empty()) continue;

            // ��ƻ��
            auto [d,a] = pq.top();
            pq.pop();
            res++;
            if(a > 1) {
                pq.push({d,a-1});
            }
        }

        return res;
    }
};


��һ�������ƻ������һ�� n �죬ÿ�춼���Գ������ɸ�ƻ�����ڵ� i �죬���ϻ᳤�� apples[i] ��ƻ������Щƻ�������� days[i] ���Ҳ����˵���� i + days[i] ��ʱ�����ã�����޷�ʳ�á�Ҳ��������ô���죬���ϲ��᳤���µ�ƻ������ʱ�� apples[i] == 0 �� days[i] == 0 ��ʾ��

�����ÿ�� ��� ��һ��ƻ������֤Ӫ�����⡣ע�⣬��������� n ��֮�������ƻ����

������������Ϊ n ���������� days �� apples ����������ԳԵ���ƻ���������Ŀ��

?

ʾ�� 1��

���룺apples = [1,2,3,5,2], days = [3,2,1,4,2]
�����7
���ͣ�����ԳԵ� 7 ��ƻ����
- ��һ�죬��Ե���һ�쳤������ƻ����
- �ڶ��죬��Ե�һ���ڶ��쳤������ƻ����
- �����죬��Ե�һ���ڶ��쳤������ƻ����������һ�죬�����쳤������ƻ�����Ѿ������ˡ�
- �����쵽�����죬��ԵĶ��ǵ����쳤������ƻ����
ʾ�� 2��

���룺apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
�����5
���ͣ�����ԳԵ� 5 ��ƻ����
- ��һ�쵽�����죬��ԵĶ��ǵ�һ�쳤������ƻ����
- ������͵����첻��ƻ����
- ������͵����죬��ԵĶ��ǵ����쳤������ƻ����
?

��ʾ��

apples.length == n
days.length == n
1 <= n <= 2 * 104
0 <= apples[i], days[i] <= 2 * 104
ֻ���� apples[i] = 0 ʱ��days[i] = 0 �ų���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-number-of-eaten-apples
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

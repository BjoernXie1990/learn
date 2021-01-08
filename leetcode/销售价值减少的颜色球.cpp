class Solution {
public:
    typedef long long LL;
    const int mod = 1e9 + 7;
    int maxProfit(vector<int>& inventory, int orders) {
        priority_queue<int> pq;     // С���ѣ�ÿ���ҵ���ǰ�����ļ�ֵ
        unordered_map<int,LL> mp;  // ÿ����ֵ���ڵ�������

        for(auto& e : inventory) {
            if(mp[e] == 0) pq.push(e);
            mp[e] ++;
        }

        pq.push(0);     // �ų�ֻʣһ����ļ�ֵ�����
        LL res = 0;
        while(orders) {
            int one = pq.top(); pq.pop();
            int two = pq.top();

            LL cnt = (one - two) * mp[one];     // ������ץȡ�Ĵ���
            if(cnt <= orders) {
                res += (one + two + 1) * cnt / 2;   // �Ȳ�������ͣ�����һ�����Դ���ļ�ֵ
                res %= mod;
                orders -= cnt;
            } else {
                LL x = orders / mp[one], y = orders % mp[one];  // x ��ǰ��Щ�򶼿���ץ�Ĵ�����y �����һ����Ҫץ���������
                res += (one + (one - x) + 1) * x * mp[one] / 2;
                res %= mod;

                // ʣ�����
                res = (res + y * (one - x)) % mod;
                orders = 0;
            }

            mp[two] += mp[one];
        }
        return res;
    }
};

����һЩ��Ŀ��?inventory?����������Ų�ͬ��ɫ����һ���˿���Ҫ?������ɫ ����Ϊ?orders?����

��λ�˿���һ������ķ�ʽ������ļ�ֵ��ÿ����ļ�ֵ��Ŀǰʣ�µ�?ͬɫ��?����Ŀ���ȷ�˵��ʣ��?6?��������ô�˿����һ�������ʱ��û���ļ�ֵΪ?6?����ʽ����Ժ�ֻʣ��?5?�������ˣ�������һ������ļ�ֵΪ?5?��Ҳ������ļ�ֵ���Ź˿͹���ͬɫ���ǵݼ��ģ�

������������?inventory?������?inventory[i]?��ʾ��?i?����ɫ��һ��ʼ����Ŀ��ͬʱ��������?orders?����ʾ�˿��ܹ����������Ŀ������԰��� ����˳��?����

���㷵������ orders?�����Ժ� ���?�ܼ�ֵ֮�͡����ڴ𰸿��ܻ�ܴ����㷵�ش𰸶� 109?+ 7?ȡ����?�Ľ����

?

ʾ�� 1��


���룺inventory = [2,5], orders = 4
�����14
���ͣ��� 1 ����һ����ɫ���򣨼�ֵΪ 2 )���� 3 ���ڶ�����ɫ���򣨼�ֵΪ 5 + 4 + 3����
����ܺ�Ϊ 2 + 5 + 4 + 3 = 14 ��
ʾ�� 2��

���룺inventory = [3,5], orders = 6
�����19
���ͣ��� 2 ����һ����ɫ���򣨼�ֵΪ 3 + 2������ 4 ���ڶ�����ɫ���򣨼�ֵΪ 5 + 4 + 3 + 2����
����ܺ�Ϊ 3 + 2 + 5 + 4 + 3 + 2 = 19 ��
ʾ�� 3��

���룺inventory = [2,8,4,10,6], orders = 20
�����110
ʾ�� 4��

���룺inventory = [1000000000], orders = 1000000000
�����21
���ͣ��� 1000000000 �ε�һ����ɫ�����ܼ�ֵΪ 500000000500000000 �� 500000000500000000 �� 109 + 7 ȡ��Ϊ 21 ��
?

��ʾ��

1 <= inventory.length <= 105
1 <= inventory[i] <= 109
1 <= orders <= min(sum(inventory[i]), 109)

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sell-diminishing-valued-colored-balls
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

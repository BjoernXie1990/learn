class Solution {
public:
    const int mod = 1e9 + 7;
    int countPairs(vector<int>& d) {
        unordered_map<int,int> mp;
        for(auto& e : d) mp[e] ++;
        
        int n = d.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            
            int num = 1;
            for(int j = 0; j < 23; j++) {
                long long need = num - d[i];
                if(num >= d[i] &&  mp.count(need)) {
                    int cnt = mp[need];
                    if(need == d[i]) cnt--;
                    ans += cnt;
                }
                num <<= 1;
            }
        }
        
        return (ans / 2) % mod;
    }
};

��� ��ָ ǡ�ð���������ͬ��Ʒ ��һ�ͣ�����ζ�̶�֮�͵��� 2 ���ݡ�

����Դ��� ���� ������Ʒ��һ�ٴ�͡�

����һ���������� deliciousness ������ deliciousness[i] �ǵ� i?????????????? ����Ʒ����ζ�̶ȣ�����������������еĲ�Ʒ�����Ĳ�ͬ ��� �������������Ҫ�� 109 + 7 ȡ�ࡣ

ע�⣬ֻҪ��Ʒ�±겻ͬ���Ϳ�����Ϊ�ǲ�ͬ�Ĳ�Ʒ���������ǵ���ζ�̶���ͬ��

?

ʾ�� 1��

���룺deliciousness = [1,3,5,7,9]
�����4
���ͣ���͵���ζ�̶����Ϊ (1,3) ��(1,7) ��(3,5) �� (7,9) ��
���Ǹ��Ե���ζ�̶�֮�ͷֱ�Ϊ 4 ��8 ��8 �� 16 ������ 2 ���ݡ�
ʾ�� 2��

���룺deliciousness = [1,1,1,3,3,3,7]
�����15
���ͣ���͵���ζ�̶����Ϊ 3 �� (1,1) ��9 �� (1,3) ���� 3 �� (1,7) ��
?

��ʾ��

1 <= deliciousness.length <= 105
0 <= deliciousness[i] <= 220

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-good-meals
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

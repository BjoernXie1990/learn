����һ���ַ��� s ��һ���������� cost ������ cost[i] �Ǵ� s ��ɾ���ַ� i �Ĵ��ۡ�

����ʹ�ַ�����������������ĸ����ͬ����Сɾ���ɱ���

��ע�⣬ɾ��һ���ַ���ɾ�������ַ��ĳɱ�����ı䡣

?

ʾ�� 1��

���룺s = "abaac", cost = [1,2,3,4,5]
�����3
���ͣ�ɾ����ĸ "a" �ĳɱ�Ϊ 3��Ȼ��õ� "abac"���ַ���������������ĸ����ͬ����
ʾ�� 2��

���룺s = "abc", cost = [1,2,3]
�����0
���ͣ�����ɾ���κ���ĸ����Ϊ�ַ����в���������������ĸ��ͬ�������
ʾ�� 3��

���룺s = "aabaa", cost = [1,2,3,4,1]
�����2
���ͣ�ɾ����һ�������һ����ĸ���õ��ַ��� ("aba") ��
?

��ʾ��

s.length == cost.length
1 <= s.length, cost.length <= 10^5
1 <= cost[i] <=?10^4
s ��ֻ����СдӢ����ĸ


class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = cost.size();
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                if(cost[i-1] > cost[i]) {
                    ans += cost[i];
                    cost[i] = cost[i-1];
                } else {
                    ans += cost[i-1];
                }
            }
        }

        return ans;
    }
};

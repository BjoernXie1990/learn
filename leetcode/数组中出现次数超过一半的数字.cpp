class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for(auto& e : nums) {
            if(cnt == 0) {
                res = e;
                cnt ++;
            } else {
                if(res == e) cnt++;
                else cnt--;
            }
        }

        return res;
    }
};

��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�

?

����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�

?

ʾ��?1:

����: [1, 2, 3, 2, 2, 2, 5, 4, 2]
���: 2
?

���ƣ�

1 <= ���鳤�� <= 50000

?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

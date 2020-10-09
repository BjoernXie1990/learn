class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        int um[1<<10];
        memset(um,0x3f,sizeof(um));
        //unordered_map<int,int> um;
        um[0] = -1;

        int ans = 0;
        int status = 0;
        for(int i = 0; i < n; i++) {
            status ^= (1 << (s[i] - '0'));

            if(um[status] == 0x3f3f3f3f) um[status] = i;
            else ans = max(ans,i - um[status]);

            for(int j = 0; j < 10; j++) {
                int st = (1 << j) ^ status;
                if(um[st] != 0x3f3f3f3f) ans = max(ans,i-um[st]);
            }
            
            // �뵱ǰ״̬��ͬ��ǰһ�γ��ֵ�λ��
            // auto pos = um.find(status);
            // if(pos != um.end()) ans = max(ans,i - pos->second);
            // else um[status] = i;

            // ��ͬ
            // int bit = 1;
            // int cnt = 10;
            // while (cnt --) {
            //     int st = status ^ bit;  // ֻ��һλ��ͬ��ǰһ�γ��ֵ�λ��
            //     pos = um.find(st);
            //     if(pos != um.end()) ans = max(ans,i - pos->second);
            //     bit <<= 1;
            // }
        }

        return ans;
    }
};


����һ���ַ��� s ���뷵�� s ����� �������ַ��� �ĳ��ȡ�

���������ַ�����������������������������

���ַ����� s ��һ���ǿ����ַ���
��������������ַ������󣬸��ַ������Ա��һ�������ַ���
?

ʾ�� 1��

���룺s = "3242415"
�����5
���ͣ�"24241" ����ĳ������ַ������������е��ַ��󣬿��Եõ����� "24142"
ʾ�� 2��

���룺s = "12345678"
�����1
ʾ�� 3��

���룺s = "213123"
�����6
���ͣ�"213123" ����ĳ������ַ������������е��ַ��󣬿��Եõ����� "231132"
ʾ�� 4��

���룺s = "00"
�����2
?

��ʾ��

1 <= s.length <= 10^5
s �����������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-longest-awesome-substring
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

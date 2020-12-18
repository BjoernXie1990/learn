class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int n = str.size();
        
        for(int i = n - 2; i >= 0; i--) {
            if(str[i] <= str[i + 1])
                continue;
            // �ҵ�ǰ��0
            while(i >= 0 && str[i] == '0') {
                i--;
            }
            for(int j = i + 1; j < n; j++) 
                str[j] = '9';
            str[i]--;
        }

        return atoi(str.c_str());
    }
};

����һ���Ǹ�����?N���ҳ�С�ڻ����?N?������������ͬʱ���������Ҫ���������λ���ϵ������ǵ���������

�����ҽ���ÿ������λ���ϵ�����?x?��?y?����?x <= y?ʱ�����ǳ���������ǵ��������ġ���

ʾ�� 1:

����: N = 10
���: 9
ʾ�� 2:

����: N = 1234
���: 1234
ʾ�� 3:

����: N = 332
���: 299
˵��: N?����?[0, 10^9]?��Χ�ڵ�һ��������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/monotone-increasing-digits
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

ʵ��?strStr()?������

����һ��?haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�? -1��

ʾ�� 1:

����: haystack = "hello", needle = "ll"
���: 2
ʾ�� 2:

����: haystack = "aaaaa", needle = "bba"
���: -1
˵��:

��?needle?�ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣

���ڱ�����ԣ���?needle?�ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե�?strstr()?�Լ� Java��?indexOf()?���������


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if(m == 0) return 0;
        else if(n == 0) return -1;

        vector<int> next(m,0);
        for(int i = 1,j = 0; i < m; i++)
        {
            while(j && needle[j] != needle[i])
                j = next[j-1];
            if(needle[j] == needle[i])
                j++;
            next[i] = j;
        }

        for(int i = 0,j = 0; i < n; i++)
        {
            while(j && haystack[i] != needle[j])
                j = next[j-1];
            
            if(haystack[i] == needle[j])
                j++;
            if(j == m)
                return i - m + 1;
        }
        return -1;
    }
};

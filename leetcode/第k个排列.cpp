��������?[1,2,3,��,n]��������Ԫ�ع���?n! �����С�

����С˳���г����������������һһ��ǣ���?n = 3 ʱ, �����������£�

"123"
"132"
"213"
"231"
"312"
"321"
����?n ��?k�����ص�?k?�����С�

˵����

���� n?�ķ�Χ�� [1, 9]��
���� k?�ķ�Χ��[1, ?n!]��
ʾ��?1:

����: n = 3, k = 3
���: "213"
ʾ��?2:

����: n = 4, k = 9
���: "2314"


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factor(n+1,1);
        deque<char> vis(n+1,'0');
        int sum = 1;
        for(int i = 1; i <= n; i++)
        {
            vis[i] = '0' + i;
            sum *= i;
            factor[i] = sum;
        }

        string ans("");
        k--;
        for(int i = n-1; i >= 0; i--)
        {
            int p = k / factor[i];
            ans += vis[p+1];
            vis.erase(vis.begin()+p+1);
            k -= p * factor[i];
        }

        return ans;
    }
};

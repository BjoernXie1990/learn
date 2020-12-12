class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * 
     * @param x string�ַ��� 
     * @return int����
     */
    int Maximumlength(string x) {
        // write code here
        int n = x.size();
        int ans = 0;
        vector<int> f(n + 1,0);
        for(int i = 1; i <= n; i++) 
            f[i] = f[i - 1] + (x[i - 1] == 'b' ? 1 : 0);
        int le = 0;
        int fle = x[le] == 'a';
        int ri = n - 1;
        int fri = x[ri] == 'c';
        
        while(le < ri) {
            int sum = f[ri] - f[le + 1];
            if(fle >= sum && fri >= sum) {
                ans = max(ans,sum * 3);
            }
            
            if(fle <= fri){
                le++;
                fle += x[le] == 'a';
            } else {
                ri--;
                fri += x[ri] == 'c';
            }
        }
        
        return ans;
    }
};


���ӣ�https://ac.nowcoder.com/acm/problem/207724
��Դ��ţ����

ţţ������һ������Ϊlenֻ����Сд��ĸ��a��-'z'���ַ���x����������Ҫһ������������У���������еĳ���Ϊ3*n��nΪ�Ǹ��������������еĵ�[1,n]����ĸȫ��Ϊ��a���������е�[n+1,2*n]����ĸȫ��Ϊ��b���������е�[2*n+1,3*n]����ĸȫ��Ϊ��c����ţţ��֪����ķ��������Ķ��������еĳ����Ƕ��١�

ʾ��1
����
����
"cbacb"
����ֵ
����
0
˵��
û�з��������ķǿ������У��������0
ʾ��2
����
����
"abaabbcccc"
����ֵ
����
6
˵��
��ķ���������������Ϊ"aabbcc"���������6
��ע:
����30\%�����ݣ�1 \leq len \leq 1000����30%�����ݣ�1��len��1000
����100\%�����ݣ�1 \leq len \leq 1e6����100%�����ݣ�1��len��1e6

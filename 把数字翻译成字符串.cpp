����һ�����֣����ǰ������¹����������Ϊ�ַ�����0 ����� ��a�� ��1 ����� ��b����������11 ����� ��l����������25 ����� ��z����
һ�����ֿ����ж�����롣����ʵ��һ����������������һ�������ж����ֲ�ͬ�ķ��뷽����

?

ʾ�� 1:

����: 12258
���: 5
����: 12258��5�ֲ�ͬ�ķ��룬�ֱ���"bccfi", "bwfi", "bczi", "mcfi"��"mzi"
?

��ʾ��

0 <= num < 231



class Solution {
public:
    int translateNum1(int num) {
       int ans = 0;
       dfs(num,ans);
       return ans; 
    }

    void dfs(int num,int& ans)
    {
        if(num < 10)
        {
            ans++;
            return;
        }

        dfs(num/10,ans);

        int tmp = num % 100;
        if(tmp <= 25 && tmp > 9)   dfs(num/100,ans);
    }



    int translateNum(int num)
    {
        if(num < 10)    return 1;
        int tmp = num % 100;
        int ret2 = 0;
        if(tmp <= 25 && tmp > 9)   ret2 = translateNum(num/100);
        return translateNum(num/10) + ret2;
    }
};

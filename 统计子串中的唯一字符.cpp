//
//���Ƕ�����һ������ countUniqueChars(s) ��ͳ���ַ��� s �е�Ψһ�ַ���������Ψһ�ַ��ĸ�����

//���磺s = "LEETCODE" �������� "L", "T","C","O","D" ����Ψһ�ַ�����Ϊ����ֻ����һ�Σ����� countUniqueChars(s) = 5 ��

//���⽫�����һ���ַ��� s ��������Ҫ���� countUniqueChars(t) ���ܺͣ����� t �� s �����ַ�����ע�⣬ĳЩ���ַ����������ظ��ģ�����ͳ��ʱҲ����������Щ�ظ������ַ�����Ҳ����˵�������ͳ�� s ���������ַ����е�Ψһ�ַ�����

//���ڴ𰸿��ܷǳ����뽫��� mod 10 ^ 9 + 7 ���ٷ��ء�

//?

//ʾ�� 1��

//����: "ABC"
//���: 10
//����: ���п��ܵ��Ӵ�Ϊ��"A","B","C","AB","BC" �� "ABC"��
//     ���У�ÿһ���Ӵ����ɶ����ַ����ɡ�
//     �����䳤���ܺ�Ϊ��1 + 1 + 1 + 2 + 2 + 3 = 10
//ʾ�� 2��

//����: "ABA"
//���: 8
//����: ���� countUniqueChars("ABA") = 1 ֮�⣬������ʾ�� 1 ��ͬ��
//ʾ�� 3��

//���룺s = "LEETCODE"
//�����92

class Solution {
public:
    int uniqueLetterString(string s) {
       int len = s.size();
        int ans = 0;
        const int div = 1000000007; 
        for(int i = 0; i < len; i++)
        {
            int left = 1,right = 1;
            //�����ҵ�һ����ͬ���ַ�
            for(int j = i - 1; j >= 0; j--)
            {
                if(s[j] == s[i])
                    break;
                left++;
            }

            //�����ҵ�һ����ͬ���ַ�
            for(int j = i + 1; j < len; j++)
            {
                if(s[j] == s[i])
                    break;
                right++;
            }

            ans = (ans + left * right) % div;
        }
        return ans;
    }
};

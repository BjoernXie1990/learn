//����һ���ַ���?s?�����㷵��������������������ַ����ĳ��ȣ�ÿ��Ԫ����ĸ����?'a'��'e'��'i'��'o'��'u' �������ַ����ж�ǡ�ó�����ż���Ρ�

//?

//ʾ�� 1��

//���룺s = "eleetminicoworoep"
//�����13
//���ͣ�����ַ����� "leetminicowor" �������� e��i��o?�� 2 �����Լ� 0 �� a��u ��
//ʾ�� 2��

//���룺s = "leetcodeisgreat"
//�����5
//���ͣ�����ַ����� "leetc" �����а��� 2 �� e ��
//ʾ�� 3��

//���룺s = "bcbcbc"
//�����6
//���ͣ����ʾ���У��ַ��� "bcbcbc" ���������ģ���Ϊ���е�Ԫ�� a��e��i��o��u �������� 0 �Ρ�



class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0,status = 0,len = s.size();
        vector<int> pos(32,-1);
        pos[0] = 0;

        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'a')
                status ^= 1<<0;
            else if(s[i] == 'e')
                status ^= 1<<1;
            else if(s[i] == 'o')
                status ^= 1<<2;
            else if(s[i] == 'i')
                status ^= 1<<3;
            else if(s[i] == 'u')
                status ^= 1<<4;
            
            if(pos[status] == -1)
                pos[status] = i+1;
            else
                ans = max(ans,i+1-pos[status]);
        }

        return ans;
    }
};

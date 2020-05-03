//���������ַ���?s1?��?s2?�����ǳ�����ȣ��������Ƿ����һ��?s1? �����п��Դ��� s2?��һ�����У������Ƿ����һ��?s2?�����п��Դ��� s1 ��һ�����С�

//�ַ���?x?���Դ����ַ���?y?�����߳��ȶ�Ϊ?n?���������������?i����?0?��?n - 1?֮�䣩����?x[i] >= y[i]���ֵ��������µ�˳�򣩡�

//?

//ʾ�� 1��

//���룺s1 = "abc", s2 = "xya"
//�����true
//���ͣ�"ayx" �� s2="xya" ��һ�����У�"abc" ���ַ��� s1="abc" ��һ�����У��� "ayx" ���Դ��� "abc" ��
//ʾ�� 2��

//���룺s1 = "abe", s2 = "acd"
//�����false 
//���ͣ�s1="abe" ���������а�����"abe"��"aeb"��"bae"��"bea"��"eab" �� "eba" ��s2="acd" ���������а�����"acd"��"adc"��"cad"��"cda"��"dac" �� "dca"��Ȼ��û���κ� s1 �����п��Դ��� s2 �����С�Ҳû�� s2 �������ܴ��� s1 �����С�
//ʾ�� 3��

//���룺s1 = "leetcodee", s2 = "interview"
//�����true



class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> num1(256,0);
        vector<int> num2(256,0);
        
        for(int i = 0; i < s1.size(); i++)
        {
            num1[s1[i]]++;
            num2[s2[i]]++;
        }
        
        return Fun(num1,s2)  || Fun(num2,s1);
    }
    
    bool Fun(vector<int>& sum, string& s)
    {
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            int j ;
            for(j = s[i]; j <= 'z'; j++)
            {
                if(sum[j])
                {
                    sum[j]--;
                    break;
                }
            }
            if(j > 'z')
                return false;
        }
        return true;
    }
};

��������ת�ַ���������һ������0��1֮���ʵ������0.72��������Ϊdouble����ӡ���Ķ����Ʊ��ʽ����������ֲ���0��1֮�䣬�����޷���ȷ����32λ���ڵĶ����Ʊ�ʾ�����ӡ��ERROR����

ʾ��1:

 ���룺0.625
 �����"0.101"
ʾ��2:

 ���룺0.1
 �����"ERROR"
 ��ʾ��0.1�޷���������׼ȷ��ʾ
��ʾ��

32λ��������е�"0."����λ��


class Solution {
public:
    string printBin(double num) {
        if(num >= 1 || num <= 0)    return "ERROR";

        string ans("0.");
        while(num > 0)
        {
            num *= 2;
            ans += (num - 1.0) >= 0 ? '1' : '0';
            if(num >= 1)    num -= 1;

            if(ans.size() > 32) return "ERROR";
        }

        return ans;
    }
};

//
//ʵ��?pow(x, n)?�������� x �� n ���ݺ�����

//ʾ�� 1:

//����: 2.00000, 10
//���: 1024.00000
//ʾ��?2:

//����: 2.10000, 3
//���: 9.26100
//ʾ��?3:

//����: 2.00000, -2
//���: 0.25000
//����: 2-2 = 1/22 = 1/4 = 0.25



class Solution {
public:
    double myPow1(double x, int n) {
        long tmp = abs(n);
        double ans = x;
        for(int i = 1; i < tmp; i++)
            ans *= x;
        return n>0?ans:(1/ans);
    }

    double myPow(double x, int n)
    {
        long tmp = abs(n);
        double ans = My_pow(x,tmp);
        return n>0?ans:(1/ans); 
    }

    double My_pow(double x, long n)
    {
        if(n == 0) return 1;
        if(n == 1) return x;

        if(n&1) return My_pow(x,n-1) * x;
            
        double tmp = My_pow(x,n/2);
        return tmp * tmp;
    }
};

//ʵ��?int sqrt(int x)?������

//���㲢����?x?��ƽ����������?x �ǷǸ�������

//���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��

//ʾ�� 1:

//����: 4
//���: 2
//ʾ�� 2:

//����: 8
//���: 2
//˵��: 8 ��ƽ������ 2.82842..., 
//?    ���ڷ���������������С�����ֽ�����ȥ��



class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
            return x;
        int left = 0;
        int right = (x / 2) + 1;
        //[left,right)
        while(left < right-1)
        {
            int mid = (left + right) / 2;
            //int sq = mid * mid;
            int sq = x / mid;
            if(sq == mid)
                return sq;
            else if(sq > mid)
                left = mid;
            else
                right = mid;
        }
        
        return left;
    }
};

��������һ���ܳ��Ļ�̳��һ���ֵؿ���ֲ�˻�����һ����ȴû�С����ǣ����ܲ�����ֲ�����ڵĵؿ��ϣ����ǻ�����ˮԴ�����߶�����ȥ��

����һ����̳����ʾΪһ���������0��1������0��ʾû��ֲ����1��ʾ��ֲ�˻�������һ����?n?���ܷ��ڲ�������ֲ��������������?n?�仨�����򷵻�True�������򷵻�False��

ʾ�� 1:

����: flowerbed = [1,0,0,0,1], n = 1
���: True
ʾ�� 2:

����: flowerbed = [1,0,0,0,1], n = 2
���: False
ע��:

���������ֺõĻ�����Υ����ֲ����
��������鳤�ȷ�ΧΪ [1, 20000]��
n �ǷǸ��������Ҳ��ᳬ����������Ĵ�С��



class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if((len == 0 && n > 0) || len < n) return false;

        for(int i = 0; i < len; i++)
        {
            if(flowerbed[i] == 1)
                continue;
            
            //��λ�ÿ����ֻ�
            int flag = 0;
            if(i-1 >= 0)    flag += flowerbed[i-1];
            if(i+1 < len)   flag += flowerbed[i+1];

            if(flag == 0)
            {
                if(n == 0) return true;
                n--;
                flowerbed[i] = 1;
            } 
        }

        return n==0;
    }
};

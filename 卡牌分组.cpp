//����һ���ƣ�ÿ�����϶�д��һ��������

//��ʱ������Ҫѡ��һ������ X��ʹ���ǿ��Խ������ư���������ֳ� 1 �������飺

//ÿ�鶼��?X?���ơ�
//�������е����϶�д����ͬ��������
//�������ѡ�� X >= 2 ʱ����?true��

//?

//ʾ�� 1��

//���룺[1,2,3,4,4,3,2,1]
//�����true
//���ͣ����еķ����� [1,1]��[2,2]��[3,3]��[4,4]
//ʾ�� 2��

//���룺[1,1,1,2,2,2,3,3]
//�����false
//���ͣ�û������Ҫ��ķ��顣
//ʾ�� 3��

//���룺[1]
//�����false
//���ͣ�û������Ҫ��ķ��顣
//ʾ�� 4��

//���룺[1,1]
//�����true
//���ͣ����еķ����� [1,1]
//ʾ�� 5��

//���룺[1,1,2,2,2,2]
//�����true
//���ͣ����еķ����� [1,1]��[2,2]��[2,2]



class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> arr(10005);
        int maxNum = 0;//��¼���ֵ������
        for(int i = 0; i < deck.size(); i++)
        {
            arr[deck[i]]++;
            if(deck[i] > maxNum)
                maxNum = deck[i];
        }

        int ans = 0;
        for(int i = 0; i <= maxNum; i++)
        {
            if(!arr[i])//�ų�û�и����ֵ����
                continue;
            if(arr[i] < 2)
                return false;
            ans = gcd(arr[i],ans);
        }
        return ans >= 2;
    }
    //��ϣ��
    bool hasGroupsSizeX2(vector<int>& deck) {
       //ʹ�ù�ϣ��������ÿ��ֵ������ -- �� map

        int ans = 0;
        for (int a :map.values())
        {
            if(a < 2)
                return false;
            ans = gcd(ans, a);
        }
        return ans >= 2;
    }

    int gcd(int a,int b)
    {
        return b == 0 ? a : gcd(b,a%b);
    }
};

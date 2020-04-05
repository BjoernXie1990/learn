

//��������֮��ĺ�������ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��

//������������ x �� y����������֮��ĺ������롣

//ע�⣺
//0 �� x, y < 231.

//ʾ��:

//����: x = 1, y = 4

//���: 2

//����:
//1   (0 0 0 1)
//4   (0 1 0 0)
//       ��   ��

//����ļ�ͷָ���˶�Ӧ������λ��ͬ��λ�á�

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x || y)
        {
            ans += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }

        return ans;
    }
};

//����������?�������� ָ�������������ֵĶ���������Ӧλ��ͬ��������

//����һ�������У�����������֮�人��������ܺ͡�

//ʾ��:

//����: 4, 14, 2

//���: 6

//����: �ڶ����Ʊ�ʾ�У�4��ʾΪ0100��14��ʾΪ1110��2��ʾΪ0010����������ʾ��Ϊ�����ֺ���λ֮���ϵ��
//���Դ�Ϊ��
//HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        vector<int> arr(32);
        for(int i = 0; i < len; i++)
        {
            int j = 0;
            while(nums[i])
            {
                nums[i] & 1 ? (arr[j]++,nums[i] >>= 1) : ( nums[i] >>= 1);
                j++;
            }
        }

        for(int i = 0; i < 32; i++)
        {
            ans += arr[i] * (len - arr[i]);
        }

        return ans;
    }
};

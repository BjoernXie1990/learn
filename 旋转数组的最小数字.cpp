��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת������һ����������������һ����ת�������ת�������СԪ�ء����磬����?[3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ1��??

ʾ�� 1��

���룺[3,4,5,1,2]
�����1
ʾ�� 2��

���룺[2,2,2,0,1]
�����0

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int le = 0;
        int ri = numbers.size() - 1;
         
        while(le < ri)
        {
            int mid = (le + ri) / 2;

            if(numbers[ri] < numbers[mid])
                le = mid + 1;
            else if(numbers[ri] > numbers[mid])
                ri = mid;
            else
                ri--;
        }

        return numbers[le];
    }
};

//����?n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��



//������������ [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ������������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ����?��л Marcos ���״�ͼ��

//ʾ��:

//����: [0,1,0,2,1,0,1,3,2,1,2,1]
//���: 6




class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                //�����ߵĸ߶ȱ�����Ա�������߶Ȼ���
                if(height[left] > leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];

                left++;
            }
            else
            {
                 //����ұߵĸ߶ȱ��ұ��Ա�������߶Ȼ���
                 if(height[right] > rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];
                right--;
            }
        }

        return ans;
    }
};

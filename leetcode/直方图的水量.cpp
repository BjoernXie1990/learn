class Solution {
public:
    int trap(vector<int>& height) {
        int le = 0, ri = height.size() - 1;
        int leMax = 0, riMax = 0;
        int ans = 0;

        while(le < ri) {
            if(height[le] < height[ri]) {
                leMax = max(height[le],leMax);
                ans += leMax - height[le++];
            } else {
                riMax = max(riMax,height[ri]);
                ans += riMax - height[ri--];
            }
        }

        return ans;
    }
};

����һ��ֱ��ͼ(Ҳ����״ͼ)���������˴�����ԴԴ���ϵص�ˮ�����ֱ��ͼ�ܴ����ˮ��?ֱ��ͼ�Ŀ��Ϊ 1��



������������ [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ��ֱ��ͼ������������£����Խ� 6 ����λ��ˮ����ɫ���ֱ�ʾˮ����?��л Marcos ���״�ͼ��

ʾ��:

����: [0,1,0,2,1,0,1,3,2,1,2,1]
���: 6

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/volume-of-histogram-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

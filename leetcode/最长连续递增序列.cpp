����һ��δ��������������飬�ҵ���������ĵĵ������У������ظ����еĳ��ȡ�

?

ʾ�� 1:

����: [1,3,5,4,7]
���: 3
����: ��������������� [1,3,5], ����Ϊ3��
���� [1,3,5,7] Ҳ�������������, �������������ģ���Ϊ5��7��ԭ�����ﱻ4������ 
ʾ�� 2:

����: [2,2,2,2,2]
���: 1
����: ��������������� [2], ����Ϊ1��


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        int le = 0;
        int len = 1;
        int ans = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                le = i;
                len = 1;
                continue;
            }

            len++;
            ans = max(ans,len);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        //for(int i = 0; i < k - 1; i++) ans[i] = nums[i];
        
        int len = 0;
        for(int i = 0; i < n; i++) {
            int pre = (n - i >= k) ? 0 : k - n + i;
            
            if(ans.size() <= pre) {
                ans.push_back(nums[i]);
                continue;
            }
            
            int j = ans.size() - 1;
            for(; j >= pre; j--) {
                if(nums[i] >= ans[j]) break;
                ans.pop_back();
            }
            if(ans.size() < k) ans.push_back(nums[i]); 
        }
        
        return ans;
    }
};

����һ���������� nums ��һ�������� k �����س���Ϊ k ����� ������ �� nums �����С�

������������Ǵ�������ɾ��һЩԪ�أ����ܲ�ɾ��Ԫ�أ��õ������С�

�������� a �������� b ��һ������ͬ��λ���ϣ���� a �е�����С�� b �ж�Ӧ�����֣���ô���ǳ������� a �������� b����ͬ�����£����� ������ �� ���磬[1,3,4] �� [1,3,5] ���߾��������ڵ�һ������ͬ��λ�ã�Ҳ�������һ��λ���ϣ� 4 С�� 5 ��

 

ʾ�� 1��

���룺nums = [3,5,2,6], k = 2
�����[2,6]
���ͣ������п��ܵ������м��� {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]} �У�[2,6] ��߾�������
ʾ�� 2��

���룺nums = [2,4,3,3,5,4,9,6], k = 4
�����[2,3,3,4]
 

��ʾ��

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= nums.length

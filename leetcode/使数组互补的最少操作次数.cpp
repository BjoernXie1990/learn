class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> f(limit * 2 + 10,0);
        unordered_map<int,int> mp;
        
        for(int i = 0; i < n / 2; i++) {
            mp[nums[i] + nums[n - 1 - i]] ++;
            f[min(nums[i],nums[n - 1 - i]) + 1] ++;
            f[limit + max(nums[i],nums[n - 1 - i]) + 1] --;
        }
        
        int ans = n * 2;
        int sum = 0;
        for(int i = 2; i <= limit * 2; i++) {
            sum += f[i];
            
            int t1 = sum - mp[i];
            int t2 = n / 2 - sum;
            
            ans = min(ans,t1 + t2 * 2);
        }
        
        return ans;
    }
};

����һ������Ϊ ż�� n ���������� nums ��һ������ limit ��ÿһ�β���������Խ� nums �е��κ������滻Ϊ 1 �� limit ֮�����һ��������

������������±� i���±�� 0 ��ʼ����nums[i] + nums[n - 1 - i] ������ͬһ������������ nums �� ������ �����磬���� [1,2,3,4] �ǻ����ģ���Ϊ���������±� i ��nums[i] + nums[n - 1 - i] = 5 ��

����ʹ���� ���� �� ���� ����������

 

ʾ�� 1��

���룺nums = [1,2,4,3], limit = 4
�����1
���ͣ����� 1 �β���������Խ����� nums ��� [1,2,2,3]���Ӵ�Ԫ���Ǳ�������֣���
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
����ÿ�� i ��nums[i] + nums[n-1-i] = 4 ������ nums �ǻ����ġ�
ʾ�� 2��

���룺nums = [1,2,2,1], limit = 2
�����2
���ͣ����� 2 �β���������Խ����� nums ��� [2,2,2,2] ���㲻�ܽ��κ����ֱ��Ϊ 3 ����Ϊ 3 > limit ��
ʾ�� 3��

���룺nums = [1,2,1,2], limit = 2
�����0
���ͣ�nums �Ѿ��ǻ����ġ�
 

��ʾ��

n == nums.length
2 <= n <= 105
1 <= nums[i] <= limit <= 105
n ��ż����

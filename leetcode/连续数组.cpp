����һ������������, �ҵ�������ͬ������ 0 �� 1 ������������飨�ĳ��ȣ���

?

ʾ�� 1:

����: [0,1]
���: 2
˵��: [0, 1] �Ǿ�����ͬ����0��1������������顣
ʾ�� 2:

����: [0,1,0]
���: 2
˵��: [0, 1] (�� [1, 0]) �Ǿ�����ͬ����0��1������������顣
?

ע��:?�����Ķ���������ĳ��Ȳ��ᳬ��50000��

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map_t;
        int n = nums.size();
        int ans = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) sum--;
            else sum++;

            if(sum == 0){
                ans = i+1;
                continue;
            }
            
            if(map_t.count(sum) > 0){
                ans = max(i - map_t[sum],ans);
            }
            else{
                map_t[sum] = i;
            }
        }

        return ans;
    }
};

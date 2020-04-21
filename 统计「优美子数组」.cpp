//��һ����������?nums ��һ������ k��

//���ĳ�� ���� ��������ǡ���� k ���������֣����Ǿ���Ϊ����������ǡ����������项��

//�뷵����������С����������项����Ŀ��

//?

//ʾ�� 1��

//���룺nums = [1,1,2,1,1], k = 3
//�����2
//���ͣ����� 3 ���������������� [1,1,2,1] �� [1,2,1,1] ��
//ʾ�� 2��

//���룺nums = [2,4,6], k = 1
//�����0
//���ͣ������в������κ����������Բ��������������顣
//ʾ�� 3��

//���룺nums = [2,2,2,1,2,2,1,2,2,2], k = 2
//�����16




class Solution {
public:
    int numberOfSubarrays1(vector<int>& nums, int k) {
        int len = nums.size();
        int* arr = new int[len+2];
        int num = 0;
        int ans = 0;

        for(int i = 0; i < len; i++)
            if(nums[i] & 1)
                arr[++num] = i;
        arr[0] = -1, arr[++num] = len; // arr������һ��[0,len] ����ұ�����
        int left = 1, right = k;

        while(right < num){
            ans += (arr[left] - arr[left-1]) * (arr[right+1] - arr[right]);
            left++;
            right++;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);        
        int odd = 0, ans = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            odd += nums[i] & 1;
            ans += odd >= k ? cnt[odd - k] : 0;
            cnt[odd] += 1;//ͳ����������֮���ж��ٸ����������Լ�
        }
        return ans;
    }
};

    


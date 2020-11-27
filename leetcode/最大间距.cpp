class Solution {
public:
    struct goods {
        bool _isHave = false;
        int _min = INT_MAX;
        int _max = INT_MIN;
    };

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for(auto& e : nums) minNum = min(minNum,e),maxNum = max(maxNum,e);

        int bucketLen = max(1,(maxNum - minNum) / (n - 1));
        int bucketCnt = (maxNum - minNum) / bucketLen + 1;
        vector<goods> arr(bucketCnt);
        for(auto& e : nums) {
            int p = (e - minNum) / bucketLen;
            arr[p]._isHave = true;
            arr[p]._min = min(arr[p]._min, e);
            arr[p]._max = max(arr[p]._max, e);
        }

        int ans = 0;
        int afterMax = INT_MIN;
        for(auto& e : arr) {
            if(!e._isHave) continue;
            if(afterMax != INT_MIN) ans = max(ans,e._min - afterMax);
            ans = max(ans,e._max - e._min);
            afterMax = e._max;
        }

        return ans;
    }
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        int maxNum = INT_MIN;
        for(auto& e : nums) maxNum = max(maxNum, e);

        vector<int> buf(n);
        int exp = 1;
        while(maxNum >= exp) {
            vector<int> cnt(10,0);
            for(auto& e : nums) cnt[(e / exp) % 10] ++;
            for(int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];

            for(int i = n - 1; i >= 0; i--) 
                buf[-- cnt[(nums[i] / exp) % 10]] = nums[i];
              
            nums.swap(buf);
            exp *= 10;
        }

        int ans = 0;
        for(int i = 1; i < n; i++) ans = max(ans,nums[i] - nums[i - 1]);
        return ans;
    }
};


����һ����������飬�ҳ�����������֮������Ԫ��֮�����Ĳ�ֵ��

�������Ԫ�ظ���С�� 2���򷵻� 0��

ʾ��?1:

����: [3,6,9,1]
���: 3
����: ������������ [1,3,6,9], ��������Ԫ�� (3,6) �� (6,9) ֮�䶼��������ֵ 3��
ʾ��?2:

����: [10]
���: 0
����: ����Ԫ�ظ���С�� 2����˷��� 0��
˵��:

����Լ�������������Ԫ�ض��ǷǸ�����������ֵ�� 32 λ�з���������Χ�ڡ�
�볢��������ʱ�临�ӶȺͿռ临�Ӷȵ������½�������⡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-gap
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

//����һ����������飬�ҳ�����������֮������Ԫ��֮�����Ĳ�ֵ��

//�������Ԫ�ظ���С�� 2���򷵻� 0��

//ʾ��?1:

//����: [3,6,9,1]
//���: 3
//����: ������������ [1,3,6,9], ��������Ԫ�� (3,6) �� (6,9) ֮�䶼��������ֵ 3��
//ʾ��?2:

//����: [10]
//���: 0
//����: ����Ԫ�ظ���С�� 2����˷��� 0��


class Solution {
public:
    struct goods {
        bool _isHave = false;
        int _min = INT_MAX;
        int _max = INT_MIN;
    };
	//Ͱ���� O(n) 
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        int minNum = INT_MAX;
        int maxNum = INT_MIN;

        //���������������ֵ����Сֵ
        for(auto& eoch : nums){
            minNum = min(eoch, minNum);
            maxNum = max(eoch, maxNum);
        }

        //Ͱ�ĳ���  [2,,4,6,8] --> (8 - 2) / (4 - 1) = 2
        //[2,4) [4,6) [6, 8)
        int bucketLen = max(1,(maxNum - minNum) / (len - 1));
        //Ͱ������
        int bucketNum = (maxNum - minNum) / bucketLen + 1;//Ϊ����Ͱ�������ұ�����
        vector<goods> buckets(bucketNum);

        for(auto& eoch : nums){
            //���㵱ǰ��������һ��Ͱ��
            int ret = (eoch - minNum) / bucketLen;
            buckets[ret]._isHave = true;
            buckets[ret]._min = min(buckets[ret]._min, eoch);
            buckets[ret]._max = max(buckets[ret]._max, eoch);
        }
        int ans = 0;
        int afterMax = INT_MIN;//ǰһ����Ч��Ͱ�����ֵ
        for(auto& bucket : buckets){
            if(bucket._isHave == false) continue;
            //���ǰһ��Ͱ���ڣ��͵�ǰͰ��Сֵ��ǰһ��Ͱ���ֵ�Ĳ��
            if(afterMax != INT_MIN) ans = max(ans, bucket._min - afterMax);
            ans = max(ans, bucket._max - bucket._min);
            afterMax = bucket._max; //����ǰһ��Ͱ�����ֵ
        }
        return ans;
    }

    //���� O(nlogn)
    int maximumGap1(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return 0;
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = 1;
        int ans = 0;
        while(right < len){
            ans = max(ans,nums[right] - nums[left]);
            right++;
            left++;
        }
        return ans;
    }
}

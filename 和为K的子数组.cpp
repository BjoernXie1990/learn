//����һ�����������һ������?k������Ҫ�ҵ��������к�Ϊ?k?��������������ĸ�����

//ʾ�� 1 :

//����:nums = [1,1,1], k = 2
//���: 2 , [1,1] �� [1,1] Ϊ���ֲ�ͬ�������
//˵�� :

//����ĳ���Ϊ [1, 20,000]��
//������Ԫ�صķ�Χ�� [-1000, 1000] ��������?k?�ķ�Χ��?[-1e7, 1e7]��



class Solution {
public:
    int subarraySum1(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        int tmp = 0;

        for(int i = 0; i < len; i++)
        {
            tmp = 0;
            for(int j = i; j < len; j++)
            {
                tmp += nums[j];
                if(tmp == k)
                    ans++;
            }
        }
        return ans;
    }

    int subarraySum2(vector<int>& nums, int k)
    {
        int len = nums.size();
        vector<int> arr(len+2,0);
        //����ǰ׺��
        for(int i = 1; i <= len; i++)
            arr[i] = arr[i-1] + nums[i-1];
        // for(int i = 1; i <= len; i++)
        //     cout<<arr[i]<<' ';
        
        int ans = 0;
        //�̶�������
        for(int i = 0; i <= len; i++)
            for(int j = i+1; j <= len; j++)
                if(arr[j]-arr[i] == k) ans++;

        //�̶�������
        // for(int i = 1; i <= len; i++)
        //     for(int j = 0; j <= len; j++)
        //         if(arr[i]-arr[j] == k) ans++;
        return ans;
    }

    //��ϣ+ǰ׺��
    int subarraySum(vector<int>& nums, int k)
    {
        int len = nums.size();
        unordered_map<int,int> map;

        int ans = 0;
        int pre = 0;
        map[0]=1;
        for(int i = 0; i < len; i++)
        {
            pre += nums[i];
            ans += map[pre-k];
            map[pre]++;
        }
        return ans;
    }
};

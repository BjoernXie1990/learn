//����һ��������������������飨���ܰ����ظ����֣�������Ҫ�����Ƿָ�ɼ��������У�
//����ÿ�����������ٰ������������������������Ƿ������������ķָ

//?

//ʾ�� 1��
//����: [1,2,3,3,4,5]
//���: True
//����:
//����Էָ�������������������� : 
//1, 2, 3
//3, 4, 5
//?

//ʾ�� 2��
//����: [1,2,3,3,4,4,5,5]
//���: True
//����:
//����Էָ�������������������� : 
//1, 2, 3, 4, 5
//3, 4, 5
//?

//ʾ�� 3��
//����: [1,2,3,4,4,5]
//���: False


#include <iostream>
#include <vector>
using namespace std;

//�����е��������ݱ������ȫ�����ֳ����������� 
class Solution {
public:
    bool isPossible(vector<int>& nums){
        unordered_map<int,int> freq,need;
        //ͳ��ÿ�����ֳ��ֵĴ���
        for(int num : nums)
            freq[num]++;
        
        for(int num : nums)
        {
            if(freq[num] == 0)
                continue;
            
            if(need[num] > 0)
            {
                need[num]--;
                need[num+1]++;
            }
            else if(freq[num + 1] > 0 && freq[num + 2] > 0)
            {
                freq[num + 1]--;
                freq[num + 2]--;
                need[num + 3]++;
            }
            else
                return false;
            
            freq[num]--;
        }

        return true;
    }
}; 

//������뷨������������Ϊ3������������ 
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int size = 0;//���������е�����
        vector<int> arr(nums.size(),0);

        return isFun(arr,nums) && isFun(arr,nums);
    }

    bool isFun(vector<int>& arr,vector<int>& nums)
    {
        int len = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(arr[i-1] + arr[i] != 0)
                continue;

            if(nums[i] - nums[i-1] == 1)
            {
                len++;
                if(len == 2)
                {
                    arr[i] = 1;
                    int count = 0;
                    //ǰ��������ȫ����1
                    for(int j = i - 1; j >= 0; j--)
                    {
                        if(nums[j] != nums[j+1])
                        {
                            arr[j] = 1;
                            count++;
                        }
                        if(count == 2)
                            return true;
                    }
                }
            }
            else if(nums[i] - nums[i-1])//�����1��
                len = 0;    
                
                //�ų��ظ�Ԫ��
            while(i+1 < nums.size() && nums[i+1] == nums[i])
                    i++;
        }

        return false;
    }
};

int main()
{
	vector<int> nums(6);
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	nums[3] = 4;
	nums[4] = 4;
	nums[5] = 5;
	Solution s1;
	cout<<s1.isPossible(nums)<<endl;
	return 0;
} 

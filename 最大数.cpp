//����һ��Ǹ������������������ǵ�˳��ʹ֮���һ������������

//ʾ�� 1:

//����: [10,2]
//���: 210
//ʾ��?2:

//����: [3,30,34,5,9]
//���: 9534330


class Solution {
public:
    static bool cmp(const string& a,const string& b)
    {
        return a+b > b+a;//30 3 --> 303 330
    }

    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        vector<string> str;

        for(int i = 0; i < len; i++)
            str.push_back(to_string(nums[i]));
        
        sort(str.begin(),str.end(),cmp);
        
        string ans;
        for(int i = 0; i < len; i++)
            ans += str[i];

        return (ans[0]=='0')?"0":ans;
    }
};

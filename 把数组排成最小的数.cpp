����һ���Ǹ��������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����

?

ʾ�� 1:

����: [10,2]
���: "102"
ʾ��?2:

����: [3,30,34,5,9]
���: "3033459"
?

��ʾ:

0 < nums.length <= 100
˵��:

���������ܷǳ�����������Ҫ����һ���ַ�������������
ƴ�����������ֿ��ܻ���ǰ�� 0�����������Ҫȥ��ǰ�� 0



class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str;

        for(auto& eoch : nums)
            str.push_back(to_string(eoch));
        
        sort(str.begin(),str.end(),cmp);

        string ans = "";
        for(auto& eoch : str)
            ans += eoch;
        return ans;
    }

    static bool cmp(const string& a,const string& b)
    {
        return a+b < b+a;
    }
};

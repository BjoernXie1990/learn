���Ǹ��������������� A?��?B��ÿ�����ʶ���һ��Сд��ĸ��

���ڣ����?b �е�ÿ����ĸ�������� a �У������ظ����ֵ���ĸ����ô�Ƶ��� b �ǵ��� a ���Ӽ��� ���磬��wrr�� �� ��warrior�� ���Ӽ��������� ��world�� ���Ӽ���

����� B �е�ÿһ������?b��b ���� a ���Ӽ�����ô���ǳ�?A �еĵ��� a ��ͨ�õġ�

����԰�����˳�����б���ʽ����?A �����е�ͨ�õ��ʡ�

?

ʾ�� 1��

���룺A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
�����["facebook","google","leetcode"]
ʾ�� 2��

���룺A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
�����["apple","google","leetcode"]
ʾ�� 3��

���룺A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
�����["facebook","google"]
ʾ�� 4��

���룺A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
�����["google","leetcode"]
ʾ�� 5��

���룺A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
�����["facebook","leetcode"]
?

��ʾ��

1 <= A.length, B.length <= 10000
1 <= A[i].length, B[i].length?<= 10
A[i]?��?B[i]?ֻ��Сд��ĸ��ɡ�
A[i]?�����еĵ��ʶ��Ƕ�һ�޶��ģ�Ҳ����˵������?i != j?ʹ��?A[i] == A[j]��


class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> arr(26,0);

        for(auto& str : B)
        {
            vector<int> tmp(26,0);
            for(auto& s : str)
                tmp[s - 'a']++;
            
            for(int i = 0; i < 26; i++)
                if(tmp[i] > arr[i]) arr[i] = tmp[i];
        }

        vector<string> ans;

        for(auto& str : A)
        {
            vector<int> tmp(26,0);
            for(auto& s : str)
                tmp[s - 'a']++;
            
            bool flag = true;
            for(int i = 0; i < 26; i++)
                if(arr[i] > tmp[i])
                {
                    flag = false;
                    break;
                }
            
            if(flag)    ans.push_back(str);
        }

        return ans;
    }
};

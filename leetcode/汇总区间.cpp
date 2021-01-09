class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0) return ans;

        int le = nums[0];
        int ri = le;
        for(int i = 1; i < n; i++) {
            if(ri + 1 != nums[i]) {
                if(le == ri) 
                    ans.push_back(to_string(le));
                else
                    ans.push_back(to_string(le) + "->" + to_string(ri));
                le = nums[i];
                ri = le;
            } else {
                ri ++;
            }
        }
        if(le == ri) 
            ans.push_back(to_string(le));
        else
            ans.push_back(to_string(le) + "->" + to_string(ri));
        return ans;
    }
};

����һ�����ظ�Ԫ�ص������������� nums ��

���� ǡ�ø����������������� �� ��С���� ���䷶Χ�б�Ҳ����˵��nums ��ÿ��Ԫ�ض�ǡ�ñ�ĳ�����䷶Χ�����ǣ����Ҳ���������ĳ����Χ�������� nums ������ x ��

�б��е�ÿ�����䷶Χ [a,b] Ӧ�ð����¸�ʽ�����

"a->b" ����� a != b
"a" ����� a == b
?

ʾ�� 1��

���룺nums = [0,1,2,4,5,7]
�����["0->2","4->5","7"]
���ͣ����䷶Χ�ǣ�
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
ʾ�� 2��

���룺nums = [0,2,3,4,6,8,9]
�����["0","2->4","6","8->9"]
���ͣ����䷶Χ�ǣ�
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
ʾ�� 3��

���룺nums = []
�����[]
ʾ�� 4��

���룺nums = [-1]
�����["-1"]
ʾ�� 5��

���룺nums = [0]
�����["0"]
?

��ʾ��

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
nums �е�����ֵ�� ������ͬ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/summary-ranges
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

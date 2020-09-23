class Solution {
public:
    string convertToTitle(int n) {
        if(n < 0) return "";

        string ans("");
        while(n) {
            n--;
            ans += (n % 26 + 'A');
            n /= 26;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};


����һ������������������ Excel �������Ӧ�������ơ�

���磬

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
ʾ�� 1:

����: 1
���: "A"
ʾ��?2:

����: 28
���: "AB"
ʾ��?3:

����: 701
���: "ZY"

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/excel-sheet-column-title
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

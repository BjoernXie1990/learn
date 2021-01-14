class Solution {
public:
    int findString(vector<string>& words, string s) {
        int le = 0, ri = words.size() - 1;
        while(le < ri) {
            int mid = (le + ri) / 2;
            while(mid > le && words[mid] == "") mid--;
            if(words[mid] == s) return mid;
            else if(words[mid] < s) le = mid + 1;
            else ri = mid;
        }

        return words[le] == s ? le : -1;
    }
};


ϡ�������������и��ź�����ַ������飬����ɢ����һЩ���ַ�������дһ�ַ������ҳ������ַ�����λ�á�

ʾ��1:

 ����: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
 �����-1
 ˵��: �����ڷ���-1��
ʾ��2:

 ���룺words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
 �����4
��ʾ:

words�ĳ�����[1, 1000000]֮��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sparse-array-search-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

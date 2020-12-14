class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;
        //sort(strs.begin(),strs.end());
        for(int i = 0; i < n; i++) {
            int j = 0;
            for(; j < n; j++) {
                if(i == j)
                    continue;
                if(check(strs[j],strs[i]))
                    break;
            }
            if(j == n) 
                ans = max(ans,(int)strs[i].size());
        }

        return ans;
    }

    bool check(string& le,string ri) {
        int n = le.size();
        int m = ri.size();
        int id = 0;
        for(int i = 0; i < n && id < m; i++) {
            if(le[i] == ri[id])
                id++;
        }
        return id == m;
    }
};


�����ַ����б�����Ҫ���������ҳ�����������С���������ж������£�������Ϊĳ�ַ������е�������У��������������ַ����������У���

�����п���ͨ��ɾȥ�ַ����е�ĳЩ�ַ�ʵ�֣������ܸı�ʣ���ַ������˳�򡣿�����Ϊ�����ַ����������У��κ��ַ���Ϊ������������С�

���뽫��һ���ַ����б��������������еĳ��ȡ������������в����ڣ����� -1 ��

?

ʾ����

����: "aba", "cdc", "eae"
���: 3
?

��ʾ��

���и������ַ������Ȳ��ᳬ�� 10 ��
�����ַ����б�ĳ��Ƚ��� [2, 50 ] ֮�䡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-uncommon-subsequence-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

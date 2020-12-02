class Solution {
public:
    typedef pair<int,int> PII;
    struct com{
        bool operator()(const PII& a,const PII& b) {
            return a.second < b.second;
        }
    };
    
    string reorganizeString(string s) {
        int f[26];
        memset(f,0x00,sizeof f);
        for(auto& ch : s) f[ch - 'a'] ++;

        priority_queue<PII,vector<PII>,com> pq;
        for(int i = 0; i < 26; i++) 
            if(f[i]) pq.push(make_pair(i + 'a',f[i]));

        string ans("");
        PII pre = make_pair(0,0);
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            ans += t.first;
            if(pre.second) pq.push(pre);
            pre = t;
            pre.second--;
        }

        return pre.second ? "" : ans;
    }
};


����һ���ַ���S������Ƿ��������Ų����е���ĸ��ʹ�������ڵ��ַ���ͬ��

�����У����������еĽ�����������У����ؿ��ַ�����

ʾ��?1:

����: S = "aab"
���: "aba"
ʾ�� 2:

����: S = "aaab"
���: ""
ע��:

S ֻ����Сд��ĸ���ҳ�����[1, 500]�����ڡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reorganize-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

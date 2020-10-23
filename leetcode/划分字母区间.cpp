class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        
        int cnt[26];
        memset(cnt,0x00,sizeof cnt);
        for(int i = 0; i < n; i++) cnt[S[i] - 'a'] = i;

        int le = 0;
        vector<int> ans;
        int ri = 0;
        for(int i = 0; i < n; i++) {
            ri = max(ri,cnt[S[i] - 'a']);
            if(i == ri) {
                ans.push_back(ri - le + 1);
                le = i + 1;
            }
        }

        return ans;
    }
};


�ַ��� S ��Сд��ĸ��ɡ�����Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ����ĸֻ����������е�һ��Ƭ�Ρ�����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�

?

ʾ�� 1��

���룺S = "ababcbacadefegdehijhklij"
�����[9,7,8]
���ͣ�
���ֽ��Ϊ "ababcbaca", "defegde", "hijhklij"��
ÿ����ĸ��������һ��Ƭ���С�
�� "ababcbacadefegde", "hijhklij" �Ļ����Ǵ���ģ���Ϊ���ֵ�Ƭ�������١�
?

��ʾ��

S�ĳ�����[1, 500]֮�䡣
Sֻ����Сд��ĸ 'a' �� 'z' ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/partition-labels
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

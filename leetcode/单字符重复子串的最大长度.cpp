����ַ����е������ַ�����ͬ����ô����ַ����ǵ��ַ��ظ����ַ�����

����һ���ַ���?text����ֻ�ܽ������������ַ�һ�λ���ʲô��������Ȼ��õ�һЩ���ַ��ظ����Ӵ���������������Ӵ��ĳ��ȡ�

?

ʾ�� 1��

���룺text = "ababa"
�����3
ʾ�� 2��

���룺text = "aaabaaa"
�����6
ʾ�� 3��

���룺text = "aaabbaaa"
�����4
ʾ�� 4��

���룺text = "aaaaa"
�����5
ʾ�� 5��

���룺text = "abcdef"
�����1
?

��ʾ��

1 <= text.length <= 20000
text ����СдӢ����ĸ��ɡ�


class Solution {
public:
    int maxRepOpt1(string text) {
        vector<pair<int,int> > rec;
        for(auto& ch : text)
            if(rec.empty() || rec.back().first != ch - 'a')
                rec.push_back({ch - 'a',1});
            else
                rec.back().second++;
        
        int len = rec.size();
        vector<int> cnt(26,0);
        for(int i = 0; i < len; i++)
            cnt[rec[i].first]++;
        
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            if(i > 0 && i < len-1 && rec[i].second == 1
                && rec[i-1].first == rec[i+1].first)
            {
                //...aaaabaaaa...
                int tmp = rec[i-1].second + rec[i+1].second;
                //...aaaabaaaa...a...
                if(cnt[rec[i-1].first] > 2) tmp++;
                ans = max(ans,tmp);
            }

            //...aaaa...a...
            ans = max(ans,rec[i].second + (cnt[rec[i].first] > 1));
        }

        return ans;
    }
};

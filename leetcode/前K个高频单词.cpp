class Solution {
public:
    using key = pair<string,int>;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> word;
        for(auto& str : words) word[str]++;
        
        vector<key> copy;
        for(auto w : word) copy.push_back(w);

        sort(copy.begin(),copy.end(),[](const auto& a,const auto& b)->bool {
            if(a.second != b.second) return a.second > b.second;

            return strcmp(a.first.c_str(),b.first.c_str()) == -1 ? true : false;
        });

        vector<string> ans;
        for(int i = 0; i < k; i++) ans.push_back(copy[i].first);

        return ans;
    }
};

��һ�ǿյĵ����б�����ǰ?k?�����ִ������ĵ��ʡ�

���صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ�����ĸ˳������

ʾ�� 1��

����: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
���: ["i", "love"]
����: "i" �� "love" Ϊ���ִ��������������ʣ���Ϊ2�Ρ�
    ע�⣬����ĸ˳�� "i" �� "love" ֮ǰ��
?

ʾ�� 2��

����: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
���: ["the", "is", "sunny", "day"]
����: "the", "is", "sunny" �� "day" �ǳ��ִ��������ĸ����ʣ�
    ���ִ�������Ϊ 4, 3, 2 �� 1 �Ρ�
?

ע�⣺

�ٶ� k ��Ϊ��Чֵ�� 1 �� k �� ����Ԫ������
����ĵ��ʾ���Сд��ĸ��ɡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/top-k-frequent-words
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

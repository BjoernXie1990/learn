����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����

ʾ��:

����: ["eat", "tea", "tan", "ate", "nat", "bat"]
���:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
˵����

���������ΪСд��ĸ��
�����Ǵ������˳��




class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > hash;

        vector<vector<string> > ans;

        for(auto& str : strs)
        {
            string key = str;
            sort(key.begin(),key.end());
            hash[key].push_back(str);
        }

        for(auto& it : hash)
            ans.push_back(it.second);
        return ans;
    }
};

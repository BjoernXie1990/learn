����һ��Ψһ�ĵ��ʣ� �ҳ����в�ͬ?��������(i, j)��ʹ���б��е��������ʣ�?words[i] + words[j]?����ƴ�ӳɻ��Ĵ���

ʾ�� 1:

����: ["abcd","dcba","lls","s","sssll"]
���: [[0,1],[1,0],[3,2],[2,4]] 
����: ��ƴ�ӳɵĻ��Ĵ�Ϊ ["dcbaabcd","abcddcba","slls","llssssll"]
ʾ�� 2:

����: ["bat","tab","cat"]
���: [[0,1],[1,0]] 
����: ��ƴ�ӳɵĻ��Ĵ�Ϊ ["battab","tabbat"]

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> map;
        for(int i = 0; i < words.size(); i++)
        {
            string key = words[i];
            reverse(key.begin(),key.end());
            map[key]=i;
        }

        vector<vector<int> > ans;
        if(map.count("") > 0)//����""�ַ���ʱ
        {
            int pos = map[""];
            for(auto& eoch : map)
            {
                auto str = eoch.first;
                if(str == "")    continue;
                if(isPalindrome(str) == true)
                    ans.push_back({pos,eoch.second});
            }
        }

        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < words[i].size(); j++)
            {
                string le = words[i].substr(0,j);
                string ri = words[i].substr(j);

                //le + ri + le������  riΪ�����ַ���
                if(map.count(le) > 0 && isPalindrome(ri) && map[le] != i)
                    ans.push_back({i,map[le]});
                
                //ri������ + le + ri  leΪ�����ַ���
                if(map.count(ri) > 0 && isPalindrome(le) && map[ri] != i)
                    ans.push_back({map[ri],i});
            }
        return ans;
    }

    bool isPalindrome(string str)
    {
        int le = 0;
        int ri = str.size()-1;
        while(le < ri && str[le] == str[ri])
        {
            le++;
            ri--;
        }

        return !(le < ri);
    }
};

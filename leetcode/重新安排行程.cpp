����һ����Ʊ���ַ�����ά���� [from, to]���������е�������Ա�ֱ��ʾ�ɻ������ͽ���Ļ����ص㣬�Ը��г̽������¹滮����������Щ��Ʊ������һ���� JFK������Ϲ��ʻ��������������������Ը��г̱���� JFK ��ʼ��

˵��:

������ڶ�����Ч���г̣�����԰��ַ���Ȼ���򷵻���С���г���ϡ����磬�г� ["JFK", "LGA"] �� ["JFK", "LGB"] ��Ⱦ͸�С���������ǰ
���еĻ�������������д��ĸ��ʾ���������룩��
�ٶ����л�Ʊ���ٴ���һ�ֺ�����г̡�
ʾ�� 1:

����: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
���: ["JFK", "MUC", "LHR", "SFO", "SJC"]
ʾ�� 2:

����: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
���: ["JFK","ATL","JFK","SFO","ATL","SFO"]
����: ��һ����Ч���г���?["JFK","SFO","ATL","JFK","ATL","SFO"]����������Ȼ������������


class Solution {
public:
    unordered_map<string,multiset<string> > map_t;
    int count = 0;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& eoch : tickets){
            map_t[eoch[0]].insert(eoch[1]);
            count += 2;
        }

        vector<string> ans;
        string from = "JFK";

        dfs(ans,from);
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void dfs(vector<string>& ans,string& from){

        while(map_t[from].empty() == false){
            auto it = map_t[from].begin();
            string to = *it;
            map_t[from].erase(it);

            dfs(ans,to);
        }
        ans.push_back(from);
    }
};

class Solution {
public:
    unordered_map<string,int> id;
    vector<int> f;
    vector<int> sz;
    int find(int x) {
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        int n = names.size();
        vector<string> vec(n);
        f.reserve(n);
        sz.reserve(n);
        for(int i = 0; i < n; i++) f[i] = i;
        for(int i = 0; i < n; i++) {
            int start = names[i].find("(");
            int end = names[i].find(")");
            string name = names[i].substr(0,start);
            int cnt = stoi(names[i].substr(start+1,end-start-1));
            id[name] = i;
            vec[i] = name;
            sz[i] = cnt;
        }

        for(auto& e : synonyms) {
            int pos = e.find(",");
            string le = e.substr(1,pos-1);
            string ri = e.substr(pos+1,e.size()-2-pos);
            auto leid = id[le];
            auto riid = id[ri];
            int x = find(leid);
            int y = find(riid);
            if(x == y) continue;
            
            if(vec[x] > vec[y]) swap(x,y);
            f[y] = x;
            sz[x] += sz[y];
        }

        set<int> st;
        vector<string> res;
        for(auto& e : vec) {
            auto eid = id[e];
            int fa = find(eid);
            if(!st.count(fa)) {
                res.push_back(vec[fa] + "(" + to_string(sz[fa]) + ")");
                st.insert(fa);
            }
        }

        return res;
    }
};

ÿ�꣬�������ṫ��һ��������Ӥ�����ֺ����ǳ��ֵ�Ƶ�ʣ�Ҳ����ͬ��Ӥ������������Щ�����ж���ƴ�������磬John �� Jon ����������ͬ�����֣������������������ֹ������������������б�һ�������ּ���Ӧ��Ƶ�ʣ���һ���Ǳ�����ͬ�����ֶԡ����һ���㷨��ӡ��ÿ����ʵ���ֵ�ʵ��Ƶ�ʡ�ע�⣬��� John �� Jon ����ͬ�ģ����� Jon �� Johnny ��ͬ���� John �� Johnny Ҳ��ͬ���������д��ݺͶԳ��ԡ�

�ڽ���б��У�ѡ�� �ֵ�����С ��������Ϊ��ʵ���֡�

?

ʾ����

���룺names = ["John(15)","Jon(12)","Chris(13)","Kris(4)","Christopher(19)"], synonyms = ["(Jon,John)","(John,Johnny)","(Chris,Kris)","(Chris,Christopher)"]
�����["John(27)","Chris(36)"]
?

��ʾ��

names.length <= 100000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/baby-names-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

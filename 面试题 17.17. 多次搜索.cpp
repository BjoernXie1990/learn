//����һ���ϳ��ַ���big��һ�������϶��ַ���������smalls�����һ��������
//����smalls�е�ÿһ���϶��ַ�������big����������
//���smalls�е��ַ�����big����ֵ�����λ��positions������positions[i]Ϊsmalls[i]���ֵ�����λ�á�

//ʾ����

//���룺
//big = "mississippi"
//smalls = ["is","ppi","hi","sis","i","ssippi"]
//����� [[1,4],[8],[],[3],[1,4,7,10],[5]]
//��ʾ��

//0 <= len(big) <= 1000
//0 <= len(smalls[i]) <= 1000
//smalls�����ַ������ᳬ�� 100000��
//�������Ϊsmalls��û���ظ��ַ�����
//���г��ֵ��ַ���ΪӢ��Сд��ĸ��




class Solution {
public:
    //KMP
    vector<vector<int>> multiSearch1(string big, vector<string>& smalls) {
        vector<vector<int> > ans;

        for(auto& eoch : smalls)
            ans.push_back(KMP(big,eoch));
        return ans;
    }

    vector<int> KMP(string& s,string& p)
    {
        vector<int> ret;

        int lens = s.size();
        int lenp = p.size();
        //����пմ���ֱ�ӷ���
        if(!lens || !lenp) return ret;

        vector<int> next(lenp,0);
        for(int i = 1, j = 0; i < lenp; i++)
        {
            while(j && p[i] != p[j])
                j = next[j-1];
            if(p[i] == p[j])
                j++;
            next[i]=j;
        }

        for(int i = 0,j = 0; i < lens; i++)
        {
            while(j && s[i]!=p[j])
                j = next[j-1];
            if(s[i]==p[j])
                j++;
            if(j == lenp)
            {
                ret.push_back(i-lenp+1);
                j = next[j-1];
            }
        }

        return ret;
    }

    //�ֵ���
    const static int N = 100010;
    int son[N][26];
    int idx;
    string key[N];//��¼Ҷ�ӽڵ�
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        for(auto& eoch : smalls)
            insert(eoch);
        
        unordered_map<string,vector<int> > hash;
        for(int i = 0; i < big.size(); i++)
            search(big,i,hash);

        vector<vector<int> > ans;
        for(auto& eoch : smalls)
            ans.push_back(hash[eoch]);
        return ans;
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p]=s;
    }

    void search(string& s,int index,unordered_map<string,vector<int> >& hash)
    {
        int p = 0;
        for(int i = index; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return ;
            p = son[p][u];
            if(key[p]!="") hash[key[p]].push_back(index);
        }
    }
    
};

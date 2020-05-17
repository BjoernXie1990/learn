//����һ������ favoriteCompanies ������ favoriteCompanies[i] �ǵ� i ���û��ղصĹ�˾�嵥���±�� 0 ��ʼ����

//���ҳ����������κ����ղصĹ�˾�嵥���Ӽ����ղ��嵥�������ظ��嵥�±ꡣ�±���Ҫ���������С�

// 

//ʾ�� 1��

//���룺favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
//�����[0,1,4] 
//���ͣ�
//favoriteCompanies[2]=["google","facebook"] �� favoriteCompanies[0]=["leetcode","google","facebook"] ���Ӽ���
//favoriteCompanies[3]=["google"] �� favoriteCompanies[0]=["leetcode","google","facebook"] �� favoriteCompanies[1]=["google","microsoft"] ���Ӽ���
//������ղ��嵥�����������κ����ղصĹ�˾�嵥���Ӽ�����ˣ���Ϊ [0,1,4] ��
//ʾ�� 2��

//���룺favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
//�����[0,1] 
//���ͣ�favoriteCompanies[2]=["facebook","google"] �� favoriteCompanies[0]=["leetcode","google","facebook"] ���Ӽ�����ˣ���Ϊ [0,1] ��
//ʾ�� 3��

//���룺favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
//�����[0,1,2,3]

class Solution {
public:

        vector<int> peopleIndexes(vector<vector<string>>& ff)
        {
            int n = ff.size();
            vector<vector<int> > f(n);
            unordered_map<string,int> map;
            
            for(int i = 0; i < n; i++)
            {
                for(auto& eoch : ff[i])
                {
                    if(!map.count(eoch)) map[eoch] = map.size();
                    
                    f[i].push_back(map[eoch]);
                }
                sort(f[i].begin(),f[i].end());
            }
            
            vector<int> ans;
            for(int i = 0; i < n; i++)
            {
                bool flag = false;
                for(int j = 0; j < n; j++)
                    if(i != j && f[i].size() < f[j].size() && check(f,i,j))
                    {
                        flag = true;
                        break;
                    }
                if(!flag) ans.push_back(i);
            }
            return ans;
        }
    
        bool check(vector<vector<int> >& f,int x,int y)
        {
            int len = 0;
            for(int i = 0; i < f[x].size(); i++)
            {
                while(len < f[y].size() && f[x][i] != f[y][len])
                    len++;
                if(len == f[y].size())
                    return false;
            }
            return true;
        }

//      ��ʱ    
//     vector<int> peopleIndexes(vector<vector<string>>& f) {
//         unordered_map<string,vector<int> > map;
//         unordered_map<string,int> hash;
//         int n = 0;
//         for(int i = 0; i < f.size(); i++)
//             for(auto& e : f[i])
//             {
//                 if(hash.find(e) == hash.end())
//                     hash[e] = n++;
//             }
//         // for(int i = 0; i < f[0].size(); i++)
//         //     cout<<hash[f[0][i]]<<' ';

//         for(int i = 0; i < f.size(); i++)
//             for(auto& e : f[i])
//                 map[e].push_back(i);
        
        
        
//         vector<int> ret;
//         for(int i = 0; i < f.size(); i++)
//         {
//             bool flag = true;
//             for(auto& eoch : f[i])
//             {
//                 flag = dfs(eoch,map,hash,f,i);
//                 if(!flag)
//                     break;
//             }
//             if(flag) ret.push_back(i);
//         }
//         return ret;
       
//     }
    
//     static bool dfs(string& str, unordered_map<string,vector<int> >& map,unordered_map<string,int>& hash,vector<vector<string>>& f,int index)
//     {
//         for(auto& eoch : map[str])
//         {
//             if(index == eoch)
//                 continue;
//             int n = 0;
//             if(f[eoch].size() < f[index].size()) continue;
            
            
//             for(auto& a : f[index])
//             {
//                 int tmp = n;
//                 for(auto& e : f[eoch])
//                     if(hash[e] == hash[a])
//                     {
//                         n++;
//                         break;
//                     }
                
//                 if(n == tmp)
//                     break;
//             }
                
//             if(n == f[index].size()) return false;
//         }
        
//         return true;
//     }
};

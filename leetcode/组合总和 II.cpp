
����һ������?candidates?��һ��Ŀ����?target?���ҳ�?candidates?�����п���ʹ���ֺ�Ϊ?target?����ϡ�

candidates?�е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�

˵����

�������֣�����Ŀ������������������
�⼯���ܰ����ظ�����ϡ�?
ʾ��?1:

����: candidates =?[10,1,2,7,6,1,5], target =?8,
����⼯Ϊ:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
ʾ��?2:

����: candidates =?[2,5,2,1,2], target =?5,
����⼯Ϊ:
[
? [1,2,2],
? [5]
]

class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(),candidates.end(),[](const int a,const int b)->bool{
            return a < b;
        });

        dfs(tmp,candidates,0,0,target);

        return ans;
    }

    void dfs(vector<int>& tmp,vector<int>& candidates,int idx,int cur,int target) {
        if(cur > target) return ;
        if(cur == target) {
            ans.push_back(tmp);
            return ;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            
            tmp.push_back(candidates[i]);

            dfs(tmp,candidates,i+1,cur + candidates[i],target);

            tmp.pop_back();
        }
    }
};

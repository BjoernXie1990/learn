����һ�����ظ�Ԫ�ص�����?candidates?��һ��Ŀ����?target?���ҳ�?candidates?�����п���ʹ���ֺ�Ϊ?target?����ϡ�

candidates?�е����ֿ����������ظ���ѡȡ��

˵����

�������֣�����?target��������������
�⼯���ܰ����ظ�����ϡ�?
ʾ��?1��

���룺candidates = [2,3,6,7], target = 7,
����⼯Ϊ��
[
  [7],
  [2,2,3]
]
ʾ��?2��

���룺candidates = [2,3,5], target = 8,
����⼯Ϊ��
[
? [2,2,2,2],
? [2,3,3],
? [3,5]
]
?

��ʾ��

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate �е�ÿ��Ԫ�ض��Ƕ�һ�޶��ġ�
1 <= target <= 500

class Solution {
public:
    int n = 0;
    vector<vector<int> > ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),[](const int a,const int b)->bool{
            return a < b;
        });
        n = candidates.size();

        vector<int> tmp;
        dfs(candidates,tmp,0,0,target);

        return ans;
    }

    void dfs(vector<int>& candidates,vector<int>& tmp,int idx,int cur,int sum) {
        if (cur == sum) {
            ans.push_back(tmp);
            return ;
        }
        //cout<<cur<<' ';
        if(idx >= n || cur > sum)    return ;

        for(int i = idx; i < n; i++) {
            tmp.push_back(candidates[i]);
            dfs(candidates,tmp,i,cur + candidates[i],sum);
            tmp.pop_back();
        }
    }
};

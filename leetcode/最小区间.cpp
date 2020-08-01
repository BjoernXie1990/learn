����?k?���������е��������顣�ҵ�һ����С���䣬ʹ��?k?���б��е�ÿ���б�������һ�������������С�

���Ƕ������?b-a < d-c?������?b-a == d-c?ʱ?a < c�������� [a,b] �� [c,d] С��

ʾ�� 1:

����:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
���: [20,24]
����: 
�б� 1��[4, 10, 15, 24, 26]��24 ������ [20,24] �С�
�б� 2��[0, 9, 12, 20]��20 ������ [20,24] �С�
�б� 3��[5, 18, 22, 30]��22 ������ [20,24] �С�
ע��:

�������б���ܰ����ظ�Ԫ�أ����������������ʾ >= ��
1 <= k <= 3500
-105 <= Ԫ�ص�ֵ?<= 105
����ʹ��Java���û�����ע�⴫���������޸�ΪList<List<Integer>>�����ô���ģ�����Կ�������Ķ���


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int> > goods;

        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < nums[i].size(); j++)
                goods.push_back({nums[i][j],i});
        
        sort(goods.begin(),goods.end(),
            [](const pair<int,int>& a,const pair<int,int>& b)->bool
            {
                if(a.first != b.first)
                    return a.first < b.first;
                return a.second < b.second;
            }
        );

        int le = 0;
        int sum = 0;
        vector<int> arr(nums.size(),0);

        int ans_le = 0;
        int ans_ri = 0;
        int len = INT_MAX;

        for(int i = 0; i < goods.size(); i++)
        {
            if(arr[goods[i].second] == 0)   sum++;
            arr[goods[i].second]++;

            while((le <= i) && (arr[goods[le].second] > 1))
            {
                 arr[goods[le].second]--;
                 le++;
            }
               
            int tmp = goods[i].first - goods[le].first;
            if(sum == nums.size() && tmp < len)
            {
                ans_le = le;
                ans_ri = i;
                len = tmp;
            }
        }

        return {goods[ans_le].first,goods[ans_ri].first};
    }
};

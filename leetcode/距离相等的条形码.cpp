��һ���ֿ����һ�������룬���е� i ��������Ϊ?barcodes[i]��

��������������Щ�����룬ʹ�����������ڵ������� ���� ��ȡ� ����Է����κ������Ҫ��Ĵ𰸣����Ᵽ֤���ڴ𰸡�

?

ʾ�� 1��

���룺[1,1,1,2,2,2]
�����[2,1,2,1,2,1]
ʾ�� 2��

���룺[1,1,1,1,2,2,3,3]
�����[1,3,1,3,2,1,2,1]
?

��ʾ��

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

class Solution {
public:
    using key = pair<int,int>;
    struct cmp
    {
        bool operator()(const key& a,const key& b)
        {
            return a.second < b.second;//���
        }
    };
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> map;
        for(auto& num : barcodes)
            map[num]++;

        priority_queue<key,vector<key>,cmp> que;
        for(auto& eoch : map)
        {
            key tmp;
            tmp.first = eoch.first;
            tmp.second = eoch.second;
            que.push(tmp);
        }

        vector<int> ans(barcodes.size(),0);
        int p = 0;
        while(!que.empty())
        {
            auto top = que.top();
            que.pop();

            while(top.second > 0)
            {
                if(p >= barcodes.size()) p = 1;
                ans[p] = top.first;
                p += 2;
                top.second--;
            }
        }

        return ans;
    }
};

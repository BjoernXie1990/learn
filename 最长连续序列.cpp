//����һ��δ������������飬�ҳ���������еĳ��ȡ�

//Ҫ���㷨��ʱ�临�Ӷ�Ϊ?O(n)��

//ʾ��:

//����:?[100, 4, 200, 1, 3, 2]
//���: 4
//����: ����������� [1, 2, 3, 4]�����ĳ���Ϊ 4��

class UnionFind
{
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> cnt;

    UnionFind(vector<int>& nums)
    {
        for(auto& eoch : nums)
        {
            parent[eoch] = eoch;
            cnt[eoch] = 1;
        }
    }

    //�Ҹ��׽ڵ㣬ֻ�и��׽ڵ������ֵ����ͬ��
    int Find(int pos)
    {
       	// while(pos != parent[pos])
        //     pos = parent[pos];

        //·��ѹ��
        if(pos != parent[pos]) parent[pos] = Find(parent[pos]);
        return parent[pos];
    }

    //���鼯�ĺϲ�
    void UnionElem(int p,int r)
    {
        int proot = Find(p);
        int rroot = Find(r);
        //�����˵������ͬһ�������У����Ժϲ�
        if(proot != rroot)
        {
            parent[proot] = rroot;
            cnt[rroot] += cnt[proot];
        }
    }
};

class Solution {
public:
    //���鼯 O(n)
    int longestConsecutive(vector<int>& nums)
    {
        int len = nums.size();
        if(len < 1) return 0;

        UnionFind uf(nums);
        for(auto& num : nums)
            if(uf.parent.find(num+1) != uf.parent.end())//ȷ����һ��Ԫ�ش��� 
                uf.UnionElem(num,num+1);//�ж��Ƿ���Ժϲ�
        
        int ans = 0;
        //ͳ�Ƴ���
        for(auto& eoch : uf.cnt)
            ans = max(ans,eoch.second);
        return ans;
    }

    //���� O(n * log(n))
    int longestConsecutive1(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < len - 1; i++)
            nums[i] = nums[i+1] - nums[i];
        
        nums[len-1] = -1;//��ֹ [1,1,1]
        int ans = 1;
        int count = 0;
        for(int i = 0; i < len; i++)
            if(nums[i] == 1)
            {
                count++;
                ans = max(ans,count+1);
            }
            else if(nums[i] != 0)
                count = 0;
        return ans;
    }

   
};



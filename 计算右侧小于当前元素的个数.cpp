����һ���������� nums����Ҫ�󷵻�һ��������?counts������ counts �и����ʣ� counts[i] ��ֵ��? nums[i] �Ҳ�С��?nums[i] ��Ԫ�ص�������

ʾ��:

����: [5,2,6,1]
���: [2,1,1,0] 
����:
5 ���Ҳ��� 2 ����С��Ԫ�� (2 �� 1).
2 ���Ҳ���� 1 ����С��Ԫ�� (1).
6 ���Ҳ��� 1 ����С��Ԫ�� (1).
1 ���Ҳ��� 0 ����С��Ԫ��.

class Solution {
public:
    struct TreeNode
    {
        TreeNode* _left;
        TreeNode* _right;
        int _val;
        int _count;//�������ڵ����
        TreeNode(int _v = 0)
            :_val(_v),_left(nullptr),_right(nullptr),_count(0)
        {}
    };
    //��״ ����
    vector<int> countSmaller2(vector<int>& nums)
    {
        TreeNode* root = nullptr;
        int len = nums.size();
        vector<int> ans(len,0);
        for(int i = len-1; i >= 0; i--)
            dfs(root,nums[i],ans,i);
        return ans;
    }

    void dfs(TreeNode*& root,int val,vector<int>& ans,int p)
    {
        if(root == nullptr)
        {
            root = new TreeNode(val);
            return;
        }

        if(val <= root->_val)
        {
            root->_count++;
            dfs(root->_right,val,ans,p);
        }
        else
        {
            ans[p] += root->_count + 1;
            dfs(root->_left,val,ans,p);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> ans(len,0);
        deque<int> tmp;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            ans[i] = BinaryFind(tmp,nums[i]);
            tmp.insert(tmp.begin() + ans[i],nums[i]);
        }
        return ans;
    }

    int BinaryFind(deque<int>& arr,int num)
    {
        if(arr.size() == 0)
            return 0;
        int le = 0;
        int ri = arr.size();
        while(le < ri)
        {
            int mid = (le + ri) / 2;
            if(arr[mid] < num) le = mid + 1;
            else if(arr[mid] >= num) ri = mid;
        }
        return le;
    }


    //�鲢
    vector<int> countSmaller1(vector<int>& nums) {
        vector<pair<int,int> > copy;
        for(int i = 0; i < nums.size(); i++)
            copy.push_back({nums[i],i});
        vector<pair<int,int> > tmp = copy;
        vector<int> ans(nums.size(),0);

        MergerSort(copy,tmp,0,nums.size()-1,ans);
        return ans;
    }

    void MergerSort(vector<pair<int,int> >& nums,vector<pair<int,int> >& tmp,int le,int ri,vector<int>& ans)
    {
        if(le >= ri)    return;
        int mid = (le + ri) / 2;
        MergerSort(nums,tmp,le,mid,ans);
        MergerSort(nums,tmp,mid+1,ri,ans);
        //��ֹ����������������
        if(nums[mid].first <= nums[mid+1].first)
            return;

        int pl = le;
        int pr = mid+1;
        for(int i = le; i <= ri; i++)
        {
            if(pl > mid)//������Ԫ���������
            {
                tmp[i] = nums[pr++];
            }
            else if(pr > ri)//������Ԫ���������
            {
                tmp[i] = nums[pl++];
                ans[tmp[i].second] += ri - mid;//��ʱ����������Ԫ�ض��������С
            }
            else if(nums[pl].first <= nums[pr].first)//�Ƚ�С��Ԫ����������
            {
                tmp[i] = nums[pl++];
                ans[tmp[i].second] += pr - mid - 1;
            }
            else if(nums[pl].first > nums[pr].first)//�Ƚ�С��Ԫ����������
            {
                tmp[i] = nums[pr++];
            }
        }

        for(int i = le; i <= ri; i++)
            nums[i] = tmp[i];
    }
};

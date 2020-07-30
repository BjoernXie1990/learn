����һ���ǿյ��������飬�������г���Ƶ��ǰ?k?�ߵ�Ԫ�ء�

?

ʾ�� 1:

����: nums = [1,1,1,2,2,3], k = 2
���: [1,2]
ʾ�� 2:

����: nums = [1], k = 1
���: [1]
?

��ʾ��

����Լ��������?k?���Ǻ���ģ��� 1 �� k �� �����в���ͬ��Ԫ�صĸ�����
����㷨��ʱ�临�Ӷȱ������� O(n log n) ,?n?������Ĵ�С��
��Ŀ���ݱ�֤��Ψһ�����仰˵��������ǰ k ����ƵԪ�صļ�����Ψһ�ġ�
����԰�����˳�򷵻ش𰸡�


class Solution {
public:
    struct cmp
    {
        bool operator()(const pair<int,int>& x,const pair<int,int>& y)
        {
            if(x.first != y.first)  
                return x.first > y.first;
            return x.second > y.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto& num : nums)   map[num]++;

        //С���� greater x>y
        using type = pair<int,int>;
        priority_queue<type,vector<type>, cmp> heap;

        cmp com;
        for(auto& eoch : map)
        {
            type tmp = {eoch.second,eoch.first};
            if(heap.size() == k)
            {
                if(com(tmp,heap.top()) == false) continue;
                heap.pop();
            }
            heap.push(tmp);
        }

        vector<int> ret;
        while(k--)
        {
            ret.push_back(heap.top().second);
            heap.pop();
        }
        return ret;
    }
};

class KthLargest {
public:
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        for(auto& e : nums) pq.push(e);
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > k)
            pq.pop();
        return pq.top();
    }
private:
    priority_queue<int,vector<int>,greater<int> > pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
 
 ���һ���ҵ��������е� k ��Ԫ�ص��ࣨclass����ע���������ĵ� k ��Ԫ�أ����ǵ� k ����ͬ��Ԫ�ء�

��ʵ�� KthLargest?�ࣺ

KthLargest(int k, int[] nums) ʹ������ k �������� nums ��ʼ������
int add(int val) �� val ���������� nums �󣬷��ص�ǰ�������е� k ���Ԫ�ء�
?

ʾ����

���룺
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
�����
[null, 4, 5, 5, 8, 8]

���ͣ�
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
?

��ʾ��
1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
������ add ���� 104 ��
��Ŀ���ݱ�֤���ڲ��ҵ� k ��Ԫ��ʱ�������������� k ��Ԫ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/kth-largest-element-in-a-stream
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

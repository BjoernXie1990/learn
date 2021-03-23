/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        it = _vec.begin();
    }
    
    int next() {
        return *(it++);
    }
    
    bool hasNext() {
        return it != _vec.end();
    }
private:
    void dfs(vector<NestedInteger>& cur) {
        for(auto& e : cur) {
            if(e.isInteger()) {
                _vec.push_back(e.getInteger());
            } else {
                dfs(e.getList());
            }
        }
    }
private:
    vector<int> _vec;
    vector<int>::iterator it;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
 
 ����һ��Ƕ�׵������б��������һ����������ʹ���ܹ�������������б��е�����������

�б��е�ÿһ�����Ϊһ����������������һ���б������б��Ԫ��Ҳ�������������������б�

?

ʾ�� 1:

����: [[1,1],2,[1,1]]
���: [1,1,2,1,1]
����: ͨ���ظ�����?next ֱ��?hasNext ���� false��next?���ص�Ԫ�ص�˳��Ӧ����: [1,1,2,1,1]��
ʾ�� 2:

����: [1,[4,[6]]]
���: [1,4,6]
����: ͨ���ظ�����?next?ֱ��?hasNext ���� false��next?���ص�Ԫ�ص�˳��Ӧ����: [1,4,6]��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/flatten-nested-list-iterator
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

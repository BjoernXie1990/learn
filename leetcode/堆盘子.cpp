class StackOfPlates {
public:
    StackOfPlates(int cap) {
        _size = cap;
    }
    
    void push(int val) {
        if(_size <= 0) return;
        if(_arr.empty() || _arr.back().size() == _size) {
            _arr.push_back(vector<int> ());
        }
        _arr.back().push_back(val);
    }
    
    int pop() {
        if(_arr.empty()) return -1;
        int top = _arr.back().back();
        _arr.back().pop_back();
        if( _arr.back().empty()) {
            _arr.pop_back();
        }
        return top;
    }
    
    int popAt(int index) {
        if(index >= _arr.size() || _arr[index].empty()) return -1;
        int top = _arr[index].back();
        _arr[index].pop_back();

        if(_arr[index].empty()) {
            _arr.erase(_arr.begin() + index);
        }
        return top;
    }
private:
    vector<vector<int> > _arr;
    int _size;
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */
 
 
 �����ӡ�������һ�����ӣ���̫�߿��ܻᵹ��������ˣ�����ʵ�����У����Ӷѵ�һ���߶�ʱ�����Ǿͻ������һ�����ӡ���ʵ�����ݽṹSetOfStacks��ģ��������Ϊ��SetOfStacksӦ���ɶ��ջ��ɣ�������ǰһ��ջ����ʱ�½�һ��ջ�����⣬SetOfStacks.push()��SetOfStacks.pop()Ӧ������ͨջ�Ĳ���������ͬ��Ҳ����˵��pop()���ص�ֵ��Ӧ�ø�ֻ��һ��ջʱ�����һ������ ���ף�ʵ��һ��popAt(int index)����������ָ������ջ��ִ��pop������

��ĳ��ջΪ��ʱ��Ӧ��ɾ����ջ����ջ��û��Ԫ�ػ򲻴��ڸ�ջʱ��pop��popAt?Ӧ���� -1.

ʾ��1:

 ���룺
["StackOfPlates", "push", "push", "popAt", "pop", "pop"]
[[1], [1], [2], [1], [], []]
 �����
[null, null, null, 2, 1, -1]
ʾ��2:

 ���룺
["StackOfPlates", "push", "push", "push", "popAt", "popAt", "popAt"]
[[2], [1], [2], [3], [0], [0], [0]]
 �����
[null, null, null, null, 2, 1, 3]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/stack-of-plates-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

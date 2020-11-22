class TripleInOne {
public:
    TripleInOne(int stackSize) {
        arr.resize(stackSize * 3,0);
        cnt = {-3,-2,-1};
    }

    
    void push(int stackNum, int value) {
        if(cnt[stackNum] + 3 >= arr.size()) return ;

        cnt[stackNum] += 3;
        arr[cnt[stackNum]] = value;
    }
    
    int pop(int stackNum) {
        if(cnt[stackNum] < 0) return -1;

        int top = arr[cnt[stackNum]];
        cnt[stackNum] -= 3;
        return top;
    }
    
    int peek(int stackNum) {
        if(cnt[stackNum] < 0) return -1;
        
        return arr[cnt[stackNum]];
    }
    
    bool isEmpty(int stackNum) {
        return cnt[stackNum] < 0;
    }
private:
    vector<int> arr;
    vector<int> cnt;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
 
 
 ����һ���������ֻ��һ��������ʵ������ջ��

��Ӧ��ʵ��push(stackNum, value)��pop(stackNum)��isEmpty(stackNum)��peek(stackNum)������stackNum��ʾջ�±꣬value��ʾѹ���ֵ��

���캯���ᴫ��һ��stackSize����������ÿ��ջ�Ĵ�С��

ʾ��1:

 ���룺
["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
 �����
[null, null, null, 1, -1, -1, true]
˵������ջΪ��ʱ`pop, peek`����-1����ջ��ʱ`push`��ѹ��Ԫ�ء�
ʾ��2:

 ���룺
["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
 �����
[null, null, null, null, 2, 1, -1, -1]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/three-in-one-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

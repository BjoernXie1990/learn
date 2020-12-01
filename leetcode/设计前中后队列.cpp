class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        _arr.push_front(val);
    }
    
    void pushMiddle(int val) {
        _arr.insert(_arr.begin() + (_arr.size() >> 1), val);
    }
    
    void pushBack(int val) {
        _arr.push_back(val);
    }
    
    int popFront() {
        if(_arr.size() == 0) return -1;

        int ret = _arr.front();
        _arr.pop_front();
        return ret;
    }
    
    int popMiddle() {
         if(_arr.size() == 0) return -1;
         int ret = _arr[(_arr.size()  - 1)/ 2];
         _arr.erase(_arr.begin() + ((_arr.size() - 1) / 2));
         return ret;
    }
    
    int popBack() {
         if(_arr.size() == 0) return -1;
         int ret = _arr.back();
         _arr.pop_back();
         return ret;
    }
private:
    deque<int> _arr;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
 
 �������һ�����У�֧����ǰ���У�������λ�õ� push?�� pop?������

�������?FrontMiddleBack?�ࣺ

FrontMiddleBack()?��ʼ�����С�
void pushFront(int val) ��?val?��ӵ����е� ��ǰ��?��
void pushMiddle(int val) ��?val?��ӵ����е� ���м�?��
void pushBack(int val)?��?val?��ӵ������ �����?��
int popFront()?�� ��ǰ�� ��Ԫ�شӶ�����ɾ��������ֵ�����ɾ��֮ǰ����Ϊ�գ���ô���� -1?��
int popMiddle() �� ���м�?��Ԫ�شӶ�����ɾ��������ֵ�����ɾ��֮ǰ����Ϊ�գ���ô���� -1?��
int popBack() �� ����� ��Ԫ�شӶ�����ɾ��������ֵ�����ɾ��֮ǰ����Ϊ�գ���ô���� -1?��
��ע�⵱��?����?�м�λ�õ�ʱ��ѡ��ǰ���λ�ý��в������ȷ�˵��

�� 6?��ӵ�?[1, 2, 3, 4, 5]?���м�λ�ã��������Ϊ?[1, 2, 6, 3, 4, 5]?��
��?[1, 2, 3, 4, 5, 6]?���м�λ�õ���Ԫ�أ�����?3?�������Ϊ?[1, 2, 4, 5, 6]?��
?

ʾ�� 1��

���룺
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
�����
[null, null, null, null, null, 1, 3, 4, 2, -1]

���ͣ�
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
q.popFront();     // ���� 1 -> [4, 3, 2]
q.popMiddle();    // ���� 3 -> [4, 2]
q.popMiddle();    // ���� 4 -> [2]
q.popBack();      // ���� 2 -> []
q.popFront();     // ���� -1 -> [] ������Ϊ�գ�
?

��ʾ��

1 <= val <= 109
������?1000?��?pushFront��?pushMiddle��?pushBack��?popFront��?popMiddle?��?popBack ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-front-middle-back-queue
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

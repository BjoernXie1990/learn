//�붨��һ�����в�ʵ�ֺ��� max_value �õ�����������ֵ��Ҫ����max_value��push_back �� pop_front �ľ�̯ʱ�临�Ӷȶ���O(1)��

//������Ϊ�գ�pop_front �� max_value?��Ҫ���� -1

//ʾ�� 1��

//����: 
//["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
//[[],[1],[2],[],[],[]]
//���:?[null,null,null,2,1,2]
//ʾ�� 2��

//����: 
//["MaxQueue","pop_front","max_value"]
//[[],[],[]]
//���:?[null,-1,-1]
//?

//���ƣ�

//1 <= push_back,pop_front,max_value���ܲ�����?<= 10000
//1 <= value <= 10^5


class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        return max_que.empty() ? -1 : max_que.front();
    }
    
    void push_back(int value) {
        que.push(value);
        //�Ӻ���ǰ����С��ֵ����ȥ 
        while(!max_que.empty() && value > max_que.back())
            max_que.pop_back();
        max_que.push_back(value);       
    }
    
    int pop_front() {
        if(que.empty()) return -1;
        int value = que.front();
        que.pop();
        
        if(value == max_que.front()) max_que.pop_front();

        return value;
    }
private:
    deque<int> max_que;
    queue<int> que;
};

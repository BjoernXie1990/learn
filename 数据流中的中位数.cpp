��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��

���磬

[2,3,4]?����λ���� 3

[2,3] ����λ���� (2 + 3) / 2 = 2.5

���һ��֧���������ֲ��������ݽṹ��

void addNum(int num) - �������������һ�����������ݽṹ�С�
double findMedian() - ����Ŀǰ����Ԫ�ص���λ����
ʾ�� 1��

���룺
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
�����[null,null,null,1.50000,null,2.00000]
ʾ�� 2��

���룺
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
�����[null,null,2.00000,null,2.50000]
?

���ƣ�

�����?addNum��findMedia����?50000?�ε��á�

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        bigQue = priority_queue<int,vector<int>,less<int> > ();
        smallQue = priority_queue<int,vector<int>,greater<int> > ();
    }
    
    void addNum(int num) {
        if(bigQue.size() == smallQue.size())
        {
            //ȡ��num����󶥶Ѻ󣬴󶥶���С��Ԫ��
            bigQue.push(num);
            smallQue.push(bigQue.top());
            bigQue.pop();
            return ;
        }

        //������Ԫ����������ȣ��󶥶���һ��Ԫ��
        smallQue.push(num);
        bigQue.push(smallQue.top());
        smallQue.pop();
    }
    
    double findMedian() {
        double ans = 0.0;

        if(bigQue.size() == smallQue.size())
            ans = (bigQue.top() + smallQue.top()) / 2.0;
        else
            ans = smallQue.top();
        return ans;
    }
private:
    priority_queue<int,vector<int>,less<int> > bigQue;
    priority_queue<int,vector<int>,greater<int> > smallQue;
};

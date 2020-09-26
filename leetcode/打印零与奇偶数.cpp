class ZeroEvenOdd {
private:
    mutex lock1;
    mutex lock2;
    mutex lock3;
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        lock2.lock();
        lock3.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            lock1.lock();
            printNumber(0);
            if((i & 1) == 1) lock3.unlock();
            else if ( (i & 1) == 0) lock2.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= n; i += 2) {
            lock2.lock();
            printNumber(i);
            lock1.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i += 2) {
            lock3.lock();
            printNumber(i);
            lock1.unlock();
        }
    }
};


��������ôһ���ࣺ

class ZeroEvenOdd {
? public ZeroEvenOdd(int n) { ... }?     // ���캯��
  public void zero(printNumber) { ... }  // ����ӡ�� 0
  public void even(printNumber) { ... }  // ����ӡ�� ż��
  public void odd(printNumber) { ... }   // ����ӡ�� ����
}
��ͬ��һ��?ZeroEvenOdd?��ʵ�����ᴫ�ݸ�������ͬ���̣߳�

�߳� A ������?zero()����ֻ��� 0 ��
�߳� B ������?even()����ֻ���ż����
�߳� C ������?odd()����ֻ���������
ÿ���̶߳���һ��?printNumber ���������һ�����������޸ĸ����Ĵ����������������?010203040506... ���������еĳ��ȱ���Ϊ 2n��

?

ʾ�� 1��

���룺n = 2
�����"0102"
˵���������߳��첽ִ�У�����һ������ zero()����һ���̵߳��� even()�����һ���̵߳���odd()����ȷ�����Ϊ "0102"��
ʾ�� 2��

���룺n = 5
�����"0102030405"

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/print-zero-even-odd
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

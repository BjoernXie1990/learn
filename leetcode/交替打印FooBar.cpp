class FooBar {
private:
    int n;
    mutex _lock1;
    mutex _lock2;
public:
    FooBar(int n) {
        this->n = n;
        _lock2.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            _lock1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            _lock2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            _lock2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            _lock1.unlock();
        }
    }
};


�����ṩһ���ࣺ

class FooBar {
  public void foo() {
? ? for (int i = 0; i < n; i++) {
? ? ? print("foo");
?   }
  }

  public void bar() {
? ? for (int i = 0; i < n; i++) {
? ? ? print("bar");
? ? }
  }
}
������ͬ���߳̽��Ṳ��һ�� FooBar?ʵ��������һ���߳̽������?foo()?��������һ���߳̽������?bar()?������

������޸ĳ�����ȷ�� "foobar" ����� n �Ρ�

?

ʾ�� 1:

����: n = 1
���: "foobar"
����: �����������̱߳��첽����������һ������ foo() ����, ��һ������ bar() ������"foobar" �������һ�Ρ�
ʾ�� 2:

����: n = 2
���: "foobarfoobar"
����: "foobar" ����������Ρ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/print-foobar-alternately
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

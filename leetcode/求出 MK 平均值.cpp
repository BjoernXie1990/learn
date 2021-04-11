class MKAverage {
public:
    typedef long long LL;
    MKAverage(int _m, int _k) {
        m = _m;
        k = _k;
    }
    
    void addElement(int num) {
        f.push_back(num);
        int n = f.size();

        if(n < m)
            return ;
        
        if(n == m) {
            auto q = f;
            sort(q.begin(),q.end());
            for(int i = 0; i < k; i ++) 
                le.insert(q[i]);
            
            for(int i = k; i < m - k; i ++)
                mid.insert(q[i]);
            
            for(int i = m - k; i < m; i ++)
                ri.insert(q[i]);

            return ;
        }

        // n > m
        insert(num);
        del(f[n - 1 - m]);
    }
    
    int calculateMKAverage() {
        int n = f.size();
        if(n < m)
            return -1;
        
        return mid.sum / (m - 2 * k);
    }
private:
    void insert(int x) {
        mid.insert(x);
        if(*mid.st.begin() < *le.st.rbegin()) {
            int a = *mid.st.begin(), b = *le.st.rbegin();
            mid.remove(a);
            le.remove(b);
            mid.insert(b);
            le.insert(a);
        }

        if(*mid.st.rbegin() > *ri.st.begin()) {
            int a = *mid.st.rbegin(), b = *ri.st.begin();
            mid.remove(a);
            mid.insert(b);
            ri.remove(b);
            ri.insert(a);
        }
    }

    void del(int x) {
        if(mid.st.count(x)) {
            mid.remove(x);
        } else if(le.st.count(x)) {
            le.remove(x);
            int t = *mid.st.begin();
            le.insert(t);
            mid.remove(t);
        } else if(ri.st.count(x)) {
            ri.remove(x);
            int t = *mid.st.rbegin();
            ri.insert(t);
            mid.remove(t);
        }
    }

private:
    struct node {
        multiset<int> st;
        LL sum = 0;

        void insert(int x) {
            st.insert(x);
            sum += x;
        }

        void remove(int x) {
            st.erase(st.find(x));
            sum -= x;
        }
    };
private:
    int m,k;
    node le,mid,ri;
    vector<int> f;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
 
 
 ������������?m?��?k?���Լ���������ʽ����������������Ҫʵ��һ�����ݽṹ����������������� MK ƽ��ֵ?��

MK ƽ��ֵ?�������²�����㣺

����������е��������� m?����MK ƽ��ֵ?Ϊ -1?����������������� m?��Ԫ�ؿ�����һ�������������С�
�����������ɾ����С�� k?���������� k?������
����ʣ��Ԫ�ص�ƽ��ֵ���� ����ȡ�������������?��
����ʵ��?MKAverage?�ࣺ

MKAverage(int m, int k)?��һ���յ����������������� m?�� k?��ʼ��?MKAverage?����
void addElement(int num)?���������в���һ���µ�Ԫ��?num?��
int calculateMKAverage()?�Ե�ǰ�����������㲢���� MK ƽ����?������� ����ȡ������������� ��
?

ʾ�� 1��

���룺
["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement", "addElement", "addElement", "calculateMKAverage"]
[[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
�����
[null, null, null, -1, null, 3, null, null, null, 5]

���ͣ�
MKAverage obj = new MKAverage(3, 1); 
obj.addElement(3);        // ��ǰԪ��Ϊ [3]
obj.addElement(1);        // ��ǰԪ��Ϊ [3,1]
obj.calculateMKAverage(); // ���� -1 ����Ϊ m = 3 ������������ֻ�� 2 ��Ԫ��
obj.addElement(10);       // ��ǰԪ��Ϊ [3,1,10]
obj.calculateMKAverage(); // ��� 3 ��Ԫ��Ϊ [3,1,10]
                          // ɾ����С�Լ����� 1 ��Ԫ�غ�����Ϊ [3]
                          // [3] ��ƽ��ֵ���� 3/1 = 3 ���ʷ��� 3
obj.addElement(5);        // ��ǰԪ��Ϊ [3,1,10,5]
obj.addElement(5);        // ��ǰԪ��Ϊ [3,1,10,5,5]
obj.addElement(5);        // ��ǰԪ��Ϊ [3,1,10,5,5,5]
obj.calculateMKAverage(); // ��� 3 ��Ԫ��Ϊ [5,5,5]
                          // ɾ����С�Լ����� 1 ��Ԫ�غ�����Ϊ [5]
                          // [5] ��ƽ��ֵ���� 5/1 = 5 ���ʷ��� 5
?

��ʾ��

3 <= m <= 105
1 <= k*2 < m
1 <= num <= 105
addElement ��?calculateMKAverage?�ܲ������������� 105 ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/finding-mk-average
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

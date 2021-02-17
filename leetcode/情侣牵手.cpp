class unionFind{
    public:
        unionFind(int n) : f(n) {
            cnt = n;
            for(int i = 1; i < n; i++) f[i] = i;
        }

        int find(int x) {
            if(f[x] != x) f[x] = find(f[x]);
            return f[x]; 
        }

        bool merge(int a,int b) {
            a = find(a);
            b = find(b);
            if(a == b) return false;
            f[a] = b;
            cnt --;
            return true;
        }

        int get() {
            return cnt;
        }
    private:
        vector<int> f;
        int cnt;
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unionFind uf(n / 2);

        for(int i = 0; i < n; i+=2) {
            uf.merge(row[i]/2,row[i+1]/2);
        }

        return n / 2 - uf.get();
    }
};
N �����������������е� 2N ����λ�ϣ���Ҫǣ���Է����֡� �������ٽ�����λ�Ĵ������Ա�ÿ�����¿��Բ�������һ�� һ�ν�����ѡ���������ˣ�������վ����������λ��

�˺���λ��?0?��?2N-1?��������ʾ�������ǰ�˳���ţ���һ����?(0, 1)���ڶ�����?(2, 3)���Դ����ƣ����һ����?(2N-2, 2N-1)��

��Щ���µĳ�ʼ��λ??row[i]?�������ʼ���ڵ� i ����λ�ϵ��˾����ġ�

ʾ�� 1:

����: row = [0, 2, 1, 3]
���: 1
����: ����ֻ��Ҫ����row[1]��row[2]��λ�ü��ɡ�
ʾ�� 2:

����: row = [3, 2, 0, 1]
���: 0
����: ���轻����λ�����е����¶��Ѿ�������ǣ���ˡ�
˵��:

len(row) ��ż������ֵ��?[4, 60]��Χ�ڡ�
���Ա�֤row ������?0...len(row)-1?��һ��ȫ���С�
ͨ������19,138�ύ����29,232

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/couples-holding-hands
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

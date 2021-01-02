class Solution {
public:
    vector<int> f;
    int size = 0;
    void init(int n) {
        f.reserve(n);
        for(int i = 0; i < n; i ++)
            f[i] = i;
        size = n;
    }

    int find(int x) {
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    void connect(int l,int r) {
        l = find(l);
        r = find(r);
        if(l != r) {
            f[r] = f[l];
            size--;
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        init(n);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                if(find(i) == find(leftChild[i]) || find(leftChild[i]) != leftChild[i])
                    return false;
                connect(i,leftChild[i]);
            }

            if(rightChild[i] != -1) {
                if(find(i) == find(rightChild[i]) || find(rightChild[i]) != rightChild[i])
                    return false;
                connect(i,rightChild[i]);
            }
        }

        return (bool)(size == 1);
    }
};


���������� n?���ڵ㣬����?0?�� n - 1?��ţ����нڵ�?i?�������ӽڵ�ֱ���?leftChild[i]?��?rightChild[i]��

ֻ�� ���� �ڵ��ܹ��γ��� ֻ �γ� һ��?��Ч�Ķ�����ʱ������?true�����򷵻� false��

����ڵ�?i?û�����ӽڵ㣬��ô?leftChild[i]?�͵���?-1�����ӽڵ�Ҳ���ϸù���

ע�⣺�ڵ�û��ֵ���������н���ʹ�ýڵ��š�

?

ʾ�� 1��



���룺n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
�����true
ʾ�� 2��



���룺n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
�����false
ʾ�� 3��



���룺n = 2, leftChild = [1,0], rightChild = [-1,-1]
�����false
ʾ�� 4��



���룺n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
�����false
?

��ʾ��

1 <= n <= 10^4
leftChild.length == rightChild.length == n
-1 <= leftChild[i], rightChild[i] <= n - 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/validate-binary-tree-nodes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

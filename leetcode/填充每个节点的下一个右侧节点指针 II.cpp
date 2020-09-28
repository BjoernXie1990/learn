/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> que;
        que.push(root);

        while(que.empty() == false) {
            Node* pre = que.front();
            int size = que.size();
            
            for(int i = 0; i < size; i++) {
                Node* f = que.front();
                que.pop();
                if(f->left != nullptr)  que.push(f->left);
                if(f->right != nullptr) que.push(f->right);

                if(i != size-1) {
                    Node* preNext = que.front();
                    pre->next = preNext;
                    pre = preNext;
                }
            }
        }

        return root;
    } 
};

����һ��������

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��

��ʼ״̬�£�����?next ָ�붼������Ϊ NULL��

?

���ף�

��ֻ��ʹ�ó���������ռ䡣
ʹ�õݹ����Ҳ����Ҫ�󣬱����еݹ����ռ�õ�ջ�ռ䲻��������Ŀռ临�Ӷȡ�
?

ʾ����



���룺root = [1,2,3,4,5,null,7]
�����[1,#,2,3,#,4,5,7,#]
���ͣ�������������ͼ A ��ʾ����ĺ���Ӧ���������ÿ�� next ָ�룬��ָ������һ���Ҳ�ڵ㣬��ͼ B ��ʾ��
?

��ʾ��

���еĽڵ���С�� 6000
-100?<= node.val <= 100
?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

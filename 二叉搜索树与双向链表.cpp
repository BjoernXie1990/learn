����һ�ö��������������ö���������ת����һ�������ѭ��˫������Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��

?

Ϊ���������õ�������⣬������Ķ���������Ϊ����

?



?

����ϣ�����������������ת��Ϊ˫��ѭ�����������е�ÿ���ڵ㶼��һ��ǰ���ͺ��ָ�롣����˫��ѭ��������һ���ڵ��ǰ�������һ���ڵ㣬���һ���ڵ�ĺ���ǵ�һ���ڵ㡣

��ͼչʾ������Ķ���������ת���ɵ�������head�� ��ʾָ������������СԪ�صĽڵ㡣

?



?

�ر�أ�����ϣ�����Ծ͵����ת����������ת������Ժ����нڵ����ָ����Ҫָ��ǰ�������нڵ����ָ����Ҫָ���̡�����Ҫ���������еĵ�һ���ڵ��ָ�롣

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        Node* pre = nullptr;
        dfs(root,pre);

        head->left = tail;
        tail->right = head;

        return head;
    }

    void dfs(Node* root,Node*& pre)
    {
        if(root == nullptr)
            return ;

        dfs(root->left,pre);
        if(pre == nullptr)
            head = root;
        else
            pre->right = root;

        root->left = pre;
        pre = root;
        tail = root;
        dfs(root->right,pre);
    }
};

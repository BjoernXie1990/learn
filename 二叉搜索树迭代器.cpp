ʵ��һ���������������������㽫ʹ�ö����������ĸ��ڵ��ʼ����������

���� next() �����ض����������е���һ����С������

?

ʾ����



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // ���� 3
iterator.next();    // ���� 7
iterator.hasNext(); // ���� true
iterator.next();    // ���� 9
iterator.hasNext(); // ���� true
iterator.next();    // ���� 15
iterator.hasNext(); // ���� true
iterator.next();    // ���� 20
iterator.hasNext(); // ���� false
?

��ʾ��

next()?��?hasNext()?������ʱ�临�Ӷ���?O(1)����ʹ��?O(h) �ڴ棬����?h?�����ĸ߶ȡ�
����Լ���?next()?����������Ч�ģ�Ҳ����˵�������� next()?ʱ��BST �����ٴ���һ����һ����С��������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        //��ʼ������������������һ����������С�ڵ��λ��
        TreeNode* cur = root;
        while(cur != nullptr)
        {
            Tnode.push(cur);
            cur = cur->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* ret = Tnode.top();
        Tnode.pop();
        
        //���ret���ҽڵ���ڣ����ҽڵ�����С��һ����,����Щ����ջ
        if(ret->right != nullptr)
        {
            TreeNode* cur = ret->right;
            while(cur != nullptr)
            {
                Tnode.push(cur);
                cur = cur->left;
            }
        }
        
        //�ҽڵ㲻���ڣ���Ҫ���ϲ���û�б����ʵĽڵ�,Ҳ����ջ��Ԫ��
        return ret->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !Tnode.empty();
    }
private:
    stack<TreeNode*> Tnode;//ջ��Ԫ��Ϊ��һ����С�Ľڵ�
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

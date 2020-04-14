//����һ�� N ������������ڵ�ֵ�Ĳ�������� (�������ң�������)��

//���磬����һ��?3����?:

//?



//?

//������������:

//[
//     [1],
//     [3,2,4],
//     [5,6]
//]

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > ans;
        queue<Node*> que;
        que.push(root);

        while(!que.empty() && root)
        {
            int size = que.size();
            vector<int> ret;

            for(int i = 0; i < size; i++)
            {
                Node* node = que.front();
                que.pop();
                if(!node)
                    continue;
                ret.push_back(node->val);
                //���ӽڵ����
                for(auto eoch : node->children)
                    que.push(eoch);
            }
            ans.push_back(ret);
        }
        return ans;
    }
};

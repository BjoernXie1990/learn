���������ڶ�ȡһ��������ÿ��һ��ʱ�䣬��ϣ�����ҳ����� x ����(С�ڻ���� x ��ֵ�ĸ���)����ʵ�����ݽṹ���㷨��֧����Щ������Ҳ����˵��

ʵ�� track(int x)?������ÿ����һ�����ֶ�����ø÷�����

ʵ�� getRankOfNumber(int x) ����������С�ڻ���� x ��ֵ�ĸ�����

ע�⣺�������ԭ�������Ķ�

ʾ��:

����:
["StreamRank", "getRankOfNumber", "track", "getRankOfNumber"]
[[], [1], [0], [0]]
���:
[null,0,null,1]
��ʾ��

x <= 50000
track?��?getRankOfNumber �����ĵ��ô����������� 2000 ��

class StreamRank {
public:
    struct node{
        int _data;
        node* _left;
        node* _right;
        int _num;

        node(int data){
            _data = data;
            _left = _right = nullptr;
            _num = 1;
        }
    };

    StreamRank() {
        _root = nullptr;
    }
    
    //insert
    void track(int x) {
        insert(_root,x);
    }
    
    //find
    int getRankOfNumber(int x) {
        return find(_root,x);
    }
private:
    void insert(node*& root,int x){
        if(root == nullptr){
            root = new node(x);
            return ;
        }

        if(root->_data == x){
            root->_num++;
        }else if(root->_data < x){
            insert(root->_right,x);
        }else if(root->_data > x){
            root->_num++;
            insert(root->_left,x);
        }
    }

    int find(node* root,int x){
        if(root == nullptr){
            return 0;
        }

        if(root->_data == x){
            return root->_num;
        }

        if(root->_data < x){
            return find(root->_right,x) + root->_num;
        }
        
        //root->_data > x
        return find(root->_left,x);
    }
private:
    node* _root;
};

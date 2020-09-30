class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        _mt.clear();
        _arr.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = _mt.find(val) == _mt.end();
        int pos = _arr.size();
        _arr.push_back(val);
        _mt[val].insert(pos);
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(_mt.find(val) == _mt.end()) return false;
        
        // unordered_set
        int pos = *(_mt[val].begin());
        _mt[val].erase(pos);
        if(_mt[val].empty() == true) _mt.erase(val);

        int n = _arr.size();
        if(pos != n-1) {
            _arr[pos] = _arr[n-1];
            _mt[_arr[pos]].erase(n-1);
            _mt[_arr[pos]].insert(pos);
        }
        
        _arr.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand() % _arr.size();
        return _arr[pos];
    }
private:
    unordered_map<int,unordered_set<int> > _mt;
    vector<int> _arr;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 
 ���һ��֧����ƽ��?ʱ�临�Ӷ�?O(1)?�£�?ִ�����²��������ݽṹ��

ע��: ��������ظ�Ԫ�ء�

insert(val)���򼯺��в���Ԫ�� val��
remove(val)���� val ����ʱ���Ӽ������Ƴ�һ�� val��
getRandom�������м����������ȡһ��Ԫ�ء�ÿ��Ԫ�ر����صĸ���Ӧ�������ڼ����е�������������ء�
ʾ��:

// ��ʼ��һ���յļ��ϡ�
RandomizedCollection collection = new RandomizedCollection();

// �򼯺��в��� 1 ������ true ��ʾ���ϲ����� 1 ��
collection.insert(1);

// �򼯺��в�����һ�� 1 ������ false ��ʾ���ϰ��� 1 ���������ڰ��� [1,1] ��
collection.insert(1);

// �򼯺��в��� 2 ������ true ���������ڰ��� [1,1,2] ��
collection.insert(2);

// getRandom Ӧ���� 2/3 �ĸ��ʷ��� 1 ��1/3 �ĸ��ʷ��� 2 ��
collection.getRandom();

// �Ӽ�����ɾ�� 1 ������ true ���������ڰ��� [1,2] ��
collection.remove(1);

// getRandom Ӧ����ͬ���ʷ��� 1 �� 2 ��
collection.getRandom();

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

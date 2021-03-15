class MyHashMap {
public:
    typedef pair<int,int> PII;
    /** Initialize your data structure here. */
    MyHashMap() {
        base = 769;
        hash.resize(base);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int id = key % base;
        for(auto& e : hash[id]) {
            int x = e.first, y = e.second;
            if(x == key) {
                e.second = value;
                return ;
            }
        }
        hash[id].push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int id = key % base;
        for(auto& e : hash[id]) {
            int x = e.first, y = e.second;
            if(x == key) {
                return y;
            }
        }

        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int id = key % base;
        for(auto e = hash[id].begin(); e != hash[id].end(); e++) {
            int x = e->first, y = e->second;
            if(x == key) {
                hash[id].erase(e);
                return ;
            }
        }
    }
private:
    vector<list<PII> > hash;
    int base;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 
 
 ��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣӳ�䣨HashMap����

ʵ�� MyHashMap �ࣺ

MyHashMap() �ÿ�ӳ���ʼ������
void put(int key, int value) �� HashMap ����һ����ֵ�� (key, value) ����� key �Ѿ�������ӳ���У���������Ӧ��ֵ value ��
int get(int key) �����ض��� key ��ӳ��� value �����ӳ���в����� key ��ӳ�䣬���� -1 ��
void remove(key) ���ӳ���д��� key ��ӳ�䣬���Ƴ� key ��������Ӧ�� value ��
?

ʾ����

���룺
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
�����
[null, null, null, 1, -1, null, 1, null, -1]

���ͣ�
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // myHashMap ����Ϊ [[1,1]]
myHashMap.put(2, 2); // myHashMap ����Ϊ [[1,1], [2,2]]
myHashMap.get(1);    // ���� 1 ��myHashMap ����Ϊ [[1,1], [2,2]]
myHashMap.get(3);    // ���� -1��δ�ҵ�����myHashMap ����Ϊ [[1,1], [2,2]]
myHashMap.put(2, 1); // myHashMap ����Ϊ [[1,1], [2,1]]���������е�ֵ��
myHashMap.get(2);    // ���� 1 ��myHashMap ����Ϊ [[1,1], [2,1]]
myHashMap.remove(2); // ɾ����Ϊ 2 �����ݣ�myHashMap ����Ϊ [[1,1]]
myHashMap.get(2);    // ���� -1��δ�ҵ�����myHashMap ����Ϊ [[1,1]]
?

��ʾ��

0 <= key, value <= 106
������ 104 �� put��get �� remove ����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-hashmap
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

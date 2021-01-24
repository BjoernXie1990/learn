struct goods{
    int id;
    vector<int> vec;
};

class AnimalShelf {
public:
    AnimalShelf() {
        id = 0;
    }
    
    void enqueue(vector<int> animal) {
        if(animal[1] == 1) dog.push({id++,animal});
        else cat.push({id++,animal});
    }
    
    vector<int> dequeueAny() {
        vector<int> res;
        if(dog.size() && cat.size()) {
            int x = dog.front().id;
            int y = cat.front().id;
        
            if(x < y) {
                res = dog.front().vec;
                dog.pop();
            } else {
                res = cat.front().vec;
                cat.pop();
            }
        } else if(dog.size()) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
        
        return res;
    }
    
    vector<int> dequeueDog() {
        if(dog.size() == 0) return {-1,-1};
        vector<int> res = dog.front().vec;
        dog.pop();
        return res;
    }
    
    vector<int> dequeueCat() {
        if(cat.size() == 0) return {-1,-1};
        vector<int> res = cat.front().vec;
        cat.pop();
        return res;
    }
private:
    queue<goods> dog;
    queue<goods> cat;
    int id;
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
 
 
 �������������мҶ���������ֻ���ݹ���è�����ϸ����ء��Ƚ��ȳ�����ԭ�����������������Ķ���ʱ��������ֻ���������ж����С����ϡ������������������ʱ�䳤�̶������Ķ�����߿�����ѡè�򹷣�ͬʱ�����������ද���С����ϡ��ģ�������֮�������˲���������ѡ�������Ķ����봴�����������ϵͳ�����ݽṹ��ʵ�ָ��ֲ�������������enqueue��dequeueAny��dequeueDog��dequeueCat������ʹ��Java���õ�LinkedList���ݽṹ��

enqueue������һ��animal������animal[0]�������ţ�animal[1]���������࣬���� 0 ����è��1 ������

dequeue*��������һ���б�[������, ��������]����û�п��������Ķ���򷵻�[-1,-1]��

ʾ��1:

 ���룺
["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [], [], []]
 �����
[null,null,null,[0,0],[-1,-1],[1,0]]
ʾ��2:

 ���룺
["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]
 �����
[null,null,null,null,[2,1],[0,0],[1,0]]
˵��:

���������������Ϊ20000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/animal-shelter-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

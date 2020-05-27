//����ʵ��һ�������ֳ˻��ࡹProductOfNumbers��Ҫ��֧���������ַ�����

//1.?add(int num)

//������?num?��ӵ���ǰ�����б������档
//2. getProduct(int k)

//���ص�ǰ�����б��У����?k?�����ֵĳ˻���
//����Լ��赱ǰ�б���ʼ�� ���� ���� k �����֡�
//��Ŀ���ݱ�֤���κ�ʱ����һ�����������еĳ˻����� 32-bit ������Χ�ڣ����������

//?

//ʾ����

//���룺
//["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
//[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

//�����
//[null,null,null,null,null,null,20,40,0,null,32]

//���ͣ�
//ProductOfNumbers productOfNumbers = new ProductOfNumbers();
//productOfNumbers.add(3);        // [3]
//productOfNumbers.add(0);        // [3,0]
//productOfNumbers.add(2);        // [3,0,2]
//productOfNumbers.add(5);        // [3,0,2,5]
//productOfNumbers.add(4);        // [3,0,2,5,4]
//productOfNumbers.getProduct(2); // ���� 20 ����� 2 �����ֵĳ˻��� 5 * 4 = 20
//productOfNumbers.getProduct(3); // ���� 40 ����� 3 �����ֵĳ˻��� 2 * 5 * 4 = 40
//productOfNumbers.getProduct(4); // ����  0 ����� 4 �����ֵĳ˻��� 0 * 2 * 5 * 4 = 0
//productOfNumbers.add(8);        // [3,0,2,5,4,8]
//productOfNumbers.getProduct(2); // ���� 32 ����� 2 �����ֵĳ˻��� 4 * 8 = 32 



//��ʱ
class ProductOfNumbers1 {
public:
    ProductOfNumbers1() {
        mul.push_back(0);
    }
    
    void add(int num) {
        for(auto& eoch : mul)
            eoch *= num;
        mul.push_back(num);
    }
    
    int getProduct(int k) {
        return mul[mul.size() - k];
    }
private:
    vector<int> mul;
};

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        mul.push_back(1);
    }
    
    void add(int num) {
        if(num == 0)
        {
            mul = vector<int> (1,1);
            return ;
        }
        mul.push_back(num * mul.back());
    }
    
    int getProduct(int k) {
        if(k >= mul.size()) return 0;
        return mul.back() / mul[mul.size() - k - 1]; 
    }
private:
    vector<int> mul;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

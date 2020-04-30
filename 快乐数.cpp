//��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

//��������������Ϊ������һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���ͣ�Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1����� ���Ա�Ϊ? 1����ô��������ǿ�������

//��� n �ǿ������ͷ��� True �����ǣ��򷵻� False ��

//?

//ʾ����

//���룺19
//�����true
//���ͣ�
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1



class Solution {
public:
    //����ö�� + find����
    bool isHappy1(int n) {
        vector<int> arr;
        int num = n;
        while(1) {
            int tmp = 0;
            int count = num;
            while(count) {
                tmp += (count % 10) * (count % 10);
                count /= 10;
            }
            if(tmp == 1) return true;

            auto ret = find(arr.begin(),arr.end(),tmp);
            if(ret == arr.end()) arr.push_back(tmp);
            else break;
            num = tmp;
        }
        return false;
    }

    //�����һ�
    bool isHappy(int n) {
        int slow = n;
        int fast = sqrtSum(n);
        while(slow != fast) {
            slow = sqrtSum(slow);
            fast = sqrtSum(sqrtSum(fast));
            if(slow == 1) return true;
        }
        return slow == 1; //��ֹ��һ��������1
    }

    //����ƽ����
    int sqrtSum(int num) {
        int count = num;
        int ans = 0;
        while(count) {
            ans +=  (count % 10) * (count % 10);
            count /= 10;
        }
        return ans;
    }
};

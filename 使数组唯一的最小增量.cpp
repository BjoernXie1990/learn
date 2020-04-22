//������������ A��ÿ�� move ��������ѡ������?A[i]�����������?1��

//����ʹ A?�е�ÿ��ֵ����Ψһ�����ٲ���������

//ʾ�� 1:

//���룺[1,2,2]
//�����1
//���ͣ�����һ�� move ���������齫��Ϊ [1, 2, 3]��
//ʾ�� 2:

//���룺[3,2,1,2,1,7]
//�����6
//���ͣ����� 6 �� move ���������齫��Ϊ [3, 4, 1, 2, 5, 7]��
//���Կ��� 5 �λ� 5 �����µ� move �����ǲ����������ÿ��ֵΨһ�ġ�

class Solution {
public:
    
    //����O(nlog(n))
    int minIncrementForUnique1(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;

        for(int i = 1; i < A.size(); i++){
            if(A[i] <= A[i-1]){
                ans += A[i-1] + 1 - A[i];
                A[i] = A[i-1] + 1;
            }
        }
        return ans;
    }
    //��������  O(N + K)
    int minIncrementForUnique2(vector<int>& A) {
        int len = A.size();
        if(len <= 1)
            return 0;
        int maxValue = 0;
        vector<int> arr1(80004);//��ֹ����ȫ����������������
        for(size_t i = 0; i < len; i++){
            arr1[A[i]]++;
            maxValue = max(A[i],maxValue);
        }
        int ans = 0;
        maxValue <<= 1;

        for(int i = 0; i <= maxValue; i++){
            if(arr1[i] > 1){
                ans += arr1[i] - 1;//��ǰλ��ֻ����һ��ֵ����������ֵ����+1
                arr1[i+1] += arr1[i] - 1;//+1�ƶ��������λ��
                arr1[i] = 1;
            }
        }

        return ans;
    }

    //·��ѹ�� O(n) 
    vector<int> arr{vector<int> (80000,-1)};//-1��ʾ��λ
    int minIncrementForUnique(vector<int>& A){
        int ans = 0;
        for(int start : A){
            int end = findPos(start);
            ans += end - start;
        }
        return ans;
    }

    int findPos(int start){
        int end = arr[start];
        //����ǿ�λ��ֱ�ӷ������λ�þͿ���
        if(end == -1){
            arr[start] = start;
            return start;
        }

        //���ǿ�λ��ֱ��������һ����λ
        end = findPos(end + 1);
        arr[start] = end; //�Ա���һ�η��ʵ�ʱ��ֱ���������Բ����λ��
        return end;
    }
};

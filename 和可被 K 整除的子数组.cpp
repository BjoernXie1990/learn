//����һ���������� A����������Ԫ��֮�Ϳɱ� K?�����ģ��������ǿգ����������Ŀ��

//?

//ʾ����

//���룺A = [4,5,0,-2,-3,1], K = 5
//�����7
//���ͣ�
//�� 7 ��������������Ԫ��֮�Ϳɱ� K = 5 ������
//[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
//?

//��ʾ��

//1 <= A.length <= 30000
//-10000 <= A[i] <= 10000
//2 <= K <= 10000


class Solution {
public:
    //O��n ^ 2��
    int subarraysDivByK1(vector<int>& A, int K) {
        int len = A.size();
        vector<int> tmp(len+1,0);

        //ǰ׺��
        for(int i = 0; i < len; i++)
            tmp[i+1] = tmp[i] + A[i];
        
        int ans = 0;
        for(int i = 1; i <= len; i++)
            for(int j = 0; j < i; j++)
            {
                if((tmp[i] - tmp[j]) % K == 0) ans++;
            }
 
        return ans;
    }

    //��ϣ��
    //(tmp[i] - tmp[j]) % K == 0  --->   tmp[i] % K ==  tmp[j] % K
    int subarraysDivByK(vector<int>& A, int K)
    {
        int len = A.size();
        vector<int> map(K,0);
        map[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            sum += A[i];
            int pos = (sum%K + K) % K;
            ans += map[pos];
            map[pos]++;
        }

        return ans;
    } 
};

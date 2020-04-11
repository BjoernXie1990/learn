//�㽫���?K?��������������ʹ��һ����?1?��?N??���� N?��¥�Ľ�����

//ÿ�����Ĺ��ܶ���һ���ģ����һ�������ˣ���Ͳ����ٰ�������ȥ��

//��֪������¥��?F ������?0 <= F <= N �κδӸ��� F?��¥�����µļ��������飬��?F?¥�������͵�¥�����µļ����������ơ�

//ÿ���ƶ��������ȡһ��������������������ļ���������������һ¥��?X?���£�����?1 <= X <= N����

//���Ŀ����ȷ�е�֪�� F ��ֵ�Ƕ��١�

//���� F �ĳ�ʼֵ��Σ���ȷ�� F ��ֵ����С�ƶ������Ƕ��٣�

//?

//ʾ�� 1��

//���룺K = 1, N = 2
//�����2
//���ͣ�
//������ 1 ¥���䡣��������ˣ����ǿ϶�֪�� F = 0 ��
//���򣬼����� 2 ¥���䡣��������ˣ����ǿ϶�֪�� F = 1 ��
//�����û�飬��ô���ǿ϶�֪�� F = 2 ��
//��ˣ�����������������Ҫ�ƶ� 2 ����ȷ�� F �Ƕ��١�
//ʾ�� 2��

//���룺K = 2, N = 6
//�����3
//ʾ�� 3��

//���룺K = 3, N = 14
//�����4
//���� 


class Solution {
public:
    //�ݹ�
    int superEggDrop1(int k, int N) {
        if(k <= 1 || N <= 1)
            return N;
        int maxAns = N;
        for(int i = 1; i <= N; i++)
        {
            //(k-1,i-1)   ��ǰ��ˤ���ˣ�����-1����֤�ǵ�i������⣬����ǰi�������
            //(k,N-i)  ��ǰ��û��ˤ������Ҫȥ����� N-i ����
            int tmax = max(superEggDrop(k-1,i-1), superEggDrop(k,N-i));
            maxAns = min(maxAns,tmax + 1);//tmax + 1  1��ʾ��i��ˤһ��
        }
        return maxAns;
    }

    //�Ż�
    int superEggDrop2(int k, int N) {
        vector<vector<int> > dp(k+1,vector<int>(N+1,0));

        for(int i = 1; i <= N; i++)
            dp[1][i] = i;//ֻ��һ������
        
        for(int egg = 2; egg <= k; egg++)//���õļ�����
        {
            for(int n = 1; n <= N; n++)//��ǰ¥����
            {
                int maxDrop = N + N;
                for(int x = 1; x <= n; x++)
                {
                    int tMin = max(dp[egg-1][x-1],dp[egg][n-x]);
                    maxDrop = min(maxDrop,tMin + 1);
                }
                dp[egg][n] = maxDrop;
            }
        }

        return dp[k][N];
    }

    int superEggDrop3(int k, int N) {
        vector<int> dp(N+1,0);

        for(int i = 1; i <= N; i++)//1������
            dp[i] = i;

        //�������
        for(int egg = 2; egg <= k; egg++)
        {
            vector<int> dp2(N+1,0);//��egg���������Բ��¥����
            int x = 1;//�ӵ�һ�㿪ʼ
            for(int n = 1; n <= N; n++)
            {
                //max(dp[x-1],dp2[n-x]) > max(dp[x], dp2[n-x-1]
                //T1 =dp(K?1,X?1)��T2 =dp(K,N?X)
                //max(T1(x-1), T2(x-1)) > max(T1(x), T2(x))
                while(x < n && 
                    max(dp[x-1],dp2[n-x]) > max(dp[x], dp2[n-x-1]))
                    x++;
                dp2[n] = 1 + max(dp[x-1],dp2[n-x]);
            }

            dp = dp2;
        }

        return dp[N];
    }

     //�Ż�
    int superEggDrop4(int k, int N) {
        vector<vector<int> > dp(k+1,vector<int>(N+1,0));// k��������n�����Բ�����ٲ�¥

        for(int n = 1; n <= N; n++)
        {
            for(int egg = 1; egg <= k; egg++)
            {
                //dp[egg][n]  -->  ��egg��������n-1�����¥���� + ��ǰ¥��(1) == dp[egg][n-1] + 1;
                //ǰ��egg-1��������n-1�������¥���� == dp[egg-1][n-1]
                dp[egg][n] = dp[egg][n-1] + dp[egg-1][n-1] + 1;
                if(dp[egg][n] >= N)
                    return n;
            }
        }
        return N;
    }

     //�Ż�
    int superEggDrop(int k, int N) {
        vector<vector<int> > dp(k+1,vector<int>(N+1,0));

        int m = 0;
        while(dp[k][m] < N)
        {
            m++;
            for(int egg = 1; egg <= k; egg++)
                dp[egg][m] = 1 + dp[egg-1][m-1] + dp[egg][m-1];
        }

        return m;
    }
};

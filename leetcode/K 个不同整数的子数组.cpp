����һ������������ A����� A?��ĳ���������в�ͬ�����ĸ���ǡ��Ϊ K����� A �������������һ��������������Ϊ�������顣

�����磬[1,2,3,1,2] ����?3?����ͬ��������1��2���Լ�?3����

����?A?�к����������Ŀ��

?

ʾ�� 1��

���룺A = [1,2,1,2,3], K = 2
�����7
���ͣ�ǡ���� 2 ����ͬ������ɵ������飺[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
ʾ�� 2��

���룺A = [1,2,1,3,4], K = 3
�����3
���ͣ�ǡ���� 3 ����ͬ������ɵ������飺[1,2,1,3], [2,1,3], [1,3,4].
?

��ʾ��

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length

class Solution {
public:
    
    int ans = 0;
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        vector<int> hash(n+1,0);
        int le = 0;
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(hash[A[i]] == 0) sum++;
            hash[A[i]]++;

            while(sum > K && le < i)
            {
                //��i -> le ����
                dfs(hash,A,K,le,i,sum);
                hash[A[le]]--;
                if(hash[A[le]] == 0)    sum--;
                le++;
            }
        }

        while(sum == K && le < n)
        {
            dfs(hash,A,K,le,n-1,sum);
            hash[A[le]]--;
            if(hash[A[le]] == 0)    sum--;
            le++;
        }
        return ans;
    }

    void dfs(vector<int>& hash,vector<int>& A,int K,int le,int ri,int& sum)
    {
        if(sum < K || le > ri) return;
        if(sum == K)    ans++;
        
        hash[A[ri]]--;

        if(hash[A[ri]] == 0)    sum--;
        dfs(hash,A,K,le,ri-1,sum);
        if(hash[A[ri]] == 0)    sum++;

        hash[A[ri]]++;
    }
};

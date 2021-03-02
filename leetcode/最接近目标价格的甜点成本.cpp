class Solution {
public:
    set<int> f;
    int n , m, k;
    
    int closestCost(vector<int>& a, vector<int>& b, int t) {
        n = a.size(), m = b.size();
        k = t;
        f.clear();
        dfs(b,0,0);
        
        int res = a[0];
        for(int i = 0; i < n; i++) {
            int tmp = 0;
            for(auto& e : f) {
                int d = a[i] + e;
                if(abs(t - d) < abs(res - t))
                    res = d;
                else if(abs(t - d) == abs(res - t) && d < res)
                    res = d;
            }
        }
        
        return res;
    }
    
    void dfs(vector<int>& b,int id,int sum) {
        f.insert(sum);
        
        for(int i = id; i < m; i++) {
            dfs(b,i + 1,sum);
            sum += b[i];
            dfs(b,i + 1, sum);
            
            sum += b[i];
            dfs(b,i + 1, sum);
        }
    }
};

���������㣬������Ҫ�������ϡ�Ŀǰ���� n �ֱ�������Ϻ� m �����Ͽɹ�ѡ���������������Ҫ��ѭ���¼�������

����ѡ�� һ�� ��������ϡ�
������� һ�ֻ���� ���ϣ�Ҳ���Բ�����κ����ϡ�
ÿ�����͵����� ������� ��
���������������룺

baseCosts ��һ������Ϊ n ���������飬����ÿ�� baseCosts[i] ��ʾ�� i �ֱ�������ϵļ۸�
toppingCosts��һ������Ϊ m ���������飬����ÿ�� toppingCosts[i] ��ʾ һ�� �� i �ֱ��������ϵļ۸�
target ��һ����������ʾ����������Ŀ��۸�
��ϣ���Լ���������ܳɱ������ܽӽ�Ŀ��۸� target ��

������ӽ� target �����ɱ�������ж��ַ��������� �ɱ���Խϵ� ��һ�֡�

 

ʾ�� 1��

���룺baseCosts = [1,7], toppingCosts = [3,4], target = 10
�����10
���ͣ���������ķ�����ϣ������±���� 0 ��ʼ����
- ѡ�� 1 �Ż��ϣ��ɱ� 7
- ѡ�� 1 �� 0 �����ϣ��ɱ� 1 x 3 = 3
- ѡ�� 0 �� 1 �����ϣ��ɱ� 0 x 4 = 0
�ܳɱ���7 + 3 + 0 = 10 ��
ʾ�� 2��

���룺baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
�����17
���ͣ���������ķ�����ϣ������±���� 0 ��ʼ����
- ѡ�� 1 �Ż��ϣ��ɱ� 3
- ѡ�� 1 �� 0 �����ϣ��ɱ� 1 x 4 = 4
- ѡ�� 2 �� 1 �����ϣ��ɱ� 2 x 5 = 10
- ѡ�� 0 �� 2 �����ϣ��ɱ� 0 x 100 = 0
�ܳɱ���3 + 4 + 10 + 0 = 17 ���������ܳɱ�Ϊ 18 ���������������
ʾ�� 3��

���룺baseCosts = [3,10], toppingCosts = [2,5], target = 9
�����8
���ͣ����������ܳɱ�Ϊ 8 �� 10 ����㡣���� 8 ����Ϊ���ǳɱ����͵ķ�����
ʾ�� 4��

���룺baseCosts = [10], toppingCosts = [1], target = 1
�����10
���ͣ�ע�⣬�����ѡ������κ����ϣ��������ѡ��һ�ֻ��ϡ�
 

��ʾ��

n == baseCosts.length
m == toppingCosts.length
1 <= n, m <= 10
1 <= baseCosts[i], toppingCosts[i] <= 104
1 <= target <= 104

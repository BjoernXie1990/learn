����һ��?n?x n?�Ķ���������?grid��ÿһ�β����У������ѡ�������?��������?���н�����

һ������Ҫ���������Ҫ�������Խ������ϵĸ���ȫ������ 0?��

���㷵��ʹ��������Ҫ������ٲ�������������޷�ʹ�������Ҫ�����㷵�� -1?��

���Խ���ָ���Ǵ�?(1, 1)?��?(n, n)?����Щ���ӡ�

?

ʾ�� 1��



���룺grid = [[0,0,1],[1,1,0],[1,0,0]]
�����3
ʾ�� 2��



���룺grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
�����-1
���ͣ������ж���һ���ģ������������޷�ʹ�������Ҫ��
ʾ�� 3��



���룺grid = [[1,0,0],[1,1,0],[1,1,1]]
�����0
?

��ʾ��

n == grid.length
n == grid[i].length
1 <= n?<= 200
grid[i][j]?Ҫô��?0?Ҫô��?1?��


class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> arr;
        int n = grid.size();
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = n-1; j >= 0; j--)
                if(grid[i][j] == 0) sum++;
                else break;
            arr.push_back(sum);
        }
        
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int j = 0;
            for(j = i; j < n; j++)
                if(arr[j] >= n - i - 1) break;
            if(j == n)  return -1;

            for(; j > i; j--)
            {
                swap(arr[j],arr[j-1]);
                ans++;
            }  
        }
        
        return ans;
    }
    
};

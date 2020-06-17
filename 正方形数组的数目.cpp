����һ���Ǹ���������?A�����������ÿ������Ԫ��֮����һ����ȫƽ�����������һ����Ϊ���������顣

���� A �����������е���Ŀ���������� A1 �� A2 ��ͬ�ĳ�Ҫ�����Ǵ���ĳ������ i��ʹ�� A1[i] != A2[i]��

?

ʾ�� 1��

���룺[1,17,8]
�����2
���ͣ�
[1,8,17] �� [17,8,1] ������Ч�����С�
ʾ�� 2��

���룺[2,2,2]
�����1
?

��ʾ��

1 <= A.length <= 12
0 <= A[i] <= 1e9



class Solution {
public:
    unordered_map<int,int> map;
    int len = 0;
    int ans = 0;
    int numSquarefulPerms(vector<int>& A) {
        len = A.size();
        for(auto& num : A)
            map[num]++;
        
        for(auto& num : map)
            dfs(num.first,1);
        
        return ans;
    }

    void dfs(int cur,int depth)
    {
        if(depth == len)
        {
            ans++;
            return;
        }
        map[cur]--;
        for(auto& num : map)
        {
            if(map[num.first] && IsSquare(cur + num.first))
                dfs(num.first,depth+1);
        }
        map[cur]++;
    }

    bool IsSquare(int num)
    {
        int tmp = sqrt(num);
        return tmp * tmp == num;
    }
};

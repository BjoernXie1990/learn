����һЩ��ͬ��ɫ�ĺ��ӣ����ӵ���ɫ�����ֱ�ʾ������ͬ�����ֱ�ʾ��ͬ����ɫ��
�㽫���������ֲ���ȥȥ�����ӣ�ֱ�����еĺ��Ӷ�ȥ��Ϊֹ��ÿһ��������Ƴ�������ͬ��ɫ������ k �����ӣ�k?>= 1��������һ��֮���㽫�õ� k*k �����֡�
���㽫���к��Ӷ�ȥ��֮�������ܻ�õ������ֺ͡�

?

ʾ����

���룺boxes = [1,3,2,2,2,3,4,3,1]
�����23
���ͣ�
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 ��) 
----> [1, 3, 3, 3, 1] (1*1=1 ��) 
----> [1, 1] (3*3=9 ��) 
----> [] (2*2=4 ��)
?

��ʾ��

1 <= boxes.length <= 100
1 <= boxes[i]?<= 100


class Solution {
public:
    int dp[101][101][101];
    int removeBoxes(vector<int>& boxes) {
        memset(dp,0x00,sizeof(dp));

        return dfs(boxes,0,boxes.size()-1,0);
    }

    int dfs(vector<int>& boxes,int le,int ri,int k)
    {
        if(le > ri) return 0;
        if(dp[le][ri][k] != 0)  return dp[le][ri][k];

        //�ж��Ҳ���ͬ��ɫ�ĺ���������ȥ���Ҳ����
        while(le < ri && boxes[ri] == boxes[ri-1])
        {
            ri--;
            k++;
        }
        dp[le][ri][k] = dfs(boxes,le,ri-1,0) + (k + 1) * (k + 1);

        //ȥ�����ĺ���
        for(int i = le; i < ri; i++)
            if(boxes[i] == boxes[ri])
                dp[le][ri][k] = max(dp[le][ri][k],dfs(boxes,le,i,k+1) + dfs(boxes,i+1,ri-1,0));
        return dp[le][ri][k];
    }
};

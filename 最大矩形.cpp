//����һ�������� 0 �� 1 �Ķ�ά�����ƾ����ҳ�ֻ���� 1 �������Σ��������������


class Solution {
public:
    /*
    [
        ["1","0","1","0","0"],
        ["1","0","1","1","1"],
        ["1","1","1","1","1"],
        ["1","0","0","1","0"]
    ]

    ��һ����״ͼ�ĸ߶�["1","0","1","0","0"]��������Ϊ1��

    �ڶ�����״ͼ�ĸ߶�["2","0","2","1","1"]��������Ϊ3��

    ��������״ͼ�ĸ߶�["3","1","3","2","2"]��������Ϊ6��

    ���Ĳ���״ͼ�ĸ߶�["4","0","0","3","0"]��������Ϊ4��
    */
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(!row || !matrix[0].size()) return 0;
        int col = matrix[0].size();

        vector<int> height(col+2,0);
        int ans = 0;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == '1') height[j+1]++;
                else height[j+1]=0;

            int area = MaxRectangle(height);
            ans = max(area,ans); 
        }
        return ans;
    }

    int MaxRectangle(vector<int>& height)
    {
        stack<int> st;
        int ret = 0;

        for(int i = 0; i < height.size(); i++)
        {
            while(!st.empty() && height[i] < height[st.top()])
            {
                int top = st.top();
                st.pop();

                int area = (i - st.top() - 1) * height[top];
                ret = max(area,ret);
            }
            st.push(i);
        }
        return ret;
    }
};

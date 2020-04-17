//����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

//�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

//�ж����Ƿ��ܹ��������һ��λ�á�

//ʾ��?1:

//����: [2,3,1,1,4]
//���: true
//����: ���ǿ������� 1 ������λ�� 0 ���� λ�� 1, Ȼ���ٴ�λ�� 1 �� 3 ���������һ��λ�á�
//ʾ��?2:

//����: [3,2,1,0,4]
//���: false
//����: �������������ܻᵽ������Ϊ 3 ��λ�á�����λ�õ������Ծ������ 0 �� ��������Զ�����ܵ������һ��λ�á�

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;

        for(int i = 0; i < len; i++)
        {
            if(i > ans)
                return false;
            ans = max(ans,i + nums[i]); 
        }

        return true;
    }
};
//
//����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

//�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

//���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

//ʾ��:

//����: [2,3,1,1,4]
//���: 2
//����: �������һ��λ�õ���С��Ծ���� 2��
//?    ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã���?1?����Ȼ����?3?��������������һ��λ�á�


class Solution {
public:
    int jump1(vector<int>& nums) {
        int len = nums.size();
        int min_jump = 0x0000ffff;
        dfs(nums,len,0,min_jump,0);
        return min_jump;
    }
    //���ѳ�ʱ  [5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5]
    void dfs(vector<int>& nums, int& len, int index,int& min_jump,int now_jump)
    {
        //�ж��Ƿ����ֱ���������һ��
        if(index >= len-1)
        {
            min_jump = min(min_jump,now_jump);
            return ;
        }

        for(int i = 1; i <= nums[index]; i++)
        {
            //���Լ�һ����֦�������ǰ������������Զ�����Ŀǰ����Զ����С���ͼ���
            dfs(nums,len,index+i,min_jump,now_jump+1);
        }
    }
    //��̬�滮 [ȫ1] ��ʱ
    int jump2(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len,0x0000ffff);//dp[i]��ʾ������ǰλ����С��Ծ����
        dp[0] = 0;
        for(int i = 0; i < len; i++)
        {
            int jump = min(len-1,i+nums[i]);
            for(int j = 1; j <= jump; j++)
            {
                dp[j] = min(dp[j],dp[i]+1);
            }
        }

        return dp[len-1];
    }

    //ÿһ�α������ҵ�ǰ���Ե�����Զ�ľ�����бȽ�
    int jump(vector<int>& nums){
        int end = 0;
        int maxPosition = 0; 
        int steps = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
         //����������Զ��
            maxPosition = max(maxPosition, nums[i] + i); 
            if( i == end) //�����߽磬�͸��±߽磬���Ҳ�����һ
            {
                end = maxPosition;
                steps++;
            }
        }
        return steps;
    }
};

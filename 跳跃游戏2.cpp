����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

ʾ��:

����: [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
?    ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã���?1?����Ȼ����?3?��������������һ��λ�á�
˵��:

���������ǿ��Ե�����������һ��λ�á�


	//BFS
     int jump(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;

        vector<int> visit(len,0);
        queue<int> que;
        que.push(0);//��ʼ�����
        visit[0] = 1;

        int ans = 0;
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                int pos = que.front();
                que.pop();
                if(pos + nums[pos] >= len-1) return ++ans;
                for(int j = nums[pos]; ~j; j--)
                {
                    if(visit[pos + j]) continue;
                    que.push(pos + j);
                    visit[pos + j] = 1;
                }
            }
            ans++;
        }
        return -1;
    }

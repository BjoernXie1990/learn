struct eve {
    int time;   // ����ʱ��
    int id;     // ���������
    eve(int t,int i)
        :time(t),id(i){}
    
    
};
// > ��С��
bool operator < (const eve& a,const eve& b) {
    return a.time > b.time;
}

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<eve> pq;
        set<int> st;    // ���з�����
        int n = arrival.size();

        int nums[k];
        memset(nums,0x00,sizeof(nums));
        int cnt = 1;
        for(int i = 0; i < k && i < n; i++) {
            eve tmp(arrival[i]+load[i],i);
            pq.push(tmp);
            nums[i]++;
        }

        for(int i = k; i < n; i++) {
            // ȥ�����з�����
            while(pq.empty() == false && pq.top().time <= arrival[i]) {
                auto f = pq.top();
                pq.pop();
                st.insert(f.id);
            }

            if(st.size() == 0) continue;    // û�п��У�����
            auto idx = st.lower_bound((i%k)); // ��һ���� i % k ��ģ����еķ�����λ��
            if(idx == st.end()) idx = st.begin();

            eve tmp(arrival[i]+load[i],*idx);
            pq.push(tmp);
            nums[*idx]++;
            cnt = max(nums[*idx],cnt);
            st.erase(idx);
        }

        vector<int> ans;
        for(int i = 0; i < k; i++) if(nums[i] == cnt) ans.push_back(i);
        return ans;
    }
};

���� k?�������������Ϊ 0?�� k-1?�����ǿ���ͬʱ�����������顣ÿ��������������ļ����������� ����ͬʱ������һ������?��������䵽�������Ĺ������£�

��?i?����Ŵ� 0 ��ʼ�������󵽴
������з��������ѱ�ռ�ݣ���ô��������������ȫ��������
�����?(i % k)?�����������У���ô��Ӧ�������ᴦ�������
���򣬽������Ÿ���һ�����еķ�����������������һ��������Ҫ�Ļ����ܴӵ� 0 ����������ʼ��������һ�����еķ����������ȷ�˵������� i?����������æ����ô��鿴�� (i+1)?������������ (i+2)?���������ȵȡ�
����һ�� �ϸ����?������������?arrival?����ʾ��?i?������ĵ���ʱ�䣬����һ������?load?������?load[i]?��ʾ��?i?������Ĺ�������Ҳ���Ƿ��������������Ҫ��ʱ�䣩������������ҵ� �æ�ķ�����?���æ����Ϊһ������������������������з����������ġ�

���㷵�ذ�������?�æ������?��ŵ��б������������˳�򷵻�����б�

?

ʾ�� 1��



���룺k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
�����[1] 
���ͣ�
���з�����һ��ʼ���ǿ��еġ�
ǰ 3 ������ֱ���ǰ 3 ̨���������δ���
���� 3 ������ʱ�򣬷����� 0 ��ռ�ݣ��������°��ŵ���һ̨���еķ�������Ҳ���Ƿ����� 1 ��
���� 4 ������ʱ���������з���������ռ�ݣ�������������
������ 0 �� 2 �ֱ𶼴�����һ�����󣬷����� 1 �����������������Է����� 1 ����æ�ķ�������
ʾ�� 2��

���룺k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
�����[0]
���ͣ�
ǰ 3 ������ֱ�ǰ 3 ������������
���� 3 ���������ڷ����� 0 ���У����������� 0 ����
������ 0 �������������󣬷����� 1 �� 2 �ֱ�����һ���������Է����� 0 ����æ�ķ�������
ʾ�� 3��

���룺k = 3, arrival = [1,2,3], load = [10,12,11]
�����[0,1,2]
���ͣ�ÿ���������ֱ�����һ�������������Ƕ�����æ�ķ�������
ʾ�� 4��

���룺k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
�����[1]
ʾ�� 5��

���룺k = 1, arrival = [1], load = [1]
�����[0]
?

��ʾ��

1 <= k <= 105
1 <= arrival.length, load.length <= 105
arrival.length == load.length
1 <= arrival[i], load[i] <= 109
arrival?��֤ �ϸ����?��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

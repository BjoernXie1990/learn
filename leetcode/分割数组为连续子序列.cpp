class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnt,need;
        for(int e : nums) cnt[e]++;

        for(int e : nums) {
            if(cnt[e] == 0) continue;

            if(need[e] > 0) {
                need[e] --;
                need[e + 1] ++;
            } else if(cnt[e + 1] && cnt[e + 2]) {
                cnt[e + 1] --;
                cnt[e + 2] --;
                need[e + 3] ++;
            } else {
                return false;
            }

            cnt[e] --;
        }

        return true;
    }
};


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int> > > mp;
        for(int e : nums) {
            if(mp.count(e) == 0) {
                mp[e] = priority_queue<int,vector<int>,greater<int> > ();
            }

            if(mp.count(e - 1)) {
                auto& pq = mp[e - 1];
                int preLen = pq.top();
                pq.pop();
                if(pq.empty()) mp.erase(e - 1);
                mp[e].push(preLen + 1);
            } else {
                mp[e].push(1);
            }
        }

        for(auto& e : mp) {
            auto pq = e.second;
            if(pq.top() < 3) return false;
        }
        return true;
    }
};


����һ��������������������� num�����ܰ����ظ����֣������㽫���Ƿָ��һ�����������У�����ÿ�������ж���������������ҳ�������Ϊ 3 ��

���������������ָ�򷵻� true �����򣬷��� false ��

?

ʾ�� 1��

����: [1,2,3,3,4,5]
���: True
����:
����Էָ�������������������� : 
1, 2, 3
3, 4, 5
?

ʾ�� 2��

����: [1,2,3,3,4,4,5,5]
���: True
����:
����Էָ�������������������� : 
1, 2, 3, 4, 5
3, 4, 5
?

ʾ�� 3��

����: [1,2,3,4,4,5]
���: False
?

��ʾ��

��������鳤�ȷ�ΧΪ [1, 10000]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

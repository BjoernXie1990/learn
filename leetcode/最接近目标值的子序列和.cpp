const int N = 2e6 + 10;
int f[N];

class Solution {
public:
    int g,cnt,n,res;
    vector<int> num;
    int minAbsDifference(vector<int>& nums, int goal) {
        res = INT_MAX,g = goal,n = nums.size(),cnt = 0;
        num = nums;
        dfs1(0,0);
        sort(f,f+cnt);
        dfs2((n + 1) /2,0);
        return res;
    }

    void dfs1(int id,int sum) {
        if(id == (n + 1) /2) {
            f[cnt ++] = sum;
            return;
        }

        dfs1(id + 1, sum);
        dfs1(id + 1, sum + num[id]);
    }

    void dfs2(int id,int sum) {
        if(id == n) {
            int le = 0, ri = cnt - 1;
            while(le < ri) {
                int mid = le + ri + 1 >> 1;
                if(f[mid] + sum <= g) le = mid;
                else ri = mid - 1;
            }
            res = min(res,abs(f[le] + sum - g));
            if(le + 1 < cnt) res = min(res,abs(f[le + 1] + sum - g));
            return;
        }
        dfs2(id + 1, sum);
        dfs2(id + 1, sum + num[id]);
    }
};

����һ���������� nums ��һ��Ŀ��ֵ goal ��

����Ҫ�� nums ��ѡ��һ�������У�ʹ������Ԫ���ܺ���ӽ� goal ��Ҳ����˵�����������Ԫ�غ�Ϊ sum ������Ҫ ��С�����Բ� abs(sum - goal) ��

���� abs(sum - goal) ���ܵ� ��Сֵ ��

ע�⣬�������������ͨ���Ƴ�ԭʼ�����е�ĳЩԪ�أ�����ȫ�����ޣ����γɵ����顣

?

ʾ�� 1��

���룺nums = [5,-7,3,5], goal = 6
�����0
���ͣ�ѡ������������Ϊѡ���������У�Ԫ�غ�Ϊ 6 ��
�����к���Ŀ��ֵ��ȣ����Ծ��Բ�Ϊ 0 ��
ʾ�� 2��

���룺nums = [7,-9,15,-2], goal = -5
�����1
���ͣ�ѡ�������� [7,-9,-2] ��Ԫ�غ�Ϊ -4 ��
���Բ�Ϊ abs(-4 - (-5)) = abs(1) = 1 ���ǿ��ܵ���Сֵ��
ʾ�� 3��

���룺nums = [1,2,3], goal = -7
�����7
?

��ʾ��

1 <= nums.length <= 40
-107 <= nums[i] <= 107
-109 <= goal <= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/closest-subsequence-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

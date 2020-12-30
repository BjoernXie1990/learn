struct Node {
    int x,m,k;
    bool operator<(const Node& no) const {
        return m < no.m;
    }
}q[100010];

int f[100005 * 32 + 10][2], idx;

class Solution {
public:
    
    void insert(int num) {
        int p = 0;
        for(int i = 31; i >= 0; i--) {
            int ne = (num >> i) & 1;
            if(f[p][ne] == 0) f[p][ne] = ++idx;
            p = f[p][ne];
        }
    }

    int find(int num) {
        if(!idx) return -1;     // û�б�num С��Ԫ��

        int p = 0;
        int res = 0;
        for(int i = 31; i >= 0; i--) {
            int ne = (num >> i) & 1;
            if(f[p][!ne]) {
                res = res * 2 + 1;
                p = f[p][!ne];
            } else {
                res = res * 2;
                p = f[p][ne];
            }
        }

        return res;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        idx = 0;
        memset(f,0x00,sizeof f);

        int n = nums.size(), m = queries.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < m; i++)
            q[i] = {queries[i][0],queries[i][1],i};
        sort(q,q+m);

        vector<int> res(m);
        int le = 0;
        for(int i = 0; i < m; i++) {
            while(le < n && nums[le] <= q[i].m){
                insert(nums[le]);
                le++;
            }
            res[q[i].k] = find(q[i].x);
        }

        return res;
    }

    // vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    //     int n = nums.size(), m = queries.size();
    //     sort(nums.begin(),nums.end());
    //     for(int i = 0; i < m; i++) queries[i].push_back(i);

    //     sort(queries.begin(),queries.end(),[](const auto& a,const auto& b)->bool{
    //         return a[1] < b[1];
    //     });

    //     vector<int> res(m);
    //     int le = 0;
    //     for(auto& e : queries) {
    //         while(le < n && nums[le] <= e[1]){
    //             insert(nums[le]);
    //             le++;
    //         }
    //         res[e[2]] = find(e[0]);
    //     }

    //     return res;
    // }
};


����һ���ɷǸ�������ɵ����� nums ������һ����ѯ���� queries ������ queries[i] = [xi, mi] ��

�� i ����ѯ�Ĵ��� xi ���κ� nums �����в����� mi ��Ԫ�ذ�λ���XOR���õ������ֵ�����仰˵������ max(nums[j] XOR xi) ���������� j ������ nums[j] <= mi ����� nums �е�����Ԫ�ض����� mi�����մ𰸾��� -1 ��

����һ���������� answer ��Ϊ��ѯ�Ĵ𰸣����� answer.length == queries.length �� answer[i] �ǵ� i ����ѯ�Ĵ𰸡�

?

ʾ�� 1��

���룺nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
�����[3,3,7]
���ͣ�
1) 0 �� 1 �ǽ��е����������� 1 ��������0 XOR 3 = 3 �� 1 XOR 3 = 2 �������еĸ���ֵ�� 3 ��
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
ʾ�� 2��

���룺nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
�����[15,-1,5]
?

��ʾ��

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109
ͨ������659�ύ����2,040

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

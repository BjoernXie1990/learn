class Solution {
public:
    const int M = 50010;
    class dtree {
        struct node {
            node* son[2];
            node() {
                son[1] = son[0] = nullptr;
            }
        };
        public:
            dtree(int size) {
                root = new node();
            }

            void insert(int num) {
                node* cur = root;
                for(int i = 30; ~i; i--) {
                    int v = (num >> i) & 1;
                    if(cur->son[v] == nullptr) {
                        cur->son[v] = new node();
                    }
                    cur = cur->son[v];
                }
            }

            int check(int num) {
                int ret = 0;
                node* cur = root;
                for(int  i = 30; ~i; i--) {
                    int v = (num >> i) & 1;
                    if(cur->son[!v] != nullptr) {
                        ret |= (1<<i);
                        cur = cur->son[!v];
                    } else {
                        cur = cur->son[v];
                    }
                }

                return ret;
            }
        private:
            node* root;
    };

    int findMaximumXOR(vector<int>& nums) {
        dtree dt(M);
        for(int i = 0; i < nums.size(); i++) dt.insert(nums[i]);

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) ans = max(ans,dt.check(nums[i]));

        return ans;
    }
};

����һ���ǿ����飬������Ԫ��Ϊ a0, a1, a2, �� , an-1������ 0 �� ai < 231?��

�ҵ� ai ��aj?������� (XOR) ������������0 �� i,??j < n?��

������O(n)��ʱ�������������

ʾ��:

����: [3, 10, 5, 25, 2, 8]

���: 28

����: ���Ľ���� 5 ^ 25 = 28.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

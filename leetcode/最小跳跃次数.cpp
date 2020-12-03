class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();

        queue<int> que({0});
        int step = 0;
        int len = 0;
        while(!que.empty()) {
            int size = que.size();
            while(size --) {
                int f = que.front();
                que.pop();

                // right
                if(f + jump[f] >= n) return step + 1;
                if(f + jump[f] >= len) que.push(f + jump[f]);

                // left 
                for(int i = len; i <= f; i++) que.push(i);
                len = max(len,f + 1);
            }
            step++;
        }

        return step;
    }
};

Ϊ�˸�ˢ���ͬѧһЩ�����������Ŷ�������һ��������Ϸ������Ϸ���� N �����ⵯ���ų�һ�ţ����Ϊ 0 �� N-1����ʼ��һ��С���ڱ�� 0 �ĵ��ɴ�����С���ڱ��Ϊ i �ĵ��ɴ���ͨ���������ɣ�����ѡ���С�����ҵ���?jump[i] �ľ��룬���������䵽������൯�ɵ�λ�á�Ҳ����˵���ڱ��Ϊ i ���ɴ��������ɣ�С����Ե��� 0 �� i-1 �����ⵯ�ɻ��� i+jump[i] �ĵ��ɣ��� i+jump[i]>=N �����ʾС�򵯳��˻�������С��λ�ڱ�� 0 ���ĵ���ʱ���������󵯡�

Ϊ�˻�ý���������Ҫ��С�򵯳������������������Ҫ�������ٴε��ɣ����Խ�С��ӱ�� 0 ���ɵ�������������������Խ����� N-1 �ĵ��ɡ�

ʾ�� 1��

���룺jump = [2, 5, 1, 1, 1, 1]

�����3

���ͣ�С Z ������Ҫ���� 3 �ε��ɣ�С�����ε����˳��Ϊ 0 -> 2 -> 1 -> 6������С�򵯳��˻�����

���ƣ�

1 <= jump.length <= 10^6
1 <= jump[i] <= 10000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/zui-xiao-tiao-yue-ci-shu
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

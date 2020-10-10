class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);

        queue<int> que({start});
        vis[start] = true;
        while ( que.empty() == false ) {
            int size = que.size();
            while ( size -- ) {
                int f = que.front();
                que.pop();
                if(arr[f] == 0) return true;

                // i + arr[i]
                int pos = f + arr[f];
                if(pos < n && vis[pos] == false) {
                    que.push(pos);
                    vis[pos] = true;
                }

                // i - arr[i]
                pos = f - arr[f];
                if( pos >= 0 && vis[pos] == false) {
                    que.push(pos);
                    vis[pos] = true;
                }
            }
        }

        return false;
    }
};

������һ���Ǹ���������?arr�����ʼλ�ڸ��������ʼ�±�?start?��������λ���±�?i?��ʱ�����������?i + arr[i] ���� i - arr[i]��

�����ж��Լ��Ƿ��ܹ�������ӦԪ��ֵΪ 0 �� ��һ �±괦��

ע�⣬������ʲô����£��㶼�޷���������֮�⡣

?

ʾ�� 1��

���룺arr = [4,2,3,0,3,1,2], start = 5
�����true
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ����� 
�±� 5 -> �±� 4 -> �±� 1 -> �±� 3 
�±� 5 -> �±� 6 -> �±� 4 -> �±� 1 -> �±� 3 
ʾ�� 2��

���룺arr = [4,2,3,0,3,1,2], start = 0
�����true 
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ����� 
�±� 0 -> �±� 4 -> �±� 1 -> �±� 3
ʾ�� 3��

���룺arr = [3,0,2,1,2], start = 2
�����false
���ͣ��޷�����ֵΪ 0 ���±� 1 ���� 
?

��ʾ��

1 <= arr.length <= 5 * 10^4
0 <= arr[i] <?arr.length
0 <= start < arr.length

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/jump-game-iii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

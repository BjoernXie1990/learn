class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int,vector<int>,less<int> > que;  // ���

        int sum = 0;
        for(int i = 1; i < n; i++) {
            int num = heights[i] - heights[i-1];
            if(num <= 0)    continue;

            // ��Ҫʹ��ש���������
            que.push(num);
            sum += num;
            if(sum > bricks) {
                sum -= que.top();
                que.pop();
                ladders--;
            }
            if(ladders < 0) return i-1;
        }

        return n - 1;
    }
};


����һ���������� heights ����ʾ������ĸ߶ȡ�����һЩש�� bricks ������ ladders ��

��ӽ����� 0 ��ʼ�ọ́����������Ľ������ƶ����ڼ���ܻ��õ�ש������ӡ�

���ӽ����� i �ƶ��������� i+1���±� �� 0 ��ʼ ��ʱ��

�����ǰ������ĸ߶� ���ڻ���� ��һ������ĸ߶ȣ�����Ҫ���ӻ�ש��
�����ǰ�����ĸ߶� С�� ��һ�������ĸ߶ȣ�������ʹ�� һ������ �� (h[i+1] - h[i]) ��ש��
�������ѷ�ʽʹ�ø��������Ӻ�ש�飬��������Ե������Զ��������±꣨�±� �� 0 ��ʼ ����
?

ʾ�� 1��


���룺heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
�����4
���ͣ��ӽ����� 0 ����������԰��˷�������ọ́�
- ��ʹ��ש������ӵ��ｨ���� 1 ����Ϊ 4 >= 2
- ʹ�� 5 ��ש�鵽�ｨ���� 2 �������ʹ��ש������ӣ���Ϊ 2 < 7
- ��ʹ��ש������ӵ��ｨ���� 3 ����Ϊ 7 >= 6
- ʹ��Ψһ�����ӵ��ｨ���� 4 �������ʹ��ש������ӣ���Ϊ 6 < 9
�޷�Խ�������� 4 ����Ϊû�и���ש������ӡ�
ʾ�� 2��

���룺heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
�����7
ʾ�� 3��

���룺heights = [14,3,19,3], bricks = 17, ladders = 0
�����3
?

��ʾ��

1 <= heights.length <= 105
1 <= heights[i] <= 106
0 <= bricks <= 109
0 <= ladders <= heights.length

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/furthest-building-you-can-reach
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

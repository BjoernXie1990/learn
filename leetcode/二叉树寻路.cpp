��һ�����޵Ķ������ϣ�ÿ���ڵ㶼�������ӽڵ㣬���еĽڵ� ���� ���ΰ�?��֮�� ���ν��б�ǡ�

����ͼ��ʾ���������У�������һ�С������С������С������У��������ҵ�˳����б�ǣ�

��ż���У������ڶ��С������С������С������У������ҵ����˳����б�ǡ�



��������ĳһ���ڵ�ı�� label�����㷵�شӸ��ڵ㵽�ñ��Ϊ label �ڵ��·������·������;���Ľڵ�������ɵġ�

?

ʾ�� 1��

���룺label = 14
�����[1,3,4,14]
ʾ�� 2��

���룺label = 26
�����[1,2,6,10,26]
?

��ʾ��

1 <= label <= 10^6



class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int sum = 0;
        while(sum < label)
            sum = sum * 2 + 1;

        int le = (sum + 1) / 2;
        int ri = sum;

        vector<int> ans;
        while(le != ri)
        {
            ans.push_back(label);
            ri = le - 1;
            le = le / 2;
            label = label / 2;

            label = (le + ri) - label;
        }
        ans.push_back(label);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

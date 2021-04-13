class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        int maxN = 0;
        for(int i = 0; i < n; i++)
            maxN = max(maxN,vat[i]);
        if(maxN == 0)
            return 0;
        
        int res = 0x3f3f3f3f;
        for(int i = 1; i <= maxN; i++) {
            int cur = i;
            for(int j = 0; j < n; j ++) {
                int t = (vat[j] + i - 1) / i;
                cur += max(0,t - bucket[j]);
            }

            res = min(res,cur);
        }

        return res;
    }
};


���� N �����������ҳ�ʼ���յ�ˮ�ף�ÿ��ˮ������һ��ˮͰ������ˮ���� i ��ˮ���䱸��ˮͰ�������� bucket[i]��С�����������ֲ�����

����ˮͰ��ѡ������һ��ˮͰ��ʹ����������Ϊ bucket[i]+1
��ˮ����ȫ��ˮͰ����ˮ��������Զ�Ӧ��ˮ��
ÿ��ˮ�׶�Ӧ�����ˮ������ vat[i]������С��������Ҫ���ٴβ��������������ˮ����ˮҪ��

ע�⣺ʵ����ˮ�� �ﵽ�򳬹� �����ˮ�����������ˮҪ��

ʾ�� 1��

���룺bucket = [1,3], vat = [6,8]

�����4

���ͣ�
�� 1 �β������� bucket[0]��
�� 2 ~ 4 �β�����ѡ����ˮ�����������ˮҪ��


ʾ�� 2��

���룺bucket = [9,0,1], vat = [0,2,2]

�����3

���ͣ�
�� 1 �β�����ѡ������ bucket[1]
�� 2~3 �β���ѡ����ˮ�����������ˮҪ��

��ʾ��

1 <= bucket.length == vat.length <= 100
0 <= bucket[i], vat[i] <= 10^4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/o8SXZn
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

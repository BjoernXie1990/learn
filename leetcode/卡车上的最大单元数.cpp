class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),[](const auto& a,const auto& c)->bool {
            return a[1] > c[1];
        });
        
        int ans = 0;
        int n = b.size();
        int i = 0;
        while( i < n && t) {
            int cnt = min(t,b[i][0]);
            ans += (b[i][1] * cnt);
            
            t -= cnt;
            i++;
        }
        
        return ans;
    }
};

���㽫һЩ����װ�� һ������ �ϡ�����һ����ά���� boxTypes ������ boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi] ��

numberOfBoxesi ������ i �����ӵ�������
numberOfUnitsPerBoxi ������ i?ÿ�����ӿ���װ�صĵ�Ԫ������
���� truckSize ��ʾ�����Ͽ���װ�� ���� �� ������� ��ֻҪ�������������� truckSize ����Ϳ���ѡ����������װ�������ϡ�

���ؿ�������װ��?��Ԫ �� ��� ������

?

ʾ�� 1��

���룺boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
�����8
���ͣ����ӵ�������£�
- 1 ����һ������ӣ����溬 3 ����Ԫ��
- 2 ���ڶ�������ӣ�ÿ�����溬 2 ����Ԫ��
- 3 ������������ӣ�ÿ�����溬 1 ����Ԫ��
����ѡ���һ��͵ڶ�����������ӣ��Լ��������һ�����ӡ�
��Ԫ���� = (1 * 3) + (2 * 2) + (1 * 1) = 8
ʾ�� 2��

���룺boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
�����91
?

��ʾ��

1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 106

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-units-on-a-truck
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

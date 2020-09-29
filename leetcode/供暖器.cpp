class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int n = heaters.size();
        int ans = -1;
        for(auto& idx : houses) {
            int pos = BinaryFind(heaters,0,n-1,idx);
            
            int ri = (pos == n) ? INT_MAX : heaters[pos] - idx;
            int le = (pos == 0) ? INT_MAX : idx - heaters[pos-1];
            ans = max(ans,min(ri,le));
        }

        return ans;
    }

    // ��һ�γ��ֵ�λ��
    int BinaryFind(vector<int>& arr,int le,int ri,int num) {
        while(le <= ri) {
            int mid = (le + ri) / 2;

            if(arr[mid] == num) return mid;
            else if(arr[mid] > num) ri = mid - 1;
            else if(arr[mid] < num) le = mid + 1;
        }

        return le;
    }   
};

�����Ѿ����١�?������������һ���й̶����Ȱ뾶�Ĺ�ů�������з��ݹ�ů��

���ڣ�����λ��һ��ˮƽ���ϵķ��ݺ͹�ů����λ�ã��ҵ����Ը������з��ݵ���С���Ȱ뾶��

���ԣ�������뽫���Ƿ��ݺ͹�ů����λ�á��㽫�����ů������С���Ȱ뾶��

˵��:

�����ķ��ݺ͹�ů������Ŀ�ǷǸ����Ҳ��ᳬ�� 25000��
�����ķ��ݺ͹�ů����λ�þ��ǷǸ����Ҳ��ᳬ��10^9��
ֻҪ����λ�ڹ�ů���İ뾶��(�����ڱ�Ե��)�����Ϳ��Եõ���ů��
���й�ů������ѭ��İ뾶��׼�����ȵİ뾶Ҳһ����
ʾ�� 1:

����: [1,2,3],[2]
���: 1
����: ����λ��2����һ����ů����������ǽ����Ȱ뾶��Ϊ1����ô���з��ݾͶ��ܵõ���ů��
ʾ�� 2:

����: [1,2,3,4],[1,4]
���: 1
����: ��λ��1, 4����������ů����������Ҫ�����Ȱ뾶��Ϊ1���������з��ݾͶ��ܵõ���ů��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/heaters
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

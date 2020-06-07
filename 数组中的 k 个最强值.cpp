����һ���������� arr ��һ������ k ��

�� m Ϊ�������λ����ֻҪ������������ǰ��֮һ���Ϳ����ж� arr[i] ��ֵ�� arr[j] ��ֵ��ǿ��

?|arr[i] - m| > |arr[j]?- m|
?|arr[i] - m| == |arr[j] - m|���� arr[i] > arr[j]
�뷵������������ǿ�� k ��ֵ��ɵ��б��𰸿����� ����˳�� ���ء�

��λ�� ��һ�����������б��д����м�λ�õ�ֵ����ʽ�ϣ�����б�ĳ���Ϊ n ����ô��λ�����Ǹ������б��±�� 0 ��ʼ����λ�� ((n - 1) / 2) ��Ԫ�ء�

���� arr =?[6, -3, 7, 2, 11]��n = 5�����������õ� arr = [-3, 2, 6, 7, 11] ��������м�λ��Ϊ m = ((5 - 1) / 2) = 2 ����λ�� arr[m] ��ֵΪ 6 ��
���� arr =?[-7, 22, 17,?3]��n = 4�����������õ�?arr = [-7, 3, 17, 22] ��������м�λ��Ϊ?m = ((4 - 1) / 2) = 1 ����λ�� arr[m] ��ֵΪ 3 ��
?

ʾ�� 1��

���룺arr = [1,2,3,4,5], k = 2
�����[5,1]
���ͣ���λ��Ϊ 3������ǿ����˳������������Ϊ [5,1,4,2,3]����ǿ������Ԫ���� [5, 1]��[1, 5] Ҳ����ȷ�𰸡�
ע�⣬���� |5 - 3| == |1 - 3| ������ 5 �� 1 ��ǿ����Ϊ 5 > 1 ��
ʾ�� 2��

���룺arr = [1,1,3,5,5], k = 2
�����[5,5]
���ͣ���λ��Ϊ 3, ����ǿ����˳������������Ϊ [5,5,1,1,3]����ǿ������Ԫ���� [5, 5]��
ʾ�� 3��

���룺arr = [6,7,11,7,6,8], k = 5
�����[11,8,6,6,7]
���ͣ���λ��Ϊ 7, ����ǿ����˳������������Ϊ [11,8,6,6,7,7]��
[11,8,6,6,7] ���κ����ж�����ȷ�𰸡�
ʾ�� 4��

���룺arr = [6,-3,7,2,11], k = 3
�����[-3,11,2]
ʾ�� 5��

���룺arr = [-7,22,17,3], k = 2
�����[22,17]
?

��ʾ��

1 <= arr.length <= 10^5
-10^5 <= arr[i] <= 10^5
1 <= k <= arr.length


class Solution {
public:
    int m;
    vector<int> getStrongest1(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int len = arr.size();
        if(len == 0) return {};

        m = arr[(len-1)/2]; 

        sort(arr.begin(),arr.end(),[&](const int a,const int b)
                                    {
                                        int x = abs(a-m);
                                        int y = abs(b-m);
                                        return x==y ? a > b : x > y;
                                    });

        vector<int> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(arr[i]);
        return ans;
    }

    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int len = arr.size();
        if(len == 0) return {};

        m = arr[(len-1)/2]; 

        int l = 0;
        int r = arr.size() - 1;
        
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            int x = abs(arr[l] - m);
            int y = abs(arr[r] - m);
            if(x > y)
            {
                ans.push_back(arr[l]);
                l++;
            }
            else
            {
                ans.push_back(arr[r]);
                r--;
            }
        }
        return ans;
    }

};

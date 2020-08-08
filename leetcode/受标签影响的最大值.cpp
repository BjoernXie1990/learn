������һ����ļ��ϣ����е�?i?���ֵΪ?values[i]����ǩΪ?labels[i]��

���Ǵ���Щ����ѡ��һ���Ӽ�?S������һ����

|S| <= num_wanted
��������ı�ǩ L���Ӽ� S �б�ǩΪ L?�������Ŀ������?<= use_limit��
�����Ӽ�?S?�������ܵ�?�͡�

?

ʾ�� 1��

���룺values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
�����9
���ͣ�ѡ�����Ӽ��ǵ�һ�������͵����
ʾ�� 2��

���룺values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
�����12
���ͣ�ѡ�����Ӽ��ǵ�һ��ڶ���͵����
ʾ�� 3��

���룺values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
�����16
���ͣ�ѡ�����Ӽ��ǵ�һ��͵����
ʾ�� 4��

���룺values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
�����24
���ͣ�ѡ�����Ӽ��ǵ�һ��ڶ���͵����
?

��ʾ��

1 <= values.length == labels.length <= 20000
0 <= values[i], labels[i]?<= 20000
1 <= num_wanted, use_limit?<= values.length


class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        using key = pair<int,int>;
        vector<key> arr;
        unordered_map<int,int> sum_lab;

        for(int i = 0; i < values.size(); i++)
            arr.push_back(make_pair(values[i],labels[i]));
        sort(arr.begin(),arr.end(),
            [=](const key& a,const key& b)->bool{
                return a.first > b.first;
            }
        );

        int ans = 0;
        int count = 0;
        for(int i = 0; i < arr.size() && count < num_wanted; i++)
        {
            //�ų���ǩ���ִ�����������
            if(sum_lab[arr[i].second] >= use_limit) continue;

            ans += arr[i].first;
            count++;
            sum_lab[arr[i].second]++;
        }

        return ans;
    }
};


����һλ�о������ı����ô��������飨�����ô����ǷǸ�����������дһ��������������о��ߵ� h?ָ����

h ָ���Ķ��壺h ���������ô�������high citations����һ��������Ա�� h ָ����ָ���������� ��N ƪ�����У��ܹ��� h ƪ���ķֱ����������� h �Ρ��������?N - h?ƪ����ÿƪ�����ô���?������ h �Ρ���

���磺ĳ�˵� h ָ���� 20�����ʾ���ѷ���������У�ÿƪ������������ 20 �ε������ܹ��� 20 ƪ��

?

ʾ����

���룺citations = [3,0,6,1,5]
�����3 
���ͣ����������ʾ�о����ܹ��� 5 ƪ���ģ�ÿƪ������Ӧ�ı������� 3, 0, 6, 1, 5 �Ρ�
?    �����о����� 3 ƪ����ÿƪ ���� �������� 3 �Σ�������ƪ����ÿƪ������ ������ 3 �Σ��������� h ָ���� 3��
?

��ʾ����� h �ж��ֿ��ܵ�ֵ��h ָ�������������Ǹ���

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),[](const int a,const int b)->bool{
            return a < b;
        });

        int n = citations.size();
        // for(int i = 0; i < n; i++)
        // {
        //     int ans = n - i;
        //     if(ans <= citations[i])
        //         return ans;
        // }

        int ans = n;
        for(int i = 0; i < n; i++)
        {
            if(citations[i] < ans)
                ans--;
            if(citations[i] == ans) break;
        }
        return ans;
    }
};

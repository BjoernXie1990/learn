����һ�������ַ��� S������ S = "123456579"�����ǿ��Խ����ֳ�쳲�����ʽ������ [123, 456, 579]��

��ʽ�ϣ�쳲�����ʽ������һ���Ǹ������б� F�������㣺

0 <= F[i] <= 2^31 - 1����Ҳ����˵��ÿ������������ 32 λ�з����������ͣ���
F.length >= 3��
�������е�0 <= i < F.length - 2������ F[i] + F[i+1] = F[i+2] ������
���⣬��ע�⣬���ַ�����ֳ�С��ʱ��ÿ���������һ����Ҫ���㿪ͷ����������������� 0 ����

���ش� S ��ֳ���������һ��쳲�����ʽ�����п飬������ܲ���򷵻� []��

?

ʾ�� 1��

���룺"123456579"
�����[123,456,579]
ʾ�� 2��

����: "11235813"
���: [1,1,2,3,5,8,13]
ʾ�� 3��

����: "112358130"
���: []
����: ���������޷���ɡ�
ʾ�� 4��

���룺"0123"
�����[]
���ͣ�ÿ��������ֲ������㿪ͷ����� "01"��"2"��"3" ������Ч�𰸡�
ʾ�� 5��

����: "1101111"
���: [110, 1, 111]
����: ��� [11,0,11,11] Ҳͬ�������ܡ�
?

��ʾ��

1 <= S.length?<= 200
�ַ��� S ��ֻ�������֡�

class Solution {
public:
    int n;
    vector<int> splitIntoFibonacci(string s) {
        vector<int> ans;
        n = s.size();
        if(n < 3)  return ans;

        vector<long> cur; 
        dfs(0,cur,s,ans);

        return ans;
    }

    void dfs(int idx,vector<long>& cur,string& s,vector<int>& ans)
    {
        if(ans.size() != 0) return;

        //���п���
        if(idx == n && cur.size() > 2)
        {
            for(auto num : cur)
                ans.push_back((int)num);
            return;
        }

        long num = 0;
        for(int i = idx; i < n; i++)
        {
            if(i == idx + 1 && num == 0)    break;
            num = num * 10 + (s[i] -'0');
            
            if(num > INT_MAX)   break;

            int len = cur.size();
            if(len >= 2)
            {
                long pre = cur[len - 1] + cur[len - 2];
                if(pre < num || pre > INT_MAX)  break;

                if(pre > num)   continue;
            }

            // len < 2 
            // cur[len - 1] + cur[len - 2] == num
            cur.push_back(num);
            dfs(i+1,cur,s,ans);
            if(ans.size() > 0)  return;
            cur.pop_back();
        }
    }
};

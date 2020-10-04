class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string,vector<string> > mt;
        int n = keyName.size();
        for(int i = 0; i < n; i++) {
            mt[keyName[i]].push_back(keyTime[i]);
        }
        
        vector<string> ans;
        for(auto& st : mt) {
            sort(st.second.begin(),st.second.end());
            // for(auto str : st.second) {
            //     cout<<str<<" ";
            // }
            // cout<<endl;
            auto& arr = st.second;
            int m = arr.size();
            for(int i = 0; i <= m - 3; i++) {
                int cnt = 1;
                for(int j = i+1; j < m; j++) {
                    if(check(arr[i],arr[j]) == false || cnt == 3) break;
                    cnt++;
                }
                if(cnt == 3) {
                    ans.push_back(st.first);
                    break;
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    bool check(string& le,string& ri) {
        int n1 = atoi(le[0]) * 10 + atoi(le[1]);
        int n2 = atoi(le[3]) * 10 + atoi(le[4]);
        
        int m1 = atoi(ri[0]) * 10 + atoi(ri[1]);
        int m2 = atoi(ri[3]) * 10 + atoi(ri[4]);
        
        n1 += 1;
        if(n1 == 24) n2 = 0;
        if(m1 < n1 || (m1 == n1 && n2 >= m2)) return true;
        return false;
    }
    
    inline int atoi(char ch) {
        return ch - '0';
    }
};


���۹�˾��Ա����ʹ��Ա���������칫�ҵ��š�ÿ��һ��Ա��ʹ��һ������Ա����������ϵͳ���¼��Ա�������ֺ�ʹ��ʱ�䡣���һ��Ա����һСʱʱ����ʹ��Ա�����Ĵ������ڵ������Σ����ϵͳ���Զ�����һ�� ����?��

�����ַ�������?keyName?��?keyTime ������?[keyName[i], keyTime[i]]?��Ӧһ���˵����ֺ�����?ĳһ�� ��ʹ��Ա������ʱ�䡣

ʹ��ʱ��ĸ�ʽ�� 24Сʱ��?������?"HH:MM"?���ȷ�˵?"23:51" ��?"09:49"?��

���㷵��ȥ�غ���յ�ϵͳ�����Ա�����֣������ǰ� �ֵ�������?����󷵻ء�

��ע��?"10:00" - "11:00"?��Ϊһ��Сʱʱ�䷶Χ�ڣ���?"23:51" - "00:10"?������ΪһСʱ�ڣ���Ϊϵͳ��¼����ĳһ���ڵ�ʹ�������

?

ʾ�� 1��

���룺keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
�����["daniel"]
���ͣ�"daniel" ��һСʱ��ʹ���� 3 ��Ա������"10:00"��"10:40"��"11:00"����
ʾ�� 2��

���룺keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
�����["bob"]
���ͣ�"bob" ��һСʱ��ʹ���� 3 ��Ա������"21:00"��"21:20"��"21:30"����
ʾ�� 3��

���룺keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
�����[]
ʾ�� 4��

���룺keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"], keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
�����["clare","leslie"]
?

��ʾ��

1 <= keyName.length, keyTime.length <= 105
keyName.length == keyTime.length
keyTime ��ʽΪ?"HH:MM"?��
��֤?[keyName[i], keyTime[i]]?�γɵĶ�Ԫ��?������ͬ?��
1 <= keyName[i].length <= 10
keyName[i]?ֻ����СдӢ����ĸ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

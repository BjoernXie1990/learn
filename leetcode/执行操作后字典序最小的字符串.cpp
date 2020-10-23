class Solution {
public:
    inline void update(char& ch,int a) {
        ch = '0' + (ch - '0' + a) % 10;
    }
    /*
    // ö�� BFS
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> us;
        queue<string> que;
        string ans = s;
        que.push(s);
        int n = s.size();

        while(!que.empty()) {
            string f = que.front();
            que.pop();

            if(f < ans) ans = f;
            for(int i = 1; i < n; i+=2) update(f[i],a);

            if(!us.count(f)) {
                que.push(f);
                us.insert(f);
            }

            // ��ת
            f = f.substr(n-b) + f.substr(0,n-b);
            if(!us.count(f)) {
                que.push(f);
                us.insert(f);
            }
        }

        return ans;
    }
    */

    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;

        if(b % 2 == 0) { // ��תΪż������
            for(int i = 0; i < 10; i++) {
                for(int j = 1; j < n; j += 2) update(s[j],a);

                string t = s;
                for(int k = 0; k < n; k ++) {
                    t = t.substr(n-b) + t.substr(0,n-b);
                    if(t < ans) ans = t;
                }
            }
        } else {    // ��ת����Ϊ����
            for(int i = 0; i < 10; i++) {
                for(int j = 1; j < n; j += 2) update(s[j],a);       // ��תż����

                for(int j = 0; j < 10; j++) {
                    for(int k = 0; k < n; k += 2) update(s[k],a);   // ��ת������

                    string t = s;
                    for(int k = 0; k < n; k ++) {
                        t = t.substr(n-b) + t.substr(0,n-b);
                        if(t < ans) ans = t;
                    }
                }
            }
        }

        return ans;
    }
};

����һ���ַ��� s �Լ��������� a �� b �����У��ַ��� s �ĳ���Ϊż�����ҽ������� 0 �� 9 ��ɡ�

������� s �ϰ�����˳����ִ��������������֮һ��

�ۼӣ���? a �ӵ� s �������±�Ϊ������Ԫ���ϣ��±�� 0 ��ʼ��������һ������ 9 �ͻ��� 0�����ѭ�����������磬s = "3456" �� a = 5����ִ�д˲����� s ��� "3951"��
��ת���� s ������ת b λ�����磬s = "3456" �� b = 1����ִ�д˲����� s ��� "6345"��
���㷵���� s ��ִ��������������κ���Եõ��� �ֵ�����С ���ַ�����

��������ַ���������ͬ����ô�ַ��� a �ֵ�����ַ��� b С�����������壺�� a �� b ���ֲ�ͬ�ĵ�һ��λ���ϣ��ַ��� a �е��ַ���������ĸ���е�ʱ������ b �еĶ�Ӧ�ַ������磬"0158�� �ֵ���� "0190" С����Ϊ��ͬ�ĵ�һ��λ�����ڵ������ַ�����Ȼ '5' ������ '9' ֮ǰ��

?

ʾ�� 1��

���룺s = "5525", a = 9, b = 2
�����"2050"
���ͣ�ִ�в������£�
��̬��"5525"
��ת��"2555"
�ۼӣ�"2454"
�ۼӣ�"2353"
��ת��"5323"
�ۼӣ�"5222"
�ۼӣ�"5121"
��ת��"2151"
�ۼӣ�"2050"????????????
�޷�����ֵ���С�� "2050" ���ַ�����
ʾ�� 2��

���룺s = "74", a = 5, b = 1
�����"24"
���ͣ�ִ�в������£�
��̬��"74"
��ת��"47"
�ۼӣ�"42"
��ת��"24"????????????
�޷�����ֵ���С�� "24" ���ַ�����
ʾ�� 3��

���룺s = "0011", a = 4, b = 2
�����"0011"
���ͣ��޷�����ֵ���С�� "0011" ���ַ�����
ʾ�� 4��

���룺s = "43987654", a = 7, b = 3
�����"00553311"
?

��ʾ��

2 <= s.length <= 100
s.length ��ż��
s �������� 0 �� 9 ���
1 <= a <= 9
1 <= b <= s.length - 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/lexicographically-smallest-string-after-applying-operations
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

class Solution {
public:
    bool areSentencesSimilar(string s, string t) {
        int n = s.size(), m = t.size();
        if(n > m) {
            return areSentencesSimilar(t,s);
        }
        
        vector<string> v1,v2;
        
        slove(v1,s);
        slove(v2,t);
        
        if(left(v1,v2))
            return true;
        return false;
    }
    
    bool left(vector<string> v1,vector<string> v2) {
        int n = v1.size(), m = v2.size();
        
        int i = 0, j = 0;
        while(i < n && j < m && v1[i] == v2[j]) {
            i ++;
            j ++;
        }
        
        int l = n - 1, r = m - 1;
        while(l >= i && r >= j && v1[l] == v2[r]) {
            l --;
            r --;
        }
        
        if(l >= i) return false;
        return true;
    }
    
    void slove(vector<string>& v,string t) {
        t += " ";
        string s("");
        
        for(auto& e : t) {
            if(e == ' ') {
                v.push_back(s);
                s = "";
                continue;
            }
            
            s += e;
        }
    }
};


һ����������һЩ����������֮��ĵ����ո���ɣ��Ҿ��ӵĿ�ͷ�ͽ�βû�ж���ո񡣱ȷ�˵��"Hello World"?��"HELLO"?��"hello world hello world"?���Ǿ��ӡ�ÿ�����ʶ� ֻ?������д��СдӢ����ĸ��

�����������?sentence1 ��?sentence2?������ͨ��������һ�����Ӳ���һ������ľ��ӣ������ǿվ��ӣ����õ���һ�����ӣ���ô���ǳ������������� ���Ƶ�?���ȷ�˵��sentence1 = "Hello my name is Jane" ��?sentence2 = "Hello Jane"?�����ǿ����� sentence2?��?"Hello" ��?"Jane"?֮�����?"my name is"?�õ� sentence1?��

������������?sentence1 ��?sentence2?�����?sentence1 ��?sentence2 �����Ƶģ����㷵��?true?�����򷵻�?false?��

?

ʾ�� 1��

���룺sentence1 = "My name is Haley", sentence2 = "My Haley"
�����true
���ͣ������� sentence2 �� "My" �� "Haley" ֮����� "name is" ���õ� sentence1 ��
ʾ�� 2��

���룺sentence1 = "of", sentence2 = "A lot of words"
�����false
���ͣ�û���������������е�һ������ֻ����һ�����Ӿ͵õ���һ�����ӡ�
ʾ�� 3��

���룺sentence1 = "Eating right now", sentence2 = "Eating"
�����true
���ͣ������� sentence2 �Ľ�β���� "right now" �õ� sentence1 ��
ʾ�� 4��

���룺sentence1 = "Luky", sentence2 = "Lucccky"
�����false
?

��ʾ��

1 <= sentence1.length, sentence2.length <= 100
sentence1?��?sentence2?��ֻ������СдӢ����ĸ�Ϳո�
sentence1?��?sentence2?�еĵ��ʶ�ֻ�ɵ����ո������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sentence-similarity-iii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

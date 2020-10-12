class Solution {
public:
    int n = 0;
    bool checkPalindromeFormation(string a, string b) {
        n = a.size();
        if(isHui(a,0,n-1) || isHui(b,0,n-1)) return true;
        
        return check(a,b) || check(b,a);
    }
    
    bool check(string& a,string& b) {
        int le = 0;
        int ri = n-1;
        
        while(le < ri && a[le] == b[ri]) {
            le++;
            ri--;
        }
        
        if(le < ri) {
            // a[le] != b[ri]
            return (isHui(a,le,ri) || isHui(b,le,ri));
        }
        
        return true;
    }
    
    bool isHui(string& a,int le,int ri) {
        while(le < ri && le >= 0 && ri < n) {
            if(a[le] != a[ri]) return false;
            le++;
            ri--;
        }
        
        return true;
    }
};

���������ַ���?a ��?b?�����ǳ�����ͬ������ѡ��һ���±꣬�������ַ�������?��ͬ���±� �ָ����?a?���Եõ������ַ�����?aprefix?��?asuffix?������?a = aprefix + asuffix?��ͬ����?b ���Եõ������ַ���?bprefix ��?bsuffix?������?b = bprefix + bsuffix?�������ж�?aprefix + bsuffix ����?bprefix + asuffix?�ܷ񹹳ɻ��Ĵ���

���㽫һ���ַ���?s?�ָ��?sprefix ��?ssuffix?ʱ��?ssuffix ����?sprefix ����Ϊ�ա��ȷ�˵��?s = "abc"?��ô?"" + "abc"?��?"a" + "bc"?��?"ab" + "c"?��?"abc" + ""?���ǺϷ��ָ

��� �ܹ��ɻ����ַ��� ����ô�뷵��?true�����򷵻�?false?��

��ע�⣬?x + y?��ʾ�����ַ���?x ��?y?��

?

ʾ�� 1��

���룺a = "x", b = "y"
�����true
���ͣ���� a ���� b �ǻ��Ĵ�����ô��һ��Ϊ true ����Ϊ��������·ָ
aprefix = "", asuffix = "x"
bprefix = "", bsuffix = "y"
��ô aprefix + bsuffix = "" + "y" = "y" �ǻ��Ĵ���
ʾ�� 2��

���룺a = "ulacfd", b = "jizalu"
�����true
���ͣ����±�Ϊ 3 ���ָ
aprefix = "ula", asuffix = "cfd"
bprefix = "jiz", bsuffix = "alu"
��ô aprefix + bsuffix = "ula" + "alu" = "ulaalu" �ǻ��Ĵ���
?

��ʾ��

1 <= a.length, b.length <= 105
a.length == b.length
a ��?b?��ֻ����СдӢ����ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/split-two-strings-to-make-palindrome
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

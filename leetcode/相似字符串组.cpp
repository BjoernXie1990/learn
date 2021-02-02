class unionFind{
    public:
        unionFind(int n) :f(n) {
            for(int i = 1; i < n; i++) f[i] = i;
            cnt = n;
        }

        int find(int x) {
            if(f[x] != x) f[x] = find(f[x]);
            return f[x];
        }

        bool merge(int x,int y) {
            x = find(x), y = find(y);
            if(x == y) return false;
            cnt --;
            f[x] = y;
            return true;
        }

        int get() {
            return cnt;
        }
    private:
        vector<int> f;
        int cnt;
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unionFind uf(n);
        for(int i = 0; i < n; i++) 
            for(int j = i + 1; j < n; j++)
                if(check(strs[i],strs[j])) uf.merge(i,j);
        return uf.get();
    }

    bool check(string& a,string& b) {
        int n = a.size(), m = b.size();
        if(n != m) return false;

        int res = 0;
        for(int i = 0; i < n; i++) if(a[i] != b[i]) res ++;
        return res == 2 || res == 0;
    }
};


��������ַ���?X �е�������ͬλ�õ���ĸ��ʹ�������ַ���?Y ��ȣ���ô�� X �� Y �����ַ������ơ�����������ַ�����������ȵģ�������Ҳ�����Ƶġ�

���磬"tars" �� "rats" �����Ƶ� (���� 0 �� 2 ��λ��)��?"rats" �� "arts" Ҳ�����Ƶģ����� "star" ���� "tars"��"rats"���� "arts" ���ơ�

��֮������ͨ���������γ������������飺{"tars", "rats", "arts"} �� {"star"}��ע�⣬"tars" �� "arts" ����ͬһ���У���ʹ���ǲ������ơ���ʽ�ϣ���ÿ������ԣ�Ҫȷ��һ�����������У�ֻ��Ҫ����ʺ͸���������һ���������ơ�

����һ���ַ����б� strs���б��е�ÿ���ַ������� strs �����������ַ�����һ����ĸ��λ�ʡ����� strs ���ж��ٸ������ַ����飿

?

ʾ�� 1��

���룺strs = ["tars","rats","arts","star"]
�����2
ʾ�� 2��

���룺strs = ["omv","ovm"]
�����1
?

��ʾ��

1 <= strs.length <= 100
1 <= strs[i].length <= 1000
sum(strs[i].length) <= 2 * 104
strs[i] ֻ����Сд��ĸ��
strs �е����е��ʶ�������ͬ�ĳ��ȣ����Ǳ˴˵���ĸ��λ�ʡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/similar-string-groups
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

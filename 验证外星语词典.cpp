ĳ��������Ҳʹ��Ӣ��Сд��ĸ��������˳�� order ��ͬ����ĸ���˳��order����һЩСд��ĸ�����С�

����һ������������д�ĵ��� words���Լ�����ĸ���˳�� order��ֻ�е������ĵ����������������а��ֵ�������ʱ������ true�����򣬷��� false��

?

ʾ�� 1��

���룺words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
�����true
���ͣ��ڸ����Ե���ĸ���У�'h' λ�� 'l' ֮ǰ�����Ե��������ǰ��ֵ������еġ�
ʾ�� 2��

���룺words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
�����false
���ͣ��ڸ����Ե���ĸ���У�'d' λ�� 'l' ֮����ô words[0] > words[1]����˵������в��ǰ��ֵ������еġ�
ʾ�� 3��

���룺words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
�����false
���ͣ���ǰ�����ַ� "app" ƥ��ʱ���ڶ����ַ�����Զ�һЩ��Ȼ����ݴʵ������� "apple" > "app"����Ϊ 'l' > '?'������ '?' �ǿհ��ַ�������Ϊ���κ������ַ���С��������Ϣ����
?

��ʾ��

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
��?words[i]?��?order?�е������ַ�����Ӣ��Сд��ĸ��

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dic;
        for (int i = 0; i < order.size(); i++)
            dic[order[i]] = i; 

        auto f = [&dic](const string& a, const string& b) {
            for (int i = 0; i < a.size(); i++) {
                if (i == b.size()) return false;
                if (dic[a[i]] > dic[b[i]]) return false;
                if (dic[a[i]] < dic[b[i]]) return true;
            }
            return a.size() != b.size();
        };

        for (int i = 1; i < words.size(); i++) 
            if (f(words[i], words[i - 1])) return false;

        return true;
    }
};

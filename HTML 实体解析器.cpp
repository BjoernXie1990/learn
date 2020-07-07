��HTML?ʵ��������� ��һ������Ľ����������� HTML ������Ϊ���룬�����ַ������滻��������Щ������ַ�ʵ�塣

HTML ����Щ�����ַ������Ƕ�Ӧ���ַ�ʵ�������

˫���ţ��ַ�ʵ��Ϊ?&quot;?����Ӧ���ַ���?"?��
�����ţ��ַ�ʵ��Ϊ?&apos;?����Ӧ���ַ���?'?��
����ţ��ַ�ʵ��Ϊ?&amp;?����Ӧ�Ե��ַ���?&?��
���ںţ��ַ�ʵ��Ϊ?&gt;?����Ӧ���ַ���?>?��
С�ںţ��ַ�ʵ��Ϊ?&lt;?����Ӧ���ַ���?<?��
б�ߺţ��ַ�ʵ��Ϊ?&frasl;?����Ӧ���ַ���?/?��
���������ַ���?text?������ʵ��һ�� HTML?ʵ������������ؽ�����������Ľ����

?

ʾ�� 1��

���룺text = "&amp; is an HTML entity but &ambassador; is not."
�����"& is an HTML entity but &ambassador; is not."
���ͣ����������ַ�ʵ�� &amp; �� & �滻
ʾ��?2��

���룺text = "and I quote: &quot;...&quot;"
�����"and I quote: \"...\""
ʾ�� 3��

���룺text = "Stay home! Practice on Leetcode :)"
�����"Stay home! Practice on Leetcode :)"
ʾ�� 4��

���룺text = "x &gt; y &amp;&amp; x &lt; y is always false"
�����"x > y && x < y is always false"
ʾ�� 5��

���룺text = "leetcode.com&frasl;problemset&frasl;all"
�����"leetcode.com/problemset/all"
?

��ʾ��

1 <= text.length <= 10^5
�ַ������ܰ��� 256 ��ASCII �ַ��е������ַ���

class Solution {
public:
    string entityParser(string text) {
        unordered_map<string,string> map;
        map["&quot;"] = "\""; 
        map["&apos;"] = "'"; 
        map["&amp;"] = "&"; 
        map["&gt;"] = ">"; 
        map["&lt;"] = "<"; 
        map["&frasl;"] = "/";

        bool flag = false;
        string str = "";
        string ans = "";
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] == '&')
            {
                if(flag == false)
                    str += text[i];
                else
                {
                    ans += str;
                    str = "&";
                }
                flag = true;
                continue;
            }
            
            if(text[i] == ';' && flag == true)
            {
                str += ";";
                if(map.find(str) != map.end())
                    ans += map[str];
                else
                    ans += str;
                flag = false;
                str = "";
                continue;
            }

            if(flag == true)
                str += text[i];
            else
                ans += text[i];

        }

        return (str != "") ? ans + str : ans;
    }
};

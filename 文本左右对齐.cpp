����һ�����������һ������?maxWidth�������Ű浥�ʣ�ʹ���Ϊÿ��ǡ����?maxWidth?���ַ������������˶�����ı���

��Ӧ��ʹ�á�̰���㷨�������ø����ĵ��ʣ�Ҳ����˵�������ܶ����ÿ���з��õ��ʡ���Ҫʱ���ÿո�?' '?��䣬ʹ��ÿ��ǡ���� maxWidth?���ַ���

Ҫ�󾡿��ܾ��ȷ��䵥�ʼ�Ŀո����������ĳһ�е��ʼ�Ŀո��ܾ��ȷ��䣬�������õĿո���Ҫ�����Ҳ�Ŀո�����

�ı������һ��ӦΪ����룬�ҵ���֮�䲻�������Ŀո�

˵��:

������ָ�ɷǿո��ַ���ɵ��ַ����С�
ÿ�����ʵĳ��ȴ��� 0��С�ڵ���?maxWidth��
���뵥������ words?���ٰ���һ�����ʡ�
ʾ��:

����:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
���:
[
? ?"This ? ?is ? ?an",
? ?"example ?of text",
? ?"justification. ?"
]
ʾ��?2:

����:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
���:
[
? "What ? must ? be",
? "acknowledgment ?",
? "shall be ? ? ? ?"
]
����: ע�����һ�еĸ�ʽӦΪ "shall be    " ������ "shall     be",
?    ��Ϊ���һ��ӦΪ����룬�������������˶��롣       
     �ڶ���ͬ��Ϊ����룬������Ϊ����ֻ����һ�����ʡ�
ʾ��?3:

����:
words = ["Science","is","what","we","understand","well","enough","to","explain",
?        "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
���:
[
? "Science ?is ?what we",
  "understand ? ? ?well",
? "enough to explain to",
? "a ?computer. ?Art is",
? "everything ?else ?we",
? "do ? ? ? ? ? ? ? ? ?"
]


class Solution {
public:
    int curLen = 0;
    int wordLen = 0;
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int pre = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if(curLen + words[i].size() <= maxWidth)
            {
                curLen += words[i].size() + 1;//1 ����һ�������м����ٵ�һ���ո�
                wordLen += words[i].size();
                if(i == words.size() - 1)
                {
                    string str("");
                    for(int j = pre; j <= i; j++)
                    {
                        str += words[j];
                        if(str.size() < maxWidth)
                            str += " ";
                    }
                    Space(str,maxWidth - str.size());
                    ans.push_back(str);
                    break;
                }

                continue;
            }

            Add(ans,words,i,pre,maxWidth);

            //��ǰ����������һ��
            pre = i;
            curLen = 0;
            wordLen = 0;
            i--;
        }

        return ans;
    }

    void Add(vector<string>& ans,vector<string>& words, int i,int pre,int maxWidth)
    {
        //�����˵���Ѿ��չ���һ�е���,��Ӵ� pre �� i�м�ĵ��ʣ������� i 
        string str = "";
        //��ֹֻ��һ�����ʵ����
        if(i - pre == 1)
        {
            str = words[pre];
            Space(str,maxWidth - str.size());
            ans.push_back(str);
            return;
        }
            
        //i - pre ������  i - pre - 1 �����
        int avl = (maxWidth - wordLen) / (i - pre - 1);
        //��¼ƽ����֮��ʣ��Ŀո����� sum һ��С�� �����
        int sum = maxWidth - wordLen - (i - pre - 1) * avl;

        for(int j = pre; j < i; j++)
        {
            str += words[j];
            //ʣ��Ŀո��������ڴ�������ÿ�����ʵĺ����ټ�һ��
            int sp = avl + (sum > 0 ? 1 : 0);
            sum--;
            //���һ�����ʺ��治����ӿո�
            if(j != i -1)
                Space(str,sp);
        }
        
        ans.push_back(str);
    }

    void Space(string& str,int num)
    {
        for(int i = 0; i < num; i++)
            str += " ";
    }
};

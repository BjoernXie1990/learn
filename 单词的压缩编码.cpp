//����һ�������б����ǽ�����б�����һ�������ַ���?S?��һ�������б� A��

//���磬�������б��� ["time", "me", "bell"]�����ǾͿ��Խ����ʾΪ S = "time#bell#" �� indexes = [0, 2, 5]��

//����ÿһ�����������ǿ���ͨ�����ַ��� S?��������λ�ÿ�ʼ��ȡ�ַ�����ֱ�� "#" ���������ָ�����֮ǰ�ĵ����б�

//��ô�ɹ��Ը��������б���б������С�ַ��������Ƕ����أ�

//?

//ʾ����

//����: words = ["time", "me", "bell"]
//���: 10
//˵��: S = "time#bell#" �� indexes = [0, 2, 5] ��




class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int num = words.size();//������ʵ�����

        //��תÿһ������
        vector<string> reversed_words;
        for(string word : words)
        {
            reverse(word.begin(),word.end());//��ת����
            reversed_words.push_back(word);     //��ӵ��µ�������
        }

        //�����ֵ����������
        sort(reversed_words.begin(),reversed_words.end());

        int ret = 0;
        for(int i = 0; i < num; i++)
        {
            //���������һ�����ʣ�������һ��������������ʵ�ǰ׺��ֱ����ȥ
            if(i + 1 < num && reversed_words[i+1].find(reversed_words[i]) == 0)
                continue;
            
            //����ǰ׺��˵����ǰ�����Ѿ���С�����㳤����
            ret += reversed_words[i].length() + 1;
        }

        return ret;
    }
};

//��һ�������ַ������ݸ������������Դ������¡������ҽ���?Z �������С�

//���������ַ���Ϊ "LEETCODEISHIRING"?����Ϊ 3 ʱ���������£�

//L   C   I   R
//E T O E S I I G
//E   D   H   N
//֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��

//����ʵ��������ַ�������ָ�������任�ĺ�����

//string convert(string s, int numRows);
//ʾ��?1:

//����: s = "LEETCODEISHIRING", numRows = 3
//���: "LCIRETOESIIGEDHN"
//ʾ��?2:

//����: s = "LEETCODEISHIRING", numRows =?4
//���:?"LDREOEIIECIHNTSG"
//����:

//L     D     R
//E   O E   I I
//E C   I H   N
//T     S     G



class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        int len = s.size();
        vector<string> ans(numRows);
        // i % (2 * (n-1))
        int mov =  2 * (numRows - 1);
        for(int i = 0; i < len; i++)
        {
            int p = i % mov;
            if(p >= numRows)    p = mov - p;

            ans[p].push_back(s[i]);
        }
            
        
        //�ϲ�
        string ret;
        for(auto& row : ans)
            ret += row;
        return ret;
    }
};

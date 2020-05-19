//����һ���ǿ��ַ���?s�����ɾ��һ���ַ����ж��Ƿ��ܳ�Ϊ�����ַ�����

//ʾ�� 1:

//����: "aba"
//���: True
//ʾ�� 2:

//����: "abca"
//���: True
//����: �����ɾ��c�ַ���
//ע��:

//�ַ���ֻ������ a-z ��Сд��ĸ���ַ�������󳤶���50000��

class Solution {
public:
    bool validPalindrome(string s) {
        int right = s.size()-1;
        int left = 0;

        while(left < right)
        {
            if(s[right] != s[left])
                return Fun(s,left+1,right) || Fun(s,left,right-1);
            left++;
            right--;
        }
        return true;
    }

    bool Fun(string& s,int l,int r)
    {
        while(l < r)
        {
            //cout<<s[l]<<' '<<s[r]<<endl;
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

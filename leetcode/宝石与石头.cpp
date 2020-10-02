class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int hash[255];
        memset(hash,0x00,sizeof(hash));
        for(auto ch : J) hash[ch]++;

        int ans = 0;
        for(auto ch : S) if(hash[ch] != 0) ans++;

        return ans;
    }
};


�����ַ���J?����ʯͷ�б�ʯ�����ͣ����ַ���?S������ӵ�е�ʯͷ��?S?��ÿ���ַ�������һ����ӵ�е�ʯͷ�����ͣ�����֪����ӵ�е�ʯͷ���ж����Ǳ�ʯ��

J?�е���ĸ���ظ���J?��?S�е������ַ�������ĸ����ĸ���ִ�Сд�����"a"��"A"�ǲ�ͬ���͵�ʯͷ��

ʾ�� 1:

����: J = "aA", S = "aAAbbbb"
���: 3
ʾ�� 2:

����: J = "z", S = "ZZ"
���: 0
ע��:

S?��?J?��ຬ��50����ĸ��
?J?�е��ַ����ظ���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/jewels-and-stones
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

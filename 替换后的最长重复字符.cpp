//����һ�����ɴ�дӢ����ĸ��ɵ��ַ���������Խ�����λ���ϵ��ַ��滻��������ַ����ܹ�������滻?k?�Ρ���ִ�������������ҵ������ظ���ĸ����Ӵ��ĳ��ȡ�

//ע��:
//�ַ������� �� k ���ᳬ��?104��

//ʾ�� 1:

//����:
//s = "ABAB", k = 2

//���:
//4

//����:
//������'A'�滻Ϊ����'B',��֮��Ȼ��
//ʾ�� 2:

//����:
//s = "AABABBA", k = 1

//���:
//4

//����:
//���м��һ��'A'�滻Ϊ'B',�ַ�����Ϊ "AABBBBA"��
//�Ӵ� "BBBB" ����ظ���ĸ, ��Ϊ 4��


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26,0);
        int left = 0;//���ڵ���߽�
        int ans = 0;//����ڵĳ���
        int maxCh = 0;//��ǰ���ڳ��ִ��������ַ���

        for(int i = 0; i < s.size(); i++) {
            arr[s[i] - 'A']++;
            maxCh = max(maxCh, arr[s[i] - 'A']);
            //�����ǰ��������Ҫ�Ķ����ַ�����i - left + 1 - maxCh  ������ k
            //��С���ڵķ�Χ �� left++
            if(i - left + 1 - maxCh > k)  arr[s[left++] - 'A']--;
            ans = max(ans,i - left + 1);
        }
        return ans;
    }
};

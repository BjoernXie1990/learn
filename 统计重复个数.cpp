�� n �����ӵ��ַ��� s ����ַ��� S������?S = [s,n]�����磬["abc",3]=��abcabcabc����

������ǿ��Դ� s2?��ɾ��ĳЩ�ַ�ʹ���Ϊ s1������ַ��� s1?���Դ��ַ��� s2 ��á����磬���ݶ��壬"abc" ���Դ� ��abdbec�� ��ã������ܴ� ��acbbe�� ��á�

���ڸ��������ǿ��ַ��� s1?�� s2��ÿ����� 100 ���ַ��������������� 0 �� n1 �� 106?�� 1 �� n2 �� 106�����ڿ����ַ��� S1 �� S2������ S1=[s1,n1]?��S2=[s2,n2] ��

�����ҳ�һ����������ʹ[S2,M] �� S1?��õ�������� M ��

?

ʾ����

���룺
s1 ="acb",n1 = 4
s2 ="ab",n2 = 2

���أ�
2



class Solution {
public:
	//��ʱ�������������� 
    int getMaxRepetitions1(string s1, int n1, string s2, int n2) {
        int counts1 = 0, counts2 = 0;
        int lens1 = s1.size(), lens2 = s2.size();
        int s1i = 0, s2i = 0;

        while(counts1 < n1){
            for(int i = 0; i < lens1; i++){
                //��������ַ���ͬ��s2i����һλ
                if(s1[i] == s2[s2i]){
                    s2i++;
                    //s2���Ѿ����������������˵���ͷ
                    if(s2i == lens2){
                        counts2++;
                        s2i = 0;
                    }
                }
                
            }
            counts1++;//s1�϶�����һ�ν�����

            if(s2i == 0){
                double nums = n1 / counts1;
                counts1 = counts1 * nums;
                counts2 = counts2 * nums;
            }
        }

        return counts2 / n2;
    }

    int getMaxRepetitions(string s1, int n1, string s2, int n2){
        int lens2 = s2.size(), lens1 = s1.size();
        vector<int> retarr(lens2,0);//��s2��ÿһ���ַ���ͷ��������s1���ظ����ٴ�
        vector<int> nextarr(lens2,0);//��s2������ַ���ͷ����s1���ظ������һ�����ֵ��ַ�������

        for(int i = 0; i < lens2; i++){
            int ret = 0;
            int next = i;

            for(int j = 0; j < lens1; j++){
                if(s1[j] == s2[next]){
                    next++;
                    if(next == lens2){
                        next = 0;
                        ret++;
                    }
                }
            }

            retarr[i] = ret;
            nextarr[i] = next;
        }
        
        int ret = 0, next = 0;
        for(int i = 0; i < n1; i++)
        {
            ret += retarr[next];
            next = nextarr[next];
        }

        return ret / n2;
    }
};

class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size(), ans = 0, cnt = 1;
        vector<int> vec(n+1,0);
        string s("");

        for(int i = 0; i < n; i++) {
            if(input[i] == '\n') {
                vec[cnt] = vec[cnt - 1] + s.size();
                if(s.find('.') != -1) { // ˵��Ϊ�ļ�
                    ans = max(ans,vec[cnt] + cnt - 1);  // cnt - 1 Ϊ / �ַ�����
                }
                cnt = 1;
                s = "";
            } else if(input[i] == '\t') {
                cnt++;
            } else {
                s += input[i];
            }
        }

        vec[cnt] = vec[cnt-1] + s.size();
        if(s.find('.') != -1) {
            ans = max(ans,vec[cnt] + cnt - 1);
        }
        return ans;
    }
};


�����ļ�ϵͳ����ͼ��ʾ��



���ｫ dir ��Ϊ��Ŀ¼�е�ΨһĿ¼��dir ����������Ŀ¼ subdir1 �� subdir2 ��subdir1 �����ļ� file1.ext ����Ŀ¼ subsubdir1��subdir2 ������Ŀ¼ subsubdir2������Ŀ¼�°����ļ� file2.ext ��

���ı���ʽ�У�������ʾ(?��ʾ�Ʊ��)��

dir
? subdir1
? ? file1.ext
? ? subsubdir1
? subdir2
? ? subsubdir2
? ? ? file2.ext
����Ǵ����ʾ��������ļ�ϵͳ����дΪ "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" ��'\n' �� '\t' �ֱ��ǻ��з����Ʊ����

�ļ�ϵͳ�е�ÿ���ļ����ļ��ж���һ��Ψһ�� ����·�� ��������򿪲��ܵ����ļ�/Ŀ¼����λ�õ�Ŀ¼˳������·���� '/' ���ӡ����������У�ָ�� file2.ext �ľ���·���� "dir/subdir2/subsubdir2/file2.ext" ��ÿ��Ŀ¼������ĸ�����ֺ�/��ո���ɣ�ÿ���ļ�����ѭ name.extension �ĸ�ʽ���������ƺ���չ������ĸ�����ֺ�/��ո���ɡ�

����һ����������ʽ��ʾ�ļ�ϵͳ���ַ��� input �������ļ�ϵͳ�� ָ���ļ��������·�� �ĳ��ȡ� ���ϵͳ��û���ļ�������?0��

?

ʾ�� 1��


���룺input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
�����20
���ͣ�ֻ��һ���ļ�������·��Ϊ "dir/subdir2/file.ext" ��·������ 20
·�� "dir/subdir1" �����κ��ļ�
ʾ�� 2��


���룺input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
�����32
���ͣ����������ļ���
"dir/subdir1/file1.ext" ��·������ 21
"dir/subdir2/subsubdir2/file2.ext" ��·������ 32
���� 32 ����Ϊ�������·��
ʾ�� 3��

���룺input = "a"
�����0
���ͣ��������κ��ļ�
ʾ�� 4��

���룺input = "file1.txt\nfile2.txt\nlongfile.txt"
�����12
���ͣ���Ŀ¼���� 3 ���ļ���
��Ϊ��Ŀ¼���κζ����ľ���·��ֻ�����Ʊ������Դ��� "longfile.txt" ��·������Ϊ 12
?

��ʾ��

1 <= input.length <= 104
input ���ܰ���Сд���д��Ӣ����ĸ��һ�����з� '\n'��һ��ָ��� '\t'��һ���� '.'��һ���ո� ' '�������֡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-absolute-file-path
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

//����һ����־���� logs��ÿ����־�����Կո�ָ����ִ���

//����ÿ����־�����һ����Ϊ��ĸ���ֱ�ʶ����Ȼ��Ҫô��

//��ʶ�������ÿ���ֽ�����Сд��ĸ��ɣ���
//��ʶ�������ÿ���ֽ�����������ɡ�
//���ǽ���������־�ֱ��Ϊ��ĸ��־��������־����֤ÿ����־�����ʶ������������һ���֡�

//����־��������ʹ��������ĸ��־������������־֮ǰ����ĸ��־��������ĸ˳�����򣬺��Ա�ʶ������������ͬʱ������ʶ������������־Ӧ�ð�ԭ����˳�����С�

//������־������˳��

//?

//ʾ�� ��

//���룺["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
//�����["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]


class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),vector_cmp);
        return logs;
    }

    static bool vector_cmp(const string& a,const string& b)
    {
        int lena = a.size(),flaga = 1,ia = 0;//1--��ĸ��־  0 --- ������־
        int lenb = b.size(),flagb = 1,ib = 0;

        //�ҵ����ַ���������
        while(a[ia++] != ' ');
        while(b[ib++] != ' ');

        //�ж���־��ʽ
        if(a[ia] < 'a')
            flaga--;
        if(b[ib] < 'a')
            flagb--;
        
        //һ����������־��һ����ĸ��־�����
        if(flaga != flagb)
            return flaga;
        
        //����������־�����ý���
        if(flaga + flagb == 0)
            return  false;
        

        //������ĸ��־���Ƚ�����
        const string s1 = a.substr(ia,lena);
        const string s2 = b.substr(ib,lenb);
        int ret = s1.compare(s2);
        if(ret != 0)
            return ret<0?true:false;

        return a.compare(b);
    }
};

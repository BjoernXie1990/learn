�����޵�ƽ���ϣ����������λ��?(0, 0)?�����泯�����������˿��Խ�����������ָ��֮һ��

"G"��ֱ�� 1 ����λ
"L"����ת 90 ��
"R"����ת 90 ��
�����˰�˳��ִ��ָ��?instructions����һֱ�ظ����ǡ�

ֻ����ƽ���д��ڻ�ʹ�û�������Զ�޷��뿪ʱ������?true�����򣬷��� false��

?

ʾ�� 1��

���룺"GGLLGG"
�����true
���ͣ�
�����˴� (0,0) �ƶ��� (0,2)��ת 180 �ȣ�Ȼ��ص� (0,0)��
�ظ���Щָ������˽���������ԭ��Ϊ���ģ�2 Ϊ�뾶�Ļ��н����ƶ���
ʾ�� 2��

���룺"GG"
�����false
���ͣ�
�������������ƶ���
ʾ�� 3��

���룺"GL"
�����true
���ͣ�
�����˰� (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ... �����ƶ���
?

��ʾ��

1 <= instructions.length <= 100
instructions[i] ��?{'G', 'L', 'R'}?��


class Solution {
public:
    bool isRobotBounded(string instructions) {
        int tmp = 0;
        int dir[4] = {0}; //0 1 2 3 ��������
        memset(dir,0x00,sizeof(dir));

        for(int i = 0; i < 4; i++)
        {
            for(auto& ch : instructions)
            {
                if(ch == 'R')   tmp = (tmp + 1) % 4;
                else if(ch == 'L')  tmp = (tmp + 3) % 4;
                else if(ch == 'G')  dir[tmp]++;
            }
        }

        return (dir[0] == dir[2] && dir[1] == dir[3]) ? true : false;
    }
};

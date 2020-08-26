�ӵ�?(x, y)?����ת����?(x, x+y)? ����?(x+y, y)��

����һ�����?(sx, sy)?��һ���յ�?(tx, ty)�����ͨ��һϵ�е�ת�����Դ���㵽���յ㣬�򷵻� True?�����򷵻�?False��

ʾ��:
����: sx = 1, sy = 1, tx = 3, ty = 5
���: True
����:
����ͨ������һϵ��ת�������ת�����յ㣺
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

����: sx = 1, sy = 1, tx = 2, ty = 2
���: False

����: sx = 1, sy = 1, tx = 1, ty = 1
���: True

ע��:

sx, sy, tx, ty?�Ƿ�Χ��?[1, 10^9]?��������

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx > 0 && ty > 0){
            if(sx == tx && sy == ty)    return true;

            if(tx > ty){
                tx -= max((tx - sx) / ty,1) * ty;
            }else {
                ty -= max((ty - sy) / tx,1) * tx;
            }
        }

        return false;
    }
};

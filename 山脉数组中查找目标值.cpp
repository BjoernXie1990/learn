//������һ�� ����ʽ����?��

//����һ�� ɽ������?mountainArr�����㷵���ܹ�ʹ��?mountainArr.get(index)?����?target?��С?���±� index?ֵ��

//����������������±� index�����뷵��?-1��

//?

//��Ϊɽ�����飿�������?A ��һ��ɽ������Ļ���������������������

//���ȣ�A.length >= 3

//��Σ���?0 < i?< A.length - 1?�����£����� i ʹ�ã�

//A[0] < A[1] < ... A[i-1] < A[i]
//A[i] > A[i+1] > ... > A[A.length - 1]
//?

//�㽫?����ֱ�ӷ��ʸ�ɽ�����飬����ͨ��?MountainArray?�ӿ�����ȡ���ݣ�

//MountainArray.get(k)?- �᷵������������Ϊk?��Ԫ�أ��±�� 0 ��ʼ��
//MountainArray.length()?- �᷵�ظ�����ĳ���
//?

//ע�⣺

//��?MountainArray.get?���𳬹� 100 �ε��õ��ύ������Ϊ����𰸡����⣬�κ���ͼ�������ϵͳ�Ľ�����������ᵼ�±����ʸ�ȡ����

//Ϊ�˰�����Ҹ��õ���⽻��ʽ���⣬����׼����һ������ ���𰸡���https://leetcode-cn.com/playground/RKhe3ave����ע���� ����һ����ȷ�𰸡�

//?

//ʾ�� 1��

//���룺array = [1,2,3,4,5,3,1], target = 3
//�����2
//���ͣ�3 �������г��������Σ��±�ֱ�Ϊ 2 �� 5�����Ƿ�����С���±� 2��
//ʾ�� 2��

//���룺array = [0,1,2,4,2,1], target = 3
//�����-1
//���ͣ�3 ��������û�г��֣����� -1��
//?

//��ʾ��

//3 <= mountain_arr.length() <= 10000
//0 <= target <= 10^9
//0 <= mountain_arr.get(index) <=?10^9


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int mountTop = MountTopFind(mountainArr,0,len-1);
        //��ɽ��Ԫ�ص����߿�ʼ����
        int ans = BinaryFindLeft(target,mountainArr,0,mountTop);
        return (ans != -1) ? ans : BinaryFindRight(target,mountainArr,mountTop+1,len-1);//���û���ҵ��������ұ���
    }

    //�ҵ�ɽ��Ԫ��
    int MountTopFind(MountainArray& mountainArr,int left,int right) {
        int top = 0;
        while(left < right) {
            int mid = (left + right) / 2;
            //mid��ɽ�Ⱥ���ĵͣ�������϶�������ɽ��,midλ�ÿ϶�����ɽ��
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) left = mid + 1;
            else right = mid;//mid����ɽ�Ⱥ����ɽ��,midλ�ÿ�����ɽ��
        }
        return left;
    }

    //��������Ķ��ֲ���
    int BinaryFindLeft(int target,MountainArray& mountainArr,int left,int right) {
        while(left <= right) {
            int mid = (left + right) >> 1;
            int num = mountainArr.get(mid);
            if(num == target) return mid;
            else if(num > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }

    //�ݼ�������ֲ���
    int BinaryFindRight(int target,MountainArray& mountainArr,int left,int right) {
        while(left <= right) {
            int mid = (right + left) >> 1;
            int num = mountainArr.get(mid);
            if(num == target) return mid;
            else if(num > target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

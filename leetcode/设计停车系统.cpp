class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        memset(nums,0x00,sizeof(nums));
        nums[1] = big;
        nums[2] = medium;
        nums[3] = small;
    }
    
    bool addCar(int carType) {
        if(nums[carType] == 0) return false;
        nums[carType]--;
        return true;
    }
private:
    int nums[4];
};


�����һ��ͣ�������һ��ͣ��ϵͳ��ͣ�����ܹ������ֲ�ͬ��С�ĳ�λ�����к�С��ÿ�ֳߴ�ֱ��й̶���Ŀ�ĳ�λ��

����ʵ��?ParkingSystem?�ࣺ

ParkingSystem(int big, int medium, int small)?��ʼ��?ParkingSystem?�࣬���������ֱ��Ӧÿ��ͣ��λ����Ŀ��
bool addCar(int carType)?�쳵�Ƿ���?carType?��Ӧ��ͣ��λ��?carType?���������ͣ����У�С���ֱ�������?1��?2?��?3?��ʾ��һ����ֻ��ͣ��??carType?��Ӧ�ߴ��ͣ��λ�С����û�пճ�λ���뷵��?false?�����򽫸ó�ͣ�복λ������?true?��
?

ʾ�� 1��

���룺
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
�����
[null, true, true, false, false]

���ͣ�
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // ���� true ����Ϊ�� 1 ���յĴ�λ
parkingSystem.addCar(2); // ���� true ����Ϊ�� 1 ���յ��г�λ
parkingSystem.addCar(3); // ���� false ����Ϊû�пյ�С��λ
parkingSystem.addCar(1); // ���� false ����Ϊû�пյĴ�λ��Ψһһ����λ�Ѿ���ռ����
?

��ʾ��

0 <= big, medium, small <= 1000
carType?ȡֵΪ?1��?2?��?3
�������?addCar?����?1000?��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-parking-system
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

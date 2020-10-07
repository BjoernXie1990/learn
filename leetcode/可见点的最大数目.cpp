class Solution {
public:
    const double eps = 1e-8;
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int n = points.size();
        int x = location[0],y = location[1];
        int asame = 0;      // ��x,y �ص��ĵ�

        vector<double> v;
        double pi = M_PI;   //  #define M_PI 3.14159265358979323846 
        for(auto& eoch : points) {
            if(eoch[0] == x && eoch[1] == y) asame++;
            else v.push_back(atan2(eoch[0] - x, eoch[1] - y) * 180 / M_PI);  // ���x,y �ĽǶ�  

            //v.push_back(atan2(eoch[1] - y,eoch[0] - x));    //atan2(y, x)��4���޷�����,[-pi,pi]
        }
        sort(v.begin(),v.end());    // �Ƕȴ�С��������

        n = v.size();
        for(int i = 0; i < n; i++) v.push_back(v[i] + 360); // ��Ȧ
        
        int ans = 0;
        int ri = 0;
        for(int le = 0; le < n; le++) {
            while(ri+1 < v.size() && v[ri+1] - v[le] <= (double)angle + eps)
                ri++;
            ans = max(ans,ri-le+1);
        }
            
        return ans + asame;
    }
};

����һ�������� points ��һ����ʾ�Ƕȵ����� angle �����λ���� location ������ location = [posx, posy] �� points[i] = [xi, yi] ����ʾ X-Y ƽ���ϵ��������ꡣ

�ʼ�������򶫷����й۲⡣�� ���� �����ƶ��ı�λ�ã�������ͨ�� ��ת �����۲�Ƕȡ����仰˵��posx �� posy ���ܸı䡣�����Ұ��Χ�ĽǶ��� angle ��ʾ�� ���������۲����ⷽ��ʱ���Զ���� d Ϊ��ʱ����ת�Ķ�������ô�����Ұ���ǽǶȷ�Χ [d - angle/2, d + angle/2] ��ָʾ����Ƭ����

����ÿ���㣬����ɸõ㡢���λ���Լ������λ��ֱ���򶫵ķ����γɵĽǶ� λ�������Ұ�� ����ô��Ϳ��Կ�������

ͬһ�������Ͽ����ж���㡣�����ڵ�λ��Ҳ���ܴ���һЩ�㣬�����������ô��ת�����ǿ��Կ�����Щ�㡣ͬʱ���㲻���谭�㿴�������㡣

�������ܿ����ĵ�������Ŀ��

?

ʾ�� 1��



���룺points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
�����3
���ͣ���Ӱ������������Ұ���������Ұ�У����еĵ㶼�����ɼ������� [2,2] �� [3,3]��ͬһ��ֱ���ϣ�����Ȼ���Կ��� [3,3] ��
ʾ�� 2��

���룺points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
�����4
���ͣ��������Ұ�У����еĵ㶼�����ɼ�������������λ�õ��Ǹ��㡣
ʾ�� 3��



���룺points = [[0,1],[2,1]], angle = 13, location = [1,1]
�����1
���ͣ���ͼ��ʾ����ֻ�ܿ�������֮һ��
?

��ʾ��

1 <= points.length <= 105
points[i].length == 2
location.length == 2
0 <= angle < 360
0 <= posx, posy, xi, yi <= 109

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-number-of-visible-points
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

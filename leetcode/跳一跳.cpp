#include <iostream>

using namespace std;

int main() {
    int res = 0, n = 0;
    
    int cnt = 0;
    while(cin >> n, n) {
        if(n == 1) {
            cnt = 1;
        }else {
            if(cnt < 2) cnt = 2;
            else cnt += 2;
            
        }
        res += cnt;
    }
    
    cout << res << endl;
    return 0;
}


近来，跳一跳这款小游戏风靡全国，受到不少玩家的喜爱。

简化后的跳一跳规则如下：玩家每次从当前方块跳到下一个方块，如果没有跳到下一个方块上则游戏结束。

如果跳到了方块上，但没有跳到方块的中心则获得 1 分；跳到方块中心时，若上一次的得分为 1 分或这是本局游戏的第一次跳跃则此次得分为 2 分，否则此次得分比上一次得分多两分（即连续跳到方块中心时，总得分将 +2，+4，+6，+8…）。

现在给出一个人跳一跳的全过程，请你求出他本局游戏的得分（按照题目描述的规则）。

输入格式
输入包含多个数字，用空格分隔，每个数字都是 1，2，0 之一，1 表示此次跳跃跳到了方块上但是没有跳到中心，2 表示此次跳跃跳到了方块上并且跳到了方块中心，0 表示此次跳跃没有跳到方块上（此时游戏结束）。

输出格式
输出一个整数，为本局游戏的得分（在本题的规则下）。

数据范围
对于所有评测用例，输入的数字不超过 30 个，保证 0 正好出现一次且为最后一个数字。

输入样例：
1 1 2 2 2 1 1 2 2 0
输出样例：
22

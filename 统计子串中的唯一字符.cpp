//
//我们定义了一个函数 countUniqueChars(s) 来统计字符串 s 中的唯一字符，并返回唯一字符的个数。

//例如：s = "LEETCODE" ，则其中 "L", "T","C","O","D" 都是唯一字符，因为它们只出现一次，所以 countUniqueChars(s) = 5 。

//本题将会给你一个字符串 s ，我们需要返回 countUniqueChars(t) 的总和，其中 t 是 s 的子字符串。注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 s 的所有子字符串中的唯一字符）。

//由于答案可能非常大，请将结果 mod 10 ^ 9 + 7 后再返回。

//?

//示例 1：

//输入: "ABC"
//输出: 10
//解释: 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
//     其中，每一个子串都由独特字符构成。
//     所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
//示例 2：

//输入: "ABA"
//输出: 8
//解释: 除了 countUniqueChars("ABA") = 1 之外，其余与示例 1 相同。
//示例 3：

//输入：s = "LEETCODE"
//输出：92

class Solution {
public:
    int uniqueLetterString(string s) {
       int len = s.size();
        int ans = 0;
        const int div = 1000000007; 
        for(int i = 0; i < len; i++)
        {
            int left = 1,right = 1;
            //向左找第一个相同的字符
            for(int j = i - 1; j >= 0; j--)
            {
                if(s[j] == s[i])
                    break;
                left++;
            }

            //向右找第一个相同的字符
            for(int j = i + 1; j < len; j++)
            {
                if(s[j] == s[i])
                    break;
                right++;
            }

            ans = (ans + left * right) % div;
        }
        return ans;
    }
};

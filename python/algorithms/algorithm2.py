class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = []
        letter_in = []
        flag = []
        for index, letter in enumerate(s):
            count.append(1)
            letter_in.append(set(letter))
            flag.append(False)
            for i in range(index):
                if letter in letter_in[i]:
                    flag[i] = True
                if not flag[i]:
                    count[i] += 1
                    letter_in[i].add(letter)
        return max(count)

a = Solution()
print(a.lengthOfLongestSubstring('dvdf'))

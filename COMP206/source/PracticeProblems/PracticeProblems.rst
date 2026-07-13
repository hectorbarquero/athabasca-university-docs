Practice problems
++++++++++++++++++++

Unit 1 practice problems
~~~~~~~~~~~~~~~~~~~~~~~~

.. rubric:: ThinkCScpp 1.1: What is a programming language?

Richest Customer Wealth (Easy)
----------------------------------------
**Find the largest row sum in a two-dimensional integer array.**

.. code-block:: cpp

   class Solution {
   public:
       int maximumWealth(vector<vector<int>>& accounts) {
           int maximum = 0;
           for (const auto& customer : accounts) {
               int total = 0;
               for (int value : customer) total += value;
               maximum = max(maximum, total);
           }
           return maximum;
       }
   };

.. rubric:: ThinkCScpp 1.2: What is a program?

Two Sum (Easy)
----------------------------------------
**Return the indexes of two values whose sum equals a target.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int, int> seen;
           for (int i = 0; i < nums.size(); ++i) {
               int needed = target - nums[i];
               if (seen.count(needed)) return {seen[needed], i};
               seen[nums[i]] = i;
           }
           return {};
       }
   };

Fibonacci Number (Easy)
----------------------------------------
**Return the nth Fibonacci value using an iterative function.**

.. code-block:: cpp

   class Solution {
   public:
       int fib(int n) {
           if (n < 2) return n;
           int first = 0;
           int second = 1;
           for (int i = 2; i <= n; ++i) {
               int next = first + second;
               first = second;
               second = next;
           }
           return second;
       }
   };

Valid Anagram (Easy)
----------------------------------------
**Determine whether two strings contain the same character counts.**

.. code-block:: cpp

   class Solution {
   public:
       bool isAnagram(string s, string t) {
           if (s.size() != t.size()) return false;
           array<int, 26> counts{};
           for (char c : s) ++counts[c - 'a'];
           for (char c : t) --counts[c - 'a'];
           return all_of(counts.begin(), counts.end(), [](int n) { return n == 0; });
       }
   };

.. rubric:: ThinkCScpp 1.3: What is debugging?

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count how many even divisions and odd subtractions reduce a number to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;
           while (num > 0) {
               num = num % 2 == 0 ? num / 2 : num - 1;
               ++steps;
           }
           return steps;
       }
   };

.. rubric:: ThinkCScpp 1.3.1: Compile-time errors

Valid Palindrome (Easy)
----------------------------------------
**Check whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               while (left < right && !isalnum(s[left])) ++left;
               while (left < right && !isalnum(s[right])) --right;
               if (tolower(s[left]) != tolower(s[right])) return false;
               ++left;
               --right;
           }
           return true;
       }
   };

Plus One (Easy)
----------------------------------------
**Increment a large integer stored as an array of decimal digits.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> plusOne(vector<int>& digits) {
           for (int i = digits.size() - 1; i >= 0; --i) {
               if (digits[i] < 9) {
                   ++digits[i];
                   return digits;
               }
               digits[i] = 0;
           }
           digits.insert(digits.begin(), 1);
           return digits;
       }
   };

Count the Digits That Divide a Number (Easy)
--------------------------------------------
**Count the digits that divide the original number without a remainder.**

.. code-block:: cpp

   class Solution {
   public:
       int countDigits(int num) {
           int count = 0;
           for (int value = num; value > 0; value /= 10) {
               int digit = value % 10;
               if (digit != 0 && num % digit == 0) {
                   ++count;
               }
           }
           return count;
       }
   };

Final Value of Variable After Performing Operations (Easy)
----------------------------------------------------------
**Apply increment and decrement strings to a single integer variable.**

.. code-block:: cpp

   class Solution {
   public:
       int finalValueAfterOperations(vector<string>& operations) {
           int value = 0;
           for (const string& operation : operations) {
               value += operation[1] == '+' ? 1 : -1;
           }
           return value;
       }
   };

.. rubric:: ThinkCScpp 1.3.2: Run-time errors

Fizz Buzz (Easy)
----------------------------------------
**Build strings based on whether each number is divisible by 3, 5, or both.**

.. code-block:: cpp

   class Solution {
   public:
       vector<string> fizzBuzz(int n) {
           vector<string> answer;
           for (int i = 1; i <= n; ++i) {
               if (i % 15 == 0) answer.push_back("FizzBuzz");
               else if (i % 3 == 0) answer.push_back("Fizz");
               else if (i % 5 == 0) answer.push_back("Buzz");
               else answer.push_back(to_string(i));
           }
           return answer;
       }
   };

Missing Number (Easy)
----------------------------------------
**Find the absent value from the integer range zero through n.**

.. code-block:: cpp

   class Solution {
   public:
       int missingNumber(vector<int>& nums) {
           int result = nums.size();
           for (int i = 0; i < nums.size(); ++i) {
               result ^= i ^ nums[i];
           }
           return result;
       }
   };

Plus One (Easy)
----------------------------------------
**Increment a large integer stored as an array of decimal digits.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> plusOne(vector<int>& digits) {
           for (int i = digits.size() - 1; i >= 0; --i) {
               if (digits[i] < 9) {
                   ++digits[i];
                   return digits;
               }
               digits[i] = 0;
           }
           digits.insert(digits.begin(), 1);
           return digits;
       }
   };

First Unique Character in a String (Easy)
-----------------------------------------
**Return the first index containing a character that occurs once.**

.. code-block:: cpp

   class Solution {
   public:
       int firstUniqChar(string s) {
           array<int, 26> counts{};
           for (char c : s) ++counts[c - 'a'];
           for (int i = 0; i < s.size(); ++i) {
               if (counts[s[i] - 'a'] == 1) return i;
           }
           return -1;
       }
   };

.. rubric:: ThinkCScpp 1.3.3: Logic errors and semantics

Ugly Number (Easy)
----------------------------------------
**Determine whether a positive integer has no prime factors other than 2, 3, and 5.**

.. code-block:: cpp

   class Solution {
   public:
       bool isUgly(int n) {
           if (n <= 0) return false;
           for (int factor : {2, 3, 5}) {
               while (n % factor == 0) n /= factor;
           }
           return n == 1;
       }
   };

.. rubric:: ThinkCScpp 1.3.4: Experimental debugging

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count how many even divisions and odd subtractions reduce a number to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;
           while (num > 0) {
               num = num % 2 == 0 ? num / 2 : num - 1;
               ++steps;
           }
           return steps;
       }
   };

Remove Duplicates from Sorted Array (Easy)
------------------------------------------
**Compress a sorted array in place so each value appears once.**

.. code-block:: cpp

   class Solution {
   public:
       int removeDuplicates(vector<int>& nums) {
           if (nums.empty()) return 0;
           int write = 1;
           for (int read = 1; read < nums.size(); ++read) {
               if (nums[read] != nums[read - 1]) nums[write++] = nums[read];
           }
           return write;
       }
   };

Count the Digits That Divide a Number (Easy)
--------------------------------------------
**Count the digits that divide the original number without a remainder.**

.. code-block:: cpp

   class Solution {
   public:
       int countDigits(int num) {
           int count = 0;
           for (int value = num; value > 0; value /= 10) {
               int digit = value % 10;
               if (digit != 0 && num % digit == 0) {
                   ++count;
               }
           }
           return count;
       }
   };

.. rubric:: ProgFund 1: Introduction to Programming

Happy Number (Easy)
----------------------------------------
**Repeatedly replace a number with the sum of its squared digits and detect whether it reaches one.**

.. code-block:: cpp

   class Solution {
       int next(int n) {
           int total = 0;
           while (n > 0) {
               int digit = n % 10;
               total += digit * digit;
               n /= 10;
           }
           return total;
       }
   public:
       bool isHappy(int n) {
           unordered_set<int> seen;
           while (n != 1 && !seen.count(n)) {
               seen.insert(n);
               n = next(n);
           }
           return n == 1;
       }
   };

.. rubric:: ProgFund 1.1: Systems Development Life Cycle

Remove Element (Easy)
----------------------------------------
**Remove matching values in place and return the remaining length.**

.. code-block:: cpp

   class Solution {
   public:
       int removeElement(vector<int>& nums, int val) {
           int write = 0;
           for (int value : nums) {
               if (value != val) nums[write++] = value;
           }
           return write;
       }
   };

Single Number (Easy)
----------------------------------------
**Find the only value that doesn’t appear twice.**

.. code-block:: cpp

   class Solution {
   public:
       int singleNumber(vector<int>& nums) {
           int result = 0;
           for (int value : nums) result ^= value;
           return result;
       }
   };

.. rubric:: ProgFund 1.3: Modularization and C++ Program Layout

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

Climbing Stairs (Easy)
----------------------------------------
**Count the distinct ways to reach a step using moves of one or two.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           if (n <= 2) return n;
           int previous = 1;
           int current = 2;
           for (int step = 3; step <= n; ++step) {
               int next = previous + current;
               previous = current;
               current = next;
           }
           return current;
       }
   };

Find the Index of the First Occurrence in a String (Easy)
---------------------------------------------------------
**Return the first position where one string appears inside another.**

.. code-block:: cpp

   class Solution {
   public:
       int strStr(string haystack, string needle) {
           size_t position = haystack.find(needle);
           return position == string::npos ? -1 : static_cast<int>(position);
       }
   };

Happy Number (Easy)
----------------------------------------
**Repeatedly replace a number with the sum of its squared digits and detect whether it reaches one.**

.. code-block:: cpp

   class Solution {
       int next(int n) {
           int total = 0;
           while (n > 0) {
               int digit = n % 10;
               total += digit * digit;
               n /= 10;
           }
           return total;
       }
   public:
       bool isHappy(int n) {
           unordered_set<int> seen;
           while (n != 1 && !seen.count(n)) {
               seen.insert(n);
               n = next(n);
           }
           return n == 1;
       }
   };

.. rubric:: ProgFund 2: Program Planning & Design

Add Digits (Easy)
----------------------------------------
**Reduce an integer to one digit by repeatedly summing its digits.**

.. code-block:: cpp

   class Solution {
   public:
       int addDigits(int num) {
           return num == 0 ? 0 : 1 + (num - 1) % 9;
       }
   };

Merge Sorted Array (Easy)
----------------------------------------
**Merge two sorted integer arrays into the first array in place.**

.. code-block:: cpp

   class Solution {
   public:
       void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
           int write = m + n - 1;
           --m;
           --n;
           while (n >= 0) {
               if (m >= 0 && nums1[m] > nums2[n]) nums1[write--] = nums1[m--];
               else nums1[write--] = nums2[n--];
           }
       }
   };

Ransom Note (Easy)
----------------------------------------
**Determine whether one string can be assembled from the characters of another.**

.. code-block:: cpp

   class Solution {
   public:
       bool canConstruct(string ransomNote, string magazine) {
           array<int, 26> counts{};
           for (char c : magazine) ++counts[c - 'a'];
           for (char c : ransomNote) {
               if (--counts[c - 'a'] < 0) return false;
           }
           return true;
       }
   };

Convert the Temperature (Easy)
----------------------------------------
**Convert a Celsius value to Kelvin and Fahrenheit.**

.. code-block:: cpp

   class Solution {
   public:
       vector<double> convertTemperature(double celsius) {
           return {celsius + 273.15, celsius * 1.80 + 32.00};
       }
   };

Add Two Integers (Easy)
----------------------------------------
**Return the sum of two integer parameters.**

.. code-block:: cpp

   class Solution {
   public:
       int sum(int num1, int num2) {
           return num1 + num2;
       }
   };

.. rubric:: ProgFund 2.1: Program Design

Remove Element (Easy)
----------------------------------------
**Remove matching values in place and return the remaining length.**

.. code-block:: cpp

   class Solution {
   public:
       int removeElement(vector<int>& nums, int val) {
           int write = 0;
           for (int value : nums) {
               if (value != val) nums[write++] = value;
           }
           return write;
       }
   };

Build Array from Permutation (Easy)
----------------------------------------
**Construct an array whose values are selected through the input array’s indexes.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> buildArray(vector<int>& nums) {
           vector<int> answer(nums.size());
           for (int i = 0; i < nums.size(); ++i) {
               answer[i] = nums[nums[i]];
           }
           return answer;
       }
   };

Roman to Integer (Easy)
----------------------------------------
**Convert a Roman numeral string into an integer.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           unordered_map<char, int> value{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
           int total = 0;
           for (int i = 0; i < s.size(); ++i) {
               if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]]) total -= value[s[i]];
               else total += value[s[i]];
           }
           return total;
       }
   };

.. rubric:: ProgFund 2.2: Pseudocode

Two Sum (Easy)
----------------------------------------
**Return the indexes of two values whose sum equals a target.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int, int> seen;
           for (int i = 0; i < nums.size(); ++i) {
               int needed = target - nums[i];
               if (seen.count(needed)) return {seen[needed], i};
               seen[nums[i]] = i;
           }
           return {};
       }
   };

Climbing Stairs (Easy)
----------------------------------------
**Count the distinct ways to reach a step using moves of one or two.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           if (n <= 2) return n;
           int previous = 1;
           int current = 2;
           for (int step = 3; step <= n; ++step) {
               int next = previous + current;
               previous = current;
               current = next;
           }
           return current;
       }
   };

.. rubric:: ProgFund 2.3: Test Data

Palindrome Number (Easy)
----------------------------------------
**Determine whether an integer reads the same in both directions.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(int x) {
           if (x < 0) return false;
           long reversed = 0;
           int original = x;
           while (x > 0) {
               reversed = reversed * 10 + x % 10;
               x /= 10;
           }
           return reversed == original;
       }
   };

Count the Digits That Divide a Number (Easy)
--------------------------------------------
**Count the digits that divide the original number without a remainder.**

.. code-block:: cpp

   class Solution {
   public:
       int countDigits(int num) {
           int count = 0;
           for (int value = num; value > 0; value /= 10) {
               int digit = value % 10;
               if (digit != 0 && num % digit == 0) {
                   ++count;
               }
           }
           return count;
       }
   };

.. rubric:: ThinkCScpp 1.4: Formal and natural languages

Climbing Stairs (Easy)
----------------------------------------
**Count the distinct ways to reach a step using moves of one or two.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           if (n <= 2) return n;
           int previous = 1;
           int current = 2;
           for (int step = 3; step <= n; ++step) {
               int next = previous + current;
               previous = current;
               current = next;
           }
           return current;
       }
   };

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count how many even divisions and odd subtractions reduce a number to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;
           while (num > 0) {
               num = num % 2 == 0 ? num / 2 : num - 1;
               ++steps;
           }
           return steps;
       }
   };

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

Final Value of Variable After Performing Operations (Easy)
----------------------------------------------------------
**Apply increment and decrement strings to a single integer variable.**

.. code-block:: cpp

   class Solution {
   public:
       int finalValueAfterOperations(vector<string>& operations) {
           int value = 0;
           for (const string& operation : operations) {
               value += operation[1] == '+' ? 1 : -1;
           }
           return value;
       }
   };

.. rubric:: ThinkCScpp 1.5: The first program

N-th Tribonacci Number (Easy)
----------------------------------------
**Return a sequence value where each term is the sum of the previous three.**

.. code-block:: cpp

   class Solution {
   public:
       int tribonacci(int n) {
           if (n == 0) return 0;
           if (n < 3) return 1;
           int a = 0, b = 1, c = 1;
           for (int i = 3; i <= n; ++i) {
               int next = a + b + c;
               a = b;
               b = c;
               c = next;
           }
           return c;
       }
   };

To Lower Case (Easy)
----------------------------------------
**Convert every uppercase letter in a string to lowercase.**

.. code-block:: cpp

   class Solution {
   public:
       string toLowerCase(string s) {
           for (char& c : s) {
               if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
           }
           return s;
       }
   };

Length of Last Word (Easy)
----------------------------------------
**Return the number of characters in the final word of a string.**

.. code-block:: cpp

   class Solution {
   public:
       int lengthOfLastWord(string s) {
           int i = s.size() - 1;
           while (i >= 0 && s[i] == ' ') --i;
           int length = 0;
           while (i >= 0 && s[i] != ' ') {
               ++length;
               --i;
           }
           return length;
       }
   };

.. rubric:: ProgFund 5: Integrated Development Environment

Number of Good Pairs (Easy)
----------------------------------------
**Count index pairs containing equal integer values.**

.. code-block:: cpp

   class Solution {
   public:
       int numIdenticalPairs(vector<int>& nums) {
           unordered_map<int, int> counts;
           int pairs = 0;
           for (int value : nums) {
               pairs += counts[value]++;
           }
           return pairs;
       }
   };

Intersection of Two Arrays (Easy)
----------------------------------------
**Return the distinct values appearing in both arrays.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
           unordered_set<int> first(nums1.begin(), nums1.end());
           unordered_set<int> common;
           for (int value : nums2) {
               if (first.count(value)) common.insert(value);
           }
           return vector<int>(common.begin(), common.end());
       }
   };

Running Sum of 1d Array (Easy)
----------------------------------------
**Replace each array value with the sum of values up to that position.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> runningSum(vector<int>& nums) {
           for (int i = 1; i < nums.size(); ++i) {
               nums[i] += nums[i - 1];
           }
           return nums;
       }
   };

.. rubric:: ProgFund 5.1: Integrated Development Environment

Palindrome Number (Easy)
----------------------------------------
**Determine whether an integer reads the same in both directions.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(int x) {
           if (x < 0) return false;
           long reversed = 0;
           int original = x;
           while (x > 0) {
               reversed = reversed * 10 + x % 10;
               x /= 10;
           }
           return reversed == original;
       }
   };

.. rubric:: ProgFund 5.2: Standard Input and Output

Ugly Number (Easy)
----------------------------------------
**Determine whether a positive integer has no prime factors other than 2, 3, and 5.**

.. code-block:: cpp

   class Solution {
   public:
       bool isUgly(int n) {
           if (n <= 0) return false;
           for (int factor : {2, 3, 5}) {
               while (n % factor == 0) n /= factor;
           }
           return n == 1;
       }
   };

Shuffle the Array (Easy)
----------------------------------------
**Interleave the first and second halves of an array.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> shuffle(vector<int>& nums, int n) {
           vector<int> answer;
           answer.reserve(nums.size());
           for (int i = 0; i < n; ++i) {
               answer.push_back(nums[i]);
               answer.push_back(nums[i + n]);
           }
           return answer;
       }
   };

.. rubric:: ProgFund 5.3: Compiler Directives

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

Score of a String (Easy)
----------------------------------------
**Sum the absolute differences between adjacent character codes.**

.. code-block:: cpp

   class Solution {
   public:
       int scoreOfString(string s) {
           int score = 0;
           for (int i = 1; i < s.size(); ++i) {
               score += abs(s[i] - s[i - 1]);
           }
           return score;
       }
   };

Climbing Stairs (Easy)
----------------------------------------
**Count the distinct ways to reach a step using moves of one or two.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           if (n <= 2) return n;
           int previous = 1;
           int current = 2;
           for (int step = 3; step <= n; ++step) {
               int next = previous + current;
               previous = current;
               current = next;
           }
           return current;
       }
   };

Valid Anagram (Easy)
----------------------------------------
**Determine whether two strings contain the same character counts.**

.. code-block:: cpp

   class Solution {
   public:
       bool isAnagram(string s, string t) {
           if (s.size() != t.size()) return false;
           array<int, 26> counts{};
           for (char c : s) ++counts[c - 'a'];
           for (char c : t) --counts[c - 'a'];
           return all_of(counts.begin(), counts.end(), [](int n) { return n == 0; });
       }
   };

Sqrt(x) (Easy)
----------------------------------------
**Return the integer part of a non-negative number’s square root.**

.. code-block:: cpp

   class Solution {
   public:
       int mySqrt(int x) {
           long left = 0;
           long right = x;
           while (left <= right) {
               long middle = left + (right - left) / 2;
               long square = middle * middle;
               if (square == x) return static_cast<int>(middle);
               if (square < x) left = middle + 1;
               else right = middle - 1;
           }
           return static_cast<int>(right);
       }
   };


Unit 2 practice problems
~~~~~~~~~~~~~~~~~~~~~~~~

.. rubric:: ThinkCScpp 2.1: More output

Final Value of Variable After Performing Operations (Easy)
----------------------------------------------------------
**Apply increment and decrement strings to a single integer variable.**

.. code-block:: cpp

   class Solution {
   public:
       int finalValueAfterOperations(vector<string>& operations) {
           int value = 0;
           for (const string& operation : operations) {
               value += operation[1] == '+' ? 1 : -1;
           }
           return value;
       }
   };

.. rubric:: ThinkCScpp 2.2: Values

Power of Two (Easy)
----------------------------------------
**Determine whether an integer is an exact power of two.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPowerOfTwo(int n) {
           return n > 0 && (n & (n - 1)) == 0;
       }
   };

Sqrt(x) (Easy)
----------------------------------------
**Return the integer part of a non-negative number’s square root.**

.. code-block:: cpp

   class Solution {
   public:
       int mySqrt(int x) {
           long left = 0;
           long right = x;
           while (left <= right) {
               long middle = left + (right - left) / 2;
               long square = middle * middle;
               if (square == x) return static_cast<int>(middle);
               if (square < x) left = middle + 1;
               else right = middle - 1;
           }
           return static_cast<int>(right);
       }
   };

Convert the Temperature (Easy)
----------------------------------------
**Convert a Celsius value to Kelvin and Fahrenheit.**

.. code-block:: cpp

   class Solution {
   public:
       vector<double> convertTemperature(double celsius) {
           return {celsius + 273.15, celsius * 1.80 + 32.00};
       }
   };

Jewels and Stones (Easy)
----------------------------------------
**Count how many characters in one string belong to a specified set.**

.. code-block:: cpp

   class Solution {
   public:
       int numJewelsInStones(string jewels, string stones) {
           unordered_set<char> types(jewels.begin(), jewels.end());
           int count = 0;
           for (char stone : stones) count += types.count(stone);
           return count;
       }
   };

.. rubric:: ThinkCScpp 2.3: Variables

Contains Duplicate (Easy)
----------------------------------------
**Return whether any integer occurs more than once.**

.. code-block:: cpp

   class Solution {
   public:
       bool containsDuplicate(vector<int>& nums) {
           unordered_set<int> seen;
           for (int value : nums) {
               if (!seen.insert(value).second) return true;
           }
           return false;
       }
   };

Length of Last Word (Easy)
----------------------------------------
**Return the number of characters in the final word of a string.**

.. code-block:: cpp

   class Solution {
   public:
       int lengthOfLastWord(string s) {
           int i = s.size() - 1;
           while (i >= 0 && s[i] == ' ') --i;
           int length = 0;
           while (i >= 0 && s[i] != ' ') {
               ++length;
               --i;
           }
           return length;
       }
   };

Add Two Integers (Easy)
----------------------------------------
**Return the sum of two integer parameters.**

.. code-block:: cpp

   class Solution {
   public:
       int sum(int num1, int num2) {
           return num1 + num2;
       }
   };

.. rubric:: ProgFund 3: Data & Operators

Single Number (Easy)
----------------------------------------
**Find the only value that doesn’t appear twice.**

.. code-block:: cpp

   class Solution {
   public:
       int singleNumber(vector<int>& nums) {
           int result = 0;
           for (int value : nums) result ^= value;
           return result;
       }
   };

Number of Good Pairs (Easy)
----------------------------------------
**Count index pairs containing equal integer values.**

.. code-block:: cpp

   class Solution {
   public:
       int numIdenticalPairs(vector<int>& nums) {
           unordered_map<int, int> counts;
           int pairs = 0;
           for (int value : nums) {
               pairs += counts[value]++;
           }
           return pairs;
       }
   };

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count how many even divisions and odd subtractions reduce a number to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;
           while (num > 0) {
               num = num % 2 == 0 ? num / 2 : num - 1;
               ++steps;
           }
           return steps;
       }
   };

.. rubric:: ProgFund 3.1: Data Types in C++

Sqrt(x) (Easy)
----------------------------------------
**Return the integer part of a non-negative number’s square root.**

.. code-block:: cpp

   class Solution {
   public:
       int mySqrt(int x) {
           long left = 0;
           long right = x;
           while (left <= right) {
               long middle = left + (right - left) / 2;
               long square = middle * middle;
               if (square == x) return static_cast<int>(middle);
               if (square < x) left = middle + 1;
               else right = middle - 1;
           }
           return static_cast<int>(right);
       }
   };

.. rubric:: ProgFund 3.2: Identifier Names

Final Value of Variable After Performing Operations (Easy)
----------------------------------------------------------
**Apply increment and decrement strings to a single integer variable.**

.. code-block:: cpp

   class Solution {
   public:
       int finalValueAfterOperations(vector<string>& operations) {
           int value = 0;
           for (const string& operation : operations) {
               value += operation[1] == '+' ? 1 : -1;
           }
           return value;
       }
   };

To Lower Case (Easy)
----------------------------------------
**Convert every uppercase letter in a string to lowercase.**

.. code-block:: cpp

   class Solution {
   public:
       string toLowerCase(string s) {
           for (char& c : s) {
               if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
           }
           return s;
       }
   };

.. rubric:: ProgFund 3.3: Constants and Variables

Fibonacci Number (Easy)
----------------------------------------
**Return the nth Fibonacci value using an iterative function.**

.. code-block:: cpp

   class Solution {
   public:
       int fib(int n) {
           if (n < 2) return n;
           int first = 0;
           int second = 1;
           for (int i = 2; i <= n; ++i) {
               int next = first + second;
               first = second;
               second = next;
           }
           return second;
       }
   };

.. rubric:: ProgFund 3.4: Data Manipulation

Smallest Even Multiple (Easy)
----------------------------------------
**Return the smallest positive value divisible by both 2 and n.**

.. code-block:: cpp

   class Solution {
   public:
       int smallestEvenMultiple(int n) {
           return n % 2 == 0 ? n : n * 2;
       }
   };

Ugly Number (Easy)
----------------------------------------
**Determine whether a positive integer has no prime factors other than 2, 3, and 5.**

.. code-block:: cpp

   class Solution {
   public:
       bool isUgly(int n) {
           if (n <= 0) return false;
           for (int factor : {2, 3, 5}) {
               while (n % factor == 0) n /= factor;
           }
           return n == 1;
       }
   };

Power of Two (Easy)
----------------------------------------
**Determine whether an integer is an exact power of two.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPowerOfTwo(int n) {
           return n > 0 && (n & (n - 1)) == 0;
       }
   };

Plus One (Easy)
----------------------------------------
**Increment a large integer stored as an array of decimal digits.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> plusOne(vector<int>& digits) {
           for (int i = digits.size() - 1; i >= 0; --i) {
               if (digits[i] < 9) {
                   ++digits[i];
                   return digits;
               }
               digits[i] = 0;
           }
           digits.insert(digits.begin(), 1);
           return digits;
       }
   };

Missing Number (Easy)
----------------------------------------
**Find the absent value from the integer range zero through n.**

.. code-block:: cpp

   class Solution {
   public:
       int missingNumber(vector<int>& nums) {
           int result = nums.size();
           for (int i = 0; i < nums.size(); ++i) {
               result ^= i ^ nums[i];
           }
           return result;
       }
   };

.. rubric:: ThinkCScpp 2.4: Assignment

Running Sum of 1d Array (Easy)
----------------------------------------
**Replace each array value with the sum of values up to that position.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> runningSum(vector<int>& nums) {
           for (int i = 1; i < nums.size(); ++i) {
               nums[i] += nums[i - 1];
           }
           return nums;
       }
   };

Shuffle the Array (Easy)
----------------------------------------
**Interleave the first and second halves of an array.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> shuffle(vector<int>& nums, int n) {
           vector<int> answer;
           answer.reserve(nums.size());
           for (int i = 0; i < n; ++i) {
               answer.push_back(nums[i]);
               answer.push_back(nums[i + n]);
           }
           return answer;
       }
   };

Two Sum (Easy)
----------------------------------------
**Return the indexes of two values whose sum equals a target.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int, int> seen;
           for (int i = 0; i < nums.size(); ++i) {
               int needed = target - nums[i];
               if (seen.count(needed)) return {seen[needed], i};
               seen[nums[i]] = i;
           }
           return {};
       }
   };

.. rubric:: ThinkCScpp 2.5: Outputting variables

Number of Good Pairs (Easy)
----------------------------------------
**Count index pairs containing equal integer values.**

.. code-block:: cpp

   class Solution {
   public:
       int numIdenticalPairs(vector<int>& nums) {
           unordered_map<int, int> counts;
           int pairs = 0;
           for (int value : nums) {
               pairs += counts[value]++;
           }
           return pairs;
       }
   };

.. rubric:: ThinkCScpp 2.6: Keywords

Count the Digits That Divide a Number (Easy)
--------------------------------------------
**Count the digits that divide the original number without a remainder.**

.. code-block:: cpp

   class Solution {
   public:
       int countDigits(int num) {
           int count = 0;
           for (int value = num; value > 0; value /= 10) {
               int digit = value % 10;
               if (digit != 0 && num % digit == 0) {
                   ++count;
               }
           }
           return count;
       }
   };

Subtract the Product and Sum of Digits of an Integer (Easy)
-----------------------------------------------------------
**Compute the product of an integer’s digits minus their sum.**

.. code-block:: cpp

   class Solution {
   public:
       int subtractProductAndSum(int n) {
           int product = 1;
           int sum = 0;
           while (n > 0) {
               int digit = n % 10;
               product *= digit;
               sum += digit;
               n /= 10;
           }
           return product - sum;
       }
   };

.. rubric:: ProgFund 3.5: Assignment Operator

Contains Duplicate (Easy)
----------------------------------------
**Return whether any integer occurs more than once.**

.. code-block:: cpp

   class Solution {
   public:
       bool containsDuplicate(vector<int>& nums) {
           unordered_set<int> seen;
           for (int value : nums) {
               if (!seen.insert(value).second) return true;
           }
           return false;
       }
   };

Richest Customer Wealth (Easy)
----------------------------------------
**Find the largest row sum in a two-dimensional integer array.**

.. code-block:: cpp

   class Solution {
   public:
       int maximumWealth(vector<vector<int>>& accounts) {
           int maximum = 0;
           for (const auto& customer : accounts) {
               int total = 0;
               for (int value : customer) total += value;
               maximum = max(maximum, total);
           }
           return maximum;
       }
   };

.. rubric:: ProgFund 3.6: Arithmetic Operators

Convert the Temperature (Easy)
----------------------------------------
**Convert a Celsius value to Kelvin and Fahrenheit.**

.. code-block:: cpp

   class Solution {
   public:
       vector<double> convertTemperature(double celsius) {
           return {celsius + 273.15, celsius * 1.80 + 32.00};
       }
   };

Fibonacci Number (Easy)
----------------------------------------
**Return the nth Fibonacci value using an iterative function.**

.. code-block:: cpp

   class Solution {
   public:
       int fib(int n) {
           if (n < 2) return n;
           int first = 0;
           int second = 1;
           for (int i = 2; i <= n; ++i) {
               int next = first + second;
               first = second;
               second = next;
           }
           return second;
       }
   };

.. rubric:: ProgFund 3.7: Data Type Conversions

Roman to Integer (Easy)
----------------------------------------
**Convert a Roman numeral string into an integer.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           unordered_map<char, int> value{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
           int total = 0;
           for (int i = 0; i < s.size(); ++i) {
               if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]]) total -= value[s[i]];
               else total += value[s[i]];
           }
           return total;
       }
   };

.. rubric:: ProgFund 4: Often Used Data Types

Convert the Temperature (Easy)
----------------------------------------
**Convert a Celsius value to Kelvin and Fahrenheit.**

.. code-block:: cpp

   class Solution {
   public:
       vector<double> convertTemperature(double celsius) {
           return {celsius + 273.15, celsius * 1.80 + 32.00};
       }
   };

Richest Customer Wealth (Easy)
----------------------------------------
**Find the largest row sum in a two-dimensional integer array.**

.. code-block:: cpp

   class Solution {
   public:
       int maximumWealth(vector<vector<int>>& accounts) {
           int maximum = 0;
           for (const auto& customer : accounts) {
               int total = 0;
               for (int value : customer) total += value;
               maximum = max(maximum, total);
           }
           return maximum;
       }
   };

.. rubric:: ProgFund 4.1: Integer Data Type

Intersection of Two Arrays (Easy)
----------------------------------------
**Return the distinct values appearing in both arrays.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
           unordered_set<int> first(nums1.begin(), nums1.end());
           unordered_set<int> common;
           for (int value : nums2) {
               if (first.count(value)) common.insert(value);
           }
           return vector<int>(common.begin(), common.end());
       }
   };

Climbing Stairs (Easy)
----------------------------------------
**Count the distinct ways to reach a step using moves of one or two.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           if (n <= 2) return n;
           int previous = 1;
           int current = 2;
           for (int step = 3; step <= n; ++step) {
               int next = previous + current;
               previous = current;
               current = next;
           }
           return current;
       }
   };

.. rubric:: ProgFund 4.2: Floating-Point Data Type

Richest Customer Wealth (Easy)
----------------------------------------
**Find the largest row sum in a two-dimensional integer array.**

.. code-block:: cpp

   class Solution {
   public:
       int maximumWealth(vector<vector<int>>& accounts) {
           int maximum = 0;
           for (const auto& customer : accounts) {
               int total = 0;
               for (int value : customer) total += value;
               maximum = max(maximum, total);
           }
           return maximum;
       }
   };

Roman to Integer (Easy)
----------------------------------------
**Convert a Roman numeral string into an integer.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           unordered_map<char, int> value{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
           int total = 0;
           for (int i = 0; i < s.size(); ++i) {
               if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]]) total -= value[s[i]];
               else total += value[s[i]];
           }
           return total;
       }
   };

.. rubric:: ProgFund 4.3: String Data Type

Intersection of Two Arrays (Easy)
----------------------------------------
**Return the distinct values appearing in both arrays.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
           unordered_set<int> first(nums1.begin(), nums1.end());
           unordered_set<int> common;
           for (int value : nums2) {
               if (first.count(value)) common.insert(value);
           }
           return vector<int>(common.begin(), common.end());
       }
   };

Reverse String (Easy)
----------------------------------------
**Reverse a character array in place.**

.. code-block:: cpp

   class Solution {
   public:
       void reverseString(vector<char>& s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               swap(s[left++], s[right--]);
           }
       }
   };

Power of Two (Easy)
----------------------------------------
**Determine whether an integer is an exact power of two.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPowerOfTwo(int n) {
           return n > 0 && (n & (n - 1)) == 0;
       }
   };

Ransom Note (Easy)
----------------------------------------
**Determine whether one string can be assembled from the characters of another.**

.. code-block:: cpp

   class Solution {
   public:
       bool canConstruct(string ransomNote, string magazine) {
           array<int, 26> counts{};
           for (char c : magazine) ++counts[c - 'a'];
           for (char c : ransomNote) {
               if (--counts[c - 'a'] < 0) return false;
           }
           return true;
       }
   };

.. rubric:: RooksGuide 2: Variables

Intersection of Two Arrays (Easy)
----------------------------------------
**Return the distinct values appearing in both arrays.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
           unordered_set<int> first(nums1.begin(), nums1.end());
           unordered_set<int> common;
           for (int value : nums2) {
               if (first.count(value)) common.insert(value);
           }
           return vector<int>(common.begin(), common.end());
       }
   };

Roman to Integer (Easy)
----------------------------------------
**Convert a Roman numeral string into an integer.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           unordered_map<char, int> value{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
           int total = 0;
           for (int i = 0; i < s.size(); ++i) {
               if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]]) total -= value[s[i]];
               else total += value[s[i]];
           }
           return total;
       }
   };

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count how many even divisions and odd subtractions reduce a number to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;
           while (num > 0) {
               num = num % 2 == 0 ? num / 2 : num - 1;
               ++steps;
           }
           return steps;
       }
   };

Build Array from Permutation (Easy)
----------------------------------------
**Construct an array whose values are selected through the input array’s indexes.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> buildArray(vector<int>& nums) {
           vector<int> answer(nums.size());
           for (int i = 0; i < nums.size(); ++i) {
               answer[i] = nums[nums[i]];
           }
           return answer;
       }
   };

Remove Duplicates from Sorted Array (Easy)
------------------------------------------
**Compress a sorted array in place so each value appears once.**

.. code-block:: cpp

   class Solution {
   public:
       int removeDuplicates(vector<int>& nums) {
           if (nums.empty()) return 0;
           int write = 1;
           for (int read = 1; read < nums.size(); ++read) {
               if (nums[read] != nums[read - 1]) nums[write++] = nums[read];
           }
           return write;
       }
   };

.. rubric:: RooksGuide 2.1: How do I decide which data type I need?

Climbing Stairs (Easy)
----------------------------------------
**Count the distinct ways to reach a step using moves of one or two.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           if (n <= 2) return n;
           int previous = 1;
           int current = 2;
           for (int step = 3; step <= n; ++step) {
               int next = previous + current;
               previous = current;
               current = next;
           }
           return current;
       }
   };

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

.. rubric:: RooksGuide 2.2: Identifiers

Jewels and Stones (Easy)
----------------------------------------
**Count how many characters in one string belong to a specified set.**

.. code-block:: cpp

   class Solution {
   public:
       int numJewelsInStones(string jewels, string stones) {
           unordered_set<char> types(jewels.begin(), jewels.end());
           int count = 0;
           for (char stone : stones) count += types.count(stone);
           return count;
       }
   };

.. rubric:: RooksGuide 2.3: Declaring a Variable

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count how many even divisions and odd subtractions reduce a number to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;
           while (num > 0) {
               num = num % 2 == 0 ? num / 2 : num - 1;
               ++steps;
           }
           return steps;
       }
   };

Plus One (Easy)
----------------------------------------
**Increment a large integer stored as an array of decimal digits.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> plusOne(vector<int>& digits) {
           for (int i = digits.size() - 1; i >= 0; --i) {
               if (digits[i] < 9) {
                   ++digits[i];
                   return digits;
               }
               digits[i] = 0;
           }
           digits.insert(digits.begin(), 1);
           return digits;
       }
   };

Palindrome Number (Easy)
----------------------------------------
**Determine whether an integer reads the same in both directions.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(int x) {
           if (x < 0) return false;
           long reversed = 0;
           int original = x;
           while (x > 0) {
               reversed = reversed * 10 + x % 10;
               x /= 10;
           }
           return reversed == original;
       }
   };

Count the Digits That Divide a Number (Easy)
--------------------------------------------
**Count the digits that divide the original number without a remainder.**

.. code-block:: cpp

   class Solution {
   public:
       int countDigits(int num) {
           int count = 0;
           for (int value = num; value > 0; value /= 10) {
               int digit = value % 10;
               if (digit != 0 && num % digit == 0) {
                   ++count;
               }
           }
           return count;
       }
   };

Shuffle the Array (Easy)
----------------------------------------
**Interleave the first and second halves of an array.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> shuffle(vector<int>& nums, int n) {
           vector<int> answer;
           answer.reserve(nums.size());
           for (int i = 0; i < n; ++i) {
               answer.push_back(nums[i]);
               answer.push_back(nums[i + n]);
           }
           return answer;
       }
   };

.. rubric:: RooksGuide 2.4: Initializing Variables

Subtract the Product and Sum of Digits of an Integer (Easy)
-----------------------------------------------------------
**Compute the product of an integer’s digits minus their sum.**

.. code-block:: cpp

   class Solution {
   public:
       int subtractProductAndSum(int n) {
           int product = 1;
           int sum = 0;
           while (n > 0) {
               int digit = n % 10;
               product *= digit;
               sum += digit;
               n /= 10;
           }
           return product - sum;
       }
   };

Length of Last Word (Easy)
----------------------------------------
**Return the number of characters in the final word of a string.**

.. code-block:: cpp

   class Solution {
   public:
       int lengthOfLastWord(string s) {
           int i = s.size() - 1;
           while (i >= 0 && s[i] == ' ') --i;
           int length = 0;
           while (i >= 0 && s[i] != ' ') {
               ++length;
               --i;
           }
           return length;
       }
   };

.. rubric:: ThinkCScpp 2.7: Operators

Valid Palindrome (Easy)
----------------------------------------
**Check whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               while (left < right && !isalnum(s[left])) ++left;
               while (left < right && !isalnum(s[right])) --right;
               if (tolower(s[left]) != tolower(s[right])) return false;
               ++left;
               --right;
           }
           return true;
       }
   };

Find the Index of the First Occurrence in a String (Easy)
---------------------------------------------------------
**Return the first position where one string appears inside another.**

.. code-block:: cpp

   class Solution {
   public:
       int strStr(string haystack, string needle) {
           size_t position = haystack.find(needle);
           return position == string::npos ? -1 : static_cast<int>(position);
       }
   };

Add Digits (Easy)
----------------------------------------
**Reduce an integer to one digit by repeatedly summing its digits.**

.. code-block:: cpp

   class Solution {
   public:
       int addDigits(int num) {
           return num == 0 ? 0 : 1 + (num - 1) % 9;
       }
   };

Smallest Even Multiple (Easy)
----------------------------------------
**Return the smallest positive value divisible by both 2 and n.**

.. code-block:: cpp

   class Solution {
   public:
       int smallestEvenMultiple(int n) {
           return n % 2 == 0 ? n : n * 2;
       }
   };

Score of a String (Easy)
----------------------------------------
**Sum the absolute differences between adjacent character codes.**

.. code-block:: cpp

   class Solution {
   public:
       int scoreOfString(string s) {
           int score = 0;
           for (int i = 1; i < s.size(); ++i) {
               score += abs(s[i] - s[i - 1]);
           }
           return score;
       }
   };

.. rubric:: ThinkCScpp 2.8: Order of operations

Fibonacci Number (Easy)
----------------------------------------
**Return the nth Fibonacci value using an iterative function.**

.. code-block:: cpp

   class Solution {
   public:
       int fib(int n) {
           if (n < 2) return n;
           int first = 0;
           int second = 1;
           for (int i = 2; i <= n; ++i) {
               int next = first + second;
               first = second;
               second = next;
           }
           return second;
       }
   };

Number of Good Pairs (Easy)
----------------------------------------
**Count index pairs containing equal integer values.**

.. code-block:: cpp

   class Solution {
   public:
       int numIdenticalPairs(vector<int>& nums) {
           unordered_map<int, int> counts;
           int pairs = 0;
           for (int value : nums) {
               pairs += counts[value]++;
           }
           return pairs;
       }
   };

.. rubric:: ThinkCScpp 2.9: Operators for characters

Single Number (Easy)
----------------------------------------
**Find the only value that doesn’t appear twice.**

.. code-block:: cpp

   class Solution {
   public:
       int singleNumber(vector<int>& nums) {
           int result = 0;
           for (int value : nums) result ^= value;
           return result;
       }
   };

.. rubric:: ProgFund 4.4: Arithmetic Assignment Operators

Merge Strings Alternately (Easy)
----------------------------------------
**Build one string by alternating characters from two inputs.**

.. code-block:: cpp

   class Solution {
   public:
       string mergeAlternately(string word1, string word2) {
           string result;
           int length = max(word1.size(), word2.size());
           for (int i = 0; i < length; ++i) {
               if (i < word1.size()) result += word1[i];
               if (i < word2.size()) result += word2[i];
           }
           return result;
       }
   };

Valid Perfect Square (Easy)
----------------------------------------
**Use integer arithmetic to decide whether a number has an exact square root.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPerfectSquare(int num) {
           long left = 1;
           long right = num;
           while (left <= right) {
               long middle = left + (right - left) / 2;
               long square = middle * middle;
               if (square == num) return true;
               if (square < num) left = middle + 1;
               else right = middle - 1;
           }
           return false;
       }
   };

.. rubric:: ProgFund 4.5: Lvalue and Rvalue

Build Array from Permutation (Easy)
----------------------------------------
**Construct an array whose values are selected through the input array’s indexes.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> buildArray(vector<int>& nums) {
           vector<int> answer(nums.size());
           for (int i = 0; i < nums.size(); ++i) {
               answer[i] = nums[nums[i]];
           }
           return answer;
       }
   };

Jewels and Stones (Easy)
----------------------------------------
**Count how many characters in one string belong to a specified set.**

.. code-block:: cpp

   class Solution {
   public:
       int numJewelsInStones(string jewels, string stones) {
           unordered_set<char> types(jewels.begin(), jewels.end());
           int count = 0;
           for (char stone : stones) count += types.count(stone);
           return count;
       }
   };

Shuffle the Array (Easy)
----------------------------------------
**Interleave the first and second halves of an array.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> shuffle(vector<int>& nums, int n) {
           vector<int> answer;
           answer.reserve(nums.size());
           for (int i = 0; i < n; ++i) {
               answer.push_back(nums[i]);
               answer.push_back(nums[i + n]);
           }
           return answer;
       }
   };

Roman to Integer (Easy)
----------------------------------------
**Convert a Roman numeral string into an integer.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           unordered_map<char, int> value{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
           int total = 0;
           for (int i = 0; i < s.size(); ++i) {
               if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]]) total -= value[s[i]];
               else total += value[s[i]];
           }
           return total;
       }
   };

.. rubric:: ProgFund 4.6: Integer Division and Modulus

Add Two Integers (Easy)
----------------------------------------
**Return the sum of two integer parameters.**

.. code-block:: cpp

   class Solution {
   public:
       int sum(int num1, int num2) {
           return num1 + num2;
       }
   };

N-th Tribonacci Number (Easy)
----------------------------------------
**Return a sequence value where each term is the sum of the previous three.**

.. code-block:: cpp

   class Solution {
   public:
       int tribonacci(int n) {
           if (n == 0) return 0;
           if (n < 3) return 1;
           int a = 0, b = 1, c = 1;
           for (int i = 3; i <= n; ++i) {
               int next = a + b + c;
               a = b;
               b = c;
               c = next;
           }
           return c;
       }
   };

Valid Palindrome (Easy)
----------------------------------------
**Check whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               while (left < right && !isalnum(s[left])) ++left;
               while (left < right && !isalnum(s[right])) --right;
               if (tolower(s[left]) != tolower(s[right])) return false;
               ++left;
               --right;
           }
           return true;
       }
   };

Subtract the Product and Sum of Digits of an Integer (Easy)
-----------------------------------------------------------
**Compute the product of an integer’s digits minus their sum.**

.. code-block:: cpp

   class Solution {
   public:
       int subtractProductAndSum(int n) {
           int product = 1;
           int sum = 0;
           while (n > 0) {
               int digit = n % 10;
               product *= digit;
               sum += digit;
               n /= 10;
           }
           return product - sum;
       }
   };

.. rubric:: RooksGuide 2.5: Assignment Statements

Valid Palindrome (Easy)
----------------------------------------
**Check whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               while (left < right && !isalnum(s[left])) ++left;
               while (left < right && !isalnum(s[right])) --right;
               if (tolower(s[left]) != tolower(s[right])) return false;
               ++left;
               --right;
           }
           return true;
       }
   };

N-th Tribonacci Number (Easy)
----------------------------------------
**Return a sequence value where each term is the sum of the previous three.**

.. code-block:: cpp

   class Solution {
   public:
       int tribonacci(int n) {
           if (n == 0) return 0;
           if (n < 3) return 1;
           int a = 0, b = 1, c = 1;
           for (int i = 3; i <= n; ++i) {
               int next = a + b + c;
               a = b;
               b = c;
               c = next;
           }
           return c;
       }
   };

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count how many even divisions and odd subtractions reduce a number to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;
           while (num > 0) {
               num = num % 2 == 0 ? num / 2 : num - 1;
               ++steps;
           }
           return steps;
       }
   };

Final Value of Variable After Performing Operations (Easy)
----------------------------------------------------------
**Apply increment and decrement strings to a single integer variable.**

.. code-block:: cpp

   class Solution {
   public:
       int finalValueAfterOperations(vector<string>& operations) {
           int value = 0;
           for (const string& operation : operations) {
               value += operation[1] == '+' ? 1 : -1;
           }
           return value;
       }
   };

.. rubric:: RooksGuide 3: Literals and Constants

Number of Good Pairs (Easy)
----------------------------------------
**Count index pairs containing equal integer values.**

.. code-block:: cpp

   class Solution {
   public:
       int numIdenticalPairs(vector<int>& nums) {
           unordered_map<int, int> counts;
           int pairs = 0;
           for (int value : nums) {
               pairs += counts[value]++;
           }
           return pairs;
       }
   };

Happy Number (Easy)
----------------------------------------
**Repeatedly replace a number with the sum of its squared digits and detect whether it reaches one.**

.. code-block:: cpp

   class Solution {
       int next(int n) {
           int total = 0;
           while (n > 0) {
               int digit = n % 10;
               total += digit * digit;
               n /= 10;
           }
           return total;
       }
   public:
       bool isHappy(int n) {
           unordered_set<int> seen;
           while (n != 1 && !seen.count(n)) {
               seen.insert(n);
               n = next(n);
           }
           return n == 1;
       }
   };

Majority Element (Easy)
----------------------------------------
**Return the value occurring more than half the time.**

.. code-block:: cpp

   class Solution {
   public:
       int majorityElement(vector<int>& nums) {
           int candidate = 0;
           int count = 0;
           for (int value : nums) {
               if (count == 0) candidate = value;
               count += value == candidate ? 1 : -1;
           }
           return candidate;
       }
   };

N-th Tribonacci Number (Easy)
----------------------------------------
**Return a sequence value where each term is the sum of the previous three.**

.. code-block:: cpp

   class Solution {
   public:
       int tribonacci(int n) {
           if (n == 0) return 0;
           if (n < 3) return 1;
           int a = 0, b = 1, c = 1;
           for (int i = 3; i <= n; ++i) {
               int next = a + b + c;
               a = b;
               b = c;
               c = next;
           }
           return c;
       }
   };

Merge Sorted Array (Easy)
----------------------------------------
**Merge two sorted integer arrays into the first array in place.**

.. code-block:: cpp

   class Solution {
   public:
       void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
           int write = m + n - 1;
           --m;
           --n;
           while (n >= 0) {
               if (m >= 0 && nums1[m] > nums2[n]) nums1[write--] = nums1[m--];
               else nums1[write--] = nums2[n--];
           }
       }
   };

.. rubric:: RooksGuide 3.1: Literals

Move Zeroes (Easy)
----------------------------------------
**Move all zero values to the end while preserving other values’ order.**

.. code-block:: cpp

   class Solution {
   public:
       void moveZeroes(vector<int>& nums) {
           int write = 0;
           for (int value : nums) {
               if (value != 0) nums[write++] = value;
           }
           while (write < nums.size()) nums[write++] = 0;
       }
   };

Richest Customer Wealth (Easy)
----------------------------------------
**Find the largest row sum in a two-dimensional integer array.**

.. code-block:: cpp

   class Solution {
   public:
       int maximumWealth(vector<vector<int>>& accounts) {
           int maximum = 0;
           for (const auto& customer : accounts) {
               int total = 0;
               for (int value : customer) total += value;
               maximum = max(maximum, total);
           }
           return maximum;
       }
   };

Length of Last Word (Easy)
----------------------------------------
**Return the number of characters in the final word of a string.**

.. code-block:: cpp

   class Solution {
   public:
       int lengthOfLastWord(string s) {
           int i = s.size() - 1;
           while (i >= 0 && s[i] == ' ') --i;
           int length = 0;
           while (i >= 0 && s[i] != ' ') {
               ++length;
               --i;
           }
           return length;
       }
   };

Majority Element (Easy)
----------------------------------------
**Return the value occurring more than half the time.**

.. code-block:: cpp

   class Solution {
   public:
       int majorityElement(vector<int>& nums) {
           int candidate = 0;
           int count = 0;
           for (int value : nums) {
               if (count == 0) candidate = value;
               count += value == candidate ? 1 : -1;
           }
           return candidate;
       }
   };

.. rubric:: RooksGuide 3.2: Declared Constants

Valid Perfect Square (Easy)
----------------------------------------
**Use integer arithmetic to decide whether a number has an exact square root.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPerfectSquare(int num) {
           long left = 1;
           long right = num;
           while (left <= right) {
               long middle = left + (right - left) / 2;
               long square = middle * middle;
               if (square == num) return true;
               if (square < num) left = middle + 1;
               else right = middle - 1;
           }
           return false;
       }
   };

N-th Tribonacci Number (Easy)
----------------------------------------
**Return a sequence value where each term is the sum of the previous three.**

.. code-block:: cpp

   class Solution {
   public:
       int tribonacci(int n) {
           if (n == 0) return 0;
           if (n < 3) return 1;
           int a = 0, b = 1, c = 1;
           for (int i = 3; i <= n; ++i) {
               int next = a + b + c;
               a = b;
               b = c;
               c = next;
           }
           return c;
       }
   };

Count the Digits That Divide a Number (Easy)
--------------------------------------------
**Count the digits that divide the original number without a remainder.**

.. code-block:: cpp

   class Solution {
   public:
       int countDigits(int num) {
           int count = 0;
           for (int value = num; value > 0; value /= 10) {
               int digit = value % 10;
               if (digit != 0 && num % digit == 0) {
                   ++count;
               }
           }
           return count;
       }
   };

Happy Number (Easy)
----------------------------------------
**Repeatedly replace a number with the sum of its squared digits and detect whether it reaches one.**

.. code-block:: cpp

   class Solution {
       int next(int n) {
           int total = 0;
           while (n > 0) {
               int digit = n % 10;
               total += digit * digit;
               n /= 10;
           }
           return total;
       }
   public:
       bool isHappy(int n) {
           unordered_set<int> seen;
           while (n != 1 && !seen.count(n)) {
               seen.insert(n);
               n = next(n);
           }
           return n == 1;
       }
   };

.. rubric:: RooksGuide 4: Assignments

Number of Good Pairs (Easy)
----------------------------------------
**Count index pairs containing equal integer values.**

.. code-block:: cpp

   class Solution {
   public:
       int numIdenticalPairs(vector<int>& nums) {
           unordered_map<int, int> counts;
           int pairs = 0;
           for (int value : nums) {
               pairs += counts[value]++;
           }
           return pairs;
       }
   };

Missing Number (Easy)
----------------------------------------
**Find the absent value from the integer range zero through n.**

.. code-block:: cpp

   class Solution {
   public:
       int missingNumber(vector<int>& nums) {
           int result = nums.size();
           for (int i = 0; i < nums.size(); ++i) {
               result ^= i ^ nums[i];
           }
           return result;
       }
   };

Length of Last Word (Easy)
----------------------------------------
**Return the number of characters in the final word of a string.**

.. code-block:: cpp

   class Solution {
   public:
       int lengthOfLastWord(string s) {
           int i = s.size() - 1;
           while (i >= 0 && s[i] == ' ') --i;
           int length = 0;
           while (i >= 0 && s[i] != ' ') {
               ++length;
               --i;
           }
           return length;
       }
   };

.. rubric:: ThinkCScpp 2.10: Composition

Palindrome Number (Easy)
----------------------------------------
**Determine whether an integer reads the same in both directions.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(int x) {
           if (x < 0) return false;
           long reversed = 0;
           int original = x;
           while (x > 0) {
               reversed = reversed * 10 + x % 10;
               x /= 10;
           }
           return reversed == original;
       }
   };

Running Sum of 1d Array (Easy)
----------------------------------------
**Replace each array value with the sum of values up to that position.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> runningSum(vector<int>& nums) {
           for (int i = 1; i < nums.size(); ++i) {
               nums[i] += nums[i - 1];
           }
           return nums;
       }
   };

Build Array from Permutation (Easy)
----------------------------------------
**Construct an array whose values are selected through the input array’s indexes.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> buildArray(vector<int>& nums) {
           vector<int> answer(nums.size());
           for (int i = 0; i < nums.size(); ++i) {
               answer[i] = nums[nums[i]];
           }
           return answer;
       }
   };


Unit 3 practice problems
~~~~~~~~~~~~~~~~~~~~~~~~

.. rubric:: ThinkCScpp 3.1: Floating-point

Score of a String (Easy)
----------------------------------------
**Sum the absolute differences between adjacent character codes.**

.. code-block:: cpp

   class Solution {
   public:
       int scoreOfString(string s) {
           int score = 0;
           for (int i = 1; i < s.size(); ++i) {
               score += abs(s[i] - s[i - 1]);
           }
           return score;
       }
   };

Sqrt(x) (Easy)
----------------------------------------
**Return the integer part of a non-negative number’s square root.**

.. code-block:: cpp

   class Solution {
   public:
       int mySqrt(int x) {
           long left = 0;
           long right = x;
           while (left <= right) {
               long middle = left + (right - left) / 2;
               long square = middle * middle;
               if (square == x) return static_cast<int>(middle);
               if (square < x) left = middle + 1;
               else right = middle - 1;
           }
           return static_cast<int>(right);
       }
   };

Convert the Temperature (Easy)
----------------------------------------
**Convert a Celsius value to Kelvin and Fahrenheit.**

.. code-block:: cpp

   class Solution {
   public:
       vector<double> convertTemperature(double celsius) {
           return {celsius + 273.15, celsius * 1.80 + 32.00};
       }
   };

Find the Index of the First Occurrence in a String (Easy)
---------------------------------------------------------
**Return the first position where one string appears inside another.**

.. code-block:: cpp

   class Solution {
   public:
       int strStr(string haystack, string needle) {
           size_t position = haystack.find(needle);
           return position == string::npos ? -1 : static_cast<int>(position);
       }
   };

Roman to Integer (Easy)
----------------------------------------
**Convert a Roman numeral string into an integer.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           unordered_map<char, int> value{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
           int total = 0;
           for (int i = 0; i < s.size(); ++i) {
               if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]]) total -= value[s[i]];
               else total += value[s[i]];
           }
           return total;
       }
   };

.. rubric:: ThinkCScpp 3.2: Converting from double to int

Jewels and Stones (Easy)
----------------------------------------
**Count how many characters in one string belong to a specified set.**

.. code-block:: cpp

   class Solution {
   public:
       int numJewelsInStones(string jewels, string stones) {
           unordered_set<char> types(jewels.begin(), jewels.end());
           int count = 0;
           for (char stone : stones) count += types.count(stone);
           return count;
       }
   };

Valid Perfect Square (Easy)
----------------------------------------
**Use integer arithmetic to decide whether a number has an exact square root.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPerfectSquare(int num) {
           long left = 1;
           long right = num;
           while (left <= right) {
               long middle = left + (right - left) / 2;
               long square = middle * middle;
               if (square == num) return true;
               if (square < num) left = middle + 1;
               else right = middle - 1;
           }
           return false;
       }
   };

Intersection of Two Arrays (Easy)
----------------------------------------
**Return the distinct values appearing in both arrays.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
           unordered_set<int> first(nums1.begin(), nums1.end());
           unordered_set<int> common;
           for (int value : nums2) {
               if (first.count(value)) common.insert(value);
           }
           return vector<int>(common.begin(), common.end());
       }
   };

Score of a String (Easy)
----------------------------------------
**Sum the absolute differences between adjacent character codes.**

.. code-block:: cpp

   class Solution {
   public:
       int scoreOfString(string s) {
           int score = 0;
           for (int i = 1; i < s.size(); ++i) {
               score += abs(s[i] - s[i - 1]);
           }
           return score;
       }
   };

.. rubric:: ThinkCScpp 3.3: Math functions

Majority Element (Easy)
----------------------------------------
**Return the value occurring more than half the time.**

.. code-block:: cpp

   class Solution {
   public:
       int majorityElement(vector<int>& nums) {
           int candidate = 0;
           int count = 0;
           for (int value : nums) {
               if (count == 0) candidate = value;
               count += value == candidate ? 1 : -1;
           }
           return candidate;
       }
   };

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

Shuffle the Array (Easy)
----------------------------------------
**Interleave the first and second halves of an array.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> shuffle(vector<int>& nums, int n) {
           vector<int> answer;
           answer.reserve(nums.size());
           for (int i = 0; i < n; ++i) {
               answer.push_back(nums[i]);
               answer.push_back(nums[i + n]);
           }
           return answer;
       }
   };

.. rubric:: ThinkCScpp 3.4: Composition

Add Digits (Easy)
----------------------------------------
**Reduce an integer to one digit by repeatedly summing its digits.**

.. code-block:: cpp

   class Solution {
   public:
       int addDigits(int num) {
           return num == 0 ? 0 : 1 + (num - 1) % 9;
       }
   };

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count how many even divisions and odd subtractions reduce a number to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;
           while (num > 0) {
               num = num % 2 == 0 ? num / 2 : num - 1;
               ++steps;
           }
           return steps;
       }
   };

.. rubric:: ThinkCScpp 3.5: Adding new functions

Find the Index of the First Occurrence in a String (Easy)
---------------------------------------------------------
**Return the first position where one string appears inside another.**

.. code-block:: cpp

   class Solution {
   public:
       int strStr(string haystack, string needle) {
           size_t position = haystack.find(needle);
           return position == string::npos ? -1 : static_cast<int>(position);
       }
   };

Two Sum (Easy)
----------------------------------------
**Return the indexes of two values whose sum equals a target.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int, int> seen;
           for (int i = 0; i < nums.size(); ++i) {
               int needed = target - nums[i];
               if (seen.count(needed)) return {seen[needed], i};
               seen[nums[i]] = i;
           }
           return {};
       }
   };

Move Zeroes (Easy)
----------------------------------------
**Move all zero values to the end while preserving other values’ order.**

.. code-block:: cpp

   class Solution {
   public:
       void moveZeroes(vector<int>& nums) {
           int write = 0;
           for (int value : nums) {
               if (value != 0) nums[write++] = value;
           }
           while (write < nums.size()) nums[write++] = 0;
       }
   };

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

First Unique Character in a String (Easy)
-----------------------------------------
**Return the first index containing a character that occurs once.**

.. code-block:: cpp

   class Solution {
   public:
       int firstUniqChar(string s) {
           array<int, 26> counts{};
           for (char c : s) ++counts[c - 'a'];
           for (int i = 0; i < s.size(); ++i) {
               if (counts[s[i] - 'a'] == 1) return i;
           }
           return -1;
       }
   };

.. rubric:: ThinkCScpp 3.6: Definitions and uses

Reverse String (Easy)
----------------------------------------
**Reverse a character array in place.**

.. code-block:: cpp

   class Solution {
   public:
       void reverseString(vector<char>& s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               swap(s[left++], s[right--]);
           }
       }
   };

Richest Customer Wealth (Easy)
----------------------------------------
**Find the largest row sum in a two-dimensional integer array.**

.. code-block:: cpp

   class Solution {
   public:
       int maximumWealth(vector<vector<int>>& accounts) {
           int maximum = 0;
           for (const auto& customer : accounts) {
               int total = 0;
               for (int value : customer) total += value;
               maximum = max(maximum, total);
           }
           return maximum;
       }
   };

Two Sum (Easy)
----------------------------------------
**Return the indexes of two values whose sum equals a target.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int, int> seen;
           for (int i = 0; i < nums.size(); ++i) {
               int needed = target - nums[i];
               if (seen.count(needed)) return {seen[needed], i};
               seen[nums[i]] = i;
           }
           return {};
       }
   };

Find the Index of the First Occurrence in a String (Easy)
---------------------------------------------------------
**Return the first position where one string appears inside another.**

.. code-block:: cpp

   class Solution {
   public:
       int strStr(string haystack, string needle) {
           size_t position = haystack.find(needle);
           return position == string::npos ? -1 : static_cast<int>(position);
       }
   };

.. rubric:: ThinkCScpp 3.7: Programs with multiple functions

Valid Perfect Square (Easy)
----------------------------------------
**Use integer arithmetic to decide whether a number has an exact square root.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPerfectSquare(int num) {
           long left = 1;
           long right = num;
           while (left <= right) {
               long middle = left + (right - left) / 2;
               long square = middle * middle;
               if (square == num) return true;
               if (square < num) left = middle + 1;
               else right = middle - 1;
           }
           return false;
       }
   };

Palindrome Number (Easy)
----------------------------------------
**Determine whether an integer reads the same in both directions.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(int x) {
           if (x < 0) return false;
           long reversed = 0;
           int original = x;
           while (x > 0) {
               reversed = reversed * 10 + x % 10;
               x /= 10;
           }
           return reversed == original;
       }
   };

Merge Strings Alternately (Easy)
----------------------------------------
**Build one string by alternating characters from two inputs.**

.. code-block:: cpp

   class Solution {
   public:
       string mergeAlternately(string word1, string word2) {
           string result;
           int length = max(word1.size(), word2.size());
           for (int i = 0; i < length; ++i) {
               if (i < word1.size()) result += word1[i];
               if (i < word2.size()) result += word2[i];
           }
           return result;
       }
   };

Jewels and Stones (Easy)
----------------------------------------
**Count how many characters in one string belong to a specified set.**

.. code-block:: cpp

   class Solution {
   public:
       int numJewelsInStones(string jewels, string stones) {
           unordered_set<char> types(jewels.begin(), jewels.end());
           int count = 0;
           for (char stone : stones) count += types.count(stone);
           return count;
       }
   };

.. rubric:: ThinkCScpp 3.8: Parameters and arguments

Richest Customer Wealth (Easy)
----------------------------------------
**Find the largest row sum in a two-dimensional integer array.**

.. code-block:: cpp

   class Solution {
   public:
       int maximumWealth(vector<vector<int>>& accounts) {
           int maximum = 0;
           for (const auto& customer : accounts) {
               int total = 0;
               for (int value : customer) total += value;
               maximum = max(maximum, total);
           }
           return maximum;
       }
   };

Convert the Temperature (Easy)
----------------------------------------
**Convert a Celsius value to Kelvin and Fahrenheit.**

.. code-block:: cpp

   class Solution {
   public:
       vector<double> convertTemperature(double celsius) {
           return {celsius + 273.15, celsius * 1.80 + 32.00};
       }
   };

Shuffle the Array (Easy)
----------------------------------------
**Interleave the first and second halves of an array.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> shuffle(vector<int>& nums, int n) {
           vector<int> answer;
           answer.reserve(nums.size());
           for (int i = 0; i < n; ++i) {
               answer.push_back(nums[i]);
               answer.push_back(nums[i + n]);
           }
           return answer;
       }
   };

.. rubric:: ThinkCScpp 3.9: Parameters and variables are local

To Lower Case (Easy)
----------------------------------------
**Convert every uppercase letter in a string to lowercase.**

.. code-block:: cpp

   class Solution {
   public:
       string toLowerCase(string s) {
           for (char& c : s) {
               if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
           }
           return s;
       }
   };

Final Value of Variable After Performing Operations (Easy)
----------------------------------------------------------
**Apply increment and decrement strings to a single integer variable.**

.. code-block:: cpp

   class Solution {
   public:
       int finalValueAfterOperations(vector<string>& operations) {
           int value = 0;
           for (const string& operation : operations) {
               value += operation[1] == '+' ? 1 : -1;
           }
           return value;
       }
   };

Plus One (Easy)
----------------------------------------
**Increment a large integer stored as an array of decimal digits.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> plusOne(vector<int>& digits) {
           for (int i = digits.size() - 1; i >= 0; --i) {
               if (digits[i] < 9) {
                   ++digits[i];
                   return digits;
               }
               digits[i] = 0;
           }
           digits.insert(digits.begin(), 1);
           return digits;
       }
   };

Valid Palindrome (Easy)
----------------------------------------
**Check whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               while (left < right && !isalnum(s[left])) ++left;
               while (left < right && !isalnum(s[right])) --right;
               if (tolower(s[left]) != tolower(s[right])) return false;
               ++left;
               --right;
           }
           return true;
       }
   };

.. rubric:: ThinkCScpp 3.10: Functions with multiple parameters

Smallest Even Multiple (Easy)
----------------------------------------
**Return the smallest positive value divisible by both 2 and n.**

.. code-block:: cpp

   class Solution {
   public:
       int smallestEvenMultiple(int n) {
           return n % 2 == 0 ? n : n * 2;
       }
   };

Valid Palindrome (Easy)
----------------------------------------
**Check whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               while (left < right && !isalnum(s[left])) ++left;
               while (left < right && !isalnum(s[right])) --right;
               if (tolower(s[left]) != tolower(s[right])) return false;
               ++left;
               --right;
           }
           return true;
       }
   };

Build Array from Permutation (Easy)
----------------------------------------
**Construct an array whose values are selected through the input array’s indexes.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> buildArray(vector<int>& nums) {
           vector<int> answer(nums.size());
           for (int i = 0; i < nums.size(); ++i) {
               answer[i] = nums[nums[i]];
           }
           return answer;
       }
   };

.. rubric:: ThinkCScpp 3.11: Functions with results

Climbing Stairs (Easy)
----------------------------------------
**Count the distinct ways to reach a step using moves of one or two.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           if (n <= 2) return n;
           int previous = 1;
           int current = 2;
           for (int step = 3; step <= n; ++step) {
               int next = previous + current;
               previous = current;
               current = next;
           }
           return current;
       }
   };

.. rubric:: ProgFund 6: Program Control Functions

To Lower Case (Easy)
----------------------------------------
**Convert every uppercase letter in a string to lowercase.**

.. code-block:: cpp

   class Solution {
   public:
       string toLowerCase(string s) {
           for (char& c : s) {
               if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
           }
           return s;
       }
   };

.. rubric:: ProgFund 6.1: Pseudocode Examples for Functions

Fibonacci Number (Easy)
----------------------------------------
**Return the nth Fibonacci value using an iterative function.**

.. code-block:: cpp

   class Solution {
   public:
       int fib(int n) {
           if (n < 2) return n;
           int first = 0;
           int second = 1;
           for (int i = 2; i <= n; ++i) {
               int next = first + second;
               first = second;
               second = next;
           }
           return second;
       }
   };

.. rubric:: ProgFund 6.2: Hierarchy or Structure Chart

Add Digits (Easy)
----------------------------------------
**Reduce an integer to one digit by repeatedly summing its digits.**

.. code-block:: cpp

   class Solution {
   public:
       int addDigits(int num) {
           return num == 0 ? 0 : 1 + (num - 1) % 9;
       }
   };

.. rubric:: ProgFund 6.3: Program Control Functions

Add Digits (Easy)
----------------------------------------
**Reduce an integer to one digit by repeatedly summing its digits.**

.. code-block:: cpp

   class Solution {
   public:
       int addDigits(int num) {
           return num == 0 ? 0 : 1 + (num - 1) % 9;
       }
   };

Ugly Number (Easy)
----------------------------------------
**Determine whether a positive integer has no prime factors other than 2, 3, and 5.**

.. code-block:: cpp

   class Solution {
   public:
       bool isUgly(int n) {
           if (n <= 0) return false;
           for (int factor : {2, 3, 5}) {
               while (n % factor == 0) n /= factor;
           }
           return n == 1;
       }
   };

Single Number (Easy)
----------------------------------------
**Find the only value that doesn’t appear twice.**

.. code-block:: cpp

   class Solution {
   public:
       int singleNumber(vector<int>& nums) {
           int result = 0;
           for (int value : nums) result ^= value;
           return result;
       }
   };

Running Sum of 1d Array (Easy)
----------------------------------------
**Replace each array value with the sum of values up to that position.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> runningSum(vector<int>& nums) {
           for (int i = 1; i < nums.size(); ++i) {
               nums[i] += nums[i - 1];
           }
           return nums;
       }
   };

Happy Number (Easy)
----------------------------------------
**Repeatedly replace a number with the sum of its squared digits and detect whether it reaches one.**

.. code-block:: cpp

   class Solution {
       int next(int n) {
           int total = 0;
           while (n > 0) {
               int digit = n % 10;
               total += digit * digit;
               n /= 10;
           }
           return total;
       }
   public:
       bool isHappy(int n) {
           unordered_set<int> seen;
           while (n != 1 && !seen.count(n)) {
               seen.insert(n);
               n = next(n);
           }
           return n == 1;
       }
   };

.. rubric:: ProgFund 6.4: Void Data Type

Climbing Stairs (Easy)
----------------------------------------
**Count the distinct ways to reach a step using moves of one or two.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           if (n <= 2) return n;
           int previous = 1;
           int current = 2;
           for (int step = 3; step <= n; ++step) {
               int next = previous + current;
               previous = current;
               current = next;
           }
           return current;
       }
   };

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

Intersection of Two Arrays (Easy)
----------------------------------------
**Return the distinct values appearing in both arrays.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
           unordered_set<int> first(nums1.begin(), nums1.end());
           unordered_set<int> common;
           for (int value : nums2) {
               if (first.count(value)) common.insert(value);
           }
           return vector<int>(common.begin(), common.end());
       }
   };

Reverse String (Easy)
----------------------------------------
**Reverse a character array in place.**

.. code-block:: cpp

   class Solution {
   public:
       void reverseString(vector<char>& s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               swap(s[left++], s[right--]);
           }
       }
   };

.. rubric:: ProgFund 6.5: Documentation and Making Source Code Readable

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count how many even divisions and odd subtractions reduce a number to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;
           while (num > 0) {
               num = num % 2 == 0 ? num / 2 : num - 1;
               ++steps;
           }
           return steps;
       }
   };

Valid Anagram (Easy)
----------------------------------------
**Determine whether two strings contain the same character counts.**

.. code-block:: cpp

   class Solution {
   public:
       bool isAnagram(string s, string t) {
           if (s.size() != t.size()) return false;
           array<int, 26> counts{};
           for (char c : s) ++counts[c - 'a'];
           for (char c : t) --counts[c - 'a'];
           return all_of(counts.begin(), counts.end(), [](int n) { return n == 0; });
       }
   };

Majority Element (Easy)
----------------------------------------
**Return the value occurring more than half the time.**

.. code-block:: cpp

   class Solution {
   public:
       int majorityElement(vector<int>& nums) {
           int candidate = 0;
           int count = 0;
           for (int value : nums) {
               if (count == 0) candidate = value;
               count += value == candidate ? 1 : -1;
           }
           return candidate;
       }
   };

.. rubric:: RooksGuide 5: Output

Convert the Temperature (Easy)
----------------------------------------
**Convert a Celsius value to Kelvin and Fahrenheit.**

.. code-block:: cpp

   class Solution {
   public:
       vector<double> convertTemperature(double celsius) {
           return {celsius + 273.15, celsius * 1.80 + 32.00};
       }
   };

.. rubric:: RooksGuide 6: Input

Add Two Integers (Easy)
----------------------------------------
**Return the sum of two integer parameters.**

.. code-block:: cpp

   class Solution {
   public:
       int sum(int num1, int num2) {
           return num1 + num2;
       }
   };

Valid Anagram (Easy)
----------------------------------------
**Determine whether two strings contain the same character counts.**

.. code-block:: cpp

   class Solution {
   public:
       bool isAnagram(string s, string t) {
           if (s.size() != t.size()) return false;
           array<int, 26> counts{};
           for (char c : s) ++counts[c - 'a'];
           for (char c : t) --counts[c - 'a'];
           return all_of(counts.begin(), counts.end(), [](int n) { return n == 0; });
       }
   };

Length of Last Word (Easy)
----------------------------------------
**Return the number of characters in the final word of a string.**

.. code-block:: cpp

   class Solution {
   public:
       int lengthOfLastWord(string s) {
           int i = s.size() - 1;
           while (i >= 0 && s[i] == ' ') --i;
           int length = 0;
           while (i >= 0 && s[i] != ' ') {
               ++length;
               --i;
           }
           return length;
       }
   };

Roman to Integer (Easy)
----------------------------------------
**Convert a Roman numeral string into an integer.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           unordered_map<char, int> value{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
           int total = 0;
           for (int i = 0; i < s.size(); ++i) {
               if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]]) total -= value[s[i]];
               else total += value[s[i]];
           }
           return total;
       }
   };

Score of a String (Easy)
----------------------------------------
**Sum the absolute differences between adjacent character codes.**

.. code-block:: cpp

   class Solution {
   public:
       int scoreOfString(string s) {
           int score = 0;
           for (int i = 1; i < s.size(); ++i) {
               score += abs(s[i] - s[i - 1]);
           }
           return score;
       }
   };

.. rubric:: RooksGuide 7: Arithmetic

Ugly Number (Easy)
----------------------------------------
**Determine whether a positive integer has no prime factors other than 2, 3, and 5.**

.. code-block:: cpp

   class Solution {
   public:
       bool isUgly(int n) {
           if (n <= 0) return false;
           for (int factor : {2, 3, 5}) {
               while (n % factor == 0) n /= factor;
           }
           return n == 1;
       }
   };

Convert the Temperature (Easy)
----------------------------------------
**Convert a Celsius value to Kelvin and Fahrenheit.**

.. code-block:: cpp

   class Solution {
   public:
       vector<double> convertTemperature(double celsius) {
           return {celsius + 273.15, celsius * 1.80 + 32.00};
       }
   };

Add Two Integers (Easy)
----------------------------------------
**Return the sum of two integer parameters.**

.. code-block:: cpp

   class Solution {
   public:
       int sum(int num1, int num2) {
           return num1 + num2;
       }
   };

.. rubric:: RooksGuide 8: Comments

Power of Two (Easy)
----------------------------------------
**Determine whether an integer is an exact power of two.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPowerOfTwo(int n) {
           return n > 0 && (n & (n - 1)) == 0;
       }
   };

Contains Duplicate (Easy)
----------------------------------------
**Return whether any integer occurs more than once.**

.. code-block:: cpp

   class Solution {
   public:
       bool containsDuplicate(vector<int>& nums) {
           unordered_set<int> seen;
           for (int value : nums) {
               if (!seen.insert(value).second) return true;
           }
           return false;
       }
   };

Palindrome Number (Easy)
----------------------------------------
**Determine whether an integer reads the same in both directions.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(int x) {
           if (x < 0) return false;
           long reversed = 0;
           int original = x;
           while (x > 0) {
               reversed = reversed * 10 + x % 10;
               x /= 10;
           }
           return reversed == original;
       }
   };

Shuffle the Array (Easy)
----------------------------------------
**Interleave the first and second halves of an array.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> shuffle(vector<int>& nums, int n) {
           vector<int> answer;
           answer.reserve(nums.size());
           for (int i = 0; i < n; ++i) {
               answer.push_back(nums[i]);
               answer.push_back(nums[i + n]);
           }
           return answer;
       }
   };

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

.. rubric:: RooksGuide 9: Data Types and Conversion

Sqrt(x) (Easy)
----------------------------------------
**Return the integer part of a non-negative number’s square root.**

.. code-block:: cpp

   class Solution {
   public:
       int mySqrt(int x) {
           long left = 0;
           long right = x;
           while (left <= right) {
               long middle = left + (right - left) / 2;
               long square = middle * middle;
               if (square == x) return static_cast<int>(middle);
               if (square < x) left = middle + 1;
               else right = middle - 1;
           }
           return static_cast<int>(right);
       }
   };

Jewels and Stones (Easy)
----------------------------------------
**Count how many characters in one string belong to a specified set.**

.. code-block:: cpp

   class Solution {
   public:
       int numJewelsInStones(string jewels, string stones) {
           unordered_set<char> types(jewels.begin(), jewels.end());
           int count = 0;
           for (char stone : stones) count += types.count(stone);
           return count;
       }
   };

.. rubric:: RooksGuide 9.1: Floating-point types

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

Climbing Stairs (Easy)
----------------------------------------
**Count the distinct ways to reach a step using moves of one or two.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           if (n <= 2) return n;
           int previous = 1;
           int current = 2;
           for (int step = 3; step <= n; ++step) {
               int next = previous + current;
               previous = current;
               current = next;
           }
           return current;
       }
   };

.. rubric:: RooksGuide 9.2: Other types introduced by C++11

Ugly Number (Easy)
----------------------------------------
**Determine whether a positive integer has no prime factors other than 2, 3, and 5.**

.. code-block:: cpp

   class Solution {
   public:
       bool isUgly(int n) {
           if (n <= 0) return false;
           for (int factor : {2, 3, 5}) {
               while (n % factor == 0) n /= factor;
           }
           return n == 1;
       }
   };

To Lower Case (Easy)
----------------------------------------
**Convert every uppercase letter in a string to lowercase.**

.. code-block:: cpp

   class Solution {
   public:
       string toLowerCase(string s) {
           for (char& c : s) {
               if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
           }
           return s;
       }
   };

.. rubric:: RooksGuide 9.3: Conversion Between Types

Ugly Number (Easy)
----------------------------------------
**Determine whether a positive integer has no prime factors other than 2, 3, and 5.**

.. code-block:: cpp

   class Solution {
   public:
       bool isUgly(int n) {
           if (n <= 0) return false;
           for (int factor : {2, 3, 5}) {
               while (n % factor == 0) n /= factor;
           }
           return n == 1;
       }
   };

Ransom Note (Easy)
----------------------------------------
**Determine whether one string can be assembled from the characters of another.**

.. code-block:: cpp

   class Solution {
   public:
       bool canConstruct(string ransomNote, string magazine) {
           array<int, 26> counts{};
           for (char c : magazine) ++counts[c - 'a'];
           for (char c : ransomNote) {
               if (--counts[c - 'a'] < 0) return false;
           }
           return true;
       }
   };

.. rubric:: RooksGuide 9.4: Coercion & Casting

Valid Palindrome (Easy)
----------------------------------------
**Check whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = s.size() - 1;
           while (left < right) {
               while (left < right && !isalnum(s[left])) ++left;
               while (left < right && !isalnum(s[right])) --right;
               if (tolower(s[left]) != tolower(s[right])) return false;
               ++left;
               --right;
           }
           return true;
       }
   };

Roman to Integer (Easy)
----------------------------------------
**Convert a Roman numeral string into an integer.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           unordered_map<char, int> value{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
           int total = 0;
           for (int i = 0; i < s.size(); ++i) {
               if (i + 1 < s.size() && value[s[i]] < value[s[i + 1]]) total -= value[s[i]];
               else total += value[s[i]];
           }
           return total;
       }
   };

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

.. rubric:: RooksGuide 9.5: Automatic Types in C++11

First Unique Character in a String (Easy)
-----------------------------------------
**Return the first index containing a character that occurs once.**

.. code-block:: cpp

   class Solution {
   public:
       int firstUniqChar(string s) {
           array<int, 26> counts{};
           for (char c : s) ++counts[c - 'a'];
           for (int i = 0; i < s.size(); ++i) {
               if (counts[s[i] - 'a'] == 1) return i;
           }
           return -1;
       }
   };

Concatenation of Array (Easy)
----------------------------------------
**Create an output array containing the input sequence twice.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getConcatenation(vector<int>& nums) {
           vector<int> answer = nums;
           answer.insert(answer.end(), nums.begin(), nums.end());
           return answer;
       }
   };

Unit 4 practice problems
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. rubric:: ThinkCScpp 4.1: The modulus operator

Subtract the Product and Sum of Digits of an Integer (Easy)
-----------------------------------------------------------
**Return the product of an integer's digits minus their sum.**

.. code-block:: cpp

   class Solution {
   public:
       int subtractProductAndSum(int n) {
           int product = 1;
           int sum = 0;

           while (n > 0) {
               int digit = n % 10;
               product *= digit;
               sum += digit;
               n /= 10;
           }

           return product - sum;
       }
   };

Count the Digits That Divide a Number (Easy)
--------------------------------------------
**Count how many digits divide the original number without a remainder.**

.. code-block:: cpp

   class Solution {
   public:
       int countDigits(int num) {
           int count = 0;

           for (int remaining = num; remaining > 0; remaining /= 10) {
               int digit = remaining % 10;

               if (digit != 0 && num % digit == 0) {
                   ++count;
               }
           }

           return count;
       }
   };

Fizz Buzz (Easy)
----------------
**Return each number as text, replacing multiples of three and five with the required words.**

.. code-block:: cpp

   class Solution {
   public:
       vector<string> fizzBuzz(int n) {
           vector<string> answer;

           for (int i = 1; i <= n; ++i) {
               if (i % 15 == 0) {
                   answer.push_back("FizzBuzz");
               } else if (i % 3 == 0) {
                   answer.push_back("Fizz");
               } else if (i % 5 == 0) {
                   answer.push_back("Buzz");
               } else {
                   answer.push_back(to_string(i));
               }
           }

           return answer;
       }
   };

.. rubric:: ThinkCScpp 4.2: Conditional execution

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count the divisions and subtractions required to reduce an integer to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;

           while (num > 0) {
               if (num % 2 == 0) {
                   num /= 2;
               } else {
                   --num;
               }

               ++steps;
           }

           return steps;
       }
   };

Maximum 69 Number (Easy)
------------------------
**Change at most one digit from six to nine to produce the greatest value.**

.. code-block:: cpp

   class Solution {
   public:
       int maximum69Number(int num) {
           string digits = to_string(num);

           for (char& digit : digits) {
               if (digit == '6') {
                   digit = '9';
                   break;
               }
           }

           return stoi(digits);
       }
   };

.. rubric:: ThinkCScpp 4.3: Alternative execution

Power of Two (Easy)
-------------------
**Return whether an integer is an exact power of two.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPowerOfTwo(int n) {
           return n > 0 && (n & (n - 1)) == 0;
       }
   };

.. rubric:: ThinkCScpp 4.4: Chained conditionals

Fizz Buzz (Easy)
----------------
**Return each number as text, replacing multiples of three and five with the required words.**

.. code-block:: cpp

   class Solution {
   public:
       vector<string> fizzBuzz(int n) {
           vector<string> answer;

           for (int i = 1; i <= n; ++i) {
               if (i % 15 == 0) {
                   answer.push_back("FizzBuzz");
               } else if (i % 3 == 0) {
                   answer.push_back("Fizz");
               } else if (i % 5 == 0) {
                   answer.push_back("Buzz");
               } else {
                   answer.push_back(to_string(i));
               }
           }

           return answer;
       }
   };

Lemonade Change (Easy)
----------------------
**Determine whether correct change can be given to every customer in order.**

.. code-block:: cpp

   class Solution {
   public:
       bool lemonadeChange(vector<int>& bills) {
           int fives = 0;
           int tens = 0;

           for (int bill : bills) {
               if (bill == 5) {
                   ++fives;
               } else if (bill == 10) {
                   if (fives == 0) {
                       return false;
                   }

                   --fives;
                   ++tens;
               } else {
                   if (tens > 0 && fives > 0) {
                       --tens;
                       --fives;
                   } else if (fives >= 3) {
                       fives -= 3;
                   } else {
                       return false;
                   }
               }
           }

           return true;
       }
   };

Roman to Integer (Easy)
-----------------------
**Convert a Roman numeral into its integer value.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           int total = 0;

           for (int i = 0; i < static_cast<int>(s.size()); ++i) {
               int value = romanValue(s[i]);

               if (i + 1 < static_cast<int>(s.size()) &&
                   value < romanValue(s[i + 1])) {
                   total -= value;
               } else {
                   total += value;
               }
           }

           return total;
       }

   private:
       int romanValue(char symbol) {
           switch (symbol) {
               case 'I': return 1;
               case 'V': return 5;
               case 'X': return 10;
               case 'L': return 50;
               case 'C': return 100;
               case 'D': return 500;
               case 'M': return 1000;
               default: return 0;
           }
       }
   };

Maximum 69 Number (Easy)
------------------------
**Change at most one digit from six to nine to produce the greatest value.**

.. code-block:: cpp

   class Solution {
   public:
       int maximum69Number(int num) {
           string digits = to_string(num);

           for (char& digit : digits) {
               if (digit == '6') {
                   digit = '9';
                   break;
               }
           }

           return stoi(digits);
       }
   };

.. rubric:: ThinkCScpp 4.5: Nested conditionals

Valid Palindrome (Easy)
-----------------------
**Determine whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = static_cast<int>(s.size()) - 1;

           while (left < right) {
               while (left < right &&
                      !isalnum(static_cast<unsigned char>(s[left]))) {
                   ++left;
               }

               while (left < right &&
                      !isalnum(static_cast<unsigned char>(s[right]))) {
                   --right;
               }

               if (tolower(static_cast<unsigned char>(s[left])) !=
                   tolower(static_cast<unsigned char>(s[right]))) {
                   return false;
               }

               ++left;
               --right;
           }

           return true;
       }
   };

Happy Number (Easy)
-------------------
**Determine whether repeatedly summing squared digits eventually reaches one.**

.. code-block:: cpp

   class Solution {
   public:
       bool isHappy(int n) {
           unordered_set<int> seen;

           while (n != 1 && !seen.count(n)) {
               seen.insert(n);
               n = digitSquareSum(n);
           }

           return n == 1;
       }

   private:
       int digitSquareSum(int n) {
           int sum = 0;

           while (n > 0) {
               int digit = n % 10;
               sum += digit * digit;
               n /= 10;
           }

           return sum;
       }
   };

.. rubric:: ThinkCScpp 4.6: The return statement

Binary Search (Easy)
--------------------
**Return the index of a target in a sorted array or negative one when absent.**

.. code-block:: cpp

   class Solution {
   public:
       int search(vector<int>& nums, int target) {
           int left = 0;
           int right = static_cast<int>(nums.size()) - 1;

           while (left <= right) {
               int middle = left + (right - left) / 2;

               if (nums[middle] == target) {
                   return middle;
               }

               if (nums[middle] < target) {
                   left = middle + 1;
               } else {
                   right = middle - 1;
               }
           }

           return -1;
       }
   };

Sqrt(x) (Easy)
--------------
**Return the truncated integer square root of a non-negative integer.**

.. code-block:: cpp

   class Solution {
   public:
       int mySqrt(int x) {
           int left = 0;
           int right = x;
           int answer = 0;

           while (left <= right) {
               int middle = left + (right - left) / 2;
               long long square = static_cast<long long>(middle) * middle;

               if (square <= x) {
                   answer = middle;
                   left = middle + 1;
               } else {
                   right = middle - 1;
               }
           }

           return answer;
       }
   };

Search Insert Position (Easy)
-----------------------------
**Return a target's index or the position where it should be inserted.**

.. code-block:: cpp

   class Solution {
   public:
       int searchInsert(vector<int>& nums, int target) {
           int left = 0;
           int right = static_cast<int>(nums.size());

           while (left < right) {
               int middle = left + (right - left) / 2;

               if (nums[middle] < target) {
                   left = middle + 1;
               } else {
                   right = middle;
               }
           }

           return left;
       }
   };

.. rubric:: ThinkCScpp 4.7: Recursion

Fibonacci Number (Easy)
-----------------------
**Return the requested Fibonacci number using a recursive function.**

.. code-block:: cpp

   class Solution {
   public:
       int fib(int n) {
           if (n < 2) {
               return n;
           }

           return fib(n - 1) + fib(n - 2);
       }
   };

Power of Three (Easy)
---------------------
**Return whether an integer can be reduced to one by repeated division by three.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPowerOfThree(int n) {
           if (n == 1) {
               return true;
           }

           if (n <= 0 || n % 3 != 0) {
               return false;
           }

           return isPowerOfThree(n / 3);
       }
   };

Reverse String (Easy)
---------------------
**Reverse a character array in place.**

.. code-block:: cpp

   class Solution {
   public:
       void reverseString(vector<char>& s) {
           reverseRange(s, 0, static_cast<int>(s.size()) - 1);
       }

   private:
       void reverseRange(vector<char>& s, int left, int right) {
           if (left >= right) {
               return;
           }

           swap(s[left], s[right]);
           reverseRange(s, left + 1, right - 1);
       }
   };

Climbing Stairs (Easy)
----------------------
**Count the distinct ways to reach the top using one-step and two-step moves.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           vector<int> memo(n + 1, -1);
           return countWays(n, memo);
       }

   private:
       int countWays(int n, vector<int>& memo) {
           if (n <= 2) {
               return n;
           }

           if (memo[n] != -1) {
               return memo[n];
           }

           memo[n] = countWays(n - 1, memo) +
                     countWays(n - 2, memo);
           return memo[n];
       }
   };

.. rubric:: ThinkCScpp 4.8: Infinite recursion

Fibonacci Number (Easy)
-----------------------
**Return the requested Fibonacci number using a recursive function.**

.. code-block:: cpp

   class Solution {
   public:
       int fib(int n) {
           if (n < 2) {
               return n;
           }

           return fib(n - 1) + fib(n - 2);
       }
   };

.. rubric:: ThinkCScpp 4.9: Stack diagrams for recursive functions

Fibonacci Number (Easy)
-----------------------
**Return the requested Fibonacci number using a recursive function.**

.. code-block:: cpp

   class Solution {
   public:
       int fib(int n) {
           if (n < 2) {
               return n;
           }

           return fib(n - 1) + fib(n - 2);
       }
   };

Merge Two Sorted Lists (Easy)
-----------------------------
**Recursively merge two sorted linked lists into one sorted list.**

.. code-block:: cpp

   class Solution {
   public:
       ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
           if (list1 == nullptr) {
               return list2;
           }

           if (list2 == nullptr) {
               return list1;
           }

           if (list1->val <= list2->val) {
               list1->next = mergeTwoLists(list1->next, list2);
               return list1;
           }

           list2->next = mergeTwoLists(list1, list2->next);
           return list2;
       }
   };

Same Tree (Easy)
----------------
**Determine recursively whether two binary trees have identical structure and values.**

.. code-block:: cpp

   class Solution {
   public:
       bool isSameTree(TreeNode* p, TreeNode* q) {
           if (p == nullptr || q == nullptr) {
               return p == q;
           }

           return p->val == q->val &&
                  isSameTree(p->left, q->left) &&
                  isSameTree(p->right, q->right);
       }
   };

.. rubric:: RooksGuide 10: Conditionals

Valid Parentheses (Easy)
------------------------
**Determine whether every bracket is closed in the correct order.**

.. code-block:: cpp

   class Solution {
   public:
       bool isValid(string s) {
           stack<char> open;

           for (char symbol : s) {
               if (symbol == '(' || symbol == '[' || symbol == '{') {
                   open.push(symbol);
               } else {
                   if (open.empty() || !matches(open.top(), symbol)) {
                       return false;
                   }

                   open.pop();
               }
           }

           return open.empty();
       }

   private:
       bool matches(char left, char right) {
           return (left == '(' && right == ')') ||
                  (left == '[' && right == ']') ||
                  (left == '{' && right == '}');
       }
   };

Best Time to Buy and Sell Stock (Easy)
--------------------------------------
**Find the greatest profit from one purchase followed by one sale.**

.. code-block:: cpp

   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int lowest = prices[0];
           int best = 0;

           for (int price : prices) {
               lowest = min(lowest, price);
               best = max(best, price - lowest);
           }

           return best;
       }
   };

.. rubric:: RooksGuide 10.1: if, else, and else if

Fizz Buzz (Easy)
----------------
**Return each number as text, replacing multiples of three and five with the required words.**

.. code-block:: cpp

   class Solution {
   public:
       vector<string> fizzBuzz(int n) {
           vector<string> answer;

           for (int i = 1; i <= n; ++i) {
               if (i % 15 == 0) {
                   answer.push_back("FizzBuzz");
               } else if (i % 3 == 0) {
                   answer.push_back("Fizz");
               } else if (i % 5 == 0) {
                   answer.push_back("Buzz");
               } else {
                   answer.push_back(to_string(i));
               }
           }

           return answer;
       }
   };

Lemonade Change (Easy)
----------------------
**Determine whether correct change can be given to every customer in order.**

.. code-block:: cpp

   class Solution {
   public:
       bool lemonadeChange(vector<int>& bills) {
           int fives = 0;
           int tens = 0;

           for (int bill : bills) {
               if (bill == 5) {
                   ++fives;
               } else if (bill == 10) {
                   if (fives == 0) {
                       return false;
                   }

                   --fives;
                   ++tens;
               } else {
                   if (tens > 0 && fives > 0) {
                       --tens;
                       --fives;
                   } else if (fives >= 3) {
                       fives -= 3;
                   } else {
                       return false;
                   }
               }
           }

           return true;
       }
   };

Maximum 69 Number (Easy)
------------------------
**Change at most one digit from six to nine to produce the greatest value.**

.. code-block:: cpp

   class Solution {
   public:
       int maximum69Number(int num) {
           string digits = to_string(num);

           for (char& digit : digits) {
               if (digit == '6') {
                   digit = '9';
                   break;
               }
           }

           return stoi(digits);
       }
   };

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count the divisions and subtractions required to reduce an integer to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;

           while (num > 0) {
               if (num % 2 == 0) {
                   num /= 2;
               } else {
                   --num;
               }

               ++steps;
           }

           return steps;
       }
   };

.. rubric:: RooksGuide 10.1.1: A small digression on expressions

Add Digits (Easy)
-----------------
**Repeatedly sum an integer's digits until only one digit remains.**

.. code-block:: cpp

   class Solution {
   public:
       int addDigits(int num) {
           while (num >= 10) {
               int sum = 0;

               while (num > 0) {
                   sum += num % 10;
                   num /= 10;
               }

               num = sum;
           }

           return num;
       }
   };

Palindrome Number (Easy)
------------------------
**Return whether an integer reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(int x) {
           if (x < 0 || (x % 10 == 0 && x != 0)) {
               return false;
           }

           int reversedHalf = 0;

           while (x > reversedHalf) {
               reversedHalf = reversedHalf * 10 + x % 10;
               x /= 10;
           }

           return x == reversedHalf || x == reversedHalf / 10;
       }
   };

.. rubric:: RooksGuide 10.1.2: Using else

Number of Steps to Reduce a Number to Zero (Easy)
-------------------------------------------------
**Count the divisions and subtractions required to reduce an integer to zero.**

.. code-block:: cpp

   class Solution {
   public:
       int numberOfSteps(int num) {
           int steps = 0;

           while (num > 0) {
               if (num % 2 == 0) {
                   num /= 2;
               } else {
                   --num;
               }

               ++steps;
           }

           return steps;
       }
   };

.. rubric:: RooksGuide 10.2: switch statements

Roman to Integer (Easy)
-----------------------
**Convert a Roman numeral into its integer value.**

.. code-block:: cpp

   class Solution {
   public:
       int romanToInt(string s) {
           int total = 0;

           for (int i = 0; i < static_cast<int>(s.size()); ++i) {
               int value = romanValue(s[i]);

               if (i + 1 < static_cast<int>(s.size()) &&
                   value < romanValue(s[i + 1])) {
                   total -= value;
               } else {
                   total += value;
               }
           }

           return total;
       }

   private:
       int romanValue(char symbol) {
           switch (symbol) {
               case 'I': return 1;
               case 'V': return 5;
               case 'X': return 10;
               case 'L': return 50;
               case 'C': return 100;
               case 'D': return 500;
               case 'M': return 1000;
               default: return 0;
           }
       }
   };

Unit 5 practice problems
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. rubric:: ThinkCScpp 5.1: Return values

Sqrt(x) (Easy)
--------------
**Return the truncated integer square root of a non-negative integer.**

.. code-block:: cpp

   class Solution {
   public:
       int mySqrt(int x) {
           int left = 0;
           int right = x;
           int answer = 0;

           while (left <= right) {
               int middle = left + (right - left) / 2;
               long long square = static_cast<long long>(middle) * middle;

               if (square <= x) {
                   answer = middle;
                   left = middle + 1;
               } else {
                   right = middle - 1;
               }
           }

           return answer;
       }
   };

Add Digits (Easy)
-----------------
**Repeatedly sum an integer's digits until only one digit remains.**

.. code-block:: cpp

   class Solution {
   public:
       int addDigits(int num) {
           while (num >= 10) {
               int sum = 0;

               while (num > 0) {
                   sum += num % 10;
                   num /= 10;
               }

               num = sum;
           }

           return num;
       }
   };

.. rubric:: ThinkCScpp 5.2: Program development

Two Sum (Easy)
--------------
**Return the indexes of two array values whose sum equals the target.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int, int> indexes;

           for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
               int required = target - nums[i];

               if (indexes.count(required)) {
                   return {indexes[required], i};
               }

               indexes[nums[i]] = i;
           }

           return {};
       }
   };

Valid Palindrome (Easy)
-----------------------
**Determine whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = static_cast<int>(s.size()) - 1;

           while (left < right) {
               while (left < right &&
                      !isalnum(static_cast<unsigned char>(s[left]))) {
                   ++left;
               }

               while (left < right &&
                      !isalnum(static_cast<unsigned char>(s[right]))) {
                   --right;
               }

               if (tolower(static_cast<unsigned char>(s[left])) !=
                   tolower(static_cast<unsigned char>(s[right]))) {
                   return false;
               }

               ++left;
               --right;
           }

           return true;
       }
   };

Best Time to Buy and Sell Stock (Easy)
--------------------------------------
**Find the greatest profit from one purchase followed by one sale.**

.. code-block:: cpp

   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int lowest = prices[0];
           int best = 0;

           for (int price : prices) {
               lowest = min(lowest, price);
               best = max(best, price - lowest);
           }

           return best;
       }
   };

Valid Anagram (Easy)
--------------------
**Determine whether two strings contain identical character counts.**

.. code-block:: cpp

   class Solution {
   public:
       bool isAnagram(string s, string t) {
           if (s.size() != t.size()) {
               return false;
           }

           array<int, 26> counts{};

           for (char character : s) {
               ++counts[character - 'a'];
           }

           for (char character : t) {
               --counts[character - 'a'];
           }

           for (int count : counts) {
               if (count != 0) {
                   return false;
               }
           }

           return true;
       }
   };

.. rubric:: ThinkCScpp 5.3: Composition

Happy Number (Easy)
-------------------
**Determine whether repeatedly summing squared digits eventually reaches one.**

.. code-block:: cpp

   class Solution {
   public:
       bool isHappy(int n) {
           unordered_set<int> seen;

           while (n != 1 && !seen.count(n)) {
               seen.insert(n);
               n = digitSquareSum(n);
           }

           return n == 1;
       }

   private:
       int digitSquareSum(int n) {
           int sum = 0;

           while (n > 0) {
               int digit = n % 10;
               sum += digit * digit;
               n /= 10;
           }

           return sum;
       }
   };

Palindrome Number (Easy)
------------------------
**Return whether an integer reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(int x) {
           if (x < 0 || (x % 10 == 0 && x != 0)) {
               return false;
           }

           int reversedHalf = 0;

           while (x > reversedHalf) {
               reversedHalf = reversedHalf * 10 + x % 10;
               x /= 10;
           }

           return x == reversedHalf || x == reversedHalf / 10;
       }
   };

.. rubric:: ThinkCScpp 5.4: Overloading

Pow(x, n) (Medium)
------------------
**Calculate a floating-point base raised to an integer exponent.**

.. code-block:: cpp

   class Solution {
   public:
       double myPow(double x, int n) {
           return power(x, static_cast<long long>(n));
       }

   private:
       double power(double x, long long n) {
           if (n == 0) {
               return 1.0;
           }

           if (n < 0) {
               return 1.0 / power(x, -n);
           }

           double half = power(x, n / 2);

           if (n % 2 == 0) {
               return half * half;
           }

           return half * half * x;
       }
   };

.. rubric:: ThinkCScpp 5.5: Boolean values

Power of Four (Easy)
--------------------
**Return whether an integer is an exact power of four.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPowerOfFour(int n) {
           if (n <= 0) {
               return false;
           }

           while (n % 4 == 0) {
               n /= 4;
           }

           return n == 1;
       }
   };

Valid Anagram (Easy)
--------------------
**Determine whether two strings contain identical character counts.**

.. code-block:: cpp

   class Solution {
   public:
       bool isAnagram(string s, string t) {
           if (s.size() != t.size()) {
               return false;
           }

           array<int, 26> counts{};

           for (char character : s) {
               ++counts[character - 'a'];
           }

           for (char character : t) {
               --counts[character - 'a'];
           }

           for (int count : counts) {
               if (count != 0) {
                   return false;
               }
           }

           return true;
       }
   };

Contains Duplicate (Easy)
-------------------------
**Return whether any integer appears more than once in an array.**

.. code-block:: cpp

   class Solution {
   public:
       bool containsDuplicate(vector<int>& nums) {
           unordered_set<int> seen;

           for (int value : nums) {
               if (!seen.insert(value).second) {
                   return true;
               }
           }

           return false;
       }
   };

.. rubric:: ThinkCScpp 5.6: Boolean variables

Happy Number (Easy)
-------------------
**Determine whether repeatedly summing squared digits eventually reaches one.**

.. code-block:: cpp

   class Solution {
   public:
       bool isHappy(int n) {
           unordered_set<int> seen;

           while (n != 1 && !seen.count(n)) {
               seen.insert(n);
               n = digitSquareSum(n);
           }

           return n == 1;
       }

   private:
       int digitSquareSum(int n) {
           int sum = 0;

           while (n > 0) {
               int digit = n % 10;
               sum += digit * digit;
               n /= 10;
           }

           return sum;
       }
   };

Valid Parentheses (Easy)
------------------------
**Determine whether every bracket is closed in the correct order.**

.. code-block:: cpp

   class Solution {
   public:
       bool isValid(string s) {
           stack<char> open;

           for (char symbol : s) {
               if (symbol == '(' || symbol == '[' || symbol == '{') {
                   open.push(symbol);
               } else {
                   if (open.empty() || !matches(open.top(), symbol)) {
                       return false;
                   }

                   open.pop();
               }
           }

           return open.empty();
       }

   private:
       bool matches(char left, char right) {
           return (left == '(' && right == ')') ||
                  (left == '[' && right == ']') ||
                  (left == '{' && right == '}');
       }
   };

.. rubric:: ThinkCScpp 5.7: Logical operators

Check if One String Swap Can Make Strings Equal (Easy)
------------------------------------------------------
**Determine whether two strings can match after at most one swap.**

.. code-block:: cpp

   class Solution {
   public:
       bool areAlmostEqual(string s1, string s2) {
           vector<int> differences;

           for (int i = 0; i < static_cast<int>(s1.size()); ++i) {
               if (s1[i] != s2[i]) {
                   differences.push_back(i);
               }
           }

           return differences.empty() ||
                  (differences.size() == 2 &&
                   s1[differences[0]] == s2[differences[1]] &&
                   s1[differences[1]] == s2[differences[0]]);
       }
   };

Valid Palindrome (Easy)
-----------------------
**Determine whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = static_cast<int>(s.size()) - 1;

           while (left < right) {
               while (left < right &&
                      !isalnum(static_cast<unsigned char>(s[left]))) {
                   ++left;
               }

               while (left < right &&
                      !isalnum(static_cast<unsigned char>(s[right]))) {
                   --right;
               }

               if (tolower(static_cast<unsigned char>(s[left])) !=
                   tolower(static_cast<unsigned char>(s[right]))) {
                   return false;
               }

               ++left;
               --right;
           }

           return true;
       }
   };

Valid Perfect Square (Easy)
---------------------------
**Return whether an integer is the square of another integer.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPerfectSquare(int num) {
           long long left = 1;
           long long right = num;

           while (left <= right) {
               long long middle = left + (right - left) / 2;
               long long square = middle * middle;

               if (square == num) {
                   return true;
               }

               if (square < num) {
                   left = middle + 1;
               } else {
                   right = middle - 1;
               }
           }

           return false;
       }
   };

Is Subsequence (Easy)
---------------------
**Determine whether one string's characters appear in another in the same order.**

.. code-block:: cpp

   class Solution {
   public:
       bool isSubsequence(string s, string t) {
           int matched = 0;

           for (char character : t) {
               if (matched < static_cast<int>(s.size()) &&
                   s[matched] == character) {
                   ++matched;
               }
           }

           return matched == static_cast<int>(s.size());
       }
   };

.. rubric:: ThinkCScpp 5.8: Bool functions

Power of Two (Easy)
-------------------
**Return whether an integer is an exact power of two.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPowerOfTwo(int n) {
           return n > 0 && (n & (n - 1)) == 0;
       }
   };

Is Subsequence (Easy)
---------------------
**Determine whether one string's characters appear in another in the same order.**

.. code-block:: cpp

   class Solution {
   public:
       bool isSubsequence(string s, string t) {
           int matched = 0;

           for (char character : t) {
               if (matched < static_cast<int>(s.size()) &&
                   s[matched] == character) {
                   ++matched;
               }
           }

           return matched == static_cast<int>(s.size());
       }
   };

Valid Perfect Square (Easy)
---------------------------
**Return whether an integer is the square of another integer.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPerfectSquare(int num) {
           long long left = 1;
           long long right = num;

           while (left <= right) {
               long long middle = left + (right - left) / 2;
               long long square = middle * middle;

               if (square == num) {
                   return true;
               }

               if (square < num) {
                   left = middle + 1;
               } else {
                   right = middle - 1;
               }
           }

           return false;
       }
   };

.. rubric:: ThinkCScpp 5.9: Returning from main

Find the Difference (Easy)
--------------------------
**Return the extra character added to the second string.**

.. code-block:: cpp

   class Solution {
   public:
       char findTheDifference(string s, string t) {
           char difference = 0;

           for (char character : s) {
               difference ^= character;
           }

           for (char character : t) {
               difference ^= character;
           }

           return difference;
       }
   };

.. rubric:: ThinkCScpp 5.10: More recursion

Climbing Stairs (Easy)
----------------------
**Count the distinct ways to reach the top using one-step and two-step moves.**

.. code-block:: cpp

   class Solution {
   public:
       int climbStairs(int n) {
           vector<int> memo(n + 1, -1);
           return countWays(n, memo);
       }

   private:
       int countWays(int n, vector<int>& memo) {
           if (n <= 2) {
               return n;
           }

           if (memo[n] != -1) {
               return memo[n];
           }

           memo[n] = countWays(n - 1, memo) +
                     countWays(n - 2, memo);
           return memo[n];
       }
   };

Pow(x, n) (Medium)
------------------
**Calculate a floating-point base raised to an integer exponent.**

.. code-block:: cpp

   class Solution {
   public:
       double myPow(double x, int n) {
           return power(x, static_cast<long long>(n));
       }

   private:
       double power(double x, long long n) {
           if (n == 0) {
               return 1.0;
           }

           if (n < 0) {
               return 1.0 / power(x, -n);
           }

           double half = power(x, n / 2);

           if (n % 2 == 0) {
               return half * half;
           }

           return half * half * x;
       }
   };

Merge Two Sorted Lists (Easy)
-----------------------------
**Recursively merge two sorted linked lists into one sorted list.**

.. code-block:: cpp

   class Solution {
   public:
       ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
           if (list1 == nullptr) {
               return list2;
           }

           if (list2 == nullptr) {
               return list1;
           }

           if (list1->val <= list2->val) {
               list1->next = mergeTwoLists(list1->next, list2);
               return list1;
           }

           list2->next = mergeTwoLists(list1, list2->next);
           return list2;
       }
   };

.. rubric:: ThinkCScpp 5.11: Leap of faith

Same Tree (Easy)
----------------
**Determine recursively whether two binary trees have identical structure and values.**

.. code-block:: cpp

   class Solution {
   public:
       bool isSameTree(TreeNode* p, TreeNode* q) {
           if (p == nullptr || q == nullptr) {
               return p == q;
           }

           return p->val == q->val &&
                  isSameTree(p->left, q->left) &&
                  isSameTree(p->right, q->right);
       }
   };

Invert Binary Tree (Easy)
-------------------------
**Recursively swap the left and right children of every tree node.**

.. code-block:: cpp

   class Solution {
   public:
       TreeNode* invertTree(TreeNode* root) {
           if (root == nullptr) {
               return nullptr;
           }

           TreeNode* left = invertTree(root->left);
           TreeNode* right = invertTree(root->right);
           root->left = right;
           root->right = left;

           return root;
       }
   };

.. rubric:: ThinkCScpp 5.12: One more example

Pascal's Triangle II (Easy)
---------------------------
**Return a selected row from Pascal's triangle.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> getRow(int rowIndex) {
           vector<int> row(rowIndex + 1, 1);

           for (int i = 1; i < rowIndex; ++i) {
               for (int j = i; j > 0; --j) {
                   row[j] += row[j - 1];
               }
           }

           return row;
       }
   };

Reverse Linked List (Easy)
--------------------------
**Reverse a singly linked list and return its new head.**

.. code-block:: cpp

   class Solution {
   public:
       ListNode* reverseList(ListNode* head) {
           if (head == nullptr || head->next == nullptr) {
               return head;
           }

           ListNode* newHead = reverseList(head->next);
           head->next->next = head;
           head->next = nullptr;

           return newHead;
       }
   };

Fibonacci Number (Easy)
-----------------------
**Return the requested Fibonacci number using a recursive function.**

.. code-block:: cpp

   class Solution {
   public:
       int fib(int n) {
           if (n < 2) {
               return n;
           }

           return fib(n - 1) + fib(n - 2);
       }
   };

Power of Three (Easy)
---------------------
**Return whether an integer can be reduced to one by repeated division by three.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPowerOfThree(int n) {
           if (n == 1) {
               return true;
           }

           if (n <= 0 || n % 3 != 0) {
               return false;
           }

           return isPowerOfThree(n / 3);
       }
   };

Unit 6 practice problems
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. rubric:: ThinkCScpp 6.1: Multiple assignment

Reverse String (Easy)
---------------------
**Reverse a character array in place.**

.. code-block:: cpp

   class Solution {
   public:
       void reverseString(vector<char>& s) {
           reverseRange(s, 0, static_cast<int>(s.size()) - 1);
       }

   private:
       void reverseRange(vector<char>& s, int left, int right) {
           if (left >= right) {
               return;
           }

           swap(s[left], s[right]);
           reverseRange(s, left + 1, right - 1);
       }
   };

Move Zeroes (Easy)
------------------
**Move all zero values to the end while preserving other values' order.**

.. code-block:: cpp

   class Solution {
   public:
       void moveZeroes(vector<int>& nums) {
           int nextNonZero = 0;

           for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
               if (nums[i] != 0) {
                   swap(nums[nextNonZero], nums[i]);
                   ++nextNonZero;
               }
           }
       }
   };

.. rubric:: ThinkCScpp 6.2: Iteration

Running Sum of 1d Array (Easy)
------------------------------
**Replace each array element with the sum of itself and all earlier elements.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> runningSum(vector<int>& nums) {
           for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
               nums[i] += nums[i - 1];
           }

           return nums;
       }
   };

Best Time to Buy and Sell Stock (Easy)
--------------------------------------
**Find the greatest profit from one purchase followed by one sale.**

.. code-block:: cpp

   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int lowest = prices[0];
           int best = 0;

           for (int price : prices) {
               lowest = min(lowest, price);
               best = max(best, price - lowest);
           }

           return best;
       }
   };

Contains Duplicate (Easy)
-------------------------
**Return whether any integer appears more than once in an array.**

.. code-block:: cpp

   class Solution {
   public:
       bool containsDuplicate(vector<int>& nums) {
           unordered_set<int> seen;

           for (int value : nums) {
               if (!seen.insert(value).second) {
                   return true;
               }
           }

           return false;
       }
   };

Maximum Subarray (Medium)
-------------------------
**Return the greatest sum among all contiguous subarrays.**

.. code-block:: cpp

   class Solution {
   public:
       int maxSubArray(vector<int>& nums) {
           int current = nums[0];
           int best = nums[0];

           for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
               current = max(nums[i], current + nums[i]);
               best = max(best, current);
           }

           return best;
       }
   };

.. rubric:: ThinkCScpp 6.3: The while statement

Binary Search (Easy)
--------------------
**Return the index of a target in a sorted array or negative one when absent.**

.. code-block:: cpp

   class Solution {
   public:
       int search(vector<int>& nums, int target) {
           int left = 0;
           int right = static_cast<int>(nums.size()) - 1;

           while (left <= right) {
               int middle = left + (right - left) / 2;

               if (nums[middle] == target) {
                   return middle;
               }

               if (nums[middle] < target) {
                   left = middle + 1;
               } else {
                   right = middle - 1;
               }
           }

           return -1;
       }
   };

Palindrome Number (Easy)
------------------------
**Return whether an integer reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(int x) {
           if (x < 0 || (x % 10 == 0 && x != 0)) {
               return false;
           }

           int reversedHalf = 0;

           while (x > reversedHalf) {
               reversedHalf = reversedHalf * 10 + x % 10;
               x /= 10;
           }

           return x == reversedHalf || x == reversedHalf / 10;
       }
   };

Sqrt(x) (Easy)
--------------
**Return the truncated integer square root of a non-negative integer.**

.. code-block:: cpp

   class Solution {
   public:
       int mySqrt(int x) {
           int left = 0;
           int right = x;
           int answer = 0;

           while (left <= right) {
               int middle = left + (right - left) / 2;
               long long square = static_cast<long long>(middle) * middle;

               if (square <= x) {
                   answer = middle;
                   left = middle + 1;
               } else {
                   right = middle - 1;
               }
           }

           return answer;
       }
   };

Happy Number (Easy)
-------------------
**Determine whether repeatedly summing squared digits eventually reaches one.**

.. code-block:: cpp

   class Solution {
   public:
       bool isHappy(int n) {
           unordered_set<int> seen;

           while (n != 1 && !seen.count(n)) {
               seen.insert(n);
               n = digitSquareSum(n);
           }

           return n == 1;
       }

   private:
       int digitSquareSum(int n) {
           int sum = 0;

           while (n > 0) {
               int digit = n % 10;
               sum += digit * digit;
               n /= 10;
           }

           return sum;
       }
   };

.. rubric:: ThinkCScpp 6.4: Tables

Fizz Buzz (Easy)
----------------
**Return each number as text, replacing multiples of three and five with the required words.**

.. code-block:: cpp

   class Solution {
   public:
       vector<string> fizzBuzz(int n) {
           vector<string> answer;

           for (int i = 1; i <= n; ++i) {
               if (i % 15 == 0) {
                   answer.push_back("FizzBuzz");
               } else if (i % 3 == 0) {
                   answer.push_back("Fizz");
               } else if (i % 5 == 0) {
                   answer.push_back("Buzz");
               } else {
                   answer.push_back(to_string(i));
               }
           }

           return answer;
       }
   };

Pascal's Triangle (Easy)
------------------------
**Generate the requested number of rows from Pascal's triangle.**

.. code-block:: cpp

   class Solution {
   public:
       vector<vector<int>> generate(int numRows) {
           vector<vector<int>> triangle;

           for (int row = 0; row < numRows; ++row) {
               triangle.push_back(vector<int>(row + 1, 1));

               for (int column = 1; column < row; ++column) {
                   triangle[row][column] =
                       triangle[row - 1][column - 1] +
                       triangle[row - 1][column];
               }
           }

           return triangle;
       }
   };

.. rubric:: ThinkCScpp 6.5: Two-dimensional tables

Richest Customer Wealth (Easy)
------------------------------
**Find the greatest row sum in a two-dimensional integer array.**

.. code-block:: cpp

   class Solution {
   public:
       int maximumWealth(vector<vector<int>>& accounts) {
           int richest = 0;

           for (const vector<int>& customer : accounts) {
               int wealth = 0;

               for (int account : customer) {
                   wealth += account;
               }

               richest = max(richest, wealth);
           }

           return richest;
       }
   };

Matrix Diagonal Sum (Easy)
--------------------------
**Sum both diagonals of a square matrix without counting the centre twice.**

.. code-block:: cpp

   class Solution {
   public:
       int diagonalSum(vector<vector<int>>& mat) {
           int total = 0;
           int size = static_cast<int>(mat.size());

           for (int row = 0; row < size; ++row) {
               total += mat[row][row];

               int opposite = size - row - 1;
               if (opposite != row) {
                   total += mat[row][opposite];
               }
           }

           return total;
       }
   };

Transpose Matrix (Easy)
-----------------------
**Return a matrix with its rows and columns exchanged.**

.. code-block:: cpp

   class Solution {
   public:
       vector<vector<int>> transpose(vector<vector<int>>& matrix) {
           int rows = static_cast<int>(matrix.size());
           int columns = static_cast<int>(matrix[0].size());
           vector<vector<int>> result(columns, vector<int>(rows));

           for (int row = 0; row < rows; ++row) {
               for (int column = 0; column < columns; ++column) {
                   result[column][row] = matrix[row][column];
               }
           }

           return result;
       }
   };

.. rubric:: ThinkCScpp 6.6: Encapsulation and generalization

Merge Sorted Array (Easy)
-------------------------
**Merge two sorted arrays into the first array without using extra output storage.**

.. code-block:: cpp

   class Solution {
   public:
       void merge(vector<int>& nums1, int m,
                  vector<int>& nums2, int n) {
           int first = m - 1;
           int second = n - 1;
           int destination = m + n - 1;

           while (second >= 0) {
               if (first >= 0 && nums1[first] > nums2[second]) {
                   nums1[destination--] = nums1[first--];
               } else {
                   nums1[destination--] = nums2[second--];
               }
           }
       }
   };

Two Sum (Easy)
--------------
**Return the indexes of two array values whose sum equals the target.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int, int> indexes;

           for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
               int required = target - nums[i];

               if (indexes.count(required)) {
                   return {indexes[required], i};
               }

               indexes[nums[i]] = i;
           }

           return {};
       }
   };

.. rubric:: ThinkCScpp 6.7: Functions

Design Parking System (Easy)
----------------------------
**Implement methods that track whether each parking-space type has capacity.**

.. code-block:: cpp

   class ParkingSystem {
   public:
       ParkingSystem(int big, int medium, int small)
           : spaces{0, big, medium, small} {
       }

       bool addCar(int carType) {
           if (spaces[carType] == 0) {
               return false;
           }

           --spaces[carType];
           return true;
       }

   private:
       array<int, 4> spaces;
   };

Min Cost Climbing Stairs (Easy)
-------------------------------
**Return the minimum cost required to move beyond the top stair.**

.. code-block:: cpp

   class Solution {
   public:
       int minCostClimbingStairs(vector<int>& cost) {
           int twoBack = 0;
           int oneBack = 0;

           for (int value : cost) {
               int current = value + min(oneBack, twoBack);
               twoBack = oneBack;
               oneBack = current;
           }

           return min(oneBack, twoBack);
       }
   };

Search Insert Position (Easy)
-----------------------------
**Return a target's index or the position where it should be inserted.**

.. code-block:: cpp

   class Solution {
   public:
       int searchInsert(vector<int>& nums, int target) {
           int left = 0;
           int right = static_cast<int>(nums.size());

           while (left < right) {
               int middle = left + (right - left) / 2;

               if (nums[middle] < target) {
                   left = middle + 1;
               } else {
                   right = middle;
               }
           }

           return left;
       }
   };

.. rubric:: ThinkCScpp 6.8: More encapsulation

Valid Palindrome (Easy)
-----------------------
**Determine whether normalized text reads the same forward and backward.**

.. code-block:: cpp

   class Solution {
   public:
       bool isPalindrome(string s) {
           int left = 0;
           int right = static_cast<int>(s.size()) - 1;

           while (left < right) {
               while (left < right &&
                      !isalnum(static_cast<unsigned char>(s[left]))) {
                   ++left;
               }

               while (left < right &&
                      !isalnum(static_cast<unsigned char>(s[right]))) {
                   --right;
               }

               if (tolower(static_cast<unsigned char>(s[left])) !=
                   tolower(static_cast<unsigned char>(s[right]))) {
                   return false;
               }

               ++left;
               --right;
           }

           return true;
       }
   };

Is Subsequence (Easy)
---------------------
**Determine whether one string's characters appear in another in the same order.**

.. code-block:: cpp

   class Solution {
   public:
       bool isSubsequence(string s, string t) {
           int matched = 0;

           for (char character : t) {
               if (matched < static_cast<int>(s.size()) &&
                   s[matched] == character) {
                   ++matched;
               }
           }

           return matched == static_cast<int>(s.size());
       }
   };

.. rubric:: ThinkCScpp 6.9: Local variables

Running Sum of 1d Array (Easy)
------------------------------
**Replace each array element with the sum of itself and all earlier elements.**

.. code-block:: cpp

   class Solution {
   public:
       vector<int> runningSum(vector<int>& nums) {
           for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
               nums[i] += nums[i - 1];
           }

           return nums;
       }
   };

.. rubric:: ThinkCScpp 6.10: More generalization

Search Insert Position (Easy)
-----------------------------
**Return a target's index or the position where it should be inserted.**

.. code-block:: cpp

   class Solution {
   public:
       int searchInsert(vector<int>& nums, int target) {
           int left = 0;
           int right = static_cast<int>(nums.size());

           while (left < right) {
               int middle = left + (right - left) / 2;

               if (nums[middle] < target) {
                   left = middle + 1;
               } else {
                   right = middle;
               }
           }

           return left;
       }
   };

Maximum Subarray (Medium)
-------------------------
**Return the greatest sum among all contiguous subarrays.**

.. code-block:: cpp

   class Solution {
   public:
       int maxSubArray(vector<int>& nums) {
           int current = nums[0];
           int best = nums[0];

           for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
               current = max(nums[i], current + nums[i]);
               best = max(best, current);
           }

           return best;
       }
   };

Move Zeroes (Easy)
------------------
**Move all zero values to the end while preserving other values' order.**

.. code-block:: cpp

   class Solution {
   public:
       void moveZeroes(vector<int>& nums) {
           int nextNonZero = 0;

           for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
               if (nums[i] != 0) {
                   swap(nums[nextNonZero], nums[i]);
                   ++nextNonZero;
               }
           }
       }
   };


Reference
---------
LeetCode. (n.d.). *LeetCode*. Retrieved Jan 2025 - Aug 2026, from https://leetcode.com/

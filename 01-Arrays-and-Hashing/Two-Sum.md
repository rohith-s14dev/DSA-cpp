# Two Sum — LeetCode 1

**Topic:** Arrays & Hashing  
**Difficulty:** Easy  
**Technique:** Hash map  
**Language:** C++20

## 1. Problem summary

Given an integer array `nums` and an integer `target`, return the indices of two distinct elements whose values add up to `target`.

Assume exactly one valid answer exists, and the same element cannot be used twice.

Problem: https://leetcode.com/problems/two-sum/

## 2. Example

**Input**
```text
nums = [2, 7, 11, 15], target = 9
```

**Output**
```text
[0, 1]
```

Because `nums[0] + nums[1] = 2 + 7 = 9`.

## 3. Approach

For each number `nums[i]`, calculate the value needed to reach the target:

```cpp
required = target - nums[i];
```

Maintain an `unordered_map` from a number to the index where it was first seen.

1. Look for `required` in the map.
2. If it exists, return its stored index and the current index.
3. Otherwise, store `nums[i]` and `i` in the map.

We search before inserting the current number. This prevents using the same array element twice.

## 4. C++20 solution

The complete runnable program is in [solutions/two_sum.cpp](../solutions/two_sum.cpp).

Core LeetCode-style implementation:

```cpp
class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> index_by_value;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const int required = target - nums[i];
            const auto it = index_by_value.find(required);

            if (it != index_by_value.end()) {
                return {it->second, i};
            }

            index_by_value.emplace(nums[i], i);
        }

        return {};
    }
};
```

## 5. Dry run

For `nums = [2, 7, 11, 15]`, `target = 9`:

| Index | Current value | Required value | Map before lookup | Result |
|---:|---:|---:|---|---|
| 0 | 2 | 7 | empty | Not found; store 2 → 0 |
| 1 | 7 | 2 | {2 → 0} | Found; return [0, 1] |

## 6. Complexity

Let `n` be the number of elements.

- **Time:** O(n) average, because each hash-map lookup and insertion is O(1) average.
- **Extra space:** O(n), because the map can store up to n elements.

Hash-table operations have O(n) worst-case behavior for an individual operation, so the linear-time claim is an average-case analysis.

## 7. Edge cases to consider

- Negative numbers, e.g. `[-3, 4]`, target `1`.
- Duplicate values, e.g. `[3, 3]`, target `6`.
- The answer uses two different indices.
- A solution near the beginning or end of the array.

## 8. Interview follow-ups

1. What is the brute-force solution and its O(n²) time complexity?
2. Why use `unordered_map` instead of `map`?
3. Why do we search before inserting the current value?
4. How would you return all unique pairs instead of one pair?
5. What are hash collisions, and how does `unordered_map` handle them?

## 9. Key takeaway

Hashing trades extra memory for faster average lookup. The important interview habit is to identify what information must be remembered while scanning the input once.
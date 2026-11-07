#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> index_by_value;
        index_by_value.reserve(nums.size());

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

int main() {
    const std::vector<int> nums{2, 7, 11, 15};
    constexpr int target = 9;

    const Solution solution;
    const std::vector<int> result = solution.twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "[" << result[0] << ", " << result[1] << "]\n";
    } else {
        std::cout << "No pair found\n";
    }

    return 0;
}
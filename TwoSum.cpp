class Solution {
public:
    // **Logic/Intuition Section**
    // 1. Problem ka goal yeh hai ki array mein do indices dhoondein jinka sum "target" ke equal ho.
    // 2. Efficient approach ke liye ek unordered_map (hash map) use karte hain:
    //    - Map mein har element ko key banake uska index store karte hain.
    // 3. Har element ke liye, uska complement nikalte hain: "compliment = target - nums[i]".
    // 4. Agar complement map mein pehle se hai, toh indices return kar dete hain.
    // 5. Nahi mila toh current element ko map mein daal dete hain for future checks.
    // 6. Yeh approach O(n) time complexity mein kaam karta hai kyunki har element ek baar hi process hota hai.

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // Hash map to store elements and their indices

        // Loop through the array
        for (int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i]; // Calculate complement

            // Check if the complement exists in the map
            if (map.find(compliment) != map.end()) {
                return {map[compliment], i}; // Return indices if found
            }

            // Store current element and its index in the map
            map[nums[i]] = i;
        }

        return {}; // Return empty if no solution is found
    }
};

// **Sample Output**
// nums = [2, 7, 11, 15], target = 9
// Complement for 2: 9 - 2 = 7 (found in map), return indices {0, 1}


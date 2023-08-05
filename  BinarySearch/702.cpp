// 702. Search in a Sorted Array of Unknown Size

// ref: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/solutions/3696477/simple-binary-search-with-sliding-window-approach/

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class ArrayReader
{
public:
    int get(int index);
};

class Solution
{
public:
    int search(const ArrayReader &reader, int target)
    {
        if (reader.get(0) == target)
            return 0;
        if (reader.get(1) == target)
            return 1;
        int left = 0, right = 1;
        while (left <= right) // find the right boundary
        {
            
            if (reader.get(right) < target)      // target is in the right half
            {
                left = right;
                right = right * 2;
            }
            else if (target <= reader.get(right)) // target is in the left half
            {
                int mid = left + (right - left) / 2;
                if (reader.get(mid) == target) // found the target
                    return mid;                    
                else if (reader.get(mid) < target) // target is in the right half
                    left = mid + 1;             
                else                           // target is in the left half
                    right = mid - 1;
            }
        }
        return -1;
    }
};
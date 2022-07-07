# [Two Sum : Easy](https://leetcode.com/problems/two-sum)


### Solution 01:
-   Take 2 for loops: i will start from 0 & j will start from i+1  _**(i=0, j=i+1)**_
-   Simply we’ll add nums[i] & nums[j], if they are equal to target we’ll push i, j to our ans vector.
-   Finally we’ll return the ans vector.
-   **Time complexity:  O(n^2^)**

### Solution 02:
-   We take an unordered_map to store the elements.
-   We iterate every element and if any point we find (target-current element) present in the map, then we’ll simply return the value of find element in the map & index of the current element.
-   If the value is not present in the map, then we’ll insert the value with its index. `(map[nums[i]] = i)`
-   As per the question, each input would have _exactly_ one solution, so we simply return { } at the end.
-   **Time complexity:  O(n)**

### Difference btw find and count function in map!

-   Since a map can only have at most one key, count will essentially stop after one element has been found. However, in view of more general containers such as multimaps and multisets, find is strictly better if you only care whether some element with this key exists, since it can really stop once the first matching element has been found.
-   In general, both count and find will use the container-specific lookup methods (tree traversal or hash table lookup), which are always fairly efficient. It's just that count has to continue iterating until the end of the equal-range, whereas find does not. Moreover, your code should document intent, so if you want to find something, use find.
<br>

# [Best Time to Buy and Sell Stock : Easy](https://leetcode.com/problems/best-time-to-buy-and-sell-stock)

- For each i, find the max element in (i+1, n). 
- `ans = max(ans, max_elem - i)`
### Time Complexity : ***O(n)***
### Space Complexity : ***O(n)***
<br>

# [Contains Duplicate : Easy](https://leetcode.com/problems/contains-duplicate)

- Insert all elements in unordered set.
- `if (set.size() == n) return true;`
### Time Complexity : ***O(n)***
### Space Complexity : ***O(n)***
<br>

# [Product of Array Except Self : Medium](https://leetcode.com/problems/product-of-array-except-self)

We can simply calculate product of the whole array and for each element in  `nums`, divide the product by  `nums[i]`. This effectively leaves us with product of whole array except self at each index. We need to take care of zeros that may occur in the array -

**1.**  If there are more than one  `0`s in  `nums`, the result is an array consisting of all  `0`.  
**2.**  If there is a single  `0`  in  `nums`, then the result is an array consisting of all  `0`  except at the index where there was  `0`  in  `nums`, which will contain product of rest of array.  
**3.**  If there's no  `0`  in  `nums`, then the result is an array  `ans`  where  `ans[i] = prod / nums[i]`  (`prod = product of all elements in nums`).
### Time Complexity : ***O(n)***
### Space Complexity : ***O(1)***
<br>

# [Maximum Subarray : Medium](https://leetcode.com/problems/maximum-subarray/)

### Kadane's Algorithm

We only need to maintain  `curMax`  which is the maximum subarray sum ending at  `i`  and  `maxTillNow`  which is the maximum sum we have seen till now. 
### Time Complexity : ***O(n)***
### Space Complexity : ***O(1)***
<br>

# [Maximum Product Subarray : Medium](https://leetcode.com/problems/maximum-product-subarray/)

### Space Optimized DP

`dpMax[i] = denotes maximum subarray product ending at i and  
 dpMin[i] =  denotes minimum subarray product ending at i `

At each index  `i`, we will update  `dpMin[i]`  as minimum of  `a[i]`  (denotes forming new subarray by choosing current element) and  `min(a[i] * dpMin[i-1], a[i] * dpMax[i-1])`  (denotes expanding previous subarray product by including current element). We do it similarly for  `dpMax[i]`  as well. Finally, the maximum product subarray will be the maximum value in  `dpMax`  array.
### Time Complexity : ***O(n)***
### Space Complexity : ***O(1)***
<br>

# [Find Minimum in Rotated Sorted Array : Medium](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

### Binary Search


Looking at subarray with index [start,end]. We can find out that if the first member is less than the last member, there's no rotation in the array. So we could directly return the first element in this subarray.

If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element. If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. Else, it is in the first half in the array.
### Time Complexity : ***O(logn)***
### Space Complexity : ***O(1)***
<br>

# [Search in Rotated Sorted Array : Medium](https://leetcode.com/problems/search-in-rotated-sorted-array/)

### Binary Search
- Find pos of roatation.
- Binary search with account for rotation.
### Time Complexity : ***O(logn)***
### Space Complexity : ***O(1)***
<br>

# [3Sum : Medium](https://leetcode.com/problems/3Sum/)

- We fix the `1st` number, the `2nd` and `3rd` number can be found following the same reasoning as `TwoSum`.
- Use hash map for not counting duplicates.
### Time Complexity : ***O(n^2^)***
### Space Complexity : ***O(n)***
<br>




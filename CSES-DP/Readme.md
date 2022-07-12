# [Dice Combinations](https://cses.fi/problemset/task/1633)

### `dp[i] = # of ways of making sum i using numbers from 1 to 6`
Initialize by dp[0] = 1, as there is one way with sum 0 (the empty set).
### Time Complexity : ***O(n)***  
<br>

# [Minimizing Coins](https://cses.fi/problemset/task/1634)

### `dp[i] = minimum number of coins with sum i`
We look at the last coin added to get sum x, say it has value v. We need dp[i-v] coins to get value i-v, and 1 coin for value v. Therefore we need dp[i-v]+1 coins if we are to use a coin with value v. Checking all possibilities for v must include the optimal choice of last coin.

As an implementation detail, we use `dp[i] = 1e9` to signify that it is not possible to make value x with the given coins.
### Time Complexity : ***O(n . x)***   
<br>

# [Coin Combinations I](https://cses.fi/problemset/task/1635)

### `dp[i] = # of ways to make value i`
We initialize dp[0] = 1, as the empty set is the only way to make 0.

Like in "Minimizing Coins", we loop over the possibilities for last coin added. There are dp[i-v] ways to make i, when adding a coin with value v last. This is since we can choose any combination for the first coins to sum to i-v, but need to choose v as the last coin. Summing over all the possibilities for v gives dp[i].
### Time Complexity : ***O(n . x)***   
<br>

# [Coin Combinations II](https://cses.fi/problemset/task/1636)

### `dp[i][j] = # of ways to make sum j using the first i coins`
Initially, we say we have dp[0][0] = 1, i.e we have the empty set with sum zero.

When calculating dp[i][j], we consider the i'th coin. Either we didn't pick the coin, then there are dp[i-1][j] possibilities. 
Otherwise, we picked the coin. Since we are allowed to pick it again, there are dp[i][j-a[i]] possibilities (not dp[i-1][j-a[i]] possibilities).

Because we consider the coins in order, we will only count one order of coins.
### Time Complexity : ***O(n . x)***   
<br>

# [Removing Digits](https://cses.fi/problemset/task/1637)

### `dp[i] = minimum # of operations to go from i to 0`
When considering a number i, for each digit in the decimal representation of i, we can try to remove it. The transition is therefore: dp[i] = min<sub>d∈digits(i)</sub> dp[i-d]. 
We initialize dp[0] = 0.
### Time Complexity : ***O(n)***   
<br>

# [Grid Paths](https://cses.fi/problemset/task/1638)

### `dp[i][j] = # of ways to reach row i and col j`
We say there is one way to reach (0,0), dp[0][0] = 1.

When we are at some position with `a[i] = .`, we came either from the left or top. So the number of ways to get to there is the number of ways to get to the position above, plus the number of ways to get to the position to the left. 
We also need to make sure that the number of ways to get to any position with `a[i] = #` is 0.
### Time Complexity : ***O(n<sup>2</sup>)***   
<br>

# [Book Shop](https://cses.fi/problemset/task/1158)

### `dp[i][j] =  maximum # of pages we can get for price at most j, only buying among the first i books`
Initially dp[0][j] = 0 for all j, as we can't get any pages without any books.

When calculating dp[i][j], we look at the last considered book, the i'th book. We either didn't buy it, leaving j money for the first i-1 books, giving dp[i-1][j] pages. 
Or we bought it, leaving j-price[i-1] money for the other i-1 books, and giving pages[i-1] extra pages from the bought book. 
Thus, buying the i'th book gives dp[i-1][j-price[i-1]] + pages[i-1] pages.
### Time Complexity : ***O(n . x)***   
<br>

# [Array Description](https://cses.fi/problemset/task/1746)

### `dp[i][j] =  # of ways to fill the array upto index i, if a[i] = j`
We treat i = 0 separately. Either `a[0] = 0`, so we can replace it by anything (i.e `dp[0][j] = 1 for all j`). Otherwise a[0] = v ≠ 0, so that dp[0][v] = 1 is the only allowed value.

Now to the other indices i > 0. If a[i] = 0, we can replace it by any value. However, if we replace it by v, the previous value must be either v-1, v or v+1. 
Thus the number of ways to fill the array up to i, is the sum of the previous value being v-1, v and v+1. If a[i] = v from the input, only dp[i][v] is allowed (i.e `dp[i][j] = 0 if j ≠ v`). 
Still `dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]`
### Time Complexity : ***O(n . m)***   
<br>

# [Edit Distance](https://cses.fi/problemset/task/1639)

### `dp[i][j] =  minimum # of moves to change first i chars of a to first j chars of b`
When we calculate dp[i][j], there are four possibilities to consider for the rightmost operation. We check all of them and take the cheapest one.

1. We deleted character a[i-1]. This took one operation, and we still need to change a[:i-1] to b[:j]. So this costs 1 + dp[i-1][j] operations.

2. We added character b[j-1] to the end of a[:i]. This took one operation, and we still need to change a[:i] to b[:j-1]. So this costs 1 + dp[i][j-1] operations.

3. We replaced a[i-1] with b[j-1]. This took one operation, and we still need to change a[:i-1] to b[:j-1]. So this costs 1 + dp[i-1][j-1] operations.

4. a[i-1] was already equal to b[j-1], so we just need to change a[:i-1] to b[:j-1]. That takes dp[i-1][j-1] operations. This possibility can be viewed as a replace operation where we don't actually need to replace a[i-1].
### Time Complexity : ***O(|a| . |b|)***   
<br>

# [Rectangle Cutting](https://cses.fi/problemset/task/1744)

### `dp[i][j] =  # of cuts needed to make a ixj rect into square`
Consider a `w×h` piece. If it is already square (`w = h`), we need 0 cuts. Otherwise, we need to make the first cut either horizontally or vertically. 
Say we make it horizontally, then we can cut at any position `1,2,..,h-1`. If we cut at position k, then we are left with two pieces of sizes `w×k` and `w×h − k`. 
We can look up the number of moves to reduce these to squares in the dp array. We loop over all possibilities k and take the best one. Similarly for vertical cuts.
### Time Complexity : ***O(a<sup>2</sup>b . ab<sup>2</sup>)***   
<br>

# [Money Sums](https://cses.fi/problemset/task/1745)

### `dp[i][j] =  1 if it is possible to make the sum j using the first i coins`
It is possible to make j with the first i coins, if either it was possible with the first i-1 coins, or we chose the i'th coin, and it was possible to make j — <value of i'th coin> using the first i-1 coins.

Note that we only need to consider sums up to `1000 ⋅ n`, since we can't make more than that using n coins of value ≤ 1000.
### Time Complexity : ***O(n<sup>2</sup> . max<sub>a(i)</sub>)***   
<br>

# [Removal Game](https://cses.fi/problemset/task/1097)

### `dp[i][j] = max diff score1−score2 if considering the game played only on interval [i, j]`
If the interval contains only one element (i = j), then the first player must take that element. So dp[i][i] = a[i].

Otherwise, player 1 can choose to take the first element or the last element. If he takes the first element, he gets a[i] points, and we are left with the interval [i+1,j], but with player 2 starting. 
`score1−score2` on interval [i+1,j] is just dp[i+1][j] if player 1 starts. Since player 2 starts, it is -dp[i+1][j]. Thus, the difference of scores will be a[i]-dp[i+1][j] if player 1 chooses the first element. 
Similarly, it will be a[j]-dp[i][j-1] if he chooses the last element. He always chooses the maximum of those, so `dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1])`.

In this problem dp[i][j] depends on dp[i+1][j], and therefore we need to compute larger i before smaller i. We do it by looping through i from high to low. 
j still needs to go from low to high, since we depend only on smaller j (dp[i][j] depends on dp[i][j-1]).

We can reconstruct the score of player 1 as the mean of, the sum of all input values, and `score1−score2`.
### Time Complexity : ***O(n<sup>2</sup>)***   
<br>

# [Two Sets II](https://cses.fi/problemset/task/1093)

### `dp[i][j] =  # of ways to make sum j using subsets of the numbers 1..i`
This is a 0-1 knapsack in disguise. If we are to have two subsets of equal sum, they must sum to half the total sum each. This means if the total sum `n(n+1)/2` is odd, the answer is zero (no possibilities). 
Otherwise we run 0-1 knapsack to get the number of ways to reach `n(n+1)/4` using subsets of the numbers 1..n-1. Why n-1? Because by only considering numbers up to n-1, we always put n in the second set, and therefore only count each pair of sets once (otherwise we count every pair of sets twice).

There is one way (the empty set) to make sum 0, so `dp[0][0] = 1`.

For counting number of ways to make sum j using values up to i, we consider the number i. 
Either we didn't include it, then there are dp[i-1][j] possibilities, or we included it, and there are dp[i-1][j-i] possibilities. So `dp[i][j] = dp[i-1][j] + dp[i-1][j-i]`.
### Time Complexity : ***O(n<sup>3</sup>)***   
<br>

# [Increasing Subsequence](https://cses.fi/problemset/task/1145)

### `dp[i] =  minimum ending value of an increasing subsequence of length i+1, using the elements considered so far`
We add elements one by one from left to right. Say we want to add a new value v. For this to be part of an increasing subsequence, the previous value in the subsequence must be lower than v. 
We might as well take the maximum length subsequence leading up to v, as the values don't matter for the continuation to the right of v. Therefore we need to extend the current longest increasing subsequence ending in a value less than v. 
This means we want to find the rightmost element in the dp array (as the position corresponds to the length of the subsequence), with value less than v. Say it is at position i. 
We can put v as a new candidate for ending value at position i+1 (since we have an increasing subsequence of length i+1 + 1, which ends on v). 
Note that since i was the rightmost position with value less than v, changing dp[i+1] to v can only make the value smaller (better), so we can always set dp[i+1] = v without checking if it is an improvement first.

Naively locating the position i with a for loop gives complexity O(n<sup>2</sup>). However, dp is always an increasing array. So we can locate i position by binary search (std::lower_bound in C++ directly gives position i+1).

The final answer is the length of the dp array after considering all elements.
### Time Complexity : ***O(n . logn)***   
<br>
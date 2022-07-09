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
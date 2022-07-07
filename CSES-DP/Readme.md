# [Dice Combinations](https://cses.fi/problemset/task/1633)

### `dp[i] = # of ways of making sum i using numbers from 1 to 6`
Initialize by dp[0] = 1, as there is one way with sum 0 (the empty set).
### Time Complexity : ***O(n)***   


# [Minimizing Coins](https://cses.fi/problemset/task/1634)

### `dp[i] = minimum number of coins with sum i`
We look at the last coin added to get sum x, say it has value v. We need dp[i-v] coins to get value i-v, and 1 coin for value v. Therefore we need dp[i-v]+1 coins if we are to use a coin with value v. Checking all possibilities for v must include the optimal choice of last coin.

As an implementation detail, we use `dp[i] = 1e9` to signify that it is not possible to make value x with the given coins.
### Time Complexity : ***O(n . x)***   


# [Coin Combinations I](https://cses.fi/problemset/task/1635)

### `dp[i] = # of ways to make value i`
We initialize dp[0] = 1, as the empty set is the only way to make 0.

Like in "Minimizing Coins", we loop over the possibilities for last coin added. There are dp[i-v] ways to make i, when adding a coin with value v last. This is since we can choose any combination for the first coins to sum to i-v, but need to choose v as the last coin. Summing over all the possibilities for v gives dp[i].
### Time Complexity : ***O(n . x)***   


# [Removing Digits](https://cses.fi/problemset/task/1637)

### `dp[i] = minimum # of operations to go from i to 0`
When considering a number i, for each digit in the decimal representation of i, we can try to remove it. The transition is therefore: dp[i] =  min~d∈digits(i)~ dp[i-d]. 
We initialize dp[0] = 0.
### Time Complexity : ***O(n)***   
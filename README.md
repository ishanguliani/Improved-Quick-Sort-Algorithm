# Improved-Quick-Sort-Algorithm
c++ implementation of improved quicksort algorithm to sort a data set containing equal elements in NlogN time

# The problem
The standard quick sort algorithm has time complexity T(n) = O(nLog(n)) in average case

However, when the input data set contains many equal elements, this leads to an unbalanced partioning during quick sort and hence a worst case time complexity of T(n) = O(n^2)

# The solution
Modified the partition function to cause a *3-way partition* instead of a 2-way partition.

# The result
This speeds up the quick sort algorithm to perform sorting on any given data set including equal elements in T(n) = NLogN time.

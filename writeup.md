# Google Test And Debugging Writeup

## Things I Thought To Test
1. For the function parse_args() I thought to test:
   1. that len_out is not a nullptr
   2. that argc is greater than 1
   3. that malloc succeeds
2. For the function get_sorted() I thought to test:
   1. that the variable len is the actual length of the original array and that the newly created array which is sorted has the same length
   2. that each value in the variable sorted_ar is actually sorted, meaning each value in sorted_ar is less than or equal to the next value.
   3. that copy_array() is a copy, a new array separate from the original
   4. that the values of the new array are the same as the original array. That means that the new array has the same values and the same amount of those values, with no new values
3. For the function make_sorted() I thought to test:
   1. that the variable min_index has the index of a value which is less than or equal to every value in the range being checked
   2. that after swap() function is called, the smaller index now contains a value less than the value in the bigger index
   3. that the range being checked for smaller values includes the 0 index and goes until the last index, with that range getting smaller until being only the last 2 indexes
4. For the function copy_array() I thought to test:
   1. that copy_array() is a copy, a new array separate from the original
   2. that the values of the new array are the same as the original array. That means that the new array has the same values and the same amount of those values, with no new values
   3. the value of the pointer pointing to the new array is not a nullptr
5. For the function min_index_of_array() I thought to test:
   1. that the integer found by the function has an equal or smaller than value than every other integer in the range of the array being checked
   2. that the variable min_index is actually a valid index, meaning that it is less than or equal to the variable len minus 1
   3. that the variable min_index at the start of the function actually points to the start of the range we want to check
6. For the function swap() I thought to test:
   1. that the values are actually swapped, meaning that a is now equal to the original value of b and b is equal to the original value of a.
   2. that the address of the variables being swapped has not had its address changed
...

## Bugs

### Bug 1

### Location

Line number(s) of the bugs.

```c++
int* temp = a;
a = b;
b = temp;
```

### How the bug was located

I found the bug after the simple test in test_swap.cpp, SimpleSwapTwoValues, showed an error. While going over the code for swap in sorting.cpp I noticed that the error was in the types of variable the function was using.

### Description

The error in the function swap() comes from the fact that when swapping the values of variable created in function, and is swapping the value of addresses instead of the values held at that address.

### Fix 

I started by derefrencing the value held by the parameter a, which is an adress of the variable we want to swap, and assigning that to a varaible of type int instead of int*. Then for the rest of the code I dereferenced the addresses to change the value held at that address. Besides using the dereferenced addresses I didn't change anything else.

```c++
int temp = *a;
*a = *b;
*b = temp;
```

### Bug 2

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 3

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"
#include "test_helpers.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */

    int numbers[3] = {1, 2, 3};
    int min_index = min_index_of_array(numbers, 3);
    EXPECT_EQ(min_index, 0);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */

    int numbers[3] = {3, 2, 1};
    int min_index = min_index_of_array(numbers, 3);
    EXPECT_EQ(min_index, 2);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */

    int numbers[5] = {5, 4, 1, 2, 3};
    int min_index = min_index_of_array(numbers, 5);
    EXPECT_EQ(min_index, 2);
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
    int numbers[5] = {5, 1, 1, 1, 3};
    int min_index = min_index_of_array(numbers, 5);
    EXPECT_EQ(min_index, 1);
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int numbers[5] = {5, 4, 1, 2, 3};
    int copy_of_numbers[5] = {5, 4, 1, 2, 3};

    min_index_of_array(numbers, 5);
    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(numbers[i], copy_of_numbers[i]);
    }


}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              (const std::vector<int>& values)) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */

    int size = values.size();
    int numbers[size];
    copy_vector_to_array(values, numbers);
    int min_index = min_index_of_array(numbers, size);
    for (int i = 0; i < size; i++)
    {
        RC_ASSERT(numbers[min_index] <= numbers[i]);
    }
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              (const std::vector<int>& values)) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */

    int size = values.size();
    int numbers[size];
    copy_vector_to_array(values, numbers);
    // storing each of the value sin the original array
    int stored_vals[sizeof(numbers)/sizeof(int)];
    for (unsigned int i = 0; i < (sizeof(numbers)/sizeof(int)); i++)
    {
        stored_vals[i] = numbers[i];
    }

    min_index_of_array(numbers, size);

    for (int i = 0; i < size; i++)
    {
        RC_ASSERT(numbers[i] == stored_vals[i]);
    }
}

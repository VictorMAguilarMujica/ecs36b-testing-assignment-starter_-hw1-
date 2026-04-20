#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int numbers[3] = {1, 2, 3};
    make_sorted(numbers, 3);
    for (int i = 0; i < 2; i++)
    {
        EXPECT_TRUE(numbers[i] <= numbers[i+1]);
    }

}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int numbers[3] = {3, 2, 1};
    make_sorted(numbers, 3);
    for (int i = 0; i < 2; i++)
    {
        EXPECT_TRUE(numbers[i] <= numbers[i+1]);
    }
}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int numbers[5] = {5, 4, 1, 2, 3};
    make_sorted(numbers, 5);
    for (int i = 0; i < 4; i++)
    {
        EXPECT_TRUE(numbers[i] <= numbers[i+1]);
    }
}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int numbers[5] = {5, 4, 1, 2, 2};
    make_sorted(numbers, 5);
    for (int i = 0; i < 4; i++)
    {
        EXPECT_TRUE(numbers[i] <= numbers[i+1]);
    }
}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int size = values.size();
    int numbers[size];
    copy_vector_to_array(values, numbers);
    make_sorted(numbers, size);
    for (int i = 0; i < size - 1; i++)
    {
        RC_ASSERT(numbers[i] <= numbers[i+1]);
    }
}

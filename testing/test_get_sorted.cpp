#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int original_arr[3] = {1, 2, 3};

    int len = 3;

    int* sorted_arr = get_sorted(original_arr, len);
    for (int i = 0; i < len - 1; i++)
    {
        EXPECT_TRUE(sorted_arr[i] <= sorted_arr[ i + 1]);
    }

    free(sorted_arr);
}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int original_arr[3] = {3, 2, 1};

    int len = 3;

    int* sorted_arr = get_sorted(original_arr, len);
    for (int i = 0; i < len - 1; i++)
    {
        EXPECT_TRUE(sorted_arr[i] <= sorted_arr[ i + 1]);
    }

    free(sorted_arr);
}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int original_arr[5] = {3, 1, 2, 5, 4};

    int len = 5;

    int* sorted_arr = get_sorted(original_arr, len);
    for (int i = 0; i < len - 1; i++)
    {
        EXPECT_TRUE(sorted_arr[i] <= sorted_arr[ i + 1]);
    }

    free(sorted_arr);

}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int original_arr[5] = {3, 1, 2, 5, 2};

    int len = 5;

    int* sorted_arr = get_sorted(original_arr, len);
    for (int i = 0; i < len - 1; i++)
    {
        EXPECT_TRUE(sorted_arr[i] <= sorted_arr[ i + 1]);
    }

    free(sorted_arr);



}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int original_arr[3] = {2, 1, 3};

    int stored_vals[3];
    for (unsigned int i = 0; i < 3; i++)
    {
        stored_vals[i] = original_arr[i];
    }

    int* sorted_arr = get_sorted(original_arr, 3);

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(original_arr[i], stored_vals[i]);
    }

    free(sorted_arr);

}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int original_arr[3] = {3, 2, 1};

    int* new_arr = get_sorted(original_arr, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            EXPECT_NE(&original_arr[i], &new_arr[j]);
        }
    }
    free(new_arr);


}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Check that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */


    int size = values.size();
    int numbers[size];
    copy_vector_to_array(values, numbers);
    int* new_arr = get_sorted(numbers, size);
    for (int i = 0; i < size - 1; i++)
    {
        RC_ASSERT(new_arr[i] <= new_arr[i+1]);
    }

    free(new_arr);
}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    ;

    int size = values.size();
    int numbers[size];
    copy_vector_to_array(values, numbers);

    int stored_vals[size];
    for (int i = 0; i < size; i++)
    {
        stored_vals[i] = numbers[i];
    }

    int* sorted_arr = get_sorted(numbers, size);

    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(numbers[i], stored_vals[i]);
    }

    free(sorted_arr);
}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int size = values.size();
    int original_arr[size];
    copy_vector_to_array(values, original_arr);

    int* new_arr = get_sorted(original_arr, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            EXPECT_NE(&original_arr[i], &new_arr[j]);
        }
    }
    free(new_arr);
}












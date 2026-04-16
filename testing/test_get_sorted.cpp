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

    int* original_arr = (int*)malloc(sizeof(int) * 3);
    original_arr[0] = 1;
    original_arr[1] = 2;
    original_arr[2] = 3;

    int len = 3;

    int* sorted_arr = get_sorted(original_arr, len);
    for (int i = 0; i < len - 1; i++)
    {
        EXPECT_TRUE(sorted_arr[i] <= sorted_arr[ i + 1]);
    }

    free(original_arr);
}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int* original_arr = (int*)malloc(sizeof(int) * 3);
    original_arr[0] = 3;
    original_arr[1] = 2;
    original_arr[2] = 1;

    int len = 3;

    int* sorted_arr = get_sorted(original_arr, len);
    for (int i = 0; i < len - 1; i++)
    {
        EXPECT_TRUE(sorted_arr[i] <= sorted_arr[ i + 1]) << "At i = " << i << " sorted_arr[i] = " << sorted_arr[i] << " and sorted_arr[i + 1] = " << sorted_arr[i + 1];
    }

    free(original_arr);
}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int* original_arr = (int*)malloc(sizeof(int) * 5);
    original_arr[0] = 3;
    original_arr[1] = 1;
    original_arr[2] = 2;
    original_arr[3] = 5;
    original_arr[4] = 4;

    int len = 5;

    int* sorted_arr = get_sorted(original_arr, len);
    for (int i = 0; i < len - 1; i++)
    {
        EXPECT_TRUE(sorted_arr[i] <= sorted_arr[ i + 1]) << "At i = " << i << " sorted_arr[i] = " << sorted_arr[i] << " and sorted_arr[i + 1] = " << sorted_arr[i + 1];
    }

    free(original_arr);

}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int* original_arr = (int*)malloc(sizeof(int) * 3);
    original_arr[0] = 3;
    original_arr[1] = 1;
    original_arr[2] = 2;
    original_arr[3] = 2;
    original_arr[4] = 4;

    int len = 5;

    int* sorted_arr = get_sorted(original_arr, len);
    for (int i = 0; i < len - 1; i++)
    {
        EXPECT_TRUE(sorted_arr[i] <= sorted_arr[ i + 1]) << "At i = " << i << " sorted_arr[i] = " << sorted_arr[i] << " and sorted_arr[i + 1] = " << sorted_arr[i + 1];
    }

    free(original_arr);



}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int* original_arr = (int*)malloc(sizeof(int) * 3);
    original_arr[0] = 3;
    original_arr[1] = 2;
    original_arr[2] = 1;

    int len = 3;

    int* new_arr = get_sorted(original_arr, len);

    EXPECT_EQ(original_arr[0], 3);
    EXPECT_EQ(original_arr[1], 2);
    EXPECT_EQ(original_arr[2], 1);

    free(original_arr);

}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int* original_arr = (int*)malloc(sizeof(int) * 3);
    original_arr[0] = 3;
    original_arr[1] = 2;
    original_arr[2] = 1;

    int len = 3;

    int* new_arr = get_sorted(original_arr, len);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            EXPECT_NE(&original_arr[i], &new_arr[j]);
        }
    }
    free(original_arr);


}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Check that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */

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

}












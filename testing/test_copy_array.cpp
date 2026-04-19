#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int* original_arr = (int*)malloc(sizeof(int) * 3);
    original_arr[0] = 3;
    original_arr[1] = 2;
    original_arr[2] = 1;

    // frequency table to keep track of how many of each number is in the original array
    // even index starting at 0 hold the number being tracked and the odd index following is the amount
    int frequency_table[6];
    frequency_table[0] = 3;
    frequency_table[1] = 1;
    frequency_table[2] = 2;
    frequency_table[3] = 1;
    frequency_table[4] = 1;
    frequency_table[5] = 1;


    int len = 3;
    int* new_arr = copy_array(original_arr, len);

    bool found_match;
    for (int i = 0; i < len; i++)
    {

        found_match = false;
        for (int j = 0; j < len * 2;)
        {

            if (frequency_table[j] == new_arr[i])
            {

                if (frequency_table[j+1] > 0)
                {
                    frequency_table[j+1] -= 1;
                    found_match = true;
                }
            }
            j += 2;
        }
        EXPECT_TRUE(found_match);
    }
    for (int x = 1; x < len * 2;)
    {
        EXPECT_EQ(frequency_table[x], 0);
        x += 2;
    }

    free(original_arr);
    free(new_arr);


}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int* original_arr = (int*)malloc(sizeof(int) * 3);
    original_arr[0] = 3;
    original_arr[1] = 2;
    original_arr[2] = 1;

    int len = 3;

    int* new_arr = copy_array(original_arr, len);

    EXPECT_EQ(original_arr[0], 3);
    EXPECT_EQ(original_arr[1], 2);
    EXPECT_EQ(original_arr[2], 1);

    free(original_arr);

}

TEST(CopyArrayTests, SimpleCopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int* original_arr = (int*)malloc(sizeof(int) * 3);
    original_arr[0] = 3;
    original_arr[1] = 2;
    original_arr[2] = 1;

    int len = 3;

    int* new_arr = copy_array(original_arr, len);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            EXPECT_NE(&original_arr[i], &new_arr[j]);
        }
    }
    free(original_arr);

}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int size = values.size();
    int numbers[size];
    copy_vector_to_array(values, numbers);
    int* new_arr = copy_array(numbers, size);
    bool copy_and_og_same_vals = elements_in_vector_and_array_are_same(values, numbers);
    RC_ASSERT(copy_and_og_same_vals == true);


}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
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
    int* new_arr = copy_array(numbers, size);

    for (int j = 0; j < size; j++)
    {
        RC_ASSERT(numbers[j] == stored_vals[j]);
    }


}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
  * Check that a copy was actually made
  * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
  * Don't forget to free any memory that was dynamically allocated as part of your test.
  */

}




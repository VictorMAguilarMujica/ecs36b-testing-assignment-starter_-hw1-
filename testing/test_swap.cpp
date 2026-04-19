#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues) {
    int a = 1;
    int og_a_val = a;
    int b = 2;
    int og_b_val = b;
    swap(&a, &b);
    EXPECT_EQ(a, og_b_val);
    EXPECT_EQ(b, og_a_val);
}

TEST(SwapTests, SimpleSwapValuesInArray) {
    int int_arr[2] = {1, 2};
    swap(int_arr, int_arr + 1);
    EXPECT_EQ(int_arr[0], 2);
    EXPECT_EQ(int_arr[1], 1);
}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
    /*
     * Swap two values and see if the swap was successful.
     */

    int og_a_val = a_start;
    int og_b_val = b_start;
    swap(&a_start, &b_start);

    RC_ASSERT(a_start == og_b_val);
    RC_ASSERT(b_start == og_a_val);
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
)
{
    // int arr[];
    // copy_vector_to_array(values, arr);

    int a = *rc::gen::arbitrary<int>();
    int b = *rc::gen::arbitrary<int>();
    int numbers[2] = {a, b};

    int og_0arr_val = numbers[0];
    int og_1arr_val = numbers[1];

    swap(numbers, numbers + 1);

    RC_ASSERT(numbers[0] == og_1arr_val);
    RC_ASSERT(numbers[1] == og_0arr_val);

    // const auto b = rc::gen::arbitrary<int>();
    // rc::Gen<int> numbers[2] = {a, b};


    //int a = values.at(0);
    // copy_vector_to_array(values, numbers);

    // rc::Gen<int> og_0arr_val = numbers[0];
    // rc::Gen<int> og_1arr_val = numbers[1];
    // swap(numbers, numbers + 1);
    //
    // RC_ASSERT(numbers[0] == og_1arr_val);
    // RC_ASSERT(numbers[1] == og_0arr_val);


}

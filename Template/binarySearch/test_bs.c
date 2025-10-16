#include "../src/binarysearch.h"
#include "../../Unity/src/unity.h"
static int array[] = {1, 3, 3, 5, 7, 9};
int n = sizeof(array) / sizeof(array[0]);

void setUp(void)
{}

void tearDown(void) {}

void test_lower_bound(void)
{
    TEST_ASSERT_EQUAL_INT(4, lower_bound(array, n, 7));
    TEST_ASSERT_EQUAL_INT(1, lower_bound(array, n, 3));
    TEST_ASSERT_EQUAL_INT(n, lower_bound(array, n, 10));
    TEST_ASSERT_EQUAL_INT(0, lower_bound(array, n, 0));
}

void test_upper_bound(void)
{
    TEST_ASSERT_EQUAL_INT(5, upper_bound(array, n, 7));
    TEST_ASSERT_EQUAL_INT(3, upper_bound(array, n, 3));
    TEST_ASSERT_EQUAL_INT(n, upper_bound(array, n, 10));
    TEST_ASSERT_EQUAL_INT(0, upper_bound(array, n, 0));
}

void test_null_zero_array(void)
{
    int a[] = {0};
    TEST_ASSERT_EQUAL_INT(0, lower_bound(array, 1, 0));
    TEST_ASSERT_EQUAL_INT(0, upper_bound(array, 1, 0));

    int b[] = {};
    TEST_ASSERT_EQUAL_INT(0, lower_bound(array, 0, 1));
    TEST_ASSERT_EQUAL_INT(0, upper_bound(array, 0, 1));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_lower_bound);
    RUN_TEST(test_upper_bound);
    RUN_TEST(test_null_zero_array);
    
    return UNITY_END();
}
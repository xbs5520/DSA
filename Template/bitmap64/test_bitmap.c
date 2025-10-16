#include "../src/bitmap64.h"
#include "../../Unity/src/unity.h"

static bitmap64 bm;
static int missing_indices[64];
static int missing_count;

void record_missing(int idx) {
    missing_indices[missing_count++] = idx;
}

void setUp(void){ bm = 0; missing_count = 0;}
void tearDown(void) {}



void test_mark_ismarked(void)
{
    for(int i = 0; i < 10; i++)
    {
        TEST_ASSERT_EQUAL_INT(0, is_marked(bm, i));
    }
    mark(&bm, 1);
    mark(&bm, 3);
    mark(&bm, 5);
    TEST_ASSERT_EQUAL_INT(1, is_marked(bm, 1));
    TEST_ASSERT_EQUAL_INT(1, is_marked(bm, 3));
    TEST_ASSERT_EQUAL_INT(1, is_marked(bm, 5));
    TEST_ASSERT_EQUAL_INT(0, is_marked(bm, 6));
}

void test_foreach_missing(void)
{
    mark(&bm, 1);
    mark(&bm, 3);

    foreach_missing(bm, 5, record_missing);
    TEST_ASSERT_EQUAL_INT(3, missing_count);
    TEST_ASSERT_EQUAL_INT(0, missing_indices[0]);
    TEST_ASSERT_EQUAL_INT(2, missing_indices[1]);
    TEST_ASSERT_EQUAL_INT(4, missing_indices[2]);
}

void test_all_received(void)
{
    mark(&bm, 1);
    mark(&bm, 2);
    mark(&bm, 3);
    TEST_ASSERT_EQUAL_INT(0, all_received(bm, 4));
    mark(&bm, 0);
    TEST_ASSERT_EQUAL_INT(1, all_received(bm, 4));
}
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_mark_ismarked);
    RUN_TEST(test_foreach_missing);
    RUN_TEST(test_all_received);
    
    return UNITY_END();
}

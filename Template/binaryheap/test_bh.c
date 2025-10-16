#include "../src/binaryheap.h"
#include "../../Unity/src/unity.h"

MinHeap g_heap;

void setUp(void){ heap_init(&g_heap); }
void tearDown(void) {}



void test_heap_init(void)
{
    heap_init(&g_heap);
    TEST_ASSERT_EQUAL_INT(0, g_heap.size);
}

void test_heap_push_top_pop(void)
{
    heap_push(&g_heap, 1);
    TEST_ASSERT_EQUAL_INT(1, heap_top(&g_heap));
    heap_push(&g_heap, 4);
    TEST_ASSERT_EQUAL_INT(1, heap_top(&g_heap));
    heap_push(&g_heap, 2);
    TEST_ASSERT_EQUAL_INT(1, heap_top(&g_heap));
    heap_push(&g_heap, 3);
    TEST_ASSERT_EQUAL_INT(1, heap_top(&g_heap));

    heap_pop(&g_heap);
    TEST_ASSERT_EQUAL_INT(2, heap_top(&g_heap));
    heap_pop(&g_heap);
    TEST_ASSERT_EQUAL_INT(3, heap_top(&g_heap));
    heap_pop(&g_heap);
    TEST_ASSERT_EQUAL_INT(4, heap_top(&g_heap));
}

void test_heap_top_empty()
{
    TEST_ASSERT_EQUAL_INT(0, g_heap.size);
    TEST_ASSERT_EQUAL_INT(-1, heap_top(&g_heap));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_heap_init);
    RUN_TEST(test_heap_push_top_pop);
    RUN_TEST(test_heap_top_empty);

    return UNITY_END();
}

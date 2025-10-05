#include "../src/ringbuffer.h"
#include "../../Unity/src/unity.h"

#define BUF_SIZE 16

static rb_t g_rb;
static uint8_t g_buf[BUF_SIZE];

void setUp(void)
{
    rb_init(&g_rb, g_buf, sizeof(g_buf));
}

void tearDown(void) {}

void test_rb_init_valid_params(void)
{
    uint8_t buf[4];
    rb_t q;

    TEST_ASSERT_EQUAL_INT(0, rb_init(&q, buf, 4));
    TEST_ASSERT_EQUAL_PTR(buf, q.buf);
    TEST_ASSERT_EQUAL_INT(4, q.cap);
    TEST_ASSERT_EQUAL_INT(0, q.head);
    TEST_ASSERT_EQUAL_INT(0, q.tail);
}

void test_rb_init_invalid_params(void)
{
    uint8_t buf[4];
    rb_t q;

    TEST_ASSERT_EQUAL_INT(-1, rb_init(&q, NULL, 4));
    TEST_ASSERT_EQUAL_INT(-1, rb_init(&q, buf, 1));
    TEST_ASSERT_EQUAL_INT(-1, rb_init(&q, buf, 0));
    TEST_ASSERT_EQUAL_INT(-1, rb_init(NULL, buf, 4));
}

void test_rb_empty_and_full_states(void)
{
    TEST_ASSERT(rb_empty(&g_rb));
    TEST_ASSERT_FALSE(rb_full(&g_rb));
    TEST_ASSERT_EQUAL_INT(0, rb_size(&g_rb));
    TEST_ASSERT_EQUAL_INT(BUF_SIZE - 1, rb_free(&g_rb));

    // fill
    // remain 1 for state size = bufsize - 1
    for(int i = 0; i < BUF_SIZE - 1; i++)
    {
        TEST_ASSERT_EQUAL_INT(1, rb_push(&g_rb, (uint8_t)i));
    }

    TEST_ASSERT_FALSE(rb_empty(&g_rb));
    TEST_ASSERT(rb_full(&g_rb));
    TEST_ASSERT_EQUAL_INT(BUF_SIZE - 1, rb_size(&g_rb));
    TEST_ASSERT_EQUAL_INT(0, rb_free(&g_rb));
}


void test_rb_push_pop_fifo_order(void)
{
    uint8_t val = 0;

    TEST_ASSERT(rb_empty(&g_rb));

    // pop from empty
    TEST_ASSERT_EQUAL_INT(0, rb_pop(&g_rb, &val));

    // push values
    TEST_ASSERT_EQUAL_INT(1, rb_push(&g_rb, 'A'));
    TEST_ASSERT_EQUAL_INT(1, rb_push(&g_rb, 'B'));
    TEST_ASSERT_EQUAL_INT(1, rb_push(&g_rb, 'C'));
    TEST_ASSERT_EQUAL_INT(1, rb_push(&g_rb, 'D'));

    // verify order FIFO
    TEST_ASSERT_EQUAL_INT(1, rb_pop(&g_rb, &val));
    TEST_ASSERT_EQUAL_INT('A', val);
    TEST_ASSERT_EQUAL_INT(1, rb_pop(&g_rb, &val));
    TEST_ASSERT_EQUAL_INT('B', val);
    TEST_ASSERT_EQUAL_INT(1, rb_pop(&g_rb, &val));
    TEST_ASSERT_EQUAL_INT('C', val);
    TEST_ASSERT_EQUAL_INT(1, rb_pop(&g_rb, &val));
    TEST_ASSERT_EQUAL_INT('D', val);

    TEST_ASSERT(rb_empty(&g_rb));
}


void test_rb_push_when_full(void)
{
    TEST_ASSERT(rb_empty(&g_rb));
    // fill
    for(int i = 0; i < BUF_SIZE - 1; i++)
    {
        TEST_ASSERT_EQUAL_INT(1, rb_push(&g_rb, (uint8_t)i));
    }

    // push when full
    TEST_ASSERT_EQUAL_INT(0, rb_push(&g_rb, 20));
    TEST_ASSERT(rb_full(&g_rb));
}

void test_rb_reset(void)
{
    for(int i = 0; i < BUF_SIZE - 1; i++)
    {
        TEST_ASSERT_EQUAL_INT(1, rb_push(&g_rb, (uint8_t)i));
    }
    TEST_ASSERT_EQUAL_INT(0, rb_empty(&g_rb));
    rb_reset(&g_rb);
    TEST_ASSERT_EQUAL_INT(1, rb_empty(&g_rb));
}

void test_rb_peek(void)
{
    TEST_ASSERT_EQUAL_INT(1, rb_empty(&g_rb));

    uint8_t val = 0;

    // peek empty
    TEST_ASSERT_EQUAL_INT(0, rb_peek(&g_rb, &val));

    // push && peek
    TEST_ASSERT_EQUAL_INT(1, rb_push(&g_rb, 20));
    TEST_ASSERT_EQUAL_INT(1, rb_peek(&g_rb, &val));
    TEST_ASSERT_EQUAL_INT(20, val);

    TEST_ASSERT_EQUAL_INT(1, rb_push(&g_rb, 30));
    TEST_ASSERT_EQUAL_INT(1, rb_peek(&g_rb, &val));
    TEST_ASSERT_EQUAL_INT(20, val);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_rb_init_valid_params);
    RUN_TEST(test_rb_init_invalid_params);
    RUN_TEST(test_rb_empty_and_full_states);
    RUN_TEST(test_rb_push_pop_fifo_order);
    RUN_TEST(test_rb_push_when_full);
    RUN_TEST(test_rb_reset);
    RUN_TEST(test_rb_peek);


    return UNITY_END();
}
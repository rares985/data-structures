#include "single_linked_list.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"

#include "log.h"
#include "types.h"

static void test_sll_create(void);
static int test_sll_create_1(void);
static int test_sll_create_2(void);

static void test_sll_destroy(void);
static int test_sll_destroy_1(void);
static int test_sll_destroy_2(void);

int test_sll_add_start(single_linked_list_t *list, void *data, size_t data_size);
int test_sll_add_end(single_linked_list_t *list, void *data, size_t data_size);
int test_sll_add_pos(single_linked_list_t *list, void *data, size_t data_size, int pos);
int test_sll_remove_start(single_linked_list_t *list);
int test_sll_remove_end(single_linked_list_t *list);
int test_sll_remove_pos(single_linked_list_t *list, int pos);
int test_sll_length(single_linked_list_t *list);
int test_sll_print(single_linked_list_t *list);


static void test_sll_create(void)
{
    int ret = ERR_GENERIC;
    const char *test_name = NULL;
    int (*test_fn)(void) = NULL;

    do {
        test_fn = test_sll_create_1;
        test_name = "test_sll_create_1";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

        test_fn = test_sll_create_2;
        test_name = "test_sll_create_2";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");
    } while(0);
}
static int test_sll_create_1(void)
{
    single_linked_list_t *list = NULL;
    int ret = ERR_OK;
    ret = sll_create(&list);
    return ret;
}
static int test_sll_create_2(void)
{
    int ret = ERR_OK;
    ret = sll_create(NULL);
    return ret;
}

static void test_sll_destroy(void)
{
    int ret = ERR_GENERIC;
    const char *test_name = NULL;
    int (*test_fn)(void) = NULL;

    do {
        test_fn = test_sll_destroy_1;
        test_name = "test_sll_destroy_1";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

        test_fn = test_sll_destroy_2;
        test_name = "test_sll_destroy_2";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");
    } while(0);
}


static int test_sll_destroy_1(void)
{
    int ret = ERR_GENERIC;
    single_linked_list_t *list = NULL;

    if (ERR_OK == sll_create(&list))
    {
        ret = sll_destroy(&list);
    }

    return ret;
}


static int test_sll_destroy_2(void)
{
    int ret = ERR_GENERIC;

    ret = sll_destroy(NULL);

    return ret;
}

int main(void)
{

    test_sll_create();
    test_sll_destroy();

    return 0;
}
#include "double_linked_list.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"

#include "log.h"
#include "types.h"

static void test_dll_create(void);
static int test_dll_create_1(void);
static int test_dll_create_2(void);

static void test_dll_destroy(void);
static int test_dll_destroy_1(void);
static int test_dll_destroy_2(void);

int test_dll_add_start(double_linked_list_t *list, void *data, size_t data_size);
int test_dll_add_end(double_linked_list_t *list, void *data, size_t data_size);
int test_dll_add_pos(double_linked_list_t *list, void *data, size_t data_size, int pos);
int test_dll_remove_start(double_linked_list_t *list);
int test_dll_remove_end(double_linked_list_t *list);
int test_dll_remove_pos(double_linked_list_t *list, int pos);
int test_dll_length(double_linked_list_t *list);
int test_dll_print(double_linked_list_t *list);


static void test_dll_create(void)
{
    int ret = ERR_GENERIC;
    const char *test_name = NULL;
    int (*test_fn)(void) = NULL;

    do {
        test_fn = test_dll_create_1;
        test_name = "test_dll_create_1";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

        test_fn = test_dll_create_2;
        test_name = "test_dll_create_2";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");
    } while(0);
}
static int test_dll_create_1(void)
{
    double_linked_list_t *list = NULL;
    int ret = ERR_OK;
    ret = dll_create(&list);
    return ret;
}
static int test_dll_create_2(void)
{
    int ret = ERR_OK;
    ret = dll_create(NULL);
    return ret;
}

static void test_dll_destroy(void)
{
    int ret = ERR_GENERIC;
    const char *test_name = NULL;
    int (*test_fn)(void) = NULL;

    do {
        test_fn = test_dll_destroy_1;
        test_name = "test_dll_destroy_1";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

        test_fn = test_dll_destroy_2;
        test_name = "test_dll_destroy_2";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");
    } while(0);
}


static int test_dll_destroy_1(void)
{
    int ret = ERR_GENERIC;
    double_linked_list_t *list = NULL;

    if (ERR_OK == dll_create(&list))
    {
        ret = dll_destroy(&list);
    }

    return ret;
}


static int test_dll_destroy_2(void)
{
    int ret = ERR_GENERIC;

    ret = dll_destroy(NULL);

    return ret;
}

int main(void)
{

    test_dll_create();
    test_dll_destroy();

    return 0;
}
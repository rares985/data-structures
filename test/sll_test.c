#include "single_linked_list.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"

#include "log.h"
#include "types.h"

single_linked_list_t *list = NULL;

static void test_sll_create(void);
static int test_sll_create_1(void);
static int test_sll_create_2(void);

static void test_sll_destroy(void);
static int test_sll_destroy_1(void);
static int test_sll_destroy_2(void);

static int test_sll_add_start(void);
static int test_sll_add_start_1(void);
static int test_sll_add_start_2(void);

static int test_sll_add_end(void);
static int test_sll_add_end_1(void);
static int test_sll_add_end_2(void);

static int test_sll_add_pos(void);
static int test_sll_add_pos_1(void);
static int test_sll_add_pos_2(void);
static int test_sll_add_pos_3(void);
static int test_sll_add_pos_4(void);
static int test_sll_add_pos_5(void);
static int test_sll_add_pos_6(void);

static int test_sll_remove_start(void);
static int test_sll_remove_start_1(void);
static int test_sll_remove_start_2(void);
static int test_sll_remove_end(void);
static int test_sll_remove_pos(void);
static int test_sll_length(void);
static int test_sll_print(void);


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

static int test_sll_add_start(void)
{
    int ret = ERR_GENERIC;
    const char *test_name = NULL;
    int (*test_fn)(void) = NULL;

    do {
        test_fn = test_sll_add_start_1;
        test_name = "test_sll_add_start_1";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

        test_fn = test_sll_add_start_2;
        test_name = "test_sll_add_start_2";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");

    } while(0);
}
static int test_sll_add_start_1(void)
{
    int ret = ERR_OK;
    single_linked_list_t *list = NULL;
    int value = 10;

    do {
        ret = sll_create(&list);
        if (ERR_OK != ret)
        {
            break;
        }

        ret = sll_add_start(list, &value, sizeof(value));
        if (ERR_OK != ret)
        {
            break;
        }

        value = 20;
        ret = sll_add_start(list, &value, sizeof(value));
        if (ERR_OK != ret)
        {
            break;
        }

        value = 30;
        ret = sll_add_start(list, &value, sizeof(value));
        if (ERR_OK != ret)
        {
            break;
        }

        if (3 != sll_length(list))
        {
            ret = ERR_GENERIC;
            break;
        }
    } while(0);

    return ret;
}
static int test_sll_add_start_2(void)
{
    int ret = ERR_OK;
    single_linked_list_t *list = NULL;
    int value = 10;

    do {
        ret = sll_create(&list);
        if (ERR_OK != ret)
        {
            break;
        }

        ret = sll_add_start(list, NULL, sizeof(int));
        if (ERR_OK != ret)
        {
            break;
        } 

        if (0 != sll_length(list))
        {
            ret = ERR_GENERIC;
            break;
        }

    } while(0);

    return ret;
}

static int test_sll_add_end(void)
{
    int ret = ERR_GENERIC;
    const char *test_name = NULL;
    int (*test_fn)(void) = NULL;

    do {
        test_fn = test_sll_add_end_1;
        test_name = "test_sll_add_end_1";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

        test_fn = test_sll_add_end_2;
        test_name = "test_sll_add_end_2";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");

    } while(0);
}
static int test_sll_add_end_1(void)
{
    int ret = ERR_OK;
    int value = 10;
    single_linked_list_t *list = NULL;
    do {
        ret = sll_create(&list);
        if (ERR_OK != ret)
        {
            break;
        }
        ret = sll_add_end(list, &value, sizeof(value));
    } while(0);
    return ret;
}
static int test_sll_add_end_2(void)
{
    int ret = ERR_OK;
    single_linked_list_t *list = NULL;
    do {
        ret = sll_create(&list);
        if (ERR_OK != ret)
        {
            break;
        }
        ret = sll_add_end(list, NULL, sizeof(int));
    } while(0);
    return ret;
}

static int test_sll_add_pos(void)
{
    int ret = ERR_GENERIC;
    const char *test_name = NULL;
    int (*test_fn)(void) = NULL;

    do {
        test_fn = test_sll_add_pos_1;
        test_name = "test_sll_add_pos_1";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");

        test_fn = test_sll_add_pos_2;
        test_name = "test_sll_add_pos_2";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");

        test_fn = test_sll_add_pos_3;
        test_name = "test_sll_add_pos_3";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");

        test_fn = test_sll_add_pos_4;
        test_name = "test_sll_add_pos_4";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

        test_fn = test_sll_add_pos_5;
        test_name = "test_sll_add_pos_5";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

        test_fn = test_sll_add_pos_6;
        test_name = "test_sll_add_pos_6";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

    } while(0);
}
static int test_sll_add_pos_1(void)
{
    /* Null parameter: list*/
    int ret = ERR_OK;
    int value = 10;
    int pos = -1;
    single_linked_list_t *list = NULL;

    ret = sll_add_pos(NULL, &value, sizeof(value), pos);

    return ret;
}
static int test_sll_add_pos_2(void)
{
    /* Null parameter: value */
    int ret = ERR_OK;
    int value = 10;
    int pos = 0;
    single_linked_list_t *list = NULL;

    ret = sll_add_pos(list, NULL, sizeof(int), pos);

    return ret;
}
static int test_sll_add_pos_3(void)
{
    /* Bad parameter: negative position */
    int ret = ERR_OK;
    int value = 10;
    int pos = -1;
    single_linked_list_t *list = NULL;
    do {
        ret = sll_create(&list);
        if (ERR_OK != ret)
        {
            break;
        }
        ret = sll_add_pos(list, &value, sizeof(value), pos);

    } while(0);
    return ret;
}
static int test_sll_add_pos_4(void)
{
    /* Bad parameter: pos too large */
    int ret = ERR_OK;
    int value = 10;
    int pos = 10;
    single_linked_list_t *list = NULL;
    do {
        ret = sll_create(&list);
        if (ERR_OK != ret)
        {
            break;
        }
        ret = sll_add_pos(list, &value, sizeof(value), pos);

    } while(0);
    return ret;
}
static int test_sll_add_pos_5(void)
{
    /* Empty list add: position 0 */
    int ret = ERR_OK;
    int value = 10;
    int pos = 0;
    single_linked_list_t *list = NULL;
    do {
        ret = sll_create(&list);
        if (ERR_OK != ret)
        {
            break;
        }
        ret = sll_add_pos(list, &value, sizeof(value), pos);
        if (ERR_OK != ret)
        {
            break;
        }

        if (1 != sll_length(list))
        {
            ret = ERR_GENERIC;
            break;
        }

    } while(0);

    return ret;
}
static int test_sll_add_pos_6(void)
{
    /* Add on last position (list has 1 element, add on pos 1) */
    int ret = ERR_OK;
    int value = 10;
    int pos = 0;
    single_linked_list_t *list = NULL;
    do {
        ret = sll_create(&list);
        if (ERR_OK != ret)
        {
            break;
        }
        ret = sll_add_pos(list, &value, sizeof(value), pos);
        if (ERR_OK != ret)
        {
            break;
        }

        ret = sll_add_pos(list, &value, sizeof(value), 1);
        if (ERR_OK != ret)
        {
            break;
        }

        if (2 != sll_length(list))
        {
            ret = ERR_GENERIC;
            break;
        }

    } while(0);

    return ret;
}


static int test_sll_remove_start(void)
{
    int ret = ERR_GENERIC;
    const char *test_name = NULL;
    int (*test_fn)(void) = NULL;

    do {
        test_fn = test_sll_remove_start_1;
        test_name = "test_sll_remove_start_1";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_OK ? "SUCCESS" : "FAILED");

        test_fn = test_sll_remove_start_2;
        test_name = "test_sll_remove_start_2";
        ret = test_fn();
        LOG_INF("%s ..... %s", test_name, ret == ERR_INVALID_PARAMS ? "SUCCESS" : "FAILED");

    } while(0);
}


static int test_sll_remove_start_1(void)
{
    int ret = ERR_OK;
    int value = 10;
    single_linked_list_t *list = NULL;
    do {
        ret = sll_create(&list);
        if (ret != ERR_OK)
        {
            break;
        }

        ret = sll_add_start(list, &value, sizeof(value));
        if (ret != ERR_OK)
        {
            break;
        }
        ret = sll_add_start(list, &value, sizeof(value));
        if (ret != ERR_OK)
        {
            break;
        }
        ret = sll_add_start(list, &value, sizeof(value));
        if (ret != ERR_OK)
        {
            break;
        }

        ret = sll_remove_start(list);
        if (ret != ERR_OK)
        {
            break;
        }
        ret = sll_remove_start(list);
        if (ret != ERR_OK)
        {
            break;
        }
        ret = sll_remove_start(list);
        if (ret != ERR_OK)
        {
            break;
        }

        if (0 != sll_length(list)) {
            ret = ERR_GENERIC;
        }
    } while(0);
    return ret;
}
static int test_sll_remove_start_2(void)
{
    int ret = ERR_GENERIC;
    ret = sll_remove_start(NULL);
    return ret;
}
int main(void)
{

    test_sll_create();
    test_sll_destroy();
    test_sll_add_start();
    test_sll_add_end();
    test_sll_add_pos();
    test_sll_remove_start();

    return 0;
}
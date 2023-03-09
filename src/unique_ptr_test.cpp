#include "unique_ptr.h"
#include "unique_ptr_test.h"
#include <utility>
#include <cassert>

void UniquePtrTest::TestMoveConstructor()
{
    UniquePtr<int> a{new int{2}};

    UniquePtr<int> b{std::move(a)};
}

void UniquePtrTest::TestOperators()
{
    UniquePtr<int> a{new int{2}};

    assert(*a == 2);

    struct Foo
    {
        int a;
        int b;
        Foo(int a_, int b_) : a(a_), b(b_) {}
    };

    UniquePtr<Foo> ptr{new Foo{2, 3}};
    assert(ptr->a == 2);
    assert(ptr->b == 3);
}

void UniquePtrTest::TestAll()
{
    TestMoveConstructor();
    TestOperators();
}
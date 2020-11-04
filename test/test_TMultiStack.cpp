#include "MultiStack.h"
#include <gtest.h>

TEST(TMultiStack, can_create_MultiStack_with_positive_length)
{
  ASSERT_NO_THROW(TMultiStack<int> tmp(5, 4));
}

TEST(TMultiStack, cant_create_MultiStack_with_null)
{
	ASSERT_ANY_THROW(TMultiStack<int> tmp(0));
}

TEST(TMultiStack, check_empty_MultiStack)
{
	TMultiStack<int> tmp(5, 4);

	EXPECT_EQ(true, tmp.IsEmpty(1));
}

TEST(TMultiStack, check_for_non_existent_empty_MultiStack)
{
	TMultiStack<int> tmp(5, 4);

	ASSERT_ANY_THROW(tmp.IsEmpty(5));
}

TEST(TMultiStack, check_negative_empty_MultiStack)
{
	TMultiStack<int> tmp(5, 4);

	ASSERT_ANY_THROW(tmp.IsEmpty(-5));
}

TEST(TMultiStack, check_IsFull_MultiStack)
{
	TMultiStack<int> tmp(5, 4);

	EXPECT_EQ(false, tmp.IsFull(1));
}

TEST(TMultiStack, check_for_non_existent_IsFull_MultiStack)
{
	TMultiStack<int> tmp(5, 4);

	ASSERT_ANY_THROW(tmp.IsFull(5));
}

TEST(TMultiStack, check_negative_IsFull_MultiStack)
{
	TMultiStack<int> tmp(5, 4);

	ASSERT_ANY_THROW(tmp.IsFull(-5));
}

TEST(TMultiStack, can_push_with_mem)
{
	TMultiStack<int> tmp(5, 4);

	ASSERT_NO_THROW(tmp.Push(10, 1));
}

TEST(TMultiStack, cant_push_with_no_mem)
{
	TMultiStack<int> tmp(5, 4);

	ASSERT_ANY_THROW(tmp.Push(10, 5));
}

TEST(TMultiStack, can_copy_stack)
{
	TMultiStack<int> tmp1(5, 4);
	tmp1.Push(10, 1);

	ASSERT_NO_THROW(TMultiStack<int> tmp2(tmp1));
}

TEST(TMultiStack, can_assing_stack)
{
	TMultiStack<int> tmp1(5, 4);
	tmp1.Push(10, 1);
	TMultiStack<int> tmp2(5, 4);
	tmp2 = tmp1;

	EXPECT_EQ(10, tmp2.Get(1));
}

TEST(TMultiStack, can_get)
{
	TMultiStack<int> tmp(5, 4);
	tmp.Push(10, 1);

	ASSERT_NO_THROW(tmp.Get(1));
}

TEST(TMultiStack, cant_get_nonexistent)
{
	TMultiStack<int> tmp(5, 4);
	tmp.Push(10, 1);

	ASSERT_ANY_THROW(tmp.Get(-4));
}

TEST(TMultiStack, cant_get_negative)
{
	TMultiStack<int> tmp1(5, 4);
	tmp1.Push(10, 1);

	ASSERT_ANY_THROW(tmp1.Get(5));
}

TEST(TMultiStack, can_GetSize)
{
	TMultiStack<int> tmp1(5, 4);

	ASSERT_NO_THROW(tmp1.GetSize());
}

TEST(TMultiStack, can_Resize)
{
	TMultiStack<int> tmp1(1, 1);
	tmp1.Push(10, 0);

	ASSERT_NO_THROW(tmp1.Resize(5, 0));
}

TEST(TMultiStack, cant_Resize_negative)
{
	TMultiStack<int> tmp1(1, 1);
	tmp1.Push(10, 0);

	ASSERT_ANY_THROW(tmp1.Resize(-1, 0));
}

TEST(TMultiStack, can_StackRelocation)
{
	TMultiStack<int> tmp(5, 3);
	tmp.Push(11, 0);
	tmp.Push(12, 1);
	tmp.Push(12, 1);
	tmp.Push(12, 1);

	ASSERT_NO_THROW(tmp.Push(15, 1));
}
/*
TEST(TMultiStack, can_MaxElem)
{
	TMultiStack<int> tmp(2, 3);
	tmp.Push(20, 0);
	tmp.Push(30, 1);
	tmp.Push(40, 2);
	tmp.Push(50, 2);

	EXPECT_EQ(50, tmp.max_elem());
}

TEST(TMultiStack, can_MinElem)
{
	TMultiStack<int> tmp(2, 3);
	tmp.Push(10, 0);
	tmp.Push(5, 1);
	tmp.Push(2, 2);
	tmp.Push(13, 2);

	EXPECT_EQ(2, tmp.min_elem());
}
*/
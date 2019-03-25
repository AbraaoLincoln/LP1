#include <iterator> // begin(), end()

#include "gtest/gtest.h"
#include "../include/int_ranges.h"

using namespace ir;

TEST(IntRange, NegateBasic)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ -1, -2, -3, -4, -5 };

    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, NegateZeros)
{
    ir::value_type A[]{ 0, 0, 0, 0, 0 };
    ir::value_type A_E[]{ 0, 0, 0, 0, 0 };

    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, NegateMixed)
{
    ir::value_type A[]{ 0, -2, 1, -3, 0 };
    ir::value_type A_E[]{ 0, 2, -1, 3, 0 };

    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, MinBasic)
{
    ir::value_type A[]{ 1, 2, -3, 4, 0 };

    auto result = ir::min( std::begin(A), std::end(A) );
    ASSERT_EQ( result , std::begin(A)+2 );
}

TEST(IntRange, MinFirstOcurrence)
{
    ir::value_type A[]{ 1, 1, 1, 1, 1 };

    auto result = ir::min( std::begin(A), std::end(A) );
    ASSERT_EQ( result , std::begin(A) );
}
TEST(IntRange, ReverseEntireArratyEven)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 6, 5, 4, 3, 2, 1 };

    ir::reverse( std::begin(A), std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, ReverseEntireArratyOdd)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ 5, 4, 3, 2, 1 };

    ir::reverse( std::begin(A), std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, ReversePartOfArrayEven)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6, 7 };
    ir::value_type A_E[]{ 1, 2, 6, 5, 4, 3, 7 };

    ir::reverse( std::begin(A)+2, std::begin(A)+6 );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, ReversePartOfArrayOdd)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6, 7 };
    ir::value_type A_E[]{ 1, 6, 5, 4, 3, 2, 7 };

    ir::reverse( std::begin(A)+1, std::begin(A)+6 );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, RotateBasic_0_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 1, 2, 3, 4, 5, 6 };

    ir::rotate( std::begin(A), std::begin(A), std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, RotateBasic_1_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 2, 3, 4, 5, 6, 1 };

    ir::rotate( std::begin(A), std::begin(A)+1, std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, RotateBasic_2_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 3, 4, 5, 6, 1, 2 };

    ir::rotate( std::begin(A), std::begin(A)+2, std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, RotateBasic_3_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 4, 5, 6, 1, 2, 3 };

    ir::rotate( std::begin(A), std::begin(A)+3, std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, RotateBasic_4_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 5, 6, 1, 2, 3, 4 };

    ir::rotate( std::begin(A), std::begin(A)+4, std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, RotateBasic_5_moves)
{
    ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
    ir::value_type A_E[]{ 6, 1, 2, 3, 4, 5 };

    ir::rotate( std::begin(A), std::begin(A)+5, std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, ScalarBasic)
{
    int Vet[] = {1, 2, -3, -4, 5, -6};
    int Vet_E[] = { 3 , 6 , -9 , -12 , 15 , -18 };
    ir::scalar_multiplication(std::begin(Vet), std::end(Vet), 3);
    ASSERT_TRUE(std::equal(std::begin(Vet), std::end(Vet), std::begin(Vet_E)));
}

TEST(IntRange, ScalarNegative)
{
    int Vet[] = {1, 2, -3, -4, 5, -6};
    int Vet_E[] = { -3 , -6 , 9 , 12 , -15 , 18 };
    ir::scalar_multiplication(std::begin(Vet), std::end(Vet), -3);
    ASSERT_TRUE(std::equal(std::begin(Vet), std::end(Vet), std::begin(Vet_E)));
}

TEST(IntRange, ProScalarBasic)
{
    int Vet[] = {1 , 3 , -5 , 4 , -2 , -1 };
    auto result = ir::dot_product(std::begin(Vet), std::begin(Vet)+3, std::begin(Vet)+3);
    ASSERT_EQ(result, 3);
}

TEST(IntRange, CompactBasic)
{
    int Vet[] = {-2, -8, 2, 7, -3, 10, 1, 0, -3, 7};
    int Vet_E[] = {2, 7 ,10 ,1 ,7, -2, -8, 0, -3, -3, -2};
    auto result = ir::compact(std::begin(Vet), std::end(Vet));
    ASSERT_TRUE(std::equal(std::begin(Vet), std::end(Vet), std::begin(Vet_E)));
    ASSERT_EQ(*result, *(std::begin(Vet_E)+5)) << "Erro ponteiro!";
}

TEST(IntRange, UniqueBasic)
{
    int A[] = {1, 2, 1, 2, 3, 3, 1, 2, 4, 5, 3, 4, 5};
    int A_E[] = {1, 2, 3, 4, 5};
    auto result = ir::unique(std::begin(A), std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), std::begin(A)+5, std::begin(A_E)));
}

TEST(IntRange, BlackWhiteBasic)
{
    int A[] = {1, 0, 1, 0, 1, 0, 1, 1, 0, 1};
    int A_E[] = {0, 0, 0, 0, 1, 1, 1, 1, 1 ,1};
    auto result = ir::sort_marbles(std::begin(A), std::end(A));
    ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#include "gtest/gtest.h"
#include "classic_algs_exception.h"
#include "union_find.h"

namespace {

    TEST(union_find_test, quick_find_constuctor_test) {
        classic_algorithms::QuickFind testQF0(0);
        classic_algorithms::QuickFind testQF10(10);
        classic_algorithms::QuickFind testQF900(900);
        classic_algorithms::QuickFind testQF100000(100000);
        ASSERT_EQ(testQF0.count(), 0);
        ASSERT_EQ(testQF10.count(), 10);
        ASSERT_EQ(testQF900.count(), 900);
        ASSERT_EQ(testQF100000.count(), 100000);
    }

    TEST(union_find_test, quick_find_union_find_test) {
        classic_algorithms::QuickFind testQF(10);
        classic_algorithms::UnionFindInterface* testUnionFind = &testQF;

        testUnionFind->unionElements(0,1);
        testUnionFind->unionElements(0,2);

        ASSERT_EQ(testUnionFind->find(0), testUnionFind->find(1));
        ASSERT_EQ(testUnionFind->find(0), testUnionFind->find(2));
        for(uint32_t i =3; i < testUnionFind->count(); ++i){
            ASSERT_NE(testUnionFind->find(0), testUnionFind->find(i));
        }
    }

    TEST(union_find_test, quick_union_constructor_test) {
        classic_algorithms::QuickUnion testQU0;
        classic_algorithms::QuickUnion testQU1(100);
        classic_algorithms::QuickUnion testQU2(10000);
        classic_algorithms::QuickUnion testQU3(0xFFFFFFF);
        
        ASSERT_EQ(testQU0.count(), 0);
        ASSERT_EQ(testQU1.count(), 100);
        ASSERT_EQ(testQU2.count(), 10000);
        ASSERT_EQ(testQU3.count(), 0xFFFFFFF);
    }

    TEST(union_find_test, quick_union_union_find_test) {
        classic_algorithms::QuickUnion testQU(10);
        classic_algorithms::UnionFindInterface* testUnionFind = &testQU;

        testUnionFind->unionElements(0,1);
        testUnionFind->unionElements(1,2);

        ASSERT_EQ(testUnionFind->find(0), testUnionFind->find(1));
        ASSERT_EQ(testUnionFind->find(0), testUnionFind->find(2));
        for(uint32_t i =3; i < testUnionFind->count(); ++i){
            ASSERT_NE(testUnionFind->find(0), testUnionFind->find(i));
        }
    }

    TEST(union_find_test, weighted_quick_union_constructor_test) {
        classic_algorithms::WeightedQuickUnion testWQU0;
        classic_algorithms::WeightedQuickUnion testWQU1(100);
        classic_algorithms::WeightedQuickUnion testWQU2(10000);
        classic_algorithms::WeightedQuickUnion testWQU3(0xFFFFF);

        ASSERT_EQ(testWQU0.count(), 0);
        ASSERT_EQ(testWQU1.count(), 100);
        ASSERT_EQ(testWQU2.count(), 10000);
        ASSERT_EQ(testWQU3.count(), 0xFFFFF);
    }

    TEST(union_find_test, weighted_quick_union_union_find_test) {
        classic_algorithms::WeightedQuickUnion testWQU(10);
        classic_algorithms::UnionFindInterface* testUnionFind = &testWQU;

        ASSERT_THROW( testUnionFind->unionElements(0,100), classic_algorithms::InvalidArgEx);
        ASSERT_THROW( testUnionFind->unionElements(-1,5), classic_algorithms::InvalidArgEx);
        ASSERT_THROW( testUnionFind->unionElements(0,10), classic_algorithms::InvalidArgEx);
        ASSERT_NO_THROW(testUnionFind->unionElements(0,3));

        testUnionFind->unionElements(0,1);
        testUnionFind->unionElements(1,2);

        ASSERT_EQ(testUnionFind->find(0), testUnionFind->find(1));
        ASSERT_EQ(testUnionFind->find(0), testUnionFind->find(2));
        for(uint32_t i = 4; i < testUnionFind->count(); ++i){
            ASSERT_NE(testUnionFind->find(0), testUnionFind->find(i));
        }
    }

    TEST(union_find_test, weighted_quick_with_pc_constructor_test) {
        classic_algorithms::WeightedQuickUnionPC testWQUPC0;
        classic_algorithms::WeightedQuickUnionPC testWQUPC1(100);
        classic_algorithms::WeightedQuickUnionPC testWQU2(10000);
        classic_algorithms::WeightedQuickUnionPC testWQU3(0xFFFFFF);

        ASSERT_EQ(testWQUPC0.count(), 0);
        ASSERT_EQ(testWQUPC1.count(), 100);
        ASSERT_EQ(testWQU2.count(), 10000);
        ASSERT_EQ(testWQU3.count(), 0xFFFFFF);
    }

    TEST(union_find_test, weighted_quick_with_pc_union_union_find_test) {
        classic_algorithms::WeightedQuickUnionPC testWQU(10);
        classic_algorithms::UnionFindInterface* testUnionFind = &testWQU;

        ASSERT_THROW( testUnionFind->unionElements(0,100), classic_algorithms::InvalidArgEx);
        ASSERT_THROW( testUnionFind->unionElements(-1,5), classic_algorithms::InvalidArgEx);
        ASSERT_THROW( testUnionFind->unionElements(0,10), classic_algorithms::InvalidArgEx);
        ASSERT_NO_THROW(testUnionFind->unionElements(0,3));

        testUnionFind->unionElements(0,1);
        testUnionFind->unionElements(1,2);

        ASSERT_EQ(testUnionFind->find(0), testUnionFind->find(1));
        ASSERT_EQ(testUnionFind->find(0), testUnionFind->find(2));
        for(uint32_t i = 4; i < testUnionFind->count(); ++i){
            ASSERT_NE(testUnionFind->find(0), testUnionFind->find(i));
        }
    }
}



/*
TEST(test_case_name, test_name) {
... test body ...
}

ASSERT_TRUE(condition); 	    EXPECT_TRUE(condition); 	    condition is true 
ASSERT_FALSE(condition); 	    EXPECT_FALSE(condition); 	    condition is false 

ASSERT_EQ(expected, actual);	EXPECT_EQ(expected, actual);	expected == actual 
ASSERT_NE(val1, val2);      	EXPECT_NE(val1, val2);      	val1 != val2 
ASSERT_LT(val1, val2);          EXPECT_LT(val1, val2); 	        val1 < val2 
ASSERT_LE(val1, val2); 	        EXPECT_LE(val1, val2);      	val1 <= val2 
ASSERT_GT(val1, val2); 	        EXPECT_GT(val1, val2); 	        val1 > val2 
ASSERT_GE(val1, val2); 	        EXPECT_GE(val1, val2);      	val1 >= val2

ASSERT_STREQ(expected_str, actual_str); 	   EXPECT_STREQ(expected_str, actual_str); 	     the two C strings have the same content 
ASSERT_STRNE(str1, str2); 	                   EXPECT_STRNE(str1, str2); 	                 the two C strings have different content 
ASSERT_STRCASEEQ(expected_str, actual_str);	   EXPECT_STRCASEEQ(expected_str, actual_str); 	 the two C strings have the same content, ignoring case 
ASSERT_STRCASENE(str1, str2);	               EXPECT_STRCASENE(str1, str2); 	             the two C strings have different content, ignoring case

*/


int main(int argc, char** argv){
    classic_algorithms::QuickUnion testQU10(10);
    std::cout << testQU10;
    try{
        // throw classic_algorithms::ClassicAlgEx("shit happens", __FILE__, __FUNCTION__, __LINE__);
        throw classic_algorithms::ClassicAlgEx();
        throw classic_algorithms::InvalidArgEx();
        throw classic_algorithms::InvalidArgEx("myArg");
        throw classic_algorithms::InvalidArgEx("myArg", __FILE__, __FUNCTION__, __LINE__);
    }catch(const std::exception& ex){
        std::wcout << ex.what() << std::endl;
    }

    ::testing::InitGoogleTest(&argc, argv);
    auto ret =  RUN_ALL_TESTS();
    std::getchar();
    return ret;

}
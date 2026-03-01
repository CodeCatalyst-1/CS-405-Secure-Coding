// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"

#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stdexcept>

//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    void SetUp() override
    {
        // initialize random seed
        srand(static_cast<unsigned>(time(nullptr)));
    }

    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    {
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    {
        collection->clear();
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing
// Use EXPECT when failure should notify, but processing should continue

TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    ASSERT_TRUE(collection);
    ASSERT_NE(collection.get(), nullptr);
}

TEST_F(CollectionTest, IsEmptyOnCreate)
{
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);
}

/* ORIGINAL FAILING TEST — COMMENTED OUT PER ASSIGNMENT INSTRUCTIONS
TEST_F(CollectionTest, AlwaysFail)
{
  FAIL();
}
*/

// ======================
// STUDENT-COMPLETED TESTS
// ======================

// Verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    add_entries(1);

    EXPECT_FALSE(collection->empty());
    EXPECT_EQ(collection->size(), 1);
}

// Verify adding five values to the collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    add_entries(5);

    EXPECT_EQ(collection->size(), 5);
    EXPECT_FALSE(collection->empty());
}

// Verify max_size >= size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, MaxSizeIsGreaterThanOrEqualToSize)
{
    EXPECT_GE(collection->max_size(), collection->size());

    add_entries(1);
    EXPECT_GE(collection->max_size(), collection->size());

    add_entries(4);
    EXPECT_GE(collection->max_size(), collection->size());

    add_entries(5);
    EXPECT_GE(collection->max_size(), collection->size());
}

// Verify capacity >= size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CapacityIsGreaterThanOrEqualToSize)
{
    EXPECT_GE(collection->capacity(), collection->size());

    add_entries(1);
    EXPECT_GE(collection->capacity(), collection->size());

    add_entries(4);
    EXPECT_GE(collection->capacity(), collection->size());

    add_entries(5);
    EXPECT_GE(collection->capacity(), collection->size());
}

// Verify resizing increases the collection
TEST_F(CollectionTest, ResizeIncreasesCollectionSize)
{
    collection->resize(5);

    EXPECT_EQ(collection->size(), 5);
}

// Verify resizing decreases the collection
TEST_F(CollectionTest, ResizeDecreasesCollectionSize)
{
    add_entries(10);
    collection->resize(5);

    EXPECT_EQ(collection->size(), 5);
}

// Verify resizing decreases the collection to zero
TEST_F(CollectionTest, ResizeToZeroClearsCollection)
{
    add_entries(5);
    collection->resize(0);

    EXPECT_TRUE(collection->empty());
    EXPECT_EQ(collection->size(), 0);
}

// Verify clear erases the collection
TEST_F(CollectionTest, ClearErasesCollection)
{
    add_entries(5);
    collection->clear();

    EXPECT_TRUE(collection->empty());
    EXPECT_EQ(collection->size(), 0);
}

// Verify erase(begin, end) erases the collection
TEST_F(CollectionTest, EraseBeginToEndClearsCollection)
{
    add_entries(5);
    collection->erase(collection->begin(), collection->end());

    EXPECT_TRUE(collection->empty());
    EXPECT_EQ(collection->size(), 0);
}

// Verify reserve increases capacity but not size
TEST_F(CollectionTest, ReserveIncreasesCapacityOnly)
{
    collection->reserve(50);

    EXPECT_GE(collection->capacity(), 50);
    EXPECT_EQ(collection->size(), 0);
}

// NEGATIVE TEST: Verify at() throws std::out_of_range for invalid index
TEST_F(CollectionTest, AtThrowsOutOfRangeException)
{
    add_entries(5);

    EXPECT_THROW(collection->at(10), std::out_of_range);
}

// CUSTOM POSITIVE TEST: Verify front() returns first element
TEST_F(CollectionTest, FrontReturnsFirstElement)
{
    collection->push_back(42);

    EXPECT_EQ(collection->front(), 42);
}

// CUSTOM NEGATIVE TEST: Verify at() throws when accessing empty vector
TEST_F(CollectionTest, AtThrowsExceptionOnEmptyVector)
{
    EXPECT_THROW(collection->at(0), std::out_of_range);
}

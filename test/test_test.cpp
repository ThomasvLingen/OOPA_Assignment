//
// Created by mafn on 4/7/16.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(Dummy, zoodle) {
    EXPECT_EQ(1, 1);
}

GTEST_API_ main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

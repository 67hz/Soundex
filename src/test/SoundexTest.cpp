#include <gtest/gtest.h>
#include "Soundex.hpp"


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class SoundexEncoding : public testing::Test {
protected:
    Soundex soundex;
};


TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    auto encoded = soundex.encode("A");

    ASSERT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    ASSERT_EQ(soundex.encode("I"), "I000");
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
    EXPECT_EQ(soundex.encode("Ab"), "A100");
    EXPECT_EQ(soundex.encode("Ac"), "A200");
    EXPECT_EQ(soundex.encode("Ad"), "A300");
}

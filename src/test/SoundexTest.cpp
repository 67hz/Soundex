#include <gtest/gtest.h>
#include "Soundex.cpp"


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

    ASSERT_EQ(encoded, "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    auto encoded = soundex.encode("I");
    ASSERT_EQ(encoded, "I000");
}

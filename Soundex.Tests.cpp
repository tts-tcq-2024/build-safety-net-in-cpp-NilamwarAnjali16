#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, BasicTest) {
    EXPECT_EQ(createSoundex("Smith"), "S530");
    EXPECT_EQ(createSoundex("Smyth"), "S530");
    EXPECT_EQ(createSoundex("Robert"), "R163");
    EXPECT_EQ(createSoundex("Rupert"), "R163");
    EXPECT_EQ(createSoundex("Ashcraft"), "A261");
    EXPECT_EQ(createSoundex("Ashcroft"), "A261");
}

TEST(SoundexTest, EdgeCases) {
    EXPECT_EQ(createSoundex("Chand"), "C530");
    EXPECT_EQ(createSoundex("Mehra"), "M600");
    EXPECT_EQ(createSoundex("Pandey"), "P530");
    EXPECT_EQ(createSoundex(""), "");
}

TEST(SoundexTest, CaseInsensitive) {
    EXPECT_EQ(createSoundex("Robert"), createSoundex("robert"));
    EXPECT_EQ(createSoundex("Smith"), createSoundex("sMiTh"));
}
TEST(SoundexTest, SingleCharacterName) {
    EXPECT_EQ(createSoundex("A"), "A000");
    EXPECT_EQ(createSoundex("B"), "B000");
}

TEST(SoundexTest, AllVowels) {
    EXPECT_EQ(createSoundex("Aeio"), "A000");
    EXPECT_EQ(createSoundex("Euio"), "E000");
}



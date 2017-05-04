// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <hex/dump.hpp>

#include <sstream>
#include <gtest/gtest.h>


TEST(test_dump, api)
{
    {
        std::string test = "hellohellohelloo";

        hex::dump hex((uint8_t*)test.c_str(), test.size());

        std::stringstream ss;

        ss << hex;

        EXPECT_EQ("0000  68 65 6c 6c 6f 68 65 6c 6c 6f 68 65 6c 6c 6f 6f  "
                  "hellohellohelloo\n", ss.str());
    }

    {
        std::vector<uint8_t> data1 =
            {
                0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
            };

        hex::dump hex(data1.data(), data1.size());
        std::stringstream ss;

        ss << hex;

        EXPECT_EQ("0000  01 02 03 04 05 06 07 08 01 02 03 04 05 06 07 08  "
                  "................\n", ss.str());

        auto data2 = hex::parse_hex_string(
            "01 02 03 04 05 06 07 08 01 02 03 04 05 06 07 08");

        EXPECT_EQ(data1, data2);
        EXPECT_EQ(hex, hex::dump(data2));
    }

    {
        std::vector<uint8_t> data1 =
            {
                0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                0xff, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                0x05, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                0xab, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
            };

        hex::dump hex(data1);
        std::stringstream ss;

        ss << hex;

        EXPECT_EQ("0000  01 02 03 04 05 06 07 08 ff 02 03 04 05 06 07 08  "
                  "................\n"
                  "0010  05 02 03 04 05 06 07 08 ab 02 03 04 05 06 07 08  "
                  "................\n",
                  ss.str());

        auto data2 = hex::parse_hex_string(
            "01 02 03 04 05 06 07 08 ff 02 03 04 05 06 07 08 "
            "05 02 03 04 05 06 07 08 ab 02 03 04 05 06 07 08");

        EXPECT_EQ(data1, data2);
        EXPECT_EQ(hex, hex::dump(data2));
    }
}

TEST(test_dump, set_size)
{
    {
        // 48 bytes
        std::vector<uint8_t> data =
            {
                0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                0x05, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
            };

        hex::dump hex(data.data(), data.size());
        hex.set_size(5);

        std::stringstream ss;
        ss << hex;

        EXPECT_EQ("0000  01 02 03 04 05                                   "
                  ".....\n"
                  "....\n"
                  "0030\n",
                  ss.str());
    }

    {
        // 48 bytes
        std::vector<uint8_t> data =
            {
                0x01, 0x02, 0x03, 0x04, 0x05
            };

        hex::dump hex(data.data(), data.size());
        hex.set_size(3);

        std::stringstream ss;
        ss << hex;

        EXPECT_EQ("0000  01 02 03                                         "
                  "...\n",
                  ss.str());
    }
}

// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <hex/dump.hpp>

#include <sstream>
#include <gtest/gtest.h>


TEST(test_hexdump, api)
{
    {
        std::string test = "hellohellohelloo";

        hex::dump hex(storage::storage(test));

        std::stringstream ss;

        ss << hex;

        EXPECT_EQ("0000  68 65 6c 6c 6f 68 65 6c 6c 6f 68 65 6c 6c 6f 6f  "
                  "hellohellohelloo\n", ss.str());
    }

    {
        std::vector<uint8_t> data =
            { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
              0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };

        hex::dump hex(storage::storage(data));
        std::stringstream ss;

        ss << hex;

        EXPECT_EQ("0000  01 02 03 04 05 06 07 08 01 02 03 04 05 06 07 08  "
                  "................\n", ss.str());
    }

    {
        std::vector<uint8_t> data =
            { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
              0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
              0x05, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
              0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };

        hex::dump hex(storage::storage(data));
        std::stringstream ss;

        ss << hex;

        EXPECT_EQ("0000  01 02 03 04 05 06 07 08 01 02 03 04 05 06 07 08  "
                  "................\n"
                  "0010  05 02 03 04 05 06 07 08 01 02 03 04 05 06 07 08  "
                  "................\n",
                  ss.str());
    }

    {
        // 48 bytes
        std::vector<uint8_t> data =
            { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
              0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
              0x05, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
              0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
              0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
              0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

        hex::dump hex(storage::storage(data));
        hex.set_max_size(5);

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
        std::vector<uint8_t> data = { 0x01, 0x02, 0x03, 0x04, 0x05 };

        hex::dump hex(storage::storage(data));
        hex.set_max_size(3);

        std::stringstream ss;
        ss << hex;

        EXPECT_EQ("0000  01 02 03                                         "
                  "...\n",
                  ss.str());
    }
}

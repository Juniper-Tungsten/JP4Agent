//
// Test controller
//
/// @file  Controller.cpp
/// @brief Main file for Juniper P4 Agent
//
// Created by Sandesh Kumar Sodhi, November 2017
// Copyright (c) [2017] Juniper Networks, Inc. All rights reserved.
//
// All rights reserved.
//
// Notice and Disclaimer: This code is licensed to you under the Apache
// License 2.0 (the "License"). You may not use this code except in compliance
// with the License. This code is not an official Juniper product. You can
// obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Third-Party Code: This code may depend on other components under separate
// copyright notice and license terms. Your use of the source code for those
// components is subject to the terms and conditions of the respective license
// as noted in the Third-Party source code file.
//


#ifndef __Controller_Utils__
#define __Controller_Utils__

#include <chrono>
#include <string>
#include <typeinfo>

class Utils {
public:
    template <typename T>
    std::string uint2Str(T i)
    {
        std::string ret;

        if (typeid(T) == typeid(uint8_t)) {
            ret = std::string(reinterpret_cast<char *>(&i), sizeof(i));
        } else if (typeid(T) == typeid(uint16_t)) {
            i = htons(i);
            ret = std::string(reinterpret_cast<char *>(&i), sizeof(i));
        } else if (typeid(T) == typeid(uint32_t)) {
            i = htonl(i);
            ret = std::string(reinterpret_cast<char *>(&i), sizeof(i));
        } else if (typeid(T) == typeid(uint64_t)) {
            unsigned char c[6];

            for (int j = 5; j > 0; j--) {
                c[j] = i & 0xff;
                i = i >> 8;
            }
            c[0] = i & 0xff;

            ret = std::string(reinterpret_cast<const char *>(c), sizeof(c));
        }

        return ret;
    }
};

#endif // __Controller_Utils__

#pragma region LICENSE

// MIT License
// 
// Copyright (c) 2024 Rohan Bharatia

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma endregion LICENSE

#pragma once

#ifndef _DATA_BUS_cpp_
#define _DATA_BUS_cpp_

#include "include/bus/data-bus.hpp"
#include "include/gate.hpp"

Gate gate;

bool Bus::data_bus(bool d)
{
    return d;
}

bool Bus::buffer1(bool d, bool e)
{
    return gate.OR(gate.AND(d, e), gate.AND(gate.NOT(e), NULL));
}

std::array<bool, 4> Bus::buffer4(std::array<bool, 4> d, bool e)
{
    return                \
    {
        buffer1(d[0], e),
        buffer1(d[1], e),
        buffer1(d[2], e),
        buffer1(d[3], e)
    };
}

#endif // _DATA_BUS_cpp_
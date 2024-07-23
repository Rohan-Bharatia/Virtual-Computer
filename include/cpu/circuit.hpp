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

#ifndef _CPU_CIRCUIT_hpp_
#define _CPU_CIRCUIT_hpp_

// std
#include <array>

class Circuit
{
public:
    std::array<bool, 2> adder1(bool a, bool b, bool carry);
    std::array<bool, 5> adder4(std::array<bool, 4> a, std::array<bool, 4> b, bool carry);

    std::array<bool, 7> ALU(std::array<bool, 4> a, std::array<bool, 4> b, bool sub);

    bool register1(bool d, bool s, bool c);
    std::array<bool, 4> register4(std::array<bool, 4> d, bool s, bool c);

    std::array<bool, 8> negate(std::array<bool, 8> d);

    std::array<bool, 4> multiplexer1(std::array<bool, 4> a, std::array<bool, 4> b, bool s);
    std::array<bool, 4> multiplexer4(std::array<bool, 4> a, std::array<bool, 4> b, std::array<bool, 4> c, std::array<bool, 4> d, bool s1, bool s2);
};

#endif // _CPU_CIRCUIT_hpp_
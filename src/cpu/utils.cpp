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

#ifndef _UTILS_cpp_
#define _UTILS_cpp_

#include "include/cpu/circuit.hpp"
#include "include/gate.hpp"

Gate gate;

std::array<bool, 8> Circuit::negate(std::array<bool, 8> d)
{
    return                                                                                                                                                                                                                                \
    {
        adder4({gate.XOR(d[0], true), gate.XOR(d[1], true), gate.XOR(d[2], true), gate.XOR(d[3], true)}, {false}, adder4({gate.XOR(d[4], true), gate.XOR(d[5], true), gate.XOR(d[6], true), gate.XOR(d[7], true)}, {false}, true)[4])[0],
        adder4({gate.XOR(d[0], true), gate.XOR(d[1], true), gate.XOR(d[2], true), gate.XOR(d[3], true)}, {false}, adder4({gate.XOR(d[4], true), gate.XOR(d[5], true), gate.XOR(d[6], true), gate.XOR(d[7], true)}, {false}, true)[4])[1],
        adder4({gate.XOR(d[0], true), gate.XOR(d[1], true), gate.XOR(d[2], true), gate.XOR(d[3], true)}, {false}, adder4({gate.XOR(d[4], true), gate.XOR(d[5], true), gate.XOR(d[6], true), gate.XOR(d[7], true)}, {false}, true)[4])[2],
        adder4({gate.XOR(d[0], true), gate.XOR(d[1], true), gate.XOR(d[2], true), gate.XOR(d[3], true)}, {false}, adder4({gate.XOR(d[4], true), gate.XOR(d[5], true), gate.XOR(d[6], true), gate.XOR(d[7], true)}, {false}, true)[4])[3],
        adder4({gate.XOR(d[4], true), gate.XOR(d[5], true), gate.XOR(d[6], true), gate.XOR(d[7], true)}, {false}, true)[0],
        adder4({gate.XOR(d[4], true), gate.XOR(d[5], true), gate.XOR(d[6], true), gate.XOR(d[7], true)}, {false}, true)[1],
        adder4({gate.XOR(d[4], true), gate.XOR(d[5], true), gate.XOR(d[6], true), gate.XOR(d[7], true)}, {false}, true)[2],
        adder4({gate.XOR(d[4], true), gate.XOR(d[5], true), gate.XOR(d[6], true), gate.XOR(d[7], true)}, {false}, true)[3]
    };
}

std::array<bool, 4> Circuit::multiplexer1(std::array<bool, 4> a, std::array<bool, 4> b, bool s)
{
    return                                                       \
    {
        gate.OR(gate.AND(a[0], gate.NOT(s)), gate.AND(b[0], s)),
        gate.OR(gate.AND(a[1], gate.NOT(s)), gate.AND(b[1], s)),
        gate.OR(gate.AND(a[2], gate.NOT(s)), gate.AND(b[2], s)),
        gate.OR(gate.AND(a[3], gate.NOT(s)), gate.AND(b[3], s))
    };
}

std::array<bool, 4> Circuit::multiplexer4(std::array<bool, 4> a, std::array<bool, 4> b, std::array<bool, 4> c, std::array<bool, 4> d, bool s1, bool s2)
{
    return multiplexer1(multiplexer1(a, b, s1), multiplexer1(c, d, s2), gate.OR(s1, s2));
}

#endif // _UTILS_cpp_
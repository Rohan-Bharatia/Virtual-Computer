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

#ifndef _ADDER_cpp_
#define _ADDER_cpp_

#include "include/cpu/circuit.hpp"
#include "include/gate.hpp"

Gate gate;

std::array<bool, 2> Circuit::adder1(bool a, bool b, bool carry)
{
    return {gate.XOR(gate.XOR(a, b), carry), gate.OR(gate.AND(gate.XOR(a, b), carry), gate.AND(a, b))};
}

std::array<bool, 5> Circuit::adder4(std::array<bool, 4> a, std::array<bool, 4> b, bool carry)
{
    return                                                                                                 \
    {
        adder1(a[3], b[3], carry)[0],
        adder1(a[2], b[2], adder1(a[3], b[3], carry)[1])[0],
        adder1(a[1], b[1], adder1(a[3], b[3], adder1(a[2], b[2], carry)[1])[1])[0],
        adder1(a[0], b[0], adder1(a[3], b[3], adder1(a[2], b[2], adder1(a[1], b[1], carry)[1])[1])[1])[0],
        adder1(a[0], b[0], adder1(a[3], b[3], adder1(a[2], b[2], adder1(a[1], b[1], carry)[1])[1])[1])[1]
    };
}

#endif // _ADDER_cpp_
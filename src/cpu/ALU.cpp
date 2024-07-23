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

#ifndef _ALU_cpp_
#define _ALU_cpp_

#include "include/cpu/circuit.hpp"
#include "include/gate.hpp"

Gate gate;

std::array<bool, 7> Circuit::ALU(std::array<bool, 4> a, std::array<bool, 4> b, bool sub)
{
    return                                                                                                                  \
    {
        adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub), gate.XOR(b[3], sub)}, sub)[0],
        adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub), gate.XOR(b[3], sub)}, sub)[1],
        adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub), gate.XOR(b[3], sub)}, sub)[2],
        adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub), gate.XOR(b[3], sub)}, sub)[3],
        adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub), gate.XOR(b[3], sub)}, sub)[4],
        adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub), gate.XOR(b[3], sub)}, sub)[0],
        gate.AND(gate.AND(gate.AND(gate.NOT(adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub),
        gate.XOR(b[3], sub)}, sub)[0]), gate.NOT(adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub),
        gate.XOR(b[3], sub)}, sub)[1])), gate.NOT(adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub),
        gate.XOR(b[3], sub)}, sub)[2])), gate.NOT(adder4(a, {gate.XOR(b[0], sub), gate.XOR(b[1], sub), gate.XOR(b[2], sub),
        gate.XOR(b[3], sub)}, sub)[3]))
    };
}

#endif // _ALU_hpp_
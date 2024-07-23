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

#ifndef _REGISTER_cpp_
#define _REGISTER_cpp_

#include "include/cpu/circuit.hpp"
#include "include/gate.hpp"
#include "include/7-segment-display.hpp"

Gate gate;
Gate::Latch latch;
Display display;


bool Circuit::register1(bool d, bool s, bool c)
{
    return latch.D_FF(gate.OR(gate.AND(register1, gate.NOT(s)), gate.AND(d, s)), c);
}

std::array<bool, 4> Circuit::register4(std::array<bool, 4> d, bool s, bool c)
{
    display.display3(0, 0, 0, 0, d[0], d[1], d[2], d[3]);
    
    return                     \
    {
        register1(d[0], s, c),
        register1(d[1], s, c),
        register1(d[2], s, c),
        register1(d[3], s, c)
    };
}

#endif // _REGISTER_cpp_
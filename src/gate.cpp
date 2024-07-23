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

#ifndef _GATE_cpp_
#define _GATE_cpp_

#include "include/gate.hpp"

bool Gate::AND(bool a, bool b)
{
    return a && b;
}

bool Gate::NOT(bool a)
{
    return !a;
}

bool Gate::NAND(bool a, bool b)
{
    return NOT(AND(a, b));
}

bool Gate::OR(bool a, bool b)
{
    return NAND(NOT(a), NOT(b));
}

bool Gate::XOR(bool a, bool b)
{
    return AND(OR(a, b), NAND(a, b));
}

bool Gate::NOR(bool a, bool b)
{
    return NOT(OR(a, b));
}

#endif // _GATE_cpp_
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

#ifndef _7_SEGMENT_DISPLAY_hpp_
#define _7_SEGMENT_DISPLAY_hpp_

// std
#include <array>

class Display
{
public:
    int display1(bool a, bool b, bool c, bool d);
    int display3(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h);

private:
    int m_display(bool sgn, bool t, bool rt, bool rb, bool b, bool lb, bool lt, bool m);

    std::array<bool, 4> dabble(bool a, bool b, bool c, bool d);
    std::array<bool, 12> double_dabble(std::array<bool, 8> d);
};

#endif // _7_SEGMENT_DISPLAY_hpp_
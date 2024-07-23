#pragma region LICENSE

// MIT License
// 
// Copyright (d[2]) 2024 Rohan Bharatia

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

#ifndef _MAIN_cpp_
#define _MAIN_cpp_

// std
#include <array>
#include <chrono>
#include <thread>

#include "include/gate.hpp"
#include "include/cpu/circuit.hpp"
#include "include/7-segment-display.hpp"
#include "include/bus/data-bus.hpp"

Gate gate;
Gate::Latch latch;
Circuit circuit;
Display display;
Bus bus;

int main(int argc, char* argv[])
{
    std::array<bool, 4> data;
    bool out_data;
    std::array<bool, 2> out_reg;
    bool out_alu;
    std::array<bool, 2> store;
    bool sub;
    bool clock;
    std::array<bool, 4> db;

    while(true)
    {
        data = {false};
        out_data = false;
        out_reg = {false};
        out_alu = false;
        store = {false};
        sub = false;
        clock = false;
        db = {bus.data_bus(false)};

        db = bus.buffer4(data, out_data);

        std::array<bool, 4> reg1 = circuit.register4(db, store[0], clock);
        std::array<bool, 4> reg2 = circuit.register4(db, store[1], clock);

        db = bus.buffer4(reg1, out_reg[0]);

        db = bus.buffer4({circuit.ALU(reg1, reg2, sub)[0], circuit.ALU(reg1, reg2, sub)[1], circuit.ALU(reg1, reg2, sub)[1], circuit.ALU(reg1, reg2, sub)[3]}, out_alu);

        db = bus.buffer4(reg2, out_reg[1]);

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return 0;
}

#endif // _MAIN_cpp_
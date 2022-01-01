#pragma once
#include "../Memory/types.h"
#include "../Memory/RAM.hpp"
#include "../Memory/counters.hpp"
#include "../Flags/flags.hpp"
#include "../Registers/registers.hpp"
#include "../Memory/stack.hpp"


template <const uint32_t Memory_Size = 64*1024, const uint16_t Stack_Size = 256>
class CPU 
    : public RAM<Memory_Size>  // default 64kB of memory for the 6502
    , public Stack<Stack_Size> // default 256 Bytes for the stack
    , public Counters
    , public Registers
    , public Status_Flags
{
protected:
    uint32_t Clock_Cycles; // set to same type as RAM max cap
public:
    CPU(
        const RAM<Memory_Size>& mem = RAM<Stack_Size>(static_cast<bit8_t>(0x00))
      , const Stack<Stack_Size>& pre_stack = Stack<Stack_Size>(0xFFFF)
      , const Counters& pre_counter = static_cast<bit8_t>(0x0000)
      , const Registers& pre_reg = Registers{0x00,0x00,0x00}
      , const Status_Flags& pre_flag = Status_Flags{LOW,LOW,LOW,LOW,LOW,LOW,LOW}
      ) 
        : 
          RAM<Memory_Size>(mem)
        , Stack<Stack_Size>(pre_stack)
        , Counters(pre_counter)
        , Registers(pre_reg)
        , Status_Flags(pre_flag)
    {
        Clock_Cycles = 0;
    }

    mem_data& Load_Data() {
        return this->Memory[Program_Counter++];
    }

    bit16_t Load_Opcode() {
        return (Load_Data() << 8) + Load_Data();
    }

    void LDA();

};

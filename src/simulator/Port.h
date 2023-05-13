#ifndef FPGA_OBFUSCATOR_SIMULATOR_PORT_H
#define FPGA_OBFUSCATOR_SIMULATOR_PORT_H

#include "StandardHeaders.h"

namespace FPGAObfuscatorSimulator
{
    using Bit = std::uint_fast8_t;

    class Port
    {
      public:
        static inline constexpr Bit LOW  = 0;
        static inline constexpr Bit HIGH = 1;

      public:
        Bit state;

      public:
        void SetLow();
        void SetHigh();
    };
}

#endif

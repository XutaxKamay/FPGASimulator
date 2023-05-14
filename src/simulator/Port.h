#ifndef VFPGA_OBFUSCATOR_SIMULATOR_PORT_H
#define VFPGA_OBFUSCATOR_SIMULATOR_PORT_H

#include "StandardHeaders.h"

namespace VFPGAObfuscatorSimulator
{
    using Bit = std::uint_fast8_t;

    class Port
    {
      public:
        static inline constinit Bit LOW  = 0;
        static inline constinit Bit HIGH = 1;

      public:
        Bit state;

      public:
        void SetLow();
        void SetHigh();
    };
}

#endif

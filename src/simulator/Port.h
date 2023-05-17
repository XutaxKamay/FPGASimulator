#ifndef VFPGA_OBFUSCATOR_SIMULATOR_PORT_H
#define VFPGA_OBFUSCATOR_SIMULATOR_PORT_H

#include "Bit.h"
#include "SharedSerializedTypes.h"

namespace VFPGAObfuscatorSimulator
{

    class Port
    {
      public:
        static inline constinit auto LOW  = 0_vfpga_obf_lib_bit;
        static inline constinit auto HIGH = 1_vfpga_obf_lib_bit;

      public:
        VFPGAObfuscatorLibrary::Bit state;

      public:
        void SetLow();
        void SetHigh();
    };
}

#endif

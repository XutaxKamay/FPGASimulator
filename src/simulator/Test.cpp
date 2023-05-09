#include "FPGA.h"
#include "Timer.h"

using namespace FPGASimulator;

static constexpr EncodedIndex operator""_p(unsigned long long index)
{
    return index;
}

static constexpr Bit operator""_b(unsigned long long index)
{
    return index;
}

int main()
{
    std::cout << "Serializing test ...\n";

    std::vector<LogicGate::Serializer> logicGatesSerializer;

    logicGatesSerializer.push_back({
      { 0_p },
      { 1_p },
      { { 0_b }, { 1_b } },
      { { 1_b }, { 0_b } }
    });

    for (std::size_t index = 2; index < 600002; index += 2)
    {
        logicGatesSerializer.push_back({
          { index },
          { index + 1 },
          { { 0_b }, { 1_b } },
          { { 1_b }, { 0_b } }
        });

        logicGatesSerializer.push_back({
          { index + 1 },
          { index },
          { { 0_b }, { 1_b } },
          { { 1_b }, { 0_b } }
        });
    }

    FPGA::Serializer fpgaSerializer { 600002, logicGatesSerializer };

    FPGA::Deserializer fpgaDeserializer;
    auto fpga = fpgaDeserializer.Deserialize(fpgaSerializer.Serialize());

    fpga.GetPort(0)->SetLow();
    std::cout << "FPGA test ... \n";

    Timer timerFPGA;
    Timer timerPrint;
    timerPrint.Start();

    std::int64_t averageTime      = 0;
    std::int64_t countAverageTime = 0;
    fpga.PrepareStages();

    while (true)
    {
        timerFPGA.Start();
        fpga.Simulate();
        timerFPGA.End();

        averageTime += timerFPGA.Difference();
        countAverageTime++;

        if (timerPrint.Seconds() >= 1)
        {
            std::cout << averageTime / countAverageTime
                      << " nanoseconds of average time in one second\n";
            countAverageTime = 0;
            averageTime      = 0;

            std::cout << "port 1 should have state 1: "
                      << fpga.GetPort(1)->state << '\n';

            timerPrint.Start();
        }
        else
        {
            timerPrint.End();
        }
    }
}

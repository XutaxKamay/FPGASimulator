# VFPGA (Virtual FPGA) Obfuscator

This is a very early version of a Virtual FPGA Obfuscator done for fun right now. It can only run logic gates in parallel in multiples stages.  
The end goal would be to use it as an obfuscation system and a way to learn how a CPU could work, where you can upload the bitstream to the FPGA from networks in an encrypted form.  
For example you would be able to run your custom virtual asynchronous soft-core where the CPU decrypts itself its instructions for funny things and CTFs built only from logic gates that runs in parallel inside your host CPU (GPU?). Or totally invent new stuffs.   

With time (quite a lot of it), I plan to implement these things:
- A similar HDL programming language where you can implement your own truth tables to write your own kind of operators to interact with variables (or anything else you want to call it for), the HDL language will or could be be just plain C++.
- Give an example of a small virtual soft-core connected to a virtual LCD and a virtual keyboard which could plays music for example. Soft-core too, with an assembler.
- Create logic gates that wouldn't be possible in real life.
- I have no idea much yet, but this is the best way I found to learn about the deep low-level stuffs without spending any pennies, but I'm sure it will end up useful in the future years as a reference, at least for myself.

Anyway, there isn't much yet to read because I want it easy to be read by other people so that even a 10 years old little guy/girl could read it without having headaches.  
This project also could be given up anytime or being taken back anytime, I just publish it because I'm not sure what I'm doing with my life (except contributing to the world with my own little force).

### You don't use getters and setters
https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-get

### How to compile
```
CXX='clang++ -march=native -Ofast' meson setup --buildtype=release build
meson compile -C build
```

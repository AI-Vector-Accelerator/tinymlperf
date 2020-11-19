# tinyMLPerf Deep Learning Benchmarks for Embedded Devices

The goal of TinyMLPerf is to provide a representative set of deep neural nets
and benchmarking code to compare performance between embedded devices. Embedded
devices include microcontrollers, DSPs, and tiny NN accelerators.  These devics
typically run at between 10MHz and 250MHz, and can perform inference using less
then 50mW of power.

TinyMLPerf submissions will allow device makers and researchers to choose the
best hardware for their use case, and allows hardware vendors to showcase their
offerings.

TinyMLPerf is primarily intended to benchmark hardware rather than new network
archietctures, or embedded neural net runtimes. The reference benchmarks are provided using
TensorFlow Lite for Microcontrollers (TFLM). Submitters can directly use the TFLM, although 
submitters are encouraged to use the software stack that works best on thier hardware.

To make:
`sudo apt-get install unzip` 
`cd v0.1`
`make clean`
`make TARGET_ARCH=cv32e40p or make TARGET_ARCH=riscv-linux`

verilator 
`make clean`
`make TARGET_ARCH=cv32e40p` 
`riscv32-unknown-elf-objcopy -O verilog  vww_perf_runner output.hex`
`testbench_verilator "+firmware=output.hex"`

spike
`make clean`
`make TARGET_ARCH=riscv-linux`
`spike  --isa=RV32IMCV     /opt/riscv/riscv32-unknown-elf/bin/pk vww_perf_runner`



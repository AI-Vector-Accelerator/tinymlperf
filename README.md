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

# CV32E40P Compilation

## Setup
The following commands will install the dependencies for this repository
```bash
sudo apt install unzip curl
``` 

## Building for CV32E40P Verilator Model
To build TinyMLPerf you must first navigate to the `./v0.1` directory.
```bash
cd ./v0.1
```

### Build for Standard ISA CV32E40P
```bash
make TARGET_ARCH=cv32e40p                                                       # Build the ELF File
riscv32-unknown-elf-objcopy -O verilog ./vww_perf_runner vww_perf_runner.hex    # Convert to HEX
testbench_verilator "+firmware=./vww_perf_runner.hex"                           # Execute on Verilator Model
```

### Build for ML Accelerated CV32E40P
```bash
make TARGET_ARCH=cv32e40p-ml                                                    # Build the ELF File
riscv32-unknown-elf-objcopy -O verilog ./vww_perf_runner vww_perf_runner.hex    # Convert to HEX
testbench_verilator "+firmware=./vww_perf_runner.hex"                           # Execute on Verilator Model
```

## Building for Spike
To build TinyMLPerf you must first navigate to the `./v0.1` directory.
```bash
cd ./v0.1
```

### Build for Standard ISA CV32E40P
```bash
make TARGET_ARCH=cv32e40p TAGS=spike                                                                        # Build the ELF File    
spike --isa=RV32IMCV --varch=vlen:32,elen:32,slen:32 /opt/riscv/riscv32-unknown-elf/bin/pk vww_perf_runner  # Execute on Spike set to mimic CV32E40P
```

### Build for ML Accelerated CV32E40P
```bash
make TARGET_ARCH=cv32e40p-ml TAGS=spike                                                                     # Build the ELF File    
spike --isa=RV32IMCV --varch=vlen:32,elen:32,slen:32 /opt/riscv/riscv32-unknown-elf/bin/pk vww_perf_runner  # Execute on Spike set to mimic CV32E40P
```

## Specify TensorFlow Version
These instructions allow a user to specify the version of TensorFlow on which TinyMLPerf is run.

1. Find the hash/sha of the commit you would like to use.
This can be on any branch, not just master.
2. Open the file `v0.1/example_submission/download_and_build_tfmicro.sh`
3. Replace the value of the variable TF_COMMIT_SHA with the hash/sha you found in step 1.
4. run `make clean` from within the dir `./v0.1` and delete the directory `v0.1/example_submission/tensorflow`  
This will ensure the new version of TensorFlow will be downloaded when the next make command is run.


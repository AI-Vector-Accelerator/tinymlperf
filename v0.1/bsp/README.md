# BSP Directory
This directory contains files and makefile.inc files for supporting different architectures.
Each subfolder represents a different architecture that this system supports. 

## Build system
A build is initiated by running `make` targeting the makefile in the top-level directory.
By default, this will build the benchmark for the host system. 

By specifying `TARGET_ARCH` in the make command e.g: `make TARGET_ARCH=cv32e40p` the makefile for the CV32E40P port of this system will be included.
This will set appropriate compiler options for this system and include any system-specific files at link-time, including an architecture specific port of tensorflow in the form of an archive file.

The makefile.inc file that is included is selected using the`TARGET_ARCH` makefile flag.
At the top of each makefile in the subdirectory the `TARGET_ARCH` file is evaluated. 
If it is found to be the same as a value it has been instructed to look out for (ideally the name of its subdirector e.g: cv32e40p).
If it is evaluated to be the same, the makefile.inc file's contents is run, else it does not run anything. 
All makefile.inc files in the bsp directory are included in the top-level makefile.
Making each included makefile evaluate the `TARGET_ARCH` flag ensures that only the contents of one included file is actually run.
# c_STM32F411RE
Bare-Metal Embedded C Programming with STM32 Nucleo-64 development board (STM32F411RE MCU).

# Software Prerequisites
* GNU Arm Embedded Toolchain: [Download Here](https://developer.arm.com/downloads/-/gnu-rm)
* OpenOCD: [Download Here](https://github.com/xpack-dev-tools/openocd-xpack/releases)
* GNU Make: [Download Here](https://gnuwin32.sourceforge.net/packages/make.htm)
* Add the executables as environment variables
* Download the STM32CubeF4 packages from [here](https://www.st.com/en/embedded-software/stm32cubef4.html) and copy the `Drivers/CMSIS/Include` folder and `Drivers/CMSIS/Device` folder to a new folder in the project root directory called `chip_headers/CMSIS`

# Build and Load Programs (using make)
* Move into the required project. (ex. cd p1_blinky)
* Run command `make final` to automatically build and link the program.
* Connect the development board.
* Run command `make load` to begin the uploading process.
* In another terminal run command `arm-none-eabi-gdb` to start the GDB. Run the following commands in the GDB terminal:
    * Run command `target remote localhost:3333` to connect to the microcontroller.
    * Run command `monitor reset init` to reset and initialize the board.
    * Run command `monitor flash write_image erase program.elf` to load the firmware onto the microcontroller.
    * Run command `monitor reset init` to reset the board.
    * Run command `monitor resume` to resume the execution of the firmware.
* Run command `make clean` to clean the build directory.

# Build and Load Programs
* Move into the required project. (ex. cd p1_blinky)
* Run command `arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 main.c -o
main.o` to comlipe the `main.c` file.
* Run command `arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 stm32f411_
startup.c -o stm32f411_startup.o` to compile the startup file.
* Run command `arm-none-eabi-gcc -nostdlib -T stm32_ls.ld *.o -o program.elf` to link the object files.
* Connect the development board.
* Run command `openocd -f board/st_nucleo_f4.cfg` to begin the uploading process.
* In another terminal run command `arm-none-eabi-gdb` to start the GDB. Run the following commands in the GDB terminal:
    * Run command `target remote localhost:3333` to connect to the microcontroller.
    * Run command `monitor reset init` to reset and initialize the board.
    * Run command `monitor flash write_image erase program.elf` to load the firmware onto the microcontroller.
    * Run command `monitor reset init` to reset the board.
    * Run command `monitor resume` to resume the execution of the firmware.
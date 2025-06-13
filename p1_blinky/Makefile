CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32_ls.ld

CMSIS_CORE_INC_DIR = ../chip_headers/CMSIS/Include
STM32_DEVICE_INC_DIR = ../chip_headers/CMSIS/Device/ST/STM32F4xx/Include
CFLAGS += -I$(CMSIS_CORE_INC_DIR) -I$(STM32_DEVICE_INC_DIR)

final : program.elf

main.o : main_cmsis.c
	$(CC) $(CFLAGS) $^ -o $@

stm32f411_startup.o : stm32f411_startup.c
	$(CC) $(CFLAGS) $^ -o $@

program.elf: main.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

load :
	openocd -f board/st_nucleo_f4.cfg

clean:
	del	-f *.o *.elf *.map
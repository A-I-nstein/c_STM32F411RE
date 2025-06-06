CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32_ls.ld

final : program.elf

main.o : main.c
	$(CC) $(CFLAGS) $^ -o $@

stm32f411_startup.o : stm32f411_startup.c
	$(CC) $(CFLAGS) $^ -o $@

program.elf: main.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

load :
	openocd -f board/st_nucleo_f4.cfg

clean:
	del	-f *.o *.elf *.map
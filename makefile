all:main.bin  main.dis 
FLAG = arm-none-eabi-
main.bin:main.elf
	$(FLAG)objcopy -O binary -S main.elf main.bin
main.elf:led.o start.o uart.o  main.o init.o copy.o exception.o interrupt.o interrupt_init.o
	$(FLAG)ld -Tsct.lds start.o led.o main.o uart.o  init.o copy.o exception.o interrupt.o interrupt_init.o -o main.elf 
main.o:main.c
	$(FLAG)gcc -c main.c -o main.o 
start.o:start.S
	$(FLAG)gcc -c start.S -o start.o 
%.o:%.c %.h
	$(FLAG)gcc -c $< -o $@  
%.dis:%.elf
	$(FLAG)objdump -D $< >$@
clean:
	-rm *.o *.elf *.bin
.PHONY:all clean
cc = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(MACH) -std=gnu11 -mthumb  -Wall

MACH = Cortex-m4

LDFLAGS = -T Stm32F446_LS.ld -nostdlib -Wl,-Map=final.map
main.o:main.c 
	$(cc) $(CFLAGS) $^ -o $@

RCC_interface.o:RCC_interface.c 
	$(cc) $(CFLAGS) $^ -o $@	
	
	
GPIO_Prog.o: GPIO_Prog.c
	$(cc) $(CFLAGS) $^ -o $@			
	
	

STM_F446startupfile.o:STM_F446startupfile.c
	$(cc) $(CFLAGS) $^ -o $@
	
	
final.elf : main.o RCC_interface.o GPIO_Prog.o STM_F446startupfile.o 
	$(cc) $(LDFLAGS) $^ -o $@
	
All : main.o GPIO_Prog.o RCC_interface.o STM_F446startupfile.o final.elf
	

clean:
	rm -rf *.o *.elf

load :
		openocd -f board/st_nucleo_f4.cfg


	
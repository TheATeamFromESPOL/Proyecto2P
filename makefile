all: ProcesoUSB servidor 


ProcesoUSB: ProcesoUSB.c
	gcc -Wall -g ProcesoUSB.c -o Usb -ludev

.PHONY:clean
clean:
	rm Servidor
	rm Usb

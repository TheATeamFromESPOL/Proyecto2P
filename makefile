all: ProcesoUSB servidor 


ProcesoUSB: ./src/ProcesoUSB.c
	gcc -Wall -g ./src/ProcesoUSB.c -o Usb -ludev

.PHONY:clean
clean:
	rm Servidor
	rm Usb

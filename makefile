all: Usb


Usb: ProcesoUSB.c
	gcc -Wall -g ProcesoUSB.c -o Usb -ludev

clean:
	rm Servidor
	rm Usb

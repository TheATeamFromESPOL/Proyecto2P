import requests
import json


ip = input("Ingrese la ip del servidor")
bandera=1
while bandera ==1 :
	print("Seleccione que tipo de solicitud desea")
	print("1. GET")
	print("2. POST")
	print("3. SALIR")
	opcion = input("Ingrese opcion: ")	
	while(opcion!="1" and opcion!="2" opcion!="3"):
		opcion = input("Ingrese opcion valida :")
	if(opcion == "1"):
		print("Seleccione que la solicitud que desea")
		print("1. Listar dispositivos")
		print("2. Leer dispositivos")
		print("3. SALIR")
		solicitud = input("Ingrese opcion: ")	
		while(solicitud != "1" and solicitud != "2" solicitud != "3"):
			solicitud = input("Ingrese opcion valida :")
		if(solicitud == "1"):
			
		elif(solicitud=="2"):
			
		else:
			bandera=0
	elif(opcion=="2"):
		print("Seleccione que la solicitud que desea")
		print("1. Nombrar Dispositivo")
		print("2. Escribir archivo")
		print("3. SALIR")
		solicitud = input("Ingrese opcion: ")	
		while(solicitud!="1" and solicitud!="2" solicitud!="3"):
			solicitud = input("Ingrese opcion valida :")
		if(solicitud == "1"):
			
		elif(solicitud=="2"):
			
		else:
			bandera=0
	else:
		bandera=0

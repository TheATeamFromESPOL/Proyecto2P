import requests
import json


url="http://127.0.0.1:8888/"
bandera=1
while bandera ==1 :
	print("Seleccione que tipo de solicitud desea")
	print("1. GET")
	print("2. POST")
	print("3. SALIR")
	opcion = input("Ingrese opcion: ")	
	while(opcion!="1" and opcion!="2" and opcion!="3"):
		opcion = input("Ingrese opcion valida :")
		
	if(opcion == "1"):
		print("Seleccione que la solicitud que desea")
		print("1. Listar dispositivos")
		print("2. Leer archivo")
		print("3. SALIR")
		solicitud = input("Ingrese opcion: ")	
		while(solicitud != "1" and solicitud != "2" and solicitud != "3"):
			solicitud = input("Ingrese opcion valida :")
		if(solicitud == "1"):
			url+="listar_dispositivos"
			#r=request.get(url)
		elif(solicitud== "2"):
			url+="leer_archivo"
			nombre=input("ingrese nombre de dispositivo")
			archivo=input("ingrese nombre del archivo")
			l={"solicitud":"leer_archivo","nombre":nombre ,"nombre_archivo":archivo}
			#r=request.get(url,data={"json":json.dumps(l)})
		else:
			print("FIN")
			bandera=0
	elif(opcion=="2"):
		print("Seleccione que la solicitud que desea")
		print("1. Nombrar Dispositivo")
		print("2. Escribir archivo")
		print("3. SALIR")
		solicitud = input("Ingrese opcion: ")	
		while(solicitud!="1" and solicitud!="2" and solicitud!="3"):
			solicitud = input("Ingrese opcion valida :")
		if(solicitud == "1"):
			url+="nombrar_dispositivo"
			nodo = input("ingrese nodo(/dev/.../):")
			nombre=input("ingrese nombre de dispositivo")
			l={"solicitud":"nombrar_dispositivo","nodo":nodo ,"nombre":nombre}
			#r=request.get(url,data={"json":json.dumps(l)})
		elif(solicitud== "2"):
			url+="escribir_archivo"
			nombre=input("ingrese nombre de dispositivo")
			archivo=input("ingrese nombre del archivo")
			contenido=input("ingrese contenido")
			tamConte=len(contenido)
			l={"solicitud":"escribir_archivo","nombre":nombre ,"nombre_archivo":archivo,
			"tamano_contenido":tamConte,"contenido":contenido}
			#r=request.get(url,data={"json":json.dumps(l)})
		else:
			print("FIN")
			bandera=0
	else:
		print("FIN")
		bandera=0
	url="http://127.0.0.1:8889/"

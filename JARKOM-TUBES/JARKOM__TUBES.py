#import socket module
from socket import *

serverPort = 80 #memasukkan nomor port
serverSocket = socket(AF_INET, SOCK_STREAM) #membuat socket

#menyiapkan server socket
serverSocket.bind(('localhost',serverPort))
serverSocket.listen(1)

print ("Server siap digunakan...")

while True :
    connectionSocket, addr = serverSocket.accept() #buat koneksi dari client
    try:
        message = connectionSocket.recv(1024).decode()#terima request dari klien
        filename = message.split()[1] #mengurai permintaan serta menyimpan path dari file yang diminta
        
        #membuka file yang diminta serta menyimpan sementara file yang diminta
        f = open(filename[1:])
        outputdata = f.read()
        
        #mengirim pesan HTTP header ke socket
        header = "HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n"
        connectionSocket.send(header.encode())

        #memberikan file yang diminta klien
        for i in range(0,len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
        connectionSocket.send("\r\n".encode())
        connectionSocket.close()

    except IOError:
        #mengirim pesan bahwa file yang diminta tidak ada
        header = "HTTP/1.1 200 404 not found\nContent-Type: text/html\r\n\r\n"
        response_body = "<html><head><title>404 Not Found</title></head><body><h1>404 Not Found</h1></body></html>"
        connectionSocket.send(header.encode())
        connectionSocket.send(response_body.encode())

        #menutup client socket
        connectionSocket.close()

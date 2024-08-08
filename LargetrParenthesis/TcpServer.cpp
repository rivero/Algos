#pragma once
#ifdef TCP_SERVER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

namespace TCP
{
#define PORT 5000

		int server() {
		int listen_fd, conn_fd;
		struct sockaddr_in servaddr;
		fd_set read_fds;
		char buffer[1024];

		listen_fd = socket(AF_INET, SOCK_STREAM, 0);
		if (listen_fd == -1) {
			perror("Socket creation failed");
			exit(EXIT_FAILURE);
		}

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		servaddr.sin_port = htons(PORT);

		if (bind(listen_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
			perror("Socket bind failed");
			exit(EXIT_FAILURE);
		}

		if (listen(listen_fd, 5) == -1) {
			perror("Listen failed");
			exit(EXIT_FAILURE);
		}

		printf("Server listening on port %d\n", PORT);

		FD_ZERO(&read_fds);
		FD_SET(listen_fd, &read_fds);

		while (1) 
		{
			fd_set temp_fds = read_fds;
			if (select(FD_SETSIZE, &temp_fds, NULL, NULL, NULL) == -1) {
				perror("Select error");
				exit(EXIT_FAILURE);
			}

			for (int fd = 0; fd < FD_SETSIZE; ++fd) {
				if (FD_ISSET(fd, &temp_fds)) {
					if (fd == listen_fd) {
						conn_fd = accept(listen_fd, NULL, NULL);
						FD_SET(conn_fd, &read_fds);
						printf("New connection accepted, fd = %d\n", conn_fd);
					}
					else {
						bzero(buffer, sizeof(buffer));
						int bytes_received = recv(fd, buffer, sizeof(buffer), 0);
						if (bytes_received <= 0) {
							printf("Client disconnected, fd = %d\n", fd);
							close(fd);
							FD_CLR(fd, &read_fds);
						}
						else {
							printf("Received from client (fd = %d): %s\n", fd, buffer);
							// Process data or send a response back to the client
						}
					}
				}
			}
		}

		return 0;
	}

		int server2() {
			int listen_fd, conn_fd;
			struct sockaddr_in servaddr;

			listen_fd = socket(AF_INET, SOCK_STREAM, 0);
			if (listen_fd == -1) {
				perror("Socket creation failed");
				return 1;
			}

			bzero(&servaddr, sizeof(servaddr));
			servaddr.sin_family = AF_INET;
			servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
			servaddr.sin_port = htons(PORT);

			if (bind(listen_fd, reinterpret_cast<struct sockaddr*>(&servaddr), sizeof(servaddr)) == -1) {
				perror("Socket bind failed");
				return 1;
			}

			if (listen(listen_fd, 5) == -1) {
				perror("Listen failed");
				return 1;
			}

			std::cout << "Server listening on port " << PORT << std::endl;

			while (true) {
				conn_fd = accept(listen_fd, nullptr, nullptr);
				if (conn_fd == -1) {
					perror("Accept failed");
					continue;
				}

				char buffer[1024];
				ssize_t bytes_received = recv(conn_fd, buffer, sizeof(buffer), 0);
				if (bytes_received <= 0) {
					close(conn_fd);
					continue;
				}

				// Process data or send a response back to the client
				// For simplicity, let's just echo the received message:
				send(conn_fd, buffer, bytes_received, 0);

				close(conn_fd);
			}

			return 0;
		}
}
#endif
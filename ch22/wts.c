/*  wts.c - Windows TCP Server Code
 *
 *
 *  Copyright (C) 1999   Chad Dixon
 *                       Macmillan Computer Publishing
 *
 *  This program is free software; you can redistribute it
 *  and/or modify it under the terms of the GNU General
 *  Public License as published by the Free Software
 *  Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will
 *  be useful, but WITHOUT ANY WARRANTY; without even the
 *  implied warranty of MERCHANTABILITY or FITNESS FOR A
 *  PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General
 *  Public License along with this program; if not, write
 *  to the Free Software Foundation, Inc., 675 Mass Ave,
 *  Cambridge, MA 02139, USA.
 *
 *  Chad Dixon may be contacted at:
 *     http://www.loopy.org
 *
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>

#define DEFAULT_FILE_NAME "sales.dat"

volatile sig_atomic_t done;

void inthandler(int Sig) {
    done = 1;
}

int CheckForData(int sockfd) {
    struct timeval tv;
    fd_set read_fd;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&read_fd);
    FD_SET(sockfd, &read_fd);
    if (select(sockfd + 1, &read_fd, NULL, NULL, &tv) == -1)

        return 0;
    if (FD_ISSET(sockfd, &read_fd)) {
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    WORD wVersionRequested = MAKEWORD(1, 1);
    WSADATA wsaData;
    SOCKET sock;
    SOCKET new_sock;
    SOCKADDR_IN my_addr;

    char data[255] = {0};
    char *endp;

    FILE *fp;
    char Filename[FILENAME_MAX] = DEFAULT_FILE_NAME;
    unsigned long currenttotal = 0;
    unsigned long newtotal = 0;

    if (argc < 2) {
        printf("No file specified. Using \"%s\"\n", DEFAULT_FILE_NAME);
    } else {
        strcpy(Filename, argv[1]);
    }

    fp = fopen(Filename, "r");
    if (fp != NULL) {
        if (NULL != fgets(data, sizeof data, fp)) {
            currenttotal = strtoul(data, &endp, 10);
        }

        fclose(fp);
    } else {
        printf("Couldn't read file %s\n", Filename);
    }

    if (signal(SIGINT, SIG_IGN) != SIG_IGN) {
        signal(SIGINT, inthandler);
    }

    if (signal(SIGTERM, SIG_IGN) != SIG_IGN) {
        signal(SIGTERM, inthandler);
    }

    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(1091);

    WSAStartup(wVersionRequested, &wsaData);
    if (wsaData.wVersion != wVersionRequested) {
        printf("\n Wrong version of Winsock\n");
        return EXIT_FAILURE;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Unexpected error on socket().\n");
        return EXIT_FAILURE;
    }

    if (bind(sock, (LPSOCKADDR)&my_addr, sizeof(struct sockaddr)) == SOCKET_ERROR) {
        printf("Unexpected error on bind()\n");
        shutdown(sock, 2);
        return EXIT_FAILURE;
    }

    if (listen(sock, SOMAXCONN) == SOCKET_ERROR) {
        printf("Unexpected error on listen()\n");
        shutdown(sock, 2);
        return EXIT_FAILURE;
    }

    while (!done) {
        if (0 != CheckForData(sock)) {
            new_sock = accept(sock, NULL, NULL);
            if (new_sock == INVALID_SOCKET) {
                printf("Unexpected error on accept()\n");
            }

            memset(data, 0, sizeof data);

            if (recv(new_sock, data, sizeof data, 0) == SOCKET_ERROR) {
                printf("Unexpected error on recv()\n");
            } else {
                newtotal += strtoul(data, &endp, 10);
                printf("Received data: %s\n", data);
            }
            sprintf(data, "%lu", currenttotal);
            if (send(new_sock, data, sizeof data, 0) == SOCKET_ERROR) {
                printf("Unexpected error on send()\n");
            }

            shutdown(new_sock, 2);
        }
    }

    shutdown(sock, 2);
    WSACleanup();

    printf("User requested program to halt.\n");
    fp = fopen(Filename, "w");
    if (fp != NULL) {
        fprintf(fp, "%lu\n", newtotal);
        fclose(fp);
    } else {
        printf("Couldn't write total %lu to file %s\n", newtotal, Filename);
    }
    return EXIT_SUCCESS;
}

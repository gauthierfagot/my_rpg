/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** main
*/

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int, char **)
{
    struct sockaddr_in addr;
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if (bind(fd, &addr, sizeof(struct sockaddr_in))) {
        return 1;
    }
    listen(fd, 5);
    close(fd);
}

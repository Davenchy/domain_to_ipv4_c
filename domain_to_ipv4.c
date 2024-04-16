#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int gai_status;
  char *domain_name = NULL;
  struct addrinfo *res, *rp, hint;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <domain>\n", argv[0]);
    return 1;
  }

  domain_name = argv[1];

  memset(&hint, 0, sizeof(hint));
  hint.ai_family = AF_INET;
  hint.ai_socktype = SOCK_STREAM;

  gai_status = getaddrinfo(domain_name, NULL, &hint, &res);
  if (gai_status != 0) {
    fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(gai_status));
    return 1;
  }

  for (rp = res; rp != NULL; rp = rp->ai_next) {
    char ip_str[INET_ADDRSTRLEN];
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)rp->ai_addr;

    if (rp->ai_family != AF_INET)
      continue;
    if (!inet_ntop(AF_INET, &(ipv4->sin_addr), ip_str, INET_ADDRSTRLEN))
      continue;

    printf("%s\n", ip_str);
  }

  freeaddrinfo(res);
  return 0;
}

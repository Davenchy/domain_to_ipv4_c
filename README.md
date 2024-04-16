# Domain to IPv4 Converter in C

This project provides a simple command-line tool written in C to convert domain names to their corresponding IPv4 addresses. It uses the getaddrinfo function from the netdb.h library to perform DNS resolution and retrieve IP addresses associated with a given domain name.

## Usage

Simply compile the provided source code and run the executable with the domain name as an argument.

```bash
$ gcc domain_to_ipv4.c -o domain_to_ipv4
```

```bash
$ ./domain_to_ipv4
Usage: ./domain_to_ipv4 <domain>
```

```bash
$ ./domain_to_ipv4 example.com
93.184.216.34
```

## Resources

- [getaddrinfo(3), freeaddrinfo(3)](https://pubs.opengroup.org/onlinepubs/9699919799/functions/getaddrinfo.html)

- [gai_strerror(3)](https://pubs.opengroup.org/onlinepubs/9699919799/functions/gai_strerror.html)

- [inet_ntop(3)](https://pubs.opengroup.org/onlinepubs/9699919799/functions/inet_ntop.html)

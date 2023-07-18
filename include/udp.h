#ifndef __UDP_H__
#define __UDP_H__

#include "sock.h"

struct udp {
    unsigned short src;
    unsigned short dst;
    unsigned short length;
    unsigned short checksum;
    unsigned char data[0];
}__attribute__((packed));

struct udp_sock {
    struct sock sk;
};

#define UDP_HDR_SZ        sizeof(struct udp)
#define ip2udp(ip)        ((struct udp *)ipdata(ip))
#define UDP_MAX_BUFSZ     (0xffff - UDP_HDR_SZ)
#define UDP_DEFAULT_TTL   64

extern struct sock *udp_lookup_sock(unsigned short nport);
extern void udp_in(struct pkbuf *pkb);
extern void udp_init(void);
extern struct sock *udp_alloc_sock(int protocol);

#endif
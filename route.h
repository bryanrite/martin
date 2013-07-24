#include "pcre.h"
#include "request.h"

#define MAX_OVECS   30

typedef struct route {
    enum http_method method;
    pcre    *re;
    int (*handler)(int, struct message*, char**, int);
} route_t;

extern route_t  *GROUTES;
extern int      GNUM_ROUTES;

int setup_routes();
int route_request(int client, struct message *m);
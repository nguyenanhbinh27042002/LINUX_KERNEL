#include <stdio.h>
#include <stdlib.h>

#define MAXN 10010
#define MAXE (MAXN*2)

typedef struct {
    int x;
    int h, r;   // h < 0 = start, h > 0 = end, r = right (only for start)
} Event;

Event ev[MAXE];
int ec;

typedef struct {
    int h, rx;
} Node;

Node heap[MAXN+5];
int hc;

int cmp(const void *a, const void *b) {
    Event *pa = a, *pb = b;
    if (pa->x != pb->x) return pa->x - pb->x;
    return pa->h - pb->h;
}

void push(int h, int rx) {
    int i = hc++;
    heap[i].h = h; heap[i].rx = rx;
    while (i) {
        int p = (i-1)/2;
        if (heap[p].h >= heap[i].h) break;
        Node t = heap[p]; heap[p] = heap[i]; heap[i] = t; i = p;
    }
}

void pop(void) {
    if (!hc) return;
    heap[0] = heap[--hc];
    int i = 0;
    while (1) {
        int l=2*i+1, r=2*i+2, mx=i;
        if (l < hc && heap[l].h > heap[mx].h) mx = l;
        if (r < hc && heap[r].h > heap[mx].h) mx = r;
        if (mx == i) break;
        Node t = heap[i]; heap[i] = heap[mx]; heap[mx] = t; i = mx;
    }
}

int top(void) { return hc ? heap[0].h : 0; }
int expired(int x) { return hc && heap[0].rx <= x; }

int main() {
    int n;
    scanf("%d", &n);
    ec = hc = 0;

    int i;
    for (i = 0; i < n; i++) {
        int l,r,h;
        scanf("%d%d%d", &l, &r, &h);
        ev[ec++] = (Event){l, -h, r};
        ev[ec++] = (Event){r,  h, 0};
    }

    qsort(ev, ec, sizeof(Event), cmp);

    push(0, 2000000007);  // ground

    int prev = 0;

    for (i = 0; i < ec; i++) {
        int x = ev[i].x;

        if (ev[i].h < 0) push(-ev[i].h, ev[i].r);

        while (expired(x)) pop();

        int cur = top();

        if (cur != prev) {
            printf("%d %d\n", x, cur);
            prev = cur;
        }
    }

    return 0;
}
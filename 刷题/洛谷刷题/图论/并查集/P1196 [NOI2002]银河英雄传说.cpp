#include <cstdio>
#include <algorithm>

const  int MAXN = 30000;
const  int MAXM = 500000;

int m;

struct unionfind {
     int head[MAXN], tail[MAXN], prefix[MAXN];

    void init( int n) {
        for ( int i = 0; i < n; i++) {
            head[i] = i;
            tail[i] = i;
        }
    }

     int find_head( int x) {
        if (head[x] == x) {
            return x;
        } else {
            if (head[head[x]] != head[x]) {
                prefix[x] += pre(head[x]);
            }
            head[x] = find_head(head[x]);
        }

        return head[x];
    }

     int find_tail( int x) {
        return tail[x] == x ? x : tail[x] = find_tail(tail[x]);
    }

     int pre( int x) {
        if (head[x] == x) {
            return prefix[x] = 0;
        } else {
            if (head[head[x]] != head[x]) {
                prefix[x] += pre(head[x]);
            }
            head[x] = find_head(head[x]);
        }

        return prefix[x];
    }

     int sum( int x,  int y) {
        return std::max(pre(x), pre(y)) - std::min(pre(x), pre(y)) - 1;
    }

    void merge( int x,  int y) {
         int head_x = find_head(x);
         int tail_y = find_tail(y);
        head[head_x] = tail_y;
        tail[tail_y] = head_x;
        prefix[head_x] = 1;
    }
} uf;

inline bool isempty(char ch) {
    return ch != '-' && (ch < '0' || ch > '9');
}

template <typename T>
inline void read(T &x) {
    x = 0;
    register char ch;
    while (isempty(ch = getchar()));

    register bool flag = false;
    if (ch == '-') {
        flag = true;
        ch = getchar();
    }

    do {
        x = x * 10 + (ch - '0');
    } while (!isempty(ch = getchar()));

    if (flag) {
        x = -x;
    }
}

inline bool iscommand(char ch) {
    return ch == 'C' || ch == 'M';
}

int main() {
    read(m);

    uf.init(MAXN);
    for ( int i = 0; i < m; i++) {
        register char command;
        register  int x, y;

        while (!iscommand(command = getchar()));
        read(x), read(y);
        x--, y--;

        if (command == 'M') {
            uf.merge(x, y);
        } else {
            if (uf.find_head(x) == uf.find_head(y)) {
                printf("%u\n", uf.sum(x, y));
            } else {
                puts("-1");
            }
        }
    }

    return 0;
}
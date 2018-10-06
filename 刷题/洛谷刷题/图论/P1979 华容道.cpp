#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>

const int MAXN = 40;
const int MAXQ = 550;
const int di[] = { 1, 0, 0, -1 };
const int dj[] = { 0, 1, -1, 0 };

int n, m;

struct Node {
    bool invalid;
    int cost[4][4];
    int dist;    // BFS prepare
    struct {
        int dist;
        bool inq;
    } v[4];      // SPFA
} map[MAXN + 1][MAXN + 1];

struct Point {
    int i, j;

    Point() {}
    Point(int i, int j) : i(i), j(j) {}

    Point move(int x) {
        return Point(i + di[x], j + dj[x]);
    }

    Node *operator->() const {
        return &map[i][j];
    }

    bool valid() const {
        return i > 0 && j > 0 && i <= n && j <= m;
    }

    bool operator==(const Point &other) const {
        return i == other.i && j == other.j;
    }
};

struct Status {
    Point p;
    int d;

    Status(Point p, int d) : p(p), d(d) {}
};

inline int bfs(Point s, Point t, Point p) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            map[i][j].dist = INT_MAX;
        }
    }

    std::queue<Point> q;
    s->dist = 0;
    q.push(s);

    while (!q.empty()) {
        Point v = q.front();
        q.pop();

        if (v == t) return v->dist;

        for (int i = 0; i < 4; i++) {
            Point u = v.move(i);

            if (u->invalid || u == p) continue;

            if (u->dist > v->dist + 1) {
                u->dist = v->dist + 1;
                q.push(u);
            }
        }
    }

    return INT_MAX;
}

inline void prepare() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j].invalid) continue;

            Point v(i, j);
            for (int s = 0; s < 4; s++) {
                Point ps = v.move(s);

                for (int t = s + 1; t < 4; t++) {
                    Point pt = v.move(t);

                    if (!ps.valid() || ps->invalid || !pt.valid() || pt->invalid) v->cost[s][t] = v->cost[t][s] = INT_MAX;
                    else v->cost[s][t] = v->cost[t][s] = bfs(ps, pt, v);

#ifdef DBG
                    printf("[%d, %d] %d => %d = %d\n", v.i, v.j, s, t, v->cost[s][t]);
#endif
                }
            }
        }
    }
}

inline int spfa(Status s, Point t) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                map[i][j].v[k].dist = INT_MAX;
                map[i][j].v[k].inq = false;
            }
        }
    }

    std::queue<Status> q;
    q.push(s);
    s.p->v[s.d].dist = 0;

    while (!q.empty()) {
        Status status = q.front();
        q.pop();

        Point &v = status.p;
        int &d = status.d;

        v->v[d].inq = false;

        // Move the empty block
        for (int i = 0; i < 4; i++) {
            if (i == d || v->cost[d][i] == INT_MAX) continue;

            if (v->v[i].dist > v->v[d].dist + v->cost[d][i]) {
                v->v[i].dist = v->v[d].dist + v->cost[d][i];
#ifdef DBG
                printf("[%d, %d]->v[%d]->dist = %d\n", v.i, v.j, i, v->v[i].dist);
#endif
                if (!v->v[i].inq) {
                    v->v[i].inq = true;
                    q.push(Status(v, i));
                }
            }
        }

        // Swap
        if (v->v[d].dist != INT_MAX) {
            Point u = v.move(d);
            int t = 3 - d;
            if (u->v[t].dist > v->v[d].dist + 1) {
                u->v[t].dist = v->v[d].dist + 1;
                if (!u->v[t].inq) {
                    u->v[t].inq = true;
                    q.push(Status(u, t));
                }
            }
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < 4; i++) {
        res = std::min(res, t->v[i].dist);
    }

    return res;
}

int main() {
    int q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            map[i][j].invalid = (x == 0);
        }
    }

    prepare();

    while (q--) {
        Point empty, s, t;
        scanf("%d %d %d %d %d %d", &empty.i, &empty.j, &s.i, &s.j, &t.i, &t.j);

        if (s == t) {
            puts("0");
            continue;
        }

        int ans = INT_MAX;
        for (int i = 0; i < 4; i++) {
            Point v = s.move(i);
            if (!v.valid()) continue;

            int d1 = bfs(empty, v, s);
            if (d1 == INT_MAX) continue;

            int d2 = spfa(Status(s, i), t);
            if (d2 == INT_MAX) continue;

            ans = std::min(ans, d1 + d2);
        }

        printf("%d\n", ans == INT_MAX ? -1 : ans);
    }

    return 0;
}
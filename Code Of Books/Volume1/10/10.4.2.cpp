#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010, ADD = 1, DELETE = -1;

#define LCHILD(x) (((x) << 1) | 1)
#define RCHILD(x) (((x) + 1) << 1)

struct rectangle { int x1, y1, x2, y2; } rects[MAXN];
struct event {
    int x, y1, y2, evtCode;
    bool operator<(const event &e) const { return x < e.x; }
} evts[MAXN * 2];
struct node { int cnt, height; } st[4 * MAXN] = {};

int n, id[MAXN *2];

void build(int p, int left, int right)
{
    if (left != right) {
        int middle = (left + right) >> 1;
        build(LCHILD(p), left, middle);
        build(RCHILD(p), middle + 1, right);
    }
    st[p].cnt = st[p].height = 0;
}

void pushUp(int p, int left, int right)
{
    st[p].height = st[LCHILD(p)].height + st[RCHILD(p)].height;
    if (st[p].cnt) st[p].height = id[right + 1] - id[left];
}

void update(int p, int left, int right, int ul, int ur, int value)
{    
    if (right < ul || left > ur) return;
    if (ul <= left && right <= ur) st[p].cnt += value;
    else {
        int middle = (left + right) >> 1;
        if (middle >= ul) update(LCHILD(p), left, middle, ul, ur, value);
        if (middle + 1 <= ur) update(RCHILD(p), middle + 1, right, ul, ur, value);
    }
    pushUp(p, left, right);
}

long long getArea()
{
    for (int i = 0; i < n; i++) id[i] = rects[i].y1, id[i + n] = rects[i].y2;
    sort(id, id + 2 * n);
    for (int i = 0; i < n; i++) {
        evts[i].evtCode = ADD, evts[i].x = rects[i].x1;
        evts[i + n].evtCode = DELETE, evts[i + n].x = rects[i].x2;
        int ty1 = lower_bound(id, id + 2 * n, rects[i].y1) - id;
        int ty2 = lower_bound(id, id + 2 * n, rects[i].y2) - id;
        evts[i].y1 = evts[i + n].y1 = ty1;
        evts[i].y2 = evts[i + n].y2 = ty2;
    }
    sort(evts, evts + 2 * n);
    long long area = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i && evts[i].x > evts[i - 1].x)
            area += (long long)(evts[i].x - evts[i - 1].x) * st[0].height;
        update(0, 0, 2 * n - 1, evts[i].y1, evts[i].y2 - 1, evts[i].evtCode);
    }
    return area;
}

int main(int argc, char *argv[])
{
    int cases = 0;
    while (cin >> n, n > 0)
    {
        cout << "Case " << ++cases << ": ";
        for (int i = 0; i < n; i++)
            cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
        cout << getArea() << '\n';
    }
    return 0;
}

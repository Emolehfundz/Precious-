// Common Area
// UVa ID: 12931
// Verdict: Accepted
// Submission Date: 2021-12-28
// UVa Run Time: 0.000s
//
// 版权所有（C）2021，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

const int OUT = 0, ON = 1, IN = 2;

struct point {
    int x, y;
    point (int x = 0, int y = 0): x(x), y(y) {}
    point operator + (point p) { return point(x + p.x, y + p.y); };
    point operator - (point p) { return point(x - p.x, y - p.y); };
};

int dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

int cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

int cp(point a, point b, point c)
{
	return cross(b - a, c - a);
}

typedef vector<point> polygon;

int isPointInPolygon(point p, polygon &pg)
{
    bool in = false;
    for (int i = 0; i < pg.size(); i++)
    {
        point a = pg[i] - p, b = pg[(i + 1) % pg.size()] - p;
        if (abs(cross(a, b)) == 0 && dot(a, b) <= 0) return ON;
        if (a.y > b.y) swap(a, b);
        if (a.y <= 0 && 0 < b.y && cross(a, b) > 0) in = !in;
    }
    return in ? IN : OUT;
}

int n1, n2;
polygon pg1, pg2;

// 判断某个多边形边的中点是否在另外一个多边形内。
bool isMiddlePointIn()
{
    for (int i = 0; i < n1; i++)
    {
        point middle = pg1[i] + pg1[(i + 1) % n1];
        middle.x /= 2, middle.y /= 2;
        if (isPointInPolygon(middle, pg2) == IN)
            return true;
    }
    for (int i = 0; i < n2; i++)
    {
        point middle = pg2[i] + pg2[(i + 1) % n2];
        middle.x /= 2, middle.y /= 2;
        if (isPointInPolygon(middle, pg1) == IN)
            return true;
    }
    return false;    
}

// 判断两条线段是否跨越式相交。
bool isIntersected()
{
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            int cp1 = cp(pg1[i], pg1[(i + 1) % n1], pg2[j]), cp2 = cp(pg1[i], pg1[(i + 1) % n1], pg2[(j + 1) % n2]);
            int cp3 = cp(pg2[j], pg2[(j + 1) % n2], pg1[i]), cp4 = cp(pg2[j], pg2[(j + 1) % n2], pg1[(i + 1) % n1]);
            if ((cp1 * cp2 < 0) && (cp3 * cp4) < 0) return true;
        }
    return false;
}

// 判断某个多边形边的顶点是否在另外一个多边形内。
bool isPointIn()
{
    for (int i = 0; i < n1; i++)
        if (isPointInPolygon(pg1[i], pg2) == IN)
            return true;
    for (int i = 0; i < n2; i++)
        if (isPointInPolygon(pg2[i], pg1) == IN)
            return true;
    return false;
}

// 判断多边形相邻两条边构成的三角形的重心是否均在两个多边形内。
bool isCenterOfTriangleIn()
{
    for (int i = 0; i < n1; i++)
    {
        point center = pg1[i] + pg1[(i + 1) % n1] + pg1[(i + 2) % n1];
        center.x /= 3, center.y /= 3;
        if (isPointInPolygon(center, pg1) == IN &&
            isPointInPolygon(center, pg2) == IN)
            return true;
    }
    for (int i = 0; i < n2; i++)
    {
        point center = pg2[i] + pg2[(i + 1) % n2] + pg2[(i + 2) % n2];
        center.x /= 3, center.y /= 3;
        if (isPointInPolygon(center, pg1) == IN &&
            isPointInPolygon(center, pg2) == IN)
            return true;
    }
    return false;
}

int main(int argc, char *argv[])
{    
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases = 0;
    while (cin >> n1)
    {
        pg1.clear();
        pg2.clear();
        for (int i = 0, x, y; i < n1; i++)
        {
            cin >> x >> y;
            pg1.push_back(point(6 * x, 6 * y));
        }
        cin >> n2;
        for (int i = 0, x, y; i < n2; i++)
        {
            cin >> x >> y;
            pg2.push_back(point(6 * x, 6 * y));
        }
        bool overlapped = isIntersected() || isPointIn() || isMiddlePointIn() || isCenterOfTriangleIn();
        cout << "Case " << ++cases << ": " << (overlapped ? "Yes" : "No") << '\n';
    }

    return 0;
}

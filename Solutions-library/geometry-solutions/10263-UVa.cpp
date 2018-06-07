/*
Name: 10263 - Railway
Online Judge: UVa
Tags: Segment Line, Euclidean Distance
Complexity:
Tutorial: Find the distance between the segment line and the point, then chek if that distance is the min.
*/


// C O D E


#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)
struct point
{
	double x, y;

	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
};
struct vec
{
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};
double dist(point p1, point p2)
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}
vec toVec(point a, point b)
{
	return vec(b.x - a.x, b.y - a.y);
};
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

point translate(point p, vec v)
{
	return point(p.x + v.x , p.y + v.y);
}
vec scale(vec v, double s)
{
	return vec(v.x * s, v.y * s);
} ;
double distToLine(point p, point a, point b, point &c)
{
	// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c)
{
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0)
	{
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0)
	{
		c = point(b.x, b.y);
		return dist(p, b);
	}
	return distToLine(p, a, b, c);
}

int main()
{
	double ex, wy, x1, y1; int s;
	while (cin >> ex >> wy)
	{
		point p1(ex, wy);
		cin >> s;
		vector<point>P;
		for (int x = 0; x < s + 1; x++)
		{
			cin >> x1 >> y1;
			P.push_back(point(x1, y1));
		}
		point closet, ans;
		double check, min = 100000.0;

		for (int x = 0; x < s; x++)
		{

			distToLineSegment(p1, P[x], P[x + 1], closet);
			check = dist(p1, closet);
			if (min > check)
			{
				ans = closet;
				min = check;
			}
		}
		cout << fixed << setprecision(4) << ans.x << endl;
		cout << fixed << setprecision(4) <<  ans.y << endl;

	}

	return 0;
}

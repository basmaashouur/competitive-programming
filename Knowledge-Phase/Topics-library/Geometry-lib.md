# Geometry

Table of Contents
================= 

* [Euclidean Geometry Foundations](#euclidean-geometry-foundations)
   - [Points](#points)
   - [Lines](#lines)
   
## Euclidean Geometry Foundations
### Points
#### Points Declaration
- If no mush precision needed use this struct
```cpp
struct point_i
{
	int x, y;
	point_i() { x = y = 0; }
	point_i(int _x, int _y) : x(_x), y(_y) {}
};

int main()
{
	point_i p1; // x = 0 y = 0
	point_i p2(1, 2); // x = 1, y = 2

	vector<point_i> P; // vector of points
	P.push_back(point_i(2, 2));
	cout << P[0].x << " " << P[0].y << endl; // print 2 2

	return 0;
}
```

- If more precision is needed then use this struct
```cpp
#define EPS 1e-9

struct point
{
	double x, y;

	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}

	// override less than operator
	bool operator < (point other) const
	{
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}

	// use EPS (1e-9) when testing equality of two floating points
	bool operator == (point other) const
	{ return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));}

};


int main()
{
	point p1, p2; // x = 0.0 y = 0.0
	point p3(1, 2); // x = 1.0 y = 2.0
	printf("%d %d\n", p1 == p2, p1 == p3); // print 1 0

	vector<point> P;
	P.push_back(point(2, 2));
	cout << P[0].x << " " << P[0].y << endl; // print 2 2

	return 0;
}

```
### Lines

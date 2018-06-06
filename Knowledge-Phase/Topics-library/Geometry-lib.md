# Geometry

Table of Contents
================= 

* [Euclidean Geometry Foundations](#euclidean-geometry-foundations)
   - [Points](#points)
     + [Points Declaration](#points-declaration)
     + [Euclidean Distance](#euclidean-distance)
     + [Point Rotation](#point-rotation)
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
	sort(P.begin(), P.end()); // comparison operator is defined above
	
	return 0;
}

```

#### Euclidean Distance
- Don't forget the point struct to insert it above that code
```cpp
double dist(point p1, point p2)
{
	// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main()
{
	point p1(5, 6), p2(1, 10);
	cout << dist(p1, p2) << endl;
	return 0;
}
```
#### Point Rotation
- We can rotate a point by angle θ counter clockwise around origin (0, 0) by the following code, 
**Insert point code struct above it**
```cpp
#define PI acos(-1.0) 
// important constant; alternative #define PI (2.0 * acos(0.0))

// Angles convertion from 360 to rad
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

point rotate(point p, double theta)
{
	double rad = DEG_to_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad),
	             p.x * sin(rad) + p.y * cos(rad));
}

```
### Lines

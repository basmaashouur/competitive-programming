# Geometry

Table of Contents
================= 

* [Euclidean Geometry Foundations](#euclidean-geometry-foundations)
   - [Points](#points)
     + [Points Declaration](#points-declaration)
     + [Euclidean Distance](#euclidean-distance)
     + [Point Rotation](#point-rotation)
     + [Vector Declaration](#vector-declaration)
     + [Point To Vector](#point-to-vector)
     + [Scale Vector](#scale-vector)
     + [Translate Point](#translate-point)
   - [Lines](#lines)
     + [Line Declaration](#line-declaration)
     + [Points To Line](#points-to-line)
     + [Point To Line](#point-to-line)
     + [Parallel Lines](#parallel-lines)
     + [Same Lines](#same-lines)
     + [Intersect Lines](#intersect-lines)
     + [Closet Point To Line](#closet-point-to-line)
     + [Reflection Point](#reflection-point)
     + [](#)
     + [](#)
     + [](#)
     + [](#)
     + [](#)
     + [](#)
     + [](#)
   
   
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
#### Vector Declaration
- Vector is not the same as stl vector
```cpp
struct vec
{
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};
```
#### Point To Vector
- Convert 2 points to vector a->b
```cpp
vec toVec(point a, point b)
{	
	return vec(b.x - a.x, b.y - a.y);
};
```
#### Scale Vector
- Nonnegative s = <1 .. 1 .. >1
```cpp
vec scale(vec v, double s)
{
	return vec(v.x * s, v.y * s);
} ;
```
#### Translate Point
-  translate p according to v
```cpp
point translate(point p, vec v) 
{
	return point(p.x + v.x , p.y + v.y);
}
```

### Lines
#### Line Declaration
-
```cpp
// ax + by + c = 0;
struct line { double a, b, c; }; 
// y = mx + c; m is the slop
struct line2 { double m, c; };
```
#### Points To Line
- Using the equation ax + by + c = 0
```cpp
#define EPS 1e-9
void pointsToLine(point p1, point p2, line &l)
{
	if (fabs(p1.x - p2.x) < EPS)
	{	// vertical line
		l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;
	}
	else
	{
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x); // always -m
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}
```
- Using the equation y = mx + c
```cpp
#define EPS 1e-9
#define INF 1e9
int pointsToLine2(point p1, point p2, line2 &l)
{
	if (abs(p1.x - p2.x) < EPS)
	{	//  vertical line
		l.m = INF; // means undfined
		l.c = p1.x;
		return 0;   // we need this return variable to differentiate result
	}
	else
	{
		l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
		l.c = p1.y - l.m * p1.x;
		return 1;
	}
}
```
#### Point To Line
- Have a slope and a point
```cpp
void pointSlopeToLine(point p, double m, line &l) 
{
	l.a = -m; // always -m
	l.b = 1;  // always 1
	l.c = -((l.a * p.x) + (l.b * p.y));
} 
```
#### Parallel Lines
- Have the same slope and have different intercepts
```cpp
#define EPS 1e-9
bool areParallel(line l1, line l2)
{	// check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
```
#### Same Lines
-
```cpp
#define EPS 1e-9
bool areSame(line l1, line l2)
{	// also check coefficient c
	return areParallel(l1 , l2) && (fabs(l1.c - l2.c) < EPS);
}
```
#### Intersect Lines
- Returns true (+ intersection point) if two lines are intersect
```cpp
#define EPS 1e-9
bool areIntersect(line l1, line l2, point &p)
{
	if (areParallel(l1, l2)) return false;
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else  p.y = -(l2.a * p.x + l2.c);
	return true;
}

```
#### Closet Point To Line
-
```cpp
```
#### Reflection Point
-
```cpp
```
####
-
```cpp
```
####
-
```cpp
```
####
-
```cpp
```
####
-
```cpp
```
####
-
```cpp
```
####
-
```cpp
```
####
-
```cpp
```


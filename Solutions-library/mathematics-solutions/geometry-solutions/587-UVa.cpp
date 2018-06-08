/*
Name: 587 - There's treasure everywhere!
Online Judge: UVa
Tags: Points, Line, Euclidean Distance
Complexity:
Tutorial: 
If we are going (N, E, W, S) it would be a a vertcial or horziontal line so compute the new point would be easy,
increase or decrease x or y depends on the move
N --> (x, y += d)
S --> (x, y -= d)
E --> (x += d, y)
Y --> (x -= d, y)

If we are going(NE, NW, SE, SW) it would make a digonal line so the sloution is not straightforward, first we need
to know the line so we will compute the slope the line makes angel 45° so the slope of it, m = tan(45) m = 1
now we need to compute the new point location, we will compute from that equation (m2+1)(x2−x1)^2 = d2,
after finding x we will find y, but the direction of computed (x, y) is NE, so we would change the direction depends on
the location
NE --> (+x, +y)
NW --> (-x, +y)
SE --> (+x, -y)
SW --> (-x, -y)


OR 
vertcial or hotzoinatl = dist * seta = dist * 1; sin(90) = 1
dioganal = dist * seta = dist * 1/sqrt(2); sin(45) = 1/sqrt(2)
*/

// C O D E


#include <bits/stdc++.h>
using namespace std;

double rate = 1 / sqrt(2);
struct point
{
	double x, y;

	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2)
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

void newpoint(point &p1, int dis, string d)
{
	if (d == "N") {p1.y += dis; return;}
	if (d == "S") {p1.y -= dis; return;}
	if (d == "E") {p1.x += dis; return;}
	if (d == "W") {p1.x -= dis; return;}
	//p1.x *= rate , p1.y *= rate;
	if (d == "NE")
	{p1.x += dis * rate , p1.y += dis * rate; return;}
	if (d == "NW")
	{p1.x -= dis * rate , p1.y += dis * rate; return;}
	if (d == "SE")
	{p1.x += dis * rate , p1.y -= dis * rate; return;}
	if (d == "SW")
	{p1.x -= dis * rate , p1.y -= dis * rate; return;}
}


int main()
{
	int cn = 1;
	while (true)
	{
		string ln , d, dirc; int dis;
		point init, p1;
		getline(cin, ln);
		if (ln == "END")break;
		for (int i = 0; i < ln.length(); i++)
		{
			if (ln[i] == ',' || ln[i] == '.')
			{
				dis = stoi(d);
				newpoint(p1, dis, dirc);
				d = "", dirc = "";
			}
			else if (isdigit(ln[i]))d += ln[i];
			else dirc += ln[i];

		}
		cout << "Map #" << cn++ << endl;
		cout << "The treasure is located at (";
		cout << fixed << setprecision(3) << p1.x << ",";
		cout << fixed << setprecision(3) << p1.y << ")." << endl;
		cout << "The distance to the treasure is ";
		cout <<  fixed << setprecision(3) << dist(init, p1) << "." << endl << endl;;
	}

	return 0;
}

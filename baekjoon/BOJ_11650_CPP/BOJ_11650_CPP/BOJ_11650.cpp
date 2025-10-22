#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
	int x;
	int y;
};

bool CompareXY(const Point& a, const Point& b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<Point> points(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> points[i].x >> points[i].y;
	}

	sort(points.begin(), points.end(), CompareXY);

	for (const auto& p : points)
	{
		cout << p.x << ' ' << p.y << '\n';
	}

	return 0;
}
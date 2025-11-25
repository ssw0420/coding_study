#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, r, c;
	
	cin >> N >> r >> c;

	// 사분면 하나를 묶어서 size로 나눔
	int size = 1 << N; // 2^N
	int result = 0;

	while (size > 1)
	{
		int halfLength = size / 2; // 사분면 한 변 길이
		int area = halfLength * halfLength; // 사분면 전체의 칸 개수

		if (r < halfLength && c < halfLength) // 0번 사분면
		{

		}
		else if (r < halfLength && c >= halfLength) // 1번 사분면
		{
			result += area;  // 1번 사분면 → 0번 사분면 1개를 지나감
			c -= halfLength; // 사분면 내에서의 좌표
		}
		else if (r >= halfLength && c < halfLength) // 2번 사분면
		{
			result += 2 * area;
			r -= halfLength;
		}
		else // 3번 사분면
		{
			result += 3 * area;
			r -= halfLength;
			c -= halfLength;
		}

		size = halfLength;
	}

	
	cout << result;

	return 0;
}
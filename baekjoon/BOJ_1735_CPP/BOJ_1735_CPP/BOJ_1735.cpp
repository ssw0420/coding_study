#include <iostream>

using namespace std;

int GetGCD(int a, int b)
{
	if (b == 0)
		return a;
	return GetGCD(b, a % b);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num1_A, num1_B;
	int num2_A, num2_B;

	cin >> num1_A >> num1_B >> num2_A >> num2_B;

	int gcd = GetGCD(num1_B, num2_B);
	int lcm = (num1_B / gcd) * num2_B;

	int num1_lcm_mult = lcm / num1_B;
	int num1_A_mult = num1_A * num1_lcm_mult;

	int num2_lcm_mult = lcm / num2_B;
	int num2_A_mult = num2_A * num2_lcm_mult;

	int resultA = num1_A_mult + num2_A_mult;
	int resultB = lcm;

	int final_gcd = GetGCD(resultA, resultB);
	
	cout << resultA / final_gcd << " " << resultB / final_gcd;

	return 0;
}
// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is an
// Armstrong number
bool isArmstrong(int num)
{
	int originalNum = num;
	int sum = 0;
	int numDigits = to_string(num).length();
	while (num > 0) {
		int digit = num % 10;
		sum += pow(digit, numDigits);
		num /= 10;
	}
	return sum == originalNum;
}

// Function to find the GCD of two numbers
int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

// Find GCD
void gcdProduct(int rangeStart, int rangeEnd)
{

	int smallestArmstrong = INT_MAX;
	int largestArmstrong = INT_MIN;

	// Iterate through the given range
	for (int i = rangeStart; i <= rangeEnd; i++) {
		if (isArmstrong(i)) {
			smallestArmstrong = min(smallestArmstrong, i);
			largestArmstrong = max(largestArmstrong, i);
		}
	}

	if (smallestArmstrong == INT_MAX
		|| largestArmstrong == INT_MIN) {
		cout << endl;
	}
	else {
		int gcdResult
			= gcd(smallestArmstrong, largestArmstrong);
		cout << gcdResult << endl;
	}
}

// Driver code
int main()
{
	int rangeStart = 100;
	int rangeEnd = 10000;

	// Function call
	gcdProduct(rangeStart, rangeEnd);

	return 0;
}

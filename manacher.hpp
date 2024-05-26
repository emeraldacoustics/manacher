#include <vector>

using namespace std;

template <class T>
void manacher(const T * first, const T * last, vector<int> & d0, vector<int> & d1)
{
	const T * & s = first;
	const int n = last - first;

	/*
	 *	palindromes of even length
	 *	[i - d0[i], i + d0[i])
	 */
	d0.resize(n);
	for (int i = 0, k, l = 0, r = 0; i < n; i++)
	{
		for (k = (i < r ? min(r - i, d0[l + r - i]) : 0) + 1; k <= i && i + k <= n && s[i - k] == s[i + k - 1]; k++);
		d0[i] = --k;
		if (r < i + k)
			l = i - k, r = i + k;
	}

	/*
	 *	palindromes of odd length
	 *	(i - d1[i], i + d1[i])
	 */
	d1.resize(n);
	for (int i = 0, k, l = 0, r = 0; i < n; i++)
	{
		for (k = (i < r ? min(r - i, d1[l + r - i]) : 0); k <= i && i + k < n && s[i - k] == s[i + k]; k++);
		d1[i] = k;
		if (r < i + k)
			l = i - k, r = i + k;
	}
}


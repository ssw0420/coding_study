#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// 해당 문제는 10000까지의 숫자라는게 정해져있고, 범위도 크지 않아서 Counting Sort 방법이 적합함
	// 실제로는 sort() 기반으로 해결하는게 맞음
	long long N;

	cin >> N;

	const int MAX_VALUE = 10000;
	vector<int> count(MAX_VALUE + 1, 0);

	// 입력과 동시에 count 배열에 등장 '횟수' 기록
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		count[x]++;
	}


	for (int i = 1; i <= MAX_VALUE; i++)
	{
		while (count[i]--)
		{
			cout << i << '\n';
		}
	}

	return 0;


	//vector<long long> vec(N);

	//for (int i = 0; i < N; i++)
	//{
	//	cin >> vec[i];
	//}


	//sort(vec.begin(), vec.end());

	//for (int i = 0; i < N; i++) {
	//	cout << vec[i] << '\n';
	//}
	//return 0;
}

//작은 구간: ≤ 32 → Insertion Sort
//재귀 깊이 : 2 * log2(N) 횟수 제한 → 초과하면 Heap Sort
//기본 : Quick Sort
//template <class _RanIt, class _Pr>
//_CONSTEXPR20 void _Sort_unchecked(_RanIt _First, _RanIt _Last, _Iter_diff_t<_RanIt> _Ideal, _Pr _Pred) {
//    // order [_First, _Last)
//    for (;;) {
//        if (_Last - _First <= _ISORT_MAX) { // small
//            _STD _Insertion_sort_unchecked(_First, _Last, _Pred);
//            return;
//        }
//
//        if (_Ideal <= 0) { // heap sort if too many divisions
//            _STD _Make_heap_unchecked(_First, _Last, _Pred);
//            _STD _Sort_heap_unchecked(_First, _Last, _Pred);
//            return;
//        }
//
//        // divide and conquer by quicksort
//        auto _Mid = _STD _Partition_by_median_guess_unchecked(_First, _Last, _Pred);
//
//        _Ideal = (_Ideal >> 1) + (_Ideal >> 2); // allow 1.5 log2(N) divisions
//
//        if (_Mid.first - _First < _Last - _Mid.second) { // loop on second half
//            _STD _Sort_unchecked(_First, _Mid.first, _Ideal, _Pred);
//            _First = _Mid.second;
//        }
//        else { // loop on first half
//            _STD _Sort_unchecked(_Mid.second, _Last, _Ideal, _Pred);
//            _Last = _Mid.first;
//        }
//    }
//}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// �ش� ������ 10000������ ���ڶ�°� �������ְ�, ������ ũ�� �ʾƼ� Counting Sort ����� ������
	// �����δ� sort() ������� �ذ��ϴ°� ����
	long long N;

	cin >> N;

	const int MAX_VALUE = 10000;
	vector<int> count(MAX_VALUE + 1, 0);

	// �Է°� ���ÿ� count �迭�� ���� 'Ƚ��' ���
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

//���� ����: �� 32 �� Insertion Sort
//��� ���� : 2 * log2(N) Ƚ�� ���� �� �ʰ��ϸ� Heap Sort
//�⺻ : Quick Sort
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
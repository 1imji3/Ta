#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>


using namespace std;
 
template <typename T>
int bs(T a[], int n , T& target) {
	int left = 0, right = n - 1 , mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == target) {
			return mid;
		}
		else if (a[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;

}
void process(char T, int n, int q, string sorted_data[], string queries[]) {
	if (T == 'i') {
		// �N�r���ഫ�����
		int int_data[30];  // �}�C�j�p�̤j��30
		for (int i = 0; i < n; ++i) {
			int_data[i] = stoi(sorted_data[i]);
		}

		// �d�ߨÿ�X���G
		for (int i = 0; i < q; ++i) {
			int target = stoi(queries[i]);
			int result = bs(int_data, n, target);
			cout << result << endl;
		}
	}
	else if (T == 's') {
		// �����ϥΦr�ꫬ�O
		string str_data[30];  // �}�C�j�p�̤j��30
		for (int i = 0; i < n; ++i) {
			str_data[i] = sorted_data[i];
		}

		// �d�ߨÿ�X���G
		for (int i = 0; i < q; ++i) {
			string target = queries[i];
			int result = bs(str_data, n, target);
			cout << result << endl;
		}
	}
}

int main() {
	char int_or_string;
	int arr_size, search_size;
	while (cin >> int_or_string >> arr_size >> search_size)
	{
		string sortarr[30];
		for (int i = 0; i < arr_size; ++i)
		{
			cin >> sortarr[i];
		}

		string searchnumarr[30];
		for (int i = 0; i < search_size; ++i)
		{
			cin >> searchnumarr[i];
		}

		process(int_or_string, arr_size, search_size, sortarr, searchnumarr);
	}
	return 0;
}
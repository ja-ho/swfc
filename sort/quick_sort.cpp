#include <iostream>
using namespace std;

#define MAX 5001
#define swap(x, y) {int t; t = x; x = y; y = t;}
void quick(int *arr, int left, int right);

//void swap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//	return;
//}

void quick_sort(int *arr, int left, int right)	//quick_sort�� ��Ÿ �ٸ� �Լ��� ������ ����. �ӵ��� ������ quick_sort�� ����
{
	if (right - left < 1) return;
	int temp_left = left;
	int temp_right = right;
	int pivot = 0;
	if (right - left == 1) pivot = left;
	else {
		if (arr[left] > arr[right]) {
			if (arr[left] > arr[right / 2]) {
				if (arr[right / 2] > arr[right]) pivot = right / 2;
				else pivot = right;
			}
			else {
				pivot = left;
			}
		}
		else {
			if (arr[right] > arr[right / 2]) {
				if (arr[right / 2] > arr[left]) pivot = right / 2;
				else pivot = left;
			}
			else pivot = right;
		}
	}
		//pivot ���� pivot�� ���� ���ʰ� ������, �߰��� �߰����� ����. 
		//pivot�� �̷��� �������ν� ��� ���ĵ� ����Ʈ�� ���� pivot���� �����ϴ� �־��� ��츦 ���� �� �ִ�.

	swap(arr[pivot], arr[left]);	//���� �Ǻ��� ù��°�� ��ȯ
	pivot = arr[left];
	while (left < right) {
		while (arr[right] >= pivot && left < right) right--;		//�Ǻ����� ���ų� ū ������ right--
		if (left != right) {
			arr[left] = arr[right];									//left�� �Ǻ����� ���� ���� �Ѱ���
		}

		while (arr[left] <= pivot && left < right) left++;			//�Ǻ����� ���ų� ���� ������ left++

		if (left != right) {
			arr[right--] = arr[left];								//�Ǻ����� ū ���� right ��ġ�� �Ѱ���
		}
	}
																	//left�� right�� ��ġ�� ������ �ݺ�
																	//pivot �ڸ��� ã�Ƴ�
	arr[left] = pivot;												//pivot�� ��ġ
	pivot = left;
	left = temp_left;
	right = temp_right;												//�Ͻ������� ����ߴ� left�� right�� �������
	
	if (left < pivot) quick_sort(arr, left, pivot - 1);
	if (right > pivot) quick_sort(arr, pivot + 1, right);
	return;
}

int main() {
	int data[MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	quick(data, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';
	return 0;
}

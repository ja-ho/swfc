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

void quick_sort(int *arr, int left, int right)	//quick_sort를 기타 다른 함수로 나누지 않음. 속도가 관건인 quick_sort기 때문
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
		//pivot 설정 pivot은 가장 왼쪽과 오른쪽, 중간의 중간값을 가짐. 
		//pivot을 이렇게 정함으로써 모두 정렬된 리스트를 왼쪽 pivot부터 정렬하는 최악의 경우를 피할 수 있다.

	swap(arr[pivot], arr[left]);	//정한 피봇을 첫번째와 교환
	pivot = arr[left];
	while (left < right) {
		while (arr[right] >= pivot && left < right) right--;		//피봇보다 같거나 큰 곳까지 right--
		if (left != right) {
			arr[left] = arr[right];									//left에 피봇보다 작은 값을 넘겨줌
		}

		while (arr[left] <= pivot && left < right) left++;			//피봇보다 같거나 작은 곳까지 left++

		if (left != right) {
			arr[right--] = arr[left];								//피봇보다 큰 것을 right 위치에 넘겨줌
		}
	}
																	//left와 right가 일치할 때까지 반복
																	//pivot 자리를 찾아냄
	arr[left] = pivot;												//pivot에 위치
	pivot = left;
	left = temp_left;
	right = temp_right;												//일시적으로 사용했던 left와 right를 원래대로
	
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

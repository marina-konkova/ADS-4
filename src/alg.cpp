// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
	int count = 0;
	for (int k = 0; k < len-1; k++) {
		for (int j = k+1; j < len; j++) {
			if (arr[k] + arr[j] == value) {
				count += 1;
			}
		}
	}
	return count;
}
int countPairs2(int* arr, int len, int value) {
	int count = 0;
	for (int k = 0; k < len - 1; k++) {
		for (int j = len - 1; k < j; j--) {
			if (arr[k] + arr[j] == value) {
				count += 1;
			}
		}
	}
	return count;
}
int countPairs3(int* arr, int len, int value) {
	int count = 0;
	for (int k = 0; k < len - 1; k++) {
		int left = k, right = len;
		while (left < right - 1) {
			int middle = (left + right) / 2;
			if (arr[k] + arr[middle] == value) {
				count += 1;
				int newmid = middle + 1;
				while (arr[k] + arr[newmid] == value) {
					count += 1;
					newmid += 1;
				}
				newmid = middle - 1;
				while (arr[k] + arr[newmid] == value) {
					count += 1;
					newmid -= 1;
				}
				break;
			} 
			if (arr[k] + arr[middle] > value) {
				right = middle;
			} else {
				left = middle;
			}
		}
	}
	return count;
}

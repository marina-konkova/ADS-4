// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int l = 0;
  int r = len - 1;
  while (l < r) {
    int sum = arr[l] + arr[r];
    if (sum == value) {
      count++;
      l++;
      r--;
    } else if (sum < value) {
      l++;
    } else {
      r--;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int l = i + 1, r = len - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] + arr[i] == value) {
        count++;
        break;
      }
      else if (arr[mid] + arr[i] < value) {
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
  }
  return count;
}

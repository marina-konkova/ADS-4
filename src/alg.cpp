// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = len-1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i, right = len;
    while (right - 1 > left) {
      int mid1 = (left + right) / 2;
      if (arr[i] + arr[mid1] == value) {
        count++;
        int mid2 = mid1 + 1;
        while (arr[i] + arr[mid2] == value && mid2 < right) {
          count++;
          mid2++;
        }
        mid2 = mid1 - 1;
        while (arr[i] + arr[mid2] == value && mid2 > left) {
          count++;
          mid2--;
        }
        break;
      }
      if (arr[i] + arr[mid1] > value) {
        right = mid1;
      } else {
        left = mid1;
      }
    }
  }
  return count;
}

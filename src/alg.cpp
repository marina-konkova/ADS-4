// Copyright 2021 NNTU-CS
#include <algorithm>
int countPairs1(int* arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value)
{
  int count = 0;
  int i = 0, j = len - 1;
  while (i < j) {
    if (arr[i] + arr[j] == value) {
      count++;
      i++;
      j--;
    }
    else if (arr[i] + arr[j] < value) {
      i++;
    }
    else {
      j--;
    }
  }
  return count;
}
int countPairs3(int* arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len; i++) {
    int j = lower_bound(arr + i + 1, arr + len, value - arr[i]) - arr;
    if (j < len && arr[j] == value - arr[i]) {
      count++;
    }
  }
  return count;
}

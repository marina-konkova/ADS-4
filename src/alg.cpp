// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
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
  for (int r = 0; r < len - 1; r++) {
    for (int l = len - 1; r < l; l--) {
      if (arr[r] + arr[l] == value) {
        count += 1;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i, right = len;
    while (left < right - 1) {
      int middle = (left + right) / 2;
      if (arr[i] + arr[middle] == value) {
        count += 1;
        int newmid = middle + 1;
        while (arr[i] + arr[newmid] == value) {
          count += 1;
          newmid += 1;
        }
        newmid = middle - 1;
        while (arr[i] + arr[newmid] == value) {
          count += 1;
          newmid -= 1;
        }
        break;
      }
      if (arr[i] + arr[middle] > value) {
        right = middle;
      } else {
        left = middle;
      }
    }
  }
  return count;
}


void reverse( int arr[], unsigned int len ) {
  /* swap first <-> last and not middle */

  int mid = len / 2;
  int l, r;
  l = 0;
  r = len-1;

  while(l < mid) {
	  int _temp = arr[l];
	  arr[l++] = arr[r];
	  arr[r--] = _temp;
  }
}

# 快速排序

随机选择一个主元(pivot)，然后将大于主元的元素放于数组的右边，小于主元的放置在左边，然后类似递归地对左侧的元素和右侧的元素分别进行相同的操作。  

快速排序之所以较快，可以这么理解：每选择一个pivot，在对其进行左右划分之后，它停留的位置就是最终的位置，而不像插入排序。  

##代码
```C++
void QuickSort::qsort(int* &A, int s, int e) {
	if(s < e){
		int i = s, j = e, x = A[i];
		while(i < j){
			while(i < j && A[j] >= x)
				j--;
			if(i < j)
				A[i++] = A[j];
			while(i < j && A[i] < x)
				i++;
			if(i < j)
				A[j--] = A[i];
		}
		A[i] = x;
		qsort(A, s, i - 1);
		qsort(A, i + 1, e);
	}
}

int* QuickSort::quickSort(int* A, int n){
	if(n > 1){
		//长度检查
		qsort(A, 0, n - 1);
		//打印
		for (int i = 0; i < n; i++) {
			cout << A[i] << " ";
		}
		return A;
	} else {
		return A;
	}
}
```

####时间复杂度
> O(NlogN)

####快速排序的最优情况?最坏情况？
> 最优：  
每次选择的主元恰好中分  
最坏：  
主元选取a[0]的情况下，对已经排序好的元素进行排序，退化为O(N^2)

####pivot取法
> * 数组第一个元素a[0]
  * 选择头、中、尾（3个数）的中位数
  * 随机，但是随机函数效率不高，所以基本不会使用
﻿# 快速排序

[返回](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/Sort/index.md)

随机选择一个主元(pivot)，然后将大于主元的元素放于数组的右边，小于主元的放置在左边，然后类似递归地对左侧的元素和右侧的元素分别进行相同的操作。  

快速排序之所以较快，可以这么理解：每选择一个pivot，在对其进行左右划分之后，它停留的位置就是最终的位置，而不像插入排序。  

##1. 代码
####C++实现
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

####median选取pivot的实现
```C++
int QuickSort::median3(int* &A, int s, int e){
	int center = (s + e) / 2;
	if (A[s] > A[center]) swap(A, s, center);
	if (A[s] > A[e]) swap(A, s, e);
	if (A[center] > A[e]) swap(A, center, e);
	swap(A, center, e - 1);			//	将pivot隐藏到右边
	// 只需要考虑A[s + 1] ... A[e - 2]
	return A[e - 1];
}

void QuickSort::qsort(int* &A, int s, int e) {
	if (e > s)
	{
		int pivot = median3(A, s, e);
		if ((e - s) < 2) return;
		int i = s, j = e - 1;
		while(1)
		{
			while(A[++i] < pivot) {}		//median为这里的做好了边界，所以不需要边界检查
			while(A[--j] > pivot) {}
			if(i < j){
				this->swap(A, i, j);
			}
			else break;
		}
		this->swap(A, i, e - 1); 
		this->qsort(A, s, i - 1);
		this->qsort(A, i + 1, e);
	}
}


int* QuickSort::quickSort(int* A, int n){
	this->qsort(A, 0, n - 1);
	this->print(A, 0, n-1);
	return A;
}

void QuickSort::swap(int* &A, int i, int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

/*
 * 打印数组
 */
void QuickSort::print(int* A, int s, int e) {
	for(int i = s; i <= e; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
```


##2. 总结
####2.1 时间复杂度
> O(NlogN)

####2.2 快速排序的最优情况?最坏情况？
> 最优：  
每次选择的主元恰好中分  
最坏：  
主元选取a[0]的情况下，对已经排序好的元素进行排序，退化为O(N^2)

####2.3 pivot取法
> * 数组第一个元素a[0]
* 选择头、中、尾（3个数）的中位数
* 随机，但是随机函数效率不高，所以基本不会使用
  
####2.4 遇到和pivot相等的元素怎么办？

> * 停下来交换
* 继续移动指针    
先来看第二种情况，如果遇到一个所有元素都相等的case，会出现只有i指针不断移动，一直比较到数组末尾，j指针不会改变。这样pivot每次都存放在端点的位置。
最终数组会退化到O(N^2)的情况。  
第一种情况，每一次pivot都会被移到比较中间的位置，每次都会相对均匀地将数组划分，最后的时间复杂度是O(NlogN)  
所以，我们选择第一种

####2.5 和其他算法的比较

> 快速排序在小数据集上并不一定比插入排序快（例如N < 100）,因为快速排序使用递归。    
  还可以在递归中，遇到数据规模足够小(一般定义一个cutoff值)，则停止递归直接调用简单的排序算法。   
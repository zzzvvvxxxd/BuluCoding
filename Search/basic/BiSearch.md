#折半查找

[返回](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/Search/index.md)

折半查找是建立在数据**有序**的条件下。  

时间效率：  
> O(logN)  


```C++
int binary_search(int* a, int key, int begin, int end)
{
    if(begin >= end)
        return -1;      //array is empty
    int middle = (begin + end) / 2;
    if(a[middle] > key)
        return binary_search(a, key, begin, middle);        //注意这里是middle
    else if (a[middle] < key)
        return binary_search(a, key, middle + 1, end);
    else
        return middle;
}

int main() {
    int a[] = {1, 3, 5, 7, 9};
    for(int i = 0; i < 15; i++){
        cout << "Searching " << i << endl;
        cout << " Position is " << binary_search(a, i, 0, 5) << endl;
    }
    return 0;
}

```

####迭代解法
```C++
int binary_search(int* a, int key, int begin, int end)
{
	while(begin < end){
		int middle = (begin + end) / 2;
		if(a[middle] < key)
			begin = middle + 1;
		else if (a[middle] > key)
			end = middle;
		else
			return middle;
	}
	return -1;
}
```
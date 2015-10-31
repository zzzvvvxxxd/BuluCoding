#最大公约数

[返回](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/Math/index.md)  

使用辗转相除法，具体可以百度

```C++
int mcd_mod(int m, int n)
{
	//假设m是较大的那个数字
	if(n == 0) 
		return m;
	else
		return mcd_mod(n, m % n);
}
```
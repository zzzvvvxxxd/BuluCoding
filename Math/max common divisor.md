#最大公约数

[返回](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/Math/index.md)  

使用辗转相除法:

* 当m>n, m和n的最大公约数等于n和m%n的最大公约数   
* 当n=0, m和n的最大公约数是m   

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
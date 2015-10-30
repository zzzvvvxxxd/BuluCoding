#斐波纳契数列

[返回]()


[题目地址](http://www.lintcode.com/zh-cn/problem/fibonacci/)

查找斐波纳契数列中第 N 个数。
所谓的斐波纳契数列是指：  
前2个数是 0 和 1 。
第 i 个数是第 i-1 个数和第i-2 个数的和。
斐波纳契数列的前10个数字是：

```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...
```

样例：  
* 给定 1，返回 0  
* 给定 2，返回 1  
* 给定 10，返回 34  

####C++
```
class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if(n==1) return 0;
        if(n==2) return 1;
        int a = 0, b = 1;
        for(int i = 0; i < n - 2; i ++)
        {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};

```

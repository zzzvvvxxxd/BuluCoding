# Rectangle Area


[返回](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/Geometry/index.md)


**题目描述：**  
Find the total area covered by two rectilinear rectangles in a 2D plane.  
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.  
![图片](https://leetcode.com/static/images/problemset/rectangle_area.png)


[题目地址](https://leetcode.com/problems/rectangle-area/)


```C++
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int all = (C - A) * (D - B) + (G - E) * (H - F);
        return all - ( (C <= E || D <= F || G <= A || H <= B) ? 0 : (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)));
    }
};
```
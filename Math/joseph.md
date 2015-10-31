#约瑟夫环

[返回](https://github.com/zzzvvvxxxd/BuluCoding/blob/master/Math/index.md)  

####C++
数组实现
```C++
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class joseph_circle{
public:
    int *next_persons;
    int length;
    int tail;
    joseph_circle(int len) : length(len) {
        next_persons = new int[length];
        for(int i = 0; i < length; i++) {
            next_persons[i] = (i + 1) % length;       //保存的是下一个元素的位置
        }
        tail = length - 1;
    }

    void eliminate(int step){
        int p = tail;
        while(next_persons[p] != p) {
            for(int i = 0; i < step - 1; i++) {
                p = next_persons[p];
            }
            int eliminated_node = next_persons[p];
            next_persons[p] = next_persons[eliminated_node];
            if (eliminated_node == tail) {
                tail = p;
            }
            cout << "eliminate node: " << eliminated_node << endl;
            print();
        }
    }

    void print() {
        int p = tail;
        while(true) {
            p = next_persons[p];
            cout << p << " ";
            if(p == tail)
                break;
        }
        cout << endl;
    }
private:
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    joseph_circle circle(6);
    circle.eliminate(3);
    return 0;
}
```
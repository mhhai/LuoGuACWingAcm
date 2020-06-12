//AC了8个测试用例
//有两个超时了
#include<iostream>
#include<vector>
using namespace std;
class minHeap
{
public:
    minHeap()
    {
        heap_size = 0;
        heap.resize(1000000, 0); // 必须resize，push的时候不能直接push_back
    }
    //想要push一个元素，可以将该元素先放到heap最后的位置，然后不断上升到正确的位置
    void push(int elem)
    {
        cout << "push开始： " << endl;
        if (heap_size == 0)
        {
            heap[1] = elem;
            heap_size += 1;
        }
        //调整
        else
        {
            heap_size += 1;
            heap[heap_size] = elem;
            int i = heap_size;
            while (i > 1 && heap[i / 2] > elem)
            {
                swap(heap[i / 2], heap[i]);  //注意不是swap(heap[i / 2], elem)
                i = i / 2;
            }
        }
        cout << "head中的元素： " << endl;
        for (int i = 0; i <= heap_size; ++i)
            cout << heap[i] << " ";
        cout << endl;
    }

    void pop()
    {
        cout << "pop开始： " << endl;
        if (heap_size < 1)
            cout << "error" << endl;

        int i = heap_size;
        swap(heap[1], heap[i]);  //将最小元素与最末尾元素调换
        //此时除了第一个元素之外，其他元素都满足最小堆的性质，因为可以调用heapify来维持最小堆的性质

        heap_size--;
        heapify(1);
        cout << "head中的元素： " << endl;
        for (int i = 0; i <= heap_size; ++i)
            cout << heap[i] << " ";
        cout << endl;
        //
    }
    int top()
    {
        cout << "top开始： " << endl;
        cout << "heap_size: " << heap_size << endl;
        cout << "head中的元素： " << endl;
        for (int i = 0; i <= heap_size; ++i)
            cout << heap[i] << " ";
        cout << endl;
        return heap[1];
    }


private:
    int heap_size;
    vector<int> heap; //
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify(int index)
    {
        int left = index * 2;  //左孩子
        int right = index * 2 + 1; //右孩子
        int minId = index;
        if (left <= heap_size && heap[minId] > heap[left])
            minId = left;
        if (right <= heap_size && heap[minId] > heap[right])
            minId = right;
        if (minId != index)
        {
            swap(heap[minId], heap[index]);
            heapify(minId);
        }
    }
};
int main()
{
    int n;
    cin >> n;
    minHeap Q;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m == 1)
        {
            int k;
            cin >> k;
            Q.push(k);
        }
        else if (m == 2)
        {
            cout << Q.top() << endl;
        }
        else if (m == 3)
        {
            Q.pop();
        }
        else
        {
            cout << "error" << endl;
        }
    }
}
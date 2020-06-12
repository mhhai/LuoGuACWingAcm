//AC��8����������
//��������ʱ��
#include<iostream>
#include<vector>
using namespace std;
class minHeap
{
public:
    minHeap()
    {
        heap_size = 0;
        heap.resize(1000000, 0); // ����resize��push��ʱ����ֱ��push_back
    }
    //��Ҫpushһ��Ԫ�أ����Խ���Ԫ���ȷŵ�heap����λ�ã�Ȼ�󲻶���������ȷ��λ��
    void push(int elem)
    {
        cout << "push��ʼ�� " << endl;
        if (heap_size == 0)
        {
            heap[1] = elem;
            heap_size += 1;
        }
        //����
        else
        {
            heap_size += 1;
            heap[heap_size] = elem;
            int i = heap_size;
            while (i > 1 && heap[i / 2] > elem)
            {
                swap(heap[i / 2], heap[i]);  //ע�ⲻ��swap(heap[i / 2], elem)
                i = i / 2;
            }
        }
        cout << "head�е�Ԫ�أ� " << endl;
        for (int i = 0; i <= heap_size; ++i)
            cout << heap[i] << " ";
        cout << endl;
    }

    void pop()
    {
        cout << "pop��ʼ�� " << endl;
        if (heap_size < 1)
            cout << "error" << endl;

        int i = heap_size;
        swap(heap[1], heap[i]);  //����СԪ������ĩβԪ�ص���
        //��ʱ���˵�һ��Ԫ��֮�⣬����Ԫ�ض�������С�ѵ����ʣ���Ϊ���Ե���heapify��ά����С�ѵ�����

        heap_size--;
        heapify(1);
        cout << "head�е�Ԫ�أ� " << endl;
        for (int i = 0; i <= heap_size; ++i)
            cout << heap[i] << " ";
        cout << endl;
        //
    }
    int top()
    {
        cout << "top��ʼ�� " << endl;
        cout << "heap_size: " << heap_size << endl;
        cout << "head�е�Ԫ�أ� " << endl;
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
        int left = index * 2;  //����
        int right = index * 2 + 1; //�Һ���
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
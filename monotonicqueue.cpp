#include<iostream>
#include<deque>
#include<vector>
using namespace std;

//A monotonic queue is a queue that saves data in a certain order (wether it be ascending or descending)
//For example, given the following array of numbers : [5, 8, 10, 2, 7, 3], fill an ascending monotonic queue 

/*
    i=0
        monotonic queue = []
        check if queue is empty = 1
            since queue is empty we do not have to make any comparisons with the last value in it
        push the element at index 0 into the monotonic queue
        monotonic queue = [5]

    i=1
        monotonic queue = [5]
        check if queue is empty = 0
        check if the last element inserted is greater than the element we want to insert = 0
        push the element at index 1 into the monotonic queue
        monotonic queue = [5, 8]
    
    i=2
        monotonic queue = [5, 8]
        check if queue is empty = 0
        check if the last element inserted is greater than the element we want to insert = 0
        push the element at index 2 into the monotonic queue
        monotic queue = [5, 8, 10]

    i=3
        monotonic queue = [5, 8, 10]
        check if queue is empty = 0
        check if the las element inserted is greater than the element we want to insert = 1
            delete last element = [5, 8, 10]
                [5, 8]
        check if the last element inserted is greater than the element we want to insert = 1
            delete last element = [5, 8]
                [5]
        check if the last element inserted is greater than the element we want to insert = 1
            delete the last element = [5]
                []
        queue is empty so we break out of for loop
        push element at index 3 into queue
        monotonic queue = [2]

    i=4
        monotonic queue = [2]
        check if queue is empty = 0
        check if last element inserted is greater than the element we want to insert = 0
        push element at index 4 into queue
        monotonic queue = [2, 7]

    i=5
        monotonic queue = [2, 7]
        check if queue is empty = 0
        check if last element inserted is greater than the element we want to insert = 1
            delete last element = [2, 7]
                [2]
        check if last element inserted is greater than the element we want to insert = 0
        push element at index 5 into queue
        monotonic queue = [2, 3]
*/

class monotonicQueue
{
private:
    deque<int> monQueue;
public:
    void push(int x)
    {
        while(!monQueue.empty() && monQueue.back() > x)
        {
            monQueue.pop_back();
        }
        monQueue.push_back(x);
    }
    void push(int *arr)
    {
        for(int i = 0; i < 10; i++)
        {
            while(!monQueue.empty() && monQueue.back() > *(arr + i))
            {
                monQueue.pop_back();
            }
            monQueue.push_back(*(arr + i));
        }
    }
    void show()
    {
        deque<int> temp = monQueue;
        cout << "\x1b[2H\x1b[J";
        while(!temp.empty())
        {
            cout << temp.back() << "\n";
            temp.pop_back();
        }
    }
    void popBack()
    {
        monQueue.pop_back();
    }
};

int main()
{
    monotonicQueue q;
    int arr[10], x, element;
    for(int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    q.push(arr);
    while(true)
    {
        cout << "1. Insert\n2. Show\n3. Pop back\n";
        cin >> x;
        switch(x)
        {
            case 1:
                cin >> element;
                q.push(element);
            break;
            case 2:
                q.show();
            break;
            case 3:
                q.popBack();
            break;
            case 4:
                return 0;
            break;
        }
    }
    return 0;
}

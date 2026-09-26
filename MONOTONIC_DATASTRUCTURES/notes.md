# Monotonic Datastructures
### Two Types
1. Monotonic Increasing
2. Monotonic Decreasing

## What is mean by `monotonic` in Data Strctures?
In mathematics, a sequence is called monotonic increasing if each element in the sequence is greater or equal to the one before it

Monotonic decreasing if each element is less or equal to the one before it.

We often use this idea in stacks and queues to achieve our goal.

## monotonic stack
A stack that always remains in increasing (monotonic increasing) or decreasing (monotonic decreasing) as elements as pushed or popped from stack.


```cpp
vector<int> arr = {4, 2, 5, 1, 3};
stack<int> st;
```

template
```cpp
for(int i = 0; i < n; i++){
    while(!st.empty() && arr[st.top()] > arr[i]){
        st.pop(); //we want increasing
    }
    st.push(i); //maintains increasing order
}
```

## How does this even help us?
let's suppose you are asked to find Next Smaller Element to Left (NSEL)
example
```cpp
arr = {4, 2, 5, 2, 3}
result = {-1, -1, 2, -1, 1}
```
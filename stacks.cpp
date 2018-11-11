/* Date: 11/10/2018
 * Description: This Program implements stacks using class template
 *              concepts
 * Author: Chandra Mohan
 */

#include <iostream>
using namespace std;

template <class T>
class stack{
  public:
    stack();
    stack(int s);
    ~stack();
    void push(T element);
    void pop();
    bool isFull();
    bool isEmpty();
  private:
    int maxSize;
    T* arr1;
    int stackPtr;
};

template <class T>
stack<T>::stack(){
  maxSize =100;
  arr1 = new T[maxSize];
  stackPtr = -1;
}

template <class T>
stack<T>::stack(int s){
  maxSize = s;
  arr1 = new T[maxSize];
  stackPtr = -1;
}

template <class T>
stack<T>::~stack(){

}

template <class T>
bool stack<T>::isFull(){
  if(stackPtr == maxSize)
  return true;
  else
  return false;
}

template <class T>
void stack<T>::push(T element){
  if(isFull()){
    cout << "The stack is full";
    exit(1);
  }
  else{
    stackPtr++;
    arr1[stackPtr] = element;
    cout << "Pushed Value is:"<< "\t" << arr1[stackPtr] <<endl;
  }
}


template <class T>
bool stack<T>::isEmpty(){
  if(stackPtr == -1)
  return true;
  else
  return false;
}

template <class T>
void stack<T>::pop(){
  if(isEmpty()){
    cout << "The Stack is Empty";
    exit(1);
  }
  else{
    cout << "Popped Value is:"<< "\t" << arr1[stackPtr] <<endl;
    stackPtr--;
  }
}

int main(){
  typedef stack<int> intStack;
  intStack p(2);
  p.push(1);
  p.push(2);
  p.push(4);
  p.pop();
  p.pop();
  p.pop();
  typedef stack<char> charStack;
  charStack c(1);
  c.push('h');
  c.push('k');
  c.pop();
  c.pop();
  typedef stack<float> floatStack;
  floatStack f(1);
  f.push(0.1);
  f.push(0.2);
  f.pop();
  f.pop();
}
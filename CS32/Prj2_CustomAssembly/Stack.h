#ifndef STACK_INCLUDED
#define STACK_INCLUDED

template <typename T>
class StackNode
{
public:
T data;
StackNode<T> *next;
StackNode<T> *prev;
private:
};

template <typename T>
class Stack
{
public:
	Stack();
	void push(T x);
	void pop();
	T top() const;
	bool empty() const;
	

private:
	StackNode<T> * m_top;
};


template <typename T>
Stack<T>::Stack()
{
	m_top=nullptr; 
}

template <typename T>
void Stack<T>::push(T x)
{
	StackNode<T> *temp=new StackNode<T>;
	temp->data=x;
	temp->next=m_top;
	m_top=temp;

}

template <typename T>
void Stack<T>::pop()
{
	StackNode<T> *vol;
	vol=m_top;
	m_top=vol->next;
	delete vol;

}
template <typename T>
T Stack<T>::top() const 
{
	
	
	return m_top->data; 

}
/*what if m_top is empty*/

template <typename T>
bool Stack<T>::empty() const
{ 
if(m_top==nullptr)
	return true;
else
	return false;
}



#endif


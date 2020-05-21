#ifndef STACK_STACKLIST_H
#define STACK_STACKLIST_H

#include "Stack.h"

template <class T>
class StackList : public Stack<T>
{
public:
  StackList();
	virtual ~StackList();
	void	push(const T& e) override;
	T&		pop() override;
  T&		top() override;
  bool	isEmpty() override;
private:
	template <class T>
	struct Node
	{
		T data_;
		Node* next_;
		Node(const T& data, Node* next) :
		  data_(data), next_(next){}
	};
	
	Node<T>* top_;
};

template <class T>
StackList<T>::StackList(): top_(nullptr)
{
}

template<class T>
StackList<T>::~StackList()
{
	Node<T>* temp;
	
	while (top_)
	{
		temp = top_;
		top_ = top_->next_;
		delete temp;
	}
	top_ = nullptr;
}

template<class T>
void StackList<T>::push(const T& e)
{
	Node<T>* temp = new Node<T>(e, top_);
	top_ = temp;
}

template<class T>
 T& StackList<T>::pop()
{
	if (!top_)
		throw StackUnderflow();

	Node<T>* temp = top_;
	T data;
	data = top_->data_;
	top_ = top_->next_;
	delete temp;
	return data;

}

template <class T>
T& StackList<T>::top()
{
  return top_->data_;
}

template <class T>
bool StackList<T>::isEmpty()
{
  return top_ == nullptr;
}

#endif //! STACK_STACKLIST_H

#ifndef _STACK_ // �̰� ���ǵǾ����� �ʴٸ� �Ʒ� ���� (is not define)
#define	_STACK_ // �����Ѵٰ� �ؼ� ���� �� �ڵ�� �������� �׳� endif�� �Ѿ


#include <exception>
#include <memory>

template <typename T>
class Stack {
private:
	T* data;
	int tp;
	int sz;
public:
	Stack(int = 10);
	~Stack();
	bool isEmpty() const;
	void push(T);
	void pop();
	T top() const;
	int size() const;
};

template <typename T>
Stack<T>::Stack(int size)
	:tp(-1), sz(size)
{
	data = new T[sz];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] data;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return tp == -1;
}

template <typename T>
T Stack<T>::top() const
{
	if (!isEmpty())
		return data[tp];
	else
		throw std::exception("Stack is empty.");
}

template <typename T>
void Stack<T>::pop()
{
	if (!isEmpty())
		tp--;
	else
		throw std::exception("Stack is empty.");
}

template <typename T>
void Stack<T>::push(T n)
{
	tp++;

	if (tp == sz) {
		T* tmp = new T[2 * sz];
		memcpy(tmp, data, sz * sizeof(T));
		sz *= 2;

		delete[] data;
		data = tmp;
	}

	data[tp] = n;
}

template <typename T>
int Stack<T>::size() const
{
	return sz;
}

#endif // !_STACK
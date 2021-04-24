#include <iostream>
#include <queue>

using namespace std;

class stack
{
	queue<int> q1, q2;
	int N = 0;

public:
	bool empty()
	{
		return q1.empty();
	}

	int size()
	{
		return N;
	}

	void push(int x)
	{
		q2.push(x);
		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		queue<int> q3 = q1;
		q1 = q2;
		q2 = q3;
		++N;
	}

	void pop()
	{
		if (q1.empty())
			cout << "Nothing to pop\n";
		else
			q1.pop(), --N;
	}

	int top()
	{
		if(q1.empty()){
			cout << "Empty Stack\n";
			return -1;
		}
		return q1.front();
	}
};

int main()
{
	stack s;
	s.push(10);
	s.push(20);
	s.push(40);
	s.push(30);
	s.push(50);
	s.push(60);
	s.push(70);

	while (!s.empty())
		cout << s.top() << '\n' , s.pop();
}

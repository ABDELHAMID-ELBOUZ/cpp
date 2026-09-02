#include "RPN.hpp"
#include <stack>

RPN::RPN()
{

}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::~RPN() {}

bool RPN::evaluate(const std::string& expr, int& result)
{
	std::stack<int> stk;

	for (size_t i = 0; i < expr.length(); ++i)
	{
		char c = expr[i];

		if (c == ' ')
			continue;

		if (c >= '0' && c <= '9')
			stk.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (stk.size() < 2)
				return false;

			int b = stk.top();
			stk.pop();
			int a = stk.top();
			stk.pop();

			if (c == '+')
				stk.push(a + b);
			else if (c == '-')
				stk.push(a - b);
			else if (c == '*')
				stk.push(a * b);
			else if (c == '/')
			{
				if (b == 0)
					return false;
				stk.push(a / b);
			}
		}
		else
			return false;
	}

	if (stk.size() != 1)
		return false;

	result = stk.top();
	return true;
}
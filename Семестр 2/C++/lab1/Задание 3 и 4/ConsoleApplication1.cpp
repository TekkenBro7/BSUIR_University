#include <iostream>

using namespace std;

class Expression
{
public:
	virtual double evaluate() = 0;
	virtual ~Expression() = 0;	
};

Expression::~Expression() {};

class Number : public Expression
{
private:
	double number;

public:
	double evaluate() override
	{
		return number;
	}
	Number()
	{
		number = 0;
	}
	Number(double num)
	{
		number = num;
	}
};

class BinaryOperation : public Expression
{
private:
	Expression* left;
	Expression* right;
	char sign;

public:
	BinaryOperation(Expression* a, char operation, Expression* b)
	{
		left = a;
		sign = operation;
		right = b;
	}
	double evaluate() override
	{
		if (sign == '+')
		{
			return left->evaluate() + right->evaluate();
		}
		else if (sign == '-')
		{
			return left->evaluate() - right->evaluate();
		}
		else if (sign == '*')
		{
			return left->evaluate() * right->evaluate();
		}
		else if (sign == '/')
		{
			return left->evaluate() / right->evaluate();
		}
	}

	~BinaryOperation()
	{
		delete left;
		delete right;
	}
};

bool check_equals(Expression const* left, Expression const* right)
{
	return *(void**)left == *(void**)right;
}


int main()
{
	Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	cout << sube->evaluate() << '\n';
	Expression* expr = new BinaryOperation(new Number(3), '+', sube);
	cout << expr->evaluate() << '\n';
	bool c = check_equals(new Number(4.5), new Number(3334));
	cout << c;

	delete expr;
}
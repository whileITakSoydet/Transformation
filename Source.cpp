#include <iostream>

using namespace std;

class Mistake
{
public:
	virtual string tell() = 0;
};

class Mistake_size :public Mistake
{
public:
	string tell() override
	{
		return "Size bigger than int";
	}
};

class Mistake_char : public Mistake
{
public:
	string tell() override
	{
		return "Translate in int error";
	}
};

int convert(string& s)
{
	int a = 0;
	while (s[a] != '\0')
	{
		a++;
		if (a > 9)
		{
			throw Mistake_size();
			return 0;
		}
	}
	int* arr = new int[a];
	for (int i = 0; i < a; i++)
	{
		arr[i] = s[i];
		if (arr[i] > 57 || arr[i] < 48)
		{
			throw Mistake_char();
			return 0;
		}
		arr[i] -= 48;
	}
	int b = 0;
	for (int i = 0; i < a; i++)
	{
		b *= 10;
		b += arr[i];
	}
	return b;
}

int main()
{
	string str = "34678";
	try
	{
		int a = convert(str);
		cout << a << endl;
	}
	catch (Mistake& e)
	{
		cout << e.tell() << endl;
	}


	return 0;
}
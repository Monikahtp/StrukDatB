#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> angkaStack;
    stack<int> tempStack;
    int input;
    while (cin >> input)
	{
	angkaStack.push(input);
    }

    while (!angkaStack.empty())
	{
	int current = angkaStack.top();
	angkaStack.pop();
	while (!tempStack.empty() && tempStack.top() < current)
	{
	angkaStack.push(tempStack.top());
	tempStack.pop();
	}
    tempStack.push(current);
    }

    while (!tempStack.empty())
	{
	cout << tempStack.top();
    tempStack.pop();
    if (!tempStack.empty()){
        cout << " ";
		}
    }
    cout << endl;
    return 0;
}


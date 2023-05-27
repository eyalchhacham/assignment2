#include "priorityQueve.h"
#include <sstream>

bool isInteger(const std::string& input); 
void startAction(char action, priorityQueve& qp, int priority = 0, string data="");


int main()
{
	string priorityInput;
	char ch;
	int numActions;
	int i;
	char action;
	int priority;
	priorityQueve q;
	string data;
	cout << "please enter num actions :";
	cin >> numActions;
	if (numActions <= 0)
	{
		cout << "wrong input";
		exit(1);
	}
	cin >> action;
	if (action != 'e')
	{
		cout << "wrong input";
		exit(1);
	}
	else
		startAction(action, q);

	for (i = 0; i < numActions-1; i++)
	{
		cin >> action;
		if (action == 'e')
		{
			cout << "wrong input";
			exit(1);
		}
		else if (action != 'f')
		{
			if (std::cin && std::cin.peek() == '\n')
			startAction(action, q);
			else
			{
				cout << "wrong input";
				exit(1);
			}
		}
		
		else
		{
			cin >> priorityInput;
			if (isInteger(priorityInput)) 
				 priority = stoi(priorityInput);
			else {
				cout << "wrong input";
				exit(1);
			}

			
			getline(cin, data);
			startAction(action,q, priority, data);
		}
	}
	

	return 0;
	
}

void startAction(char action, priorityQueve& qp, int priority, string data)
{
	switch (action)
	{
	
	case 'a':qp.max(); break;
	case 'b':qp.deleteMax();  break;
	case 'c':qp.min();   break;
	case 'd':qp.deleteMin();  break;
	case 'e': qp.createEmpty();    break;
	case 'f':qp.insert(priority, data);   break;
	case 'g':qp.median();  break;
	default:cout << "wrong input"; exit(1); break;

	}
}
bool isInteger(const std::string& input) {
	std::istringstream iss(input);
	int value;
	return (iss >> value) && iss.eof();
}
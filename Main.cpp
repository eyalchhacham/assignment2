#include "priorityQueve.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void startAction(char action, priorityQueve& qp, int priority = 0, string data="");

int main()
{
	
	
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
		cout << "invalid number of actions";
		exit(1);
	}
	cin >> action;
	if (action != 'e')
	{
		cout << "invlid action, must be e function";
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
			startAction(action,q);
		
		else
		{
			cin >> priority;
			getline(cin, data);
			startAction(action,q, priority, data);
		}
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

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
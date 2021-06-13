#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class						Tree
{
	int					TreeSize;
	list<int>				*Nodes; // 노드의 인덱스
	list<int>				*contents; // 노드의 콘텐츠, 인덱스 마다 1대1 대응이 된다.

public:

	Tree(int InputSize);
	int					setContent(int node, int content);
	int					setEdge(int parent, int child);
	//BFS
	void					BFS();
	void					BFSTraversal(list<int> queue, bool *isVisited);
};

/*
**							생성자
*/
Tree::Tree(int InputSize)
{
	this->TreeSize = InputSize;
	this->Nodes = new list<int>[InputSize];
	this->contents = new list<int>[InputSize];
}

/*
**							Node의 Content 추가
*/
int						Tree::setContent(int node, int content)
{
	if (contents[node].size() != 0)
	{
		cout << "Node [" << node << "] already has one content (command cancled)" << endl;
		return (0);
	}
	this->contents[node].push_back(content);
	return (1);
}

/*
**							Node의 Link 추가
*/
int						Tree::setEdge(int parent, int child)
{
	Nodes[parent].push_back(child);
	return (1);
}

/*
**							BFS 순회
*/
void						Tree::BFS()
{
	list<int>				queue;
	bool					*isVisited;
	int					temp;

	isVisited = new bool[TreeSize];
	for (int idx = 0; idx < TreeSize; idx++)
	{
		isVisited[idx] = false;
	}
	BFSTraversal(queue, isVisited);
}

void						Tree::BFSTraversal(list<int> queue, bool *isVisited)
{
	list<int>::iterator		iter;
	int					this_idx;

	isVisited[0] = true;
	queue.push_back(0);
	while (!queue.empty())
	{
		this_idx = queue.front();
		cout << "Node : [" << this_idx << "] " << "Content: " << contents[this_idx].front() << endl << endl;
		queue.pop_front();

		for (iter = Nodes[this_idx].begin(); iter != Nodes[this_idx].end(); ++iter)
		{
			if (!isVisited[*iter])
			{
				isVisited[*iter] = true;
				queue.push_back(*iter);
			}
		}
	}
}

/*
**								실행(실행할 때 매개변수로 전체 사이즈를 넣어야 함.)
*/
void							start(int size)
{
	// 개수만큼 동적할당
	Tree						tree(size);
	int						temp;
	int						parent;
	int						child;

	// 각각의 노드에 들어가는 값을 할당
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	cout << endl << "Enter Parent Node(0 ~ " << size - 1 << ")'s content one by one" << endl;
	for (int idx = 0; idx < size; idx++)
	{
		cout << endl;
		cout << "Node [" << idx << "]'s content : ";
		cin >> temp;
		if (!tree.setContent(idx, temp))
			idx--;
	}

	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << endl;

	// link 할당
	cout << "Enter Parent Node number and Child Node number you want to link" << endl;
	cout << "(press ctrl-D to end add link)" << endl;

	while (true)
	{
		cout << endl;
		cout << "Parent : ";
		cin >> parent;
		if (cin.eof())
		{
			cout << endl;
			break ;
		}
		cin.clear();
		cout << "child : ";
		cin >> child;
		if (cin.eof())
		{
			cout << endl;
			break ;
		}
		cin.clear();
		tree.setEdge(parent, child);
	}
	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	// BFS 실행
	cout << "[BFS Traversal]" << endl << endl;
	tree.BFS();
	cout << endl;
	cout << "----------------------------------------------------" << endl;
}

int								main(int argc, char **argv)
{
	int						size;

	if (argc != 2)
	{
		cout << "ARG ERROR" << endl;
		cout << "Enter the number of nodes in the tree when running the program" << endl;
		return (1);
	}
	for (int idx = 0; idx < strlen(argv[1]); idx++)
	{
		if (argv[1][idx] < '0' || argv[1][idx] > '9')
		{
			cout << "ARG ERROR" << endl;
			cout << "Enter the number of nodes in the tree when running the program" << endl;
			return (1);
		}
	}
	size = atoi(argv[1]);
	start(size);
	return (0);
}

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class						DFSTree
{
	int						TreeSize;
	list<int>				*Nodes;

public:

	DFSTree(int InputSize);
	void					linkNode(int parent, int child); // parent list의 목록에 연결된 child들을 추가.
	void					DFSTraversal(int v, bool visited[]); // 재귀로 In-order traversal
	void					DFS();
};

DFSTree::DFSTree(int InputSize)
{
	this->TreeSize = InputSize;
	Nodes = new list<int>[InputSize];
}

void						DFSTree::linkNode(int parent, int child)
{
	Nodes[parent].push_back(child);
}

void						DFSTree::DFSTraversal(int v, bool isVisited[])
{
	list<int>::iterator		iter;


	isVisited[v] = true;
	cout << v << " ";

	// recursively process all the adjacent vertices of the node

	for (iter = Nodes[v].begin(); iter != Nodes[v].end(); ++iter)
	{
		if (!isVisited[*iter])
			DFSTraversal(*iter, isVisited);
		// 하나씩 타고 내려가는 것
	}
}

// DFS traversal
void						DFSTree::DFS()
{
	// initially none of the vertices are visited
	bool					*isVisited;

	isVisited = new bool[TreeSize];
	for (int i = 0; i < TreeSize; i++)
	{
		isVisited[i] = false;
	}

	// explore the vertices one by one by recursively calling  DFS_util
	for (int i = 0; i < TreeSize; i++)
	{
		if (isVisited[i] == false)
			DFSTraversal(i, isVisited);
	}
	cout << endl;
}

int								main()
{
	DFSTree						tree(7);

	tree.linkNode(0, 1);
	tree.linkNode(0, 2);
	tree.linkNode(1, 3);
	tree.linkNode(1, 4);
	tree.linkNode(2, 5);
	tree.linkNode(2, 6);

	tree.DFS();

	return 0;
}

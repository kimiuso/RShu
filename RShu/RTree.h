#pragma once
#include <vector>
#include <queue>
using namespace std;

struct Rect;
struct Node;
struct Branch;

class RTree 
{
protected:
	int maxBranchs;
	int minBranchs;
public:
	Node* root;

public:
	RTree();
	virtual ~RTree();
	RTree(int);
	void Insert(Rect);
	void Insert(Node*, Branch);
	Rect AddRect(Rect, Rect);
	long AreaOfRect(Rect);
	void UpdateMBR(Node*, Rect);
	Branch GetMBR(Node*);
	void PrintRTree();
	vector<Rect> Search(Rect);
	vector<Rect> Search(Node*, Rect);
	bool Match(Rect, Rect);
	

private:
	Node* NewNode();
	void DeleteNode(Node*);
};

struct Rect
{
	int x0, y0, x1, y1;
};

struct Node
{
	vector<Branch> branchs;
	Node* parent;
	int pos;
	int count;
	int level;
};

struct Branch
{
	Rect rect;
	Node* nextNode;
};
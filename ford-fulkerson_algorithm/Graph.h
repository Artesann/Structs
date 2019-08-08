#pragma once
#include <iostream>
#include "Stack.h" 

#define INFINITY 10000;

class Graph
{
public:
	struct Arc
	{
		int from;
		int to;
		int flow;
		int c_ij;
		int c_ji;
	};
	struct Node
	{
		bool mark;
		int previous;
		int flow;
	};
	struct __Graph
	{
		Node * nodes;
		Arc * arcs;
	};
	int nodes;
	int arcs;
	__Graph _Graph;

	Graph(int *data, int nodes, int arcs);
	void Run(int sorce, int runoff);
	void draw();
	~Graph();
};


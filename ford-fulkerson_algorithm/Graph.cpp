#include "Graph.h"
using namespace std;


Graph::Graph(int *data, int nodes, int arcs)
{
	this->nodes = nodes;
	this->arcs = arcs;
	this->_Graph.nodes = new Node[nodes];
	this->_Graph.arcs = new Arc[arcs];
	for (int i = 0; i < nodes; i++)
	{
		this->_Graph.nodes[i].mark = false;
		this->_Graph.nodes[i].flow = 0;
		this->_Graph.nodes[i].previous = 0;
	}
	for (int j = 0; j < arcs; j++) 
	{
		_Graph.arcs[j].c_ji = 0;
		for (int i = 0; i < nodes; i++)
		{
			if (data[i * arcs + j] == -1) _Graph.arcs[j].from = i;
			if (data[i * arcs + j] > 0)
			{
				_Graph.arcs[j].to = i;
				_Graph.arcs[j].flow = data[i * arcs + j];
				_Graph.arcs[j].c_ij = data[i * arcs + j];
			}
		}
	}
}
//Алгорим нахождения значения наименьшего разреза сети
void Graph::Run(int sorce, int runoff)
{
	int resFlow = 0;
	Stack path;
	_Graph.nodes[sorce].mark = true;
	bool *linkes = new bool[arcs];
	_Graph.nodes[sorce].mark = true;
	_Graph.nodes[sorce].previous = -1;
	_Graph.nodes[sorce].flow = INFINITY;
	bool search = true;

	while (search)
	{
		int i = sorce;
		for (int j = 0; j < nodes; j++)
		{
			if (j != sorce) 
			{
				_Graph.nodes[j].flow = 0;
				_Graph.nodes[j].previous = 0;
				_Graph.nodes[j].mark = false;
			}
		}

		bool is_runoff = false;

		while (!is_runoff)
		{
			int numVert = 0;
			for (int j = 0; j < arcs; j++)
				linkes[j] = false;

			for (int j = 0; j < arcs; j++)
				if(((_Graph.arcs[j].from == i) && !(_Graph.nodes[_Graph.arcs[j].to].mark) && (_Graph.arcs[j].c_ij > 0)) ||
					((_Graph.arcs[j].to == i) && !(_Graph.nodes[_Graph.arcs[j].from].mark) && (_Graph.arcs[j].c_ji > 0)))
				{
					numVert++;
					linkes[j] = true;
				}

			if (numVert)
			{
				int max = 0;
				int maxVert = 0;
				int maxLink = 0;
				for (int j = 0; j < arcs; j++)
				{
					if (linkes[j])
					{
						if (_Graph.arcs[j].from == i && _Graph.arcs[j].c_ij > max)
						{
							max = _Graph.arcs[j].c_ij;
							maxVert = _Graph.arcs[j].to;
							maxLink = j;
						}
						else if (_Graph.arcs[j].to == i && _Graph.arcs[j].c_ji > max)
						{
							max = _Graph.arcs[j].c_ji;
							maxVert = _Graph.arcs[j].from;
							maxLink = j;
						}
					}
				}
				//go nex step
				if (_Graph.arcs[maxLink].to == maxVert)
				{
					if (_Graph.nodes[i].flow <= _Graph.arcs[maxLink].c_ij)
						_Graph.nodes[maxVert].flow = _Graph.nodes[i].flow;
					else
						_Graph.nodes[maxVert].flow = _Graph.arcs[maxLink].c_ij;
				}
				else if(_Graph.arcs[maxLink].from == maxVert)
				{
					if (_Graph.nodes[i].flow <= _Graph.arcs[maxLink].c_ji)
						_Graph.nodes[maxVert].flow = _Graph.nodes[i].flow;
					else
						_Graph.nodes[maxVert].flow = _Graph.arcs[maxLink].c_ji;
				}
				_Graph.nodes[maxVert].mark = true;
				_Graph.nodes[maxVert].previous = i;
				path.push(maxLink);
				i = maxVert;

				if(i == runoff)
					is_runoff = true;
			}
			else
			{
				//going back for one step
				if (i != sorce)
				{
					i = _Graph.nodes[i].previous;
					path.pop();
				}
				else
				{
					is_runoff = true;
					search = false;
				}

			}
		}
		//rebalanse flow
		int prev = 0;//-1
		bool fl = false;
		while (!path.empty())
		{
			if (!fl || (_Graph.arcs[path.get_top()].to == _Graph.arcs[prev].from))
			{
				_Graph.arcs[path.get_top()].c_ij -= _Graph.nodes[runoff].flow;
				_Graph.arcs[path.get_top()].c_ji += _Graph.nodes[runoff].flow;
			}
			else
			{
				_Graph.arcs[path.get_top()].c_ij += _Graph.nodes[runoff].flow;
				_Graph.arcs[path.get_top()].c_ji -= _Graph.nodes[runoff].flow;
			}
			prev = path.get_top();
			path.pop();
			fl = true;
		}
		resFlow += _Graph.nodes[runoff].flow;
	}
	cout << "min cut: " << resFlow << endl;
	cout << "end" << endl;
}

void Graph::draw()
{
	cout << "Nodes" << endl;
	cout << "Numb " << "Mark " << "Prev " << "Flow" << endl;
	for (int i = 0; i < nodes; i++)
	{
		cout << i << "     "
			<< _Graph.nodes[i].mark << "     "
			<< _Graph.nodes[i].previous << "     "
			<< _Graph.nodes[i].flow << endl;
	}
	cout << endl;
	cout << "Links" << endl;
	cout << "Numb " <<"From " << "To   " << "c_ij " << "c_ji" << endl;
	for (int i = 0; i < arcs; i++)
	{
		cout << i << "     "
			<< _Graph.arcs[i].from << "     "
			<< _Graph.arcs[i].to << "     "
			<< _Graph.arcs[i].c_ij << "    "
			<< _Graph.arcs[i].c_ji << endl;
	}
}

Graph::~Graph()
{
}

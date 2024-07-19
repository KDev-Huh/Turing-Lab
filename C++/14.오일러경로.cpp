#include <list>
#include <iostream>
#include <vector>
#include <fstream>

class Graph {
public:
	Graph(int size)
		: size(size)
	{
		adj = new std::list<int>[size];
	}

	~Graph()
	{
		delete[] adj;
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}
	
	int dfsCount(int);	//driver
	
	void rmEdge(int, int);
	int isEulerian();
	bool isValidNextEdge(int, int);
	void printEulerTour();

	int printCount();
	
private:
	int dfsCore(int, std::vector<bool>&);	//workhorse
	void printEulerUtil(int, std::ofstream&);
	std::list<int>* adj;
	int size;
};

int Graph::printCount() 
{
	int on = 0;
	for (int i = 0; i < size; i++)
		if (!(adj[i].size() & 1))
			on += 1;

	return (size - on) * on;
}

void Graph::printEulerTour()
{
	if (isEulerian() == 0)
		return;

	int u = 0;

	std::ofstream ofile("result.txt", std::ios::app);

	for (int i = 0; i < size; i++)
		if (adj[i].size() & 1)
		{
			u = i;
			break;
		}

	printEulerUtil(u, ofile);
	std::cout << "\b\b \n";
	ofile << "\n";
	ofile.close();
}

void Graph::printEulerUtil(int v, std::ofstream& file)
{
	for(auto w: adj[v])
		if (w != -1 && isValidNextEdge(v, w))
		{
			std::cout << "(" << v << ", " << w << "), ";
			file << "(" << v << ", " << w << "), ";
			rmEdge(v, w);
			printEulerUtil(w, file);
		}
}

bool Graph::isValidNextEdge(int v, int w)
{
	int count = 0;

	for (auto i : adj[v])
		if (i != -1)
			count++;

	if (count == 1)
		return true;

	int count1 = dfsCount(v);
	rmEdge(v, w);
	int count2 = dfsCount(v);
	addEdge(v, w);

	return !(count1 > count2);
}

void Graph::rmEdge(int v, int w)
{
	for (auto& i : adj[v])
		if (i == w)
		{
			i = -1;
			break;
		}

	for (auto& i : adj[w])
		if (i == v)
		{
			i = -1;
			break;
		}
			
}

int Graph::dfsCount(int v)
{
	std::vector <bool> visited(size, false);
	return dfsCore(v, visited);
}

int Graph::dfsCore(int v, std::vector<bool>& visited)
{
	visited[v] = true;
	int count = 1;

	for (auto w: adj[v])
		if (w != -1 && !visited[w])
			count += dfsCore(w, visited);

	return count;
}

int Graph::isEulerian()
{
	int odd = 0;

	for(int i=0;i<size;i++)
		if (dfsCount(i) != size)
			return 0;

	for (int i = 0; i < size; i++)
		if (adj[i].size() & 1)
			odd++;

	if (!odd)
		return 1;
	else if (odd == 2)
		return 2;
	else
		return 0;
}


int main()
{
	std::ofstream ofile("result.txt");
	Graph g1(4);

	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);

	printf("%d\n", g1.printCount());
	g1.printEulerTour();

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.addEdge(3, 2);
	g2.addEdge(3, 1);
	g2.addEdge(2, 4);

	g2.printEulerTour();

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <fstream> //파일 접근
#include <iomanip>
#include <stack>

using Graph = std::vector<std::vector<int>>;  

class AdjMatrix {
public:
	void load(std::string);
	void insertVertex(int);
	void insertEdge(int, int);
	void deleteEdge(int, int);
	void adjacent(int);
	void display();
	void traverse(int);
private:
	Graph graph;
	std::string vertex; // vertex이름 -> char로 표시
};
// v: 시작 노드
void AdjMatrix::traverse(int v)
{
	std::stack<int> st;
	std::vector<bool> visit(vertex.size(), false);
	visit[0] = true;
	visit[v] = true;

	st.push(v);
	int current;
	while (!st.empty())
	{
		current = st.top(); st.pop();
		std::cout << vertex[current] << " ";
		for (int i = graph[current].size()-1; i > 0; i--)
		{
			if (graph[current][i] == 1 && !visit[i])
			{
				visit[i] = true;
				st.push(i);
			}
		}
	}
}

void AdjMatrix::load(std::string file)
{
	std::ifstream ifile(file); 

	int vn, en;
	ifile >> vn; // 정점 개수
	ifile >> vertex; // 정점 이름
	ifile >> en;

	vertex = " " + vertex;
	graph.resize(vn+1, std::vector<int>(vn+1, 0));

	int start, dest, weight;
	for (int i = 0; i < en; i++)
	{
		ifile >> start >> dest >> weight;

		graph[start][dest] = weight;
		graph[dest][start] = weight;
	}

	ifile.close();
}

void AdjMatrix::insertVertex(int v)
{}
void AdjMatrix::insertEdge(int start, int dest)
{}
void AdjMatrix::deleteEdge(int start, int dest)
{}
void AdjMatrix::adjacent(int v)
{}

void AdjMatrix::display()
{
	for (int i = 0; i < vertex.size(); i++)
		std::cout << std::setw(3) << vertex[i];
	std::cout << "\n";

	for (int r = 1; r < graph.size(); r++)
	{
		std::cout << std::setw(3) << vertex[r];
		for (int c = 1; c < graph[0].size(); c++)
		{
			std::cout << std::setw(3) << graph[r][c];
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}

int main()
{
	AdjMatrix amat;
	amat.load("graph.dat");
	amat.display();
	amat.traverse(1);


	return 0;
}
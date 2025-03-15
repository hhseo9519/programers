#include <string>
#include <vector>



#include <unordered_map>



using namespace std;








const int MAX = 4e5 + 4e2;








int parent[MAX];








int degree[MAX];








int rootGroup[MAX];








int nonRootGroup[MAX];








int find(int a)



{



	if (parent[a] == a)



	{



		return a;



	}








	return parent[a] = find(parent[a]);



}








void merge(int a, int b)



{



	a = find(a);



	b = find(b);








	if (a != b)



	{



		parent[b] = a;



	}



}








vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {



	int n = nodes.size();



	unordered_map<int, int> node2idx;








	for (int i = 0; i < n; i++)



	{



		parent[i] = i;



		node2idx[nodes[i]] = i;



	}








	for (auto edge : edges)



	{



		int u = node2idx[edge[0]];



		int v = node2idx[edge[1]];







		degree[u]++;



		degree[v]++;



	}







	for (auto edge : edges)



	{



		int u = node2idx[edge[0]];



		int v = node2idx[edge[1]];







		merge(u, v);



	}







	// 각 노드에 대해 그룹 분류



	// (node % 2) == (degree % 2) → 루트로 쓰일 수 있음



	for (int i = 0; i < n; i++)



	{



		int representative = find(i);







		if ((nodes[i] % 2) == (degree[i] % 2))



		{



			rootGroup[representative]++;



		}



		else



		{



			nonRootGroup[representative]++;



		}



	}







	int hTreeCount = 0, rTreeCount = 0;








	// 홀짝 트리는 루트 그룹이 오직 하나



	// 역홀짝 트리는 비루트 그룹이 오직 하나

	for (int i = 0; i < n; i++)
	{
		if (find(i) != i)
		{
			continue;
		}
		if (rootGroup[i] == 1)
		{
			hTreeCount++;
		}
		if (nonRootGroup[i] == 1)
		{
			rTreeCount++;
		}
	}
	return vector<int>{hTreeCount, rTreeCount};

}

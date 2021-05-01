#include<bits/stdc++.h> 
using namespace std;

typedef pair<int, int> iPair;
struct node
{
	node(int a, int b) 
	{ 
		dest=a; 
		weight= b;
	}
	int dest; 
	int weight;
};

void astar(int s,int d,vector<node>v[],int visited[],int parent[],int heu[],int dist[],int n)
{
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
	pq.push(make_pair(heu[s],s));
	dist[s]=0; 

	while(!pq.empty())
	{
		int p_s = pq.top().second; 
		if(p_s == d)
		{
			return;
		}
		pq.pop();
 
		if(!visited[p_s])
		{
			for(int i=0 ; i<v[p_s].size() ; i++)
			{
				if(!visited[v[p_s][i].dest])
				{
					int f = dist[p_s] + v[p_s][i].weight + heu[v[p_s][i].dest]; 
					pq.push(make_pair(f,v[p_s][i].dest));

					dist[v[p_s][i].dest] = dist[p_s] + v[p_s][i].weight; 
					parent[v[p_s][i].dest] = p_s;
				}
			}
			visited[p_s]=1;
		}
	}
}

int main()
{
	cout<<"Enter number of vertices in the graph :"<<endl; 
	int n;
	cin>>n; 
	vector<node>v[n];
	
	cout<<"Enter the number of edges :"<<endl; 
	int e;
	cin>>e;

	for(int i=0;i<e;i++)
	{
		cout<<"Enter the from vertex: "<<endl; 
		int s;
		cin>>s;

		cout<<"Enter the to vertex: "<<endl; 
		int d;
 		cin>>d;

		cout<<"Enter the weight "<<endl; 
		int w;
		cin>>w; 
		cout<<endl;

		v[s].push_back(node(d, w));
	}

	int visited[n]; 
	int parent[n]; 
	int heu[n]; 
	int dist[n];

	cout<<"Enter the heuristic values"<<endl; 
	for(int i=0;i<n;i++)
	{
		cout<<"For vertex "<<i<<" : "; 
		cin>>heu[i];

		visited[i]=0; 
		parent[i]=i; 
		dist[i]=INT_MAX;
	}

	cout<<"Enter the source : "; 
	int s;
	cin>>s;

	cout<<"Enter the destination : "; 
	int d;
	cin>>d; 

	astar(s,d,v,visited,parent,heu,dist,n);
	int cur=d; 
	cout<<endl;

	cout<<"Path from Vertex "<<s<<"to Vertex "<<d<<"is "<<endl; 
	stack<int> path;
 
	do
	{
		path.push(cur); 
		cur=parent[cur];
	}
	while(cur!=0);
	path.push(s); 
	while(!path.empty())
	{
		cout<<path.top()<<"\t"; 
		path.pop();
	}
	cout << endl; 
	return 0;
}
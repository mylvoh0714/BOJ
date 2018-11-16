#include <bits/stdc++.h>
using namespace std;

// math //------------------------------------------------------

int gcd(int p, int q) {
	if ( q == 0 ) return p;
	return gcd(q, p % q);
}

int calc(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b%2 == 1) {
            ans *= a;
        }
        a = a * a;
        b /= 2;
    }
    return ans;
 }

// mergesort // -------------------------------------------------
void MergeSort(int arr[], int temp[], int left, int right)
{
	int mid = ( left + right ) / 2;
	if ( left < right )
	{
		MergeSort(arr, temp, left, mid);
		MergeSort(arr, temp, mid + 1, right);
		Merge(arr, temp, left, mid, right);
	}
}

void Merge(int arr[], int temp[], int left, int mid, int right)
{

	int i, j, k, l;
	i = left; j = mid + 1, k = right;

	while ( i <= mid && j <= right )
	{
		if ( arr[i] <= arr[j] )
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while ( i <= mid )
		temp[k++] = arr[i++];
	while ( j <= right )
		temp[k++] = arr[j++];

	for ( l = left; l <= right; l++ )
		arr[l] = temp[l];
}
// 2473 lower_bound() practice
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<long long> a(n);
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	sort(a.begin(), a.end());

	long long min = 3000000000;
	vector<long long> ans;
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			auto idx = lower_bound(a.begin(), a.end(), -a[i] - a[j]) - a.begin();
			for ( int k = idx - 2; k <= idx + 2; k++ )
			{
				if ( k < 0 || k >= n ) continue; // out of index
				if ( k == i || k == j ) continue; // duplicate

				if ( min > abs(a[i] + a[j] + a[k]) ) {
					min = abs(a[i] + a[j] + a[k]);
					if ( !ans.empty() ) ans.clear();
					
					ans.push_back(a[i]);
					ans.push_back(a[j]);
					ans.push_back(a[k]);
				}
			}
		}
	}
	for ( long long &i : ans ) cout << i << ' ';
}

// 2293 Coin change Problem // -----------------------------------

// dp[] = 0 1 2 3 4 5 6 7 8 9 10
//  1     1 1 1 1 1 1 1 1 1 1 1
//  2     1 1 2 2 3 3 4 4 5 5 6 
//  5     1 1 2 2 3 4 5 6 7 8 10
int N, K;
int coin[101];
int dp[10001];

int main()
{
	scanf("%d %d", &N, &K);
	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d", &coin[i]); // 1,2,5 입력
	}
	dp[0] = 1;
	
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= K; j++ )
		{
			if ( j >= coin[i] ) dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d", dp[K]);
}

// 2352 LIS O(n^2) // -----------------------------------
int a[40001];
int dp[40001];

int main()
{
	int n; scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
	
	int ans = 0;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j < i; j++ )
		{
			if ( a[j] < a[i] ) {
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	ans += 1;
	printf("%d\n", ans);
}

// 2352 LIS O(nlogn) // -----------------------------------
int a[40001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	vector<int> lis;
	lis.push_back(a[0]);
	int ans = 1;

	for ( int i = 1; i < n; i++ )
	{
		auto itr = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if ( itr == lis.size() ) lis.push_back(a[i]);
		else lis[itr] = a[i];
	}
	cout << lis.size() << '\n';
	
}

// 11049 Matrix Multiplication // -----------------------------------
int dp[501][501]; // minimum operating count.

struct matrix {
	int row;
	int col;
};
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<matrix> arr(n + 1);
	for ( int i = 1; i <= n; i++ )
		cin >> arr[i].row >> arr[i].col;

	int i = 1;
	for ( int len = 1; len <= n-1; len++ ) 
	{
		for ( i=1; i <= n - len; i++ )
		{
			int j = i + len;
			dp[i][j] = 0x7fffffff;
			for ( int k = i; k < j; k++ )
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i].row*arr[k].col*arr[j].col);
			}
		}
	}
	cout << dp[1][n] << '\n';
}

// Union-Find //------------------------------------------------------
int p[300001];

struct Edge {
    int src;
    int des;
    int w;
};

int Find(int x) {
	if ( x == p[x] ) {
		return x;
	}
	else {
		return p[x] = Find(p[x]);
	}
}
 void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

// 1916 Dijkstra //------------------------------------------------------
int visited[1001];
int dist[1001];
const int INF = 1024 * 1024 * 1024;
int main()
{
	int n; cin >> n;
	int m; cin >> m;
	vector<pair<int,int>> adj[1001];
	for ( int i = 0; i < m; i++ )
	{
		int src, des, cost;
		cin >> src >> des >> cost;
		adj[src].push_back({ cost,des });
	}
	for ( int i = 1; i <= 1000; i++ )
	{
		dist[i] = INF;
	}
	int s, e;
	cin >> s >> e;
	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
	pq.push({ 0,s });
	dist[s] = 0;
	while ( !pq.empty() )
	{
		int here = pq.top().second;
		pq.pop();
		if ( visited[here] ) continue;
		visited[here] = 1;
		for ( int i = 0; i < adj[here].size(); i++ )
		{
			int there = adj[here][i].second;
			int there_c = adj[here][i].first;
			if ( dist[there] > dist[here] + there_c ) {
				dist[there] = dist[here] + there_c;
				pq.push({ -dist[there],there });
			}
		}
	}
	cout << dist[e] << '\n';
}

// 2252 Topological Sort //------------------------------------------------

vector<int> vec[32001];
queue<int> q;
int indegree[32001]; // array that stores topological info
int n, m;
int a, b;

int main()
{
	scanf("%d %d", &n, &m);
	for ( int i = 0; i < m; i++ )
	{
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		indegree[b]++;
	}
	for ( int i = 1; i <= n; i++ )
	{
		if ( indegree[i] == 0 ) q.push(i);
	}

	for ( int i = 0; i < n; i++ )
	{
		int here = q.front();
		q.pop();
		printf("%d ", here);
		for ( int j = 0; j < vec[here].size(); j++ )
		{
			int there = vec[here][j];
			indegree[there]--;
			if ( indegree[there] == 0 ) q.push(there);
		}
	}
	printf("\n");
	return 0;
}

// 11403 Floyd //----------------------------------------------
for ( int k = 1; k <= n; k++ ) {
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( dp[i][k] && dp[k][j] )
				dp[i][j] = 1;
		}
	}
}


// 11437 LCA //------------------------------------------------
bool visited[50001];
int depth[50001];
int parent[50001];

int LCA(int lowlevel, int highlevel)
{
	// setting for highlevel = (more depth level)
	if ( depth[lowlevel] > depth[highlevel] ) {
		int temp = highlevel;
		highlevel = lowlevel;
		lowlevel = temp;
	}

	while ( depth[lowlevel] != depth[highlevel] )
	{
		highlevel = parent[highlevel];
	}

	while ( lowlevel != highlevel )
	{
		lowlevel = parent[lowlevel];
		highlevel = parent[highlevel];
	}

	return highlevel;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for ( int i = 0; i < n - 1; i++ )
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> q;
	parent[1] = 0;
	depth[1] = 0;
	visited[1] = true;
	q.push(1);

	while ( !q.empty() )
	{
		int here = q.front();
		q.pop();
		for ( int i = 0; i < adj[here].size(); i++ )
		{
			int there = adj[here][i];
			if ( !visited[there] ) {
				parent[there] = here;
				depth[there] = depth[here] + 1;
				visited[there] = true;
				q.push(there);
			}
		}
	}
	int m;
	cin >> m;
	for ( int i = 0; i < m; i++ )
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}

// 2042 Fenwick-Tree // ------------------------------------------------
long long sum(vector<long long> &tree, int i) {
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(vector<long long> &tree, int i, long long diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int main() {
    int n, m, k;
    scanf("%d %d %d",&n,&m,&k);
    vector<long long> a(n+1);
    vector<long long> tree(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%lld",&a[i]);
        update(tree, i, a[i]);
    }
    m += k;
    while (m--) { // number of query
        int t1;
        scanf("%d",&t1);
        if (t1 == 1) {
            int t2;
            long long t3;
            scanf("%d %lld",&t2,&t3);
            long long diff = t3-a[t2];
            a[t2] = t3;
            update(tree, t2, diff);
        } else {
            int t2,t3;
            scanf("%d %d",&t2,&t3);
            printf("%lld\n",sum(tree, t3) - sum(tree, t2-1)); // sum of [t2,t3]
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define ll     long long
#define endl   "\n"
#define MOD    1e9+7
#define deb(x) cout<<#x<<"="<<x<<endl

#define f  first
#define s  second
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef deque<int>  di;
typedef stack<int>  si;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef pair<int, int> 		 pi;
typedef tuple<int, int, int> ti;

void printVector(vector<int> &value){ for(auto temp:value){ cout<<temp<<" "; } cout<<"\n";}

// #define ENABLE_DEBUG

int LCS(string a, string b, int m, int n)
{
	int dp[m+1][n+1];

	for(int i=0; i<=n; i++)
		dp[i][0]=0;

	for(int i=0; i<=m; i++)
		dp[0][i]=0;

	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(a[i]==b[j])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[m][n];
}

int solve(string a, string b)
{
	int m=a.length(), n=b.length();

	int lengthLCS=LCS(a, b, m, n);

	return m+n-lengthLCS;
}

int main() 
{
	#ifdef ENABLE_DEBUG
		freopen("input.txt" , "r", stdin );
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	// cin>>t;

	while(t--)
	{
		cout<<"Result: \n";
		// string a="geek", b="eke";  //geeke	5
		string a="AGGTAB", b="GXTXAYB";  //AGGXTXAYB	9

	    cout<<solve(a, b)<<endl;
	}
	
	return 0;
}
#include <bits/stdc++.h>

class DisjointSet
{
  int* parent;
  int* rank;
public:
  DisjointSet(int n)
  {
    parent = new int[n];
    rank = new int[n];
    for (int x = 0; x < n; x++)
    {
      parent[x] = x;
      rank[x] = 0;
    }
  }
  int find(int item)
  {
    if (parent[item] == item)
    {
      return item;
    }
    else
    {
      return find(parent[item]);
    }
  }
  void join(int a,int b)
  {
    int i = find(a);
    int j = find(b);
    if (i == j) return;
    if (rank[i] > rank[j])
    {
      parent[j] = i;
    }
    else if (rank[j] > rank[i])
    {
      parent[i] = j;
    }
    else
    {
      parent[i] = j;
      rank[j]++;
    }
  }
};

int main()
{
  int n, q, a, b;
  char op[2];
  scanf("%d%d",&n,&q);
  DisjointSet d(n);
  while (q--) {
    scanf("%2s%d%d",op, &a,&b);
    if (op[0] == '=') d.join(a, b);
    else if (d.find(a) == d.find(b)) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}

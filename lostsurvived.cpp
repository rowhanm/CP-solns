#include <iostream>
#include <cstdio>
#include <algorithm>
typedef unsigned int ui;

class DisjointSet
{
  ui* parent;
  ui* rank;

public:
  ui* size;
  DisjointSet(ui n)
  {
    parent = new ui[n];
    rank = new ui[n];
    size = new ui[n];
    for (ui x = 0; x < n; x++)
    {
      parent[x] = x;
      rank[x] = 0;
      size[x] = 1;
    }
  }
  ui find(int item)
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
  void join(ui a,ui b)
  {
    a = find(a);
    b = find(b);
    if (rank[a] > rank[b])
    {
      parent[b] = a;
      size[a] = size[a] + size[b];
      size[b] = size[a];
    }
    else if (rank[b] > rank[a])
    {
      parent[a] = b;
      size[b] = size[b] + size[a];
      size[a] = size[b];
    }
    else
    {
      parent[a] = b;
      size[b] = size[b] + size[a];
      size[a] = size[b];
      rank[b]++;
    }
  }
};

int main()
{
  ui n, q, a, b;
  scanf("%u%u",&n,&q);
  DisjointSet d(n);
  while (q--) {
    scanf("%u%u", &a,&b);
    d.join(--a,--b);
    printf("%u\n",*std::max_element(d.size, d.size + n) - *std::min_element(d.size, d.size + n)); 
  }
  return 0;
}
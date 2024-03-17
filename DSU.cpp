vector<int> group;
vector<int> depth;

void create(int u) {
  group[u] = u;
}

int label(int u) {
  if (group[u] == u)
    return u;

  int aux = label(group[u]);
  group[u] = aux;

  return aux;
}

void merge(int u, int v) {
  int lu = label(u), lv = label(v);

  if (lu == lv)
    return;

  if (depth[lu] < depth[lv])
    swap(lu, lv);

  group[lv] = lu;

  if (depth[lu] == depth[lv])
    depth[lu]++;
}

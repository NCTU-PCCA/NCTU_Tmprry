struct DisjointSet{
    int n, fa[MAXN];

      void init(int size) {
            for (int i = 0; i <= size; i++) {
                    fa[i] = i;
                        }
              }

        void find(int x) {
              return fa[x] == x ? x : find(fa[x]);
                }

          void unite(int x, int y) {
                p[find(x)] = find(y);
                  }

} djs;

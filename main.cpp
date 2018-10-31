#include <iostream>
#include <vector>

unsigned long max = 10;

std::vector< std::vector< int > > a(max), b(max);
std::vector< int > way(max), best_way(max);
std::vector< bool > n_new(max);
int best_cost;
int n;

void solve(int v, int count, int cost) {
    if (cost > best_cost) return;
    if (count == n) {
        cost = cost + a[v][0];
        way[n] = v;

        if (cost < best_cost) {
            best_cost = cost;
            best_way = way;
        }
        return;
    }
    n_new[v] = false;
    way[count]=v;
    for (int i = 0; i < n; i++){
        if (n_new[b[v][i]])
            solve(b[v][i], count + 1, cost+a[v][b[v][i]]);
        n_new[v] = true;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    for (int i = 0; i < max; i++){
        a[i].resize(max);
        b[i].resize(max);
    }
    solve(1, 1, 0);

    return 0;
}
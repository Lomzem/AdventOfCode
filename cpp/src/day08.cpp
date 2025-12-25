#include "day08.hpp"
#include <algorithm>
#include <charconv>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace day08 {

class DSU {
  std::vector<int> par;
  std::vector<int> size;

public:
  DSU(const int n) : par(n + 1), size(n + 1, 1) {
    for (int i = 0; i <= n; i++) {
      par[i] = i;
    }
  }

  int size_of(const int node) const { return size[node]; }

  int find(int node) {
    while (node != par[node]) {
      par[node] = par[par[node]];
      node = par[node];
    }
    return node;
  }

  bool unionSets(const int node1, const int node2) {
    int par_1 = find(node1);
    int par_2 = find(node2);
    if (par_1 == par_2)
      return false;
    if (size[par_1] > size[par_2]) {
      par[par_2] = par_1;
      size[par_1] += size[par_2];
    } else {
      par[par_1] = par_2;
      size[par_2] += size[par_1];
    }
    return true;
  }
};

class Coord {
  size_t x;
  size_t y;
  size_t z;

public:
  Coord(size_t x, size_t y, size_t z) : x(x), y(y), z(z) {}

  static Coord from(const std::string &line) {
    size_t x;
    size_t y;
    size_t z;
    auto comma1_pos = line.find(',');
    auto comma2_pos = line.find(',', comma1_pos + 1);
    std::from_chars(line.data(), line.data() + comma1_pos, x);
    std::from_chars(line.data() + comma1_pos + 1, line.data() + comma2_pos, y);
    std::from_chars(line.data() + comma2_pos + 1, line.data() + line.size(), z);
    return Coord{x, y, z};
  }

  size_t dist2(const Coord &other) const {
    int64_t dx = this->x - other.x;
    int64_t dy = this->y - other.y;
    int64_t dz = this->z - other.z;
    return (dx * dx) + (dy * dy) + (dz * dz);
  }
};

struct Edge {
  size_t dist;
  int c1_idx;
  int c2_idx;
  bool operator<(const Edge &other) const { return this->dist < other.dist; }
};

int part1(const std::vector<std::string> &lines, const int pairs) {
  DSU dsu(lines.size());

  std::vector<Coord> coords;
  coords.reserve(lines.size());
  for (const auto &line : lines) {
    coords.push_back(Coord::from(line));
  }

  std::vector<Edge> edges;
  for (int i = 0; i < coords.size(); i++) {
    for (int j = i + 1; j < coords.size(); j++) {
      size_t dist = coords[i].dist2(coords[j]);
      edges.push_back({dist, i, j});
    }
  }

  std::sort(edges.begin(), edges.end());
  for (int i = 0; i < pairs; i++) {
    Edge cur_edge = edges[i];
    dsu.unionSets(cur_edge.c1_idx, cur_edge.c2_idx);
  }

  int res = 1;

  std::vector<bool> visited(coords.size(), false);
  std::vector<int> parent_sizes;

  for (int i = 0; i < coords.size(); i++) {
    int coord_par = dsu.find(i);
    if (visited[coord_par])
      continue;
    visited[coord_par] = true;
    parent_sizes.push_back(dsu.size_of(coord_par));
  }
  std::sort(parent_sizes.rbegin(), parent_sizes.rend());

  for (int i = 0; i < std::min(3UL, parent_sizes.size()); i++) {
    res *= parent_sizes[i];
  }

  return res;
}
int part2(const std::vector<std::string> &lines);
} // namespace day08

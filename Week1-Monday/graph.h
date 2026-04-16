#ifndef GRAPH_H
#define GRAPH_H

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <set>
#include <map>


template <class T>
struct edge
{
  T a, b;
  
  edge() {}
  
  edge(const T & a, const T & b): a(a), b(b)
  {}
};

template <class T = int,
          class VS = std::set<T>,
          class ES = std::set<edge<T> > >
class graph
{

public:

  typedef T vertex;
  typedef VS vertexSet;
  typedef ES edgeSet;


  graph()
  {

  }

  std::size_t n() const
  {
    return _t.size();  // number of vertices is size of _t
  }

  std::size_t m() const
  {
    std::size_t ans(0);

    for (auto p: _t)
      ans += p.second.size();

    return ans/2;
  }

  vertexSet V() const
  {
    vertexSet ans;

    for (auto p: _t)
      ans.insert(p.first);

    return ans;
  }

  edgeSet E() const
  {
    edgeSet ans;
    for (auto p: _t)
    {
      auto v = p.first;
      for (auto w: p.second)
        if (v < w)
              ans.insert(edge<T>(v, w));
    }
    return ans;
  }

  bool isVertex(const T & v) const
  {
    return (_t.count(v) != 0);
  }

  bool isEdge(const T & v, const T & w) const
  {
    return (isVertex(v) && isVertex(w) && _t.at(v).count(w) == 1);
  }

  vertexSet Adj(const T & v) const
  {
    assert(isVertex(v));
    return _t.at(v);
  }

  std::size_t deg(const T & v) const
  {
    assert(isVertex(v));
    return _t.at(v).size();
  }
    

  void addVertex(const T & v)
  {
    if (isVertex(v))
      return;

    _t[v] = vertexSet();

  }

  void addEdge(const T & v, const T & w)
  {
    assert(isVertex(v) && isVertex(w));
    _t[v].insert(w);
    _t[w].insert(v);
  }

  void removeEdge(const T & v, const T & w)
  {
    if (!isEdge(v, w))
      return;

    _t[v].erase(w);
    _t[w].erase(v);
  }

protected:

  std::map<vertex, vertexSet> _t;

};


template <class T>
std::ostream & operator <<(std::ostream & os, const graph<T> & G)
{
  os << G.n() << " " << G.m() << std::endl;
  for (auto v: G.V())
    os << v << " ";
  os << std::endl;

  for (auto v: G.V())
    for (auto w: G.Adj(v))
      if (v < w)
        os << v << " " << w << std::endl;
  return os;
}


template <class T>
std::istream &  operator >>(std::istream & is, graph<T> & G)
{
  std::size_t n, m;
  is >> n >> m;

  G = graph<T>();

  T v, w;
  for (std::size_t i = 0; i < n; ++i)
    {
      is >> v;
      G.addVertex(v);
    }

  for (std::size_t i = 0; i < m; ++i)
    {
      is >> v >> w;
      G.addEdge(v, w);
    }

  return is;
}


template <class T>
bool operator <(const edge<T> &e1,
                const edge<T> &e2)
{

  return ((e1.a < e2.a) || ((e1.a == e2.a) && (e1.b < e2.b)));
}

template <class T>
std::ostream & operator << (std::ostream & os, const edge<T> & e)
{
  os << "{" << e.a << ", " << e.b << "}";
  return os;
}


#endif // GRAPH_H
#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include <boost/config.hpp>
#include <boost/tokenizer.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>

static void die(const char *reason) {
  fprintf(stderr, "%s\n", reason);
  exit(1);
}

template <typename DistanceMap>
class bacon_number_recorder : public boost::default_bfs_visitor {
  DistanceMap d;
 public:
  bacon_number_recorder(DistanceMap dist) : d(dist) {}

  template <typename Edge, typename Graph>
  void tree_edge(Edge e, const Graph & g) const {
    typename boost::graph_traits<Graph>::vertex_descriptor
      u = boost::source(e, g), v = boost::target(e, g);
    d[v] = d[u] + 1;
  }
};

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  boost::property<boost::vertex_name_t, std::string>,
  boost::property<boost::edge_name_t, std::string>> Graph;

typedef boost::property_map<Graph, boost::vertex_name_t>::type actor_name_map_t;
typedef boost::property_map<Graph, boost::edge_name_t>::type movie_name_map_t;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef std::map<std::string, Vertex> NameVertexMap;

template <typename DistanceMap>
bacon_number_recorder<DistanceMap> rec_num(DistanceMap d) {
  return bacon_number_recorder<DistanceMap>(d);
}

int main(int argc, char *argv[]) {
  std::ifstream datafile(argc >= 2 ? argv[1] : "./kevin-bacon.dat");
  if(!datafile) die("No datafile given.");

  Graph g;
  actor_name_map_t actor_name = boost::get(boost::vertex_name, g);
  movie_name_map_t connecting_movie = boost::get(boost::edge_name, g);

  NameVertexMap actors;

  for(std::string line; std::getline(datafile, line); ) {
    boost::char_delimiters_separator<char> sep(false, "", ";");
    boost::tokenizer<> line_toks(line, sep);
    boost::tokenizer<>::iterator i = line_toks.begin();
    std::string actors_name = *i++;

    NameVertexMap::iterator pos;
    bool inserted;
    Vertex u, v;

    boost::tie(pos, inserted) = actors.insert(std::make_pair(actors_name, Vertex()));
    if(inserted) {
      u = boost::add_vertex(g);
      actor_name[u] = actors_name;
      pos->second = u;
    } else u = pos->second;

    std::string movie_name = *i++;

    boost::tie(pos, inserted) = actors.insert(std::make_pair(*i, Vertex()));
    if(inserted) {
      v = boost::add_vertex(g);
      actor_name[v] = *i;
      pos->second = v;
    } else v = pos->second;

    boost::graph_traits<Graph>::edge_descriptor e;
    boost::tie(e, inserted) = boost::add_edge(u, v, g);

    if(inserted) connecting_movie[e] = movie_name;
  }

  std::vector<int> bacon_number(boost::num_vertices(g));

  Vertex src = actors["Kevin Bacon"];
  bacon_number[src] = 0;

  boost::breadth_first_search(g, src, boost::visitor(rec_num(&bacon_number[0])));

  boost::graph_traits<Graph>::vertex_iterator i, end;
  for(boost::tie(i, end) = boost::vertices(g); i != end; ++i) {
    std::cout << actor_name[*i] << " has a Bacon number of " <<
      bacon_number[*i] << std::endl;
  }

  return EXIT_SUCCESS;
}

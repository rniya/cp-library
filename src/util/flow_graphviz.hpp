#pragma once
#include <fstream>
#include "atcoder/maxflow"
#include "atcoder/mincostflow"

namespace atcoder {

template <class Cap> void dump_graphviz(mf_graph<Cap> graph, std::string filename = "maxflow") {
    std::ofstream ofs(filename + ".dot");
    ofs << "digraph {\n";
    auto edges = graph.edges();
    for (const auto& e : edges) {
        ofs << e.from << " -> " << e.to << " [label = \"" << e.flow << "/" << e.cap << "\", color = "
            << (e.flow == e.cap ? "red"
                : e.flow > 0    ? "blue"
                                : "black")
            << "];\n";
    }
    ofs << "}\n";
    ofs.close();
    return;
}

template <class Cap, class Cost> void dump_graphviz(mcf_graph<Cap, Cost> graph, std::string filename = "mincostflow") {
    std::ofstream ofs(filename + ".dot");
    ofs << "digraph {\n";
    auto edges = graph.edges();
    for (const auto& e : edges) {
        ofs << e.from << " -> " << e.to << " [label = \"" << e.flow << "/" << e.cap << "(" << e.flow << "*" << e.cost
            << ")"
            << "\", color = "
            << (e.flow == e.cap ? "red"
                : e.flow > 0    ? "blue"
                                : "black")
            << "];\n";
    }
    ofs << "}\n";
    ofs.close();
    return;
}

}  // namespace atcoder

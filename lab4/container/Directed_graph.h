#pragma once
#include "Flex_list.h"
#include "Edge_sequence.h"
#include "Vertex.h"
#include "Adjacent_forward_iterator.h"

template<typename T, typename VertexContainer = Flex_list<Vertex<T>>>
class Directed_graph {
public:
    using value_type = T;
    using vertex_type = Vertex<T>;
    using vertex_id = typename vertex_type::id_type;

    using vertex_iterator = typename VertexContainer::iterator;
    using const_vertex_iterator = typename VertexContainer::const_iterator;
    using vertex_reverse_iterator = typename VertexContainer::reverse_iterator;
    using vertex_const_reverse_iterator = typename VertexContainer::const_reverse_iterator;

    using edge_type = std::pair<vertex_id, vertex_id>;
    using edge_container = Edge_sequence<vertex_id>;
    using edge_iterator = typename edge_container::iterator;
    using const_edge_iterator = typename edge_container::const_iterator;
    using edge_reverse_iterator = typename edge_container::reverse_iterator;
    using edge_const_reverse_iterator = typename edge_container::const_reverse_iterator;

    using adjacent_iterator = Adjacent_forward_iterator<vertex_id, std::unordered_set<vertex_id>>;

private:
    VertexContainer vertices_;
    edge_container  edges_;
    std::unordered_map<vertex_id, std::unordered_set<vertex_id>> adj_out_;
    std::unordered_map<vertex_id, std::unordered_set<vertex_id>> adj_in_;
    vertex_id next_id_{0};

public:
    Directed_graph() = default;

    Directed_graph(const Directed_graph& other)
        : vertices_(other.vertices_), edges_(other.edges_),
          adj_out_(other.adj_out_), adj_in_(other.adj_in_),
          next_id_(other.next_id_) {}

    Directed_graph& operator=(Directed_graph other) noexcept {
        swap(other);
        return *this;
    }

    void swap(Directed_graph& other) noexcept {
        vertices_.swap(other.vertices_);
        std::swap(edges_, other.edges_);
        std::swap(adj_out_, other.adj_out_);
        std::swap(adj_in_, other.adj_in_);
        std::swap(next_id_, other.next_id_);
    }

    bool empty() const noexcept { 
        return vertices_.empty(); 
    }
    vertex_iterator find_vertex_iter(vertex_id id) {
        for (auto it = vertices_.begin(); it != vertices_.end(); ++it)
            if (it->id == id) 
                return it;
    }

    const_vertex_iterator find_vertex_iter(vertex_id id) const {
        for (auto it = vertices_.cbegin(); it != vertices_.cend(); ++it)
            if (it->id == id) return it;
        return vertices_.cend();
    }
    void clear() {
        vertices_.clear();
        adj_out_.clear();
        adj_in_.clear();
        while (!edges_.empty()) 
            edges_.erase(edges_.begin());
        next_id_ = 0;
    }

    bool has_vertex(vertex_id id) const {
        return adj_out_.find(id) != adj_out_.end();
    }

    bool has_edge(vertex_id u, vertex_id v) const {
        auto it = adj_out_.find(u);
        const auto& s = it->second;
        return s.find(v) != s.end();
    }

    std::size_t vertex_count() const noexcept { 
        return adj_out_.size(); 
    }
    std::size_t edge_count()   const noexcept {
         return edges_.size(); 
        }

    std::size_t out_degree(vertex_id v) const {
        auto it = adj_out_.find(v);
        return it->second.size();
    }
    std::size_t in_degree(vertex_id v) const {
        auto it = adj_in_.find(v);
        return it->second.size();
    }
    std::size_t degree(vertex_id v) const {
        return in_degree(v) + out_degree(v);
    }

    std::size_t edge_degree(edge_type e) const {
        vertex_id u = e.first, v = e.second;
        if (!has_vertex(u) || !has_vertex(v) || !has_edge(u,v))
            throw std::out_of_range("edge_degree: edge not found");
        std::size_t deg_u = out_degree(u) + in_degree(u);
        std::size_t deg_v = out_degree(v) + in_degree(v);
        return (deg_u + deg_v) - 1;
    }

    vertex_id add_vertex(const T& value) {
        vertex_id id = next_id_++;
        vertices_.push_back(Vertex<T>{id, value});
        adj_out_.emplace(id, std::unordered_set<vertex_id>{});
        adj_in_.emplace(id, std::unordered_set<vertex_id>{});
        return id;
    }

    void add_edge(vertex_id u, vertex_id v) {
        adj_out_[u].insert(v);
        adj_in_[v].insert(u);
        edges_.insert({u,v});
    }

    void remove_edge(vertex_id u, vertex_id v) {
        if (!has_edge(u,v))
            throw std::out_of_range("remove_edge: edge not found");
        adj_out_[u].erase(v);
        adj_in_[v].erase(u);
        auto it = edges_.find({u,v});
        if (it != edges_.end()) 
            edges_.erase(it);
    }

    void remove_vertex(vertex_id id) {
        if (!has_vertex(id))
            throw std::out_of_range("remove_vertex: vertex not found");
        edges_.erase_all_incident(id);

        adj_out_.erase(id);
        adj_in_.erase(id);

        auto itv = find_vertex_iter(id);
        if (itv == vertices_.end())
            throw std::logic_error("internal: vertex in map but not in container");
        vertices_.erase(itv);
    }

    vertex_iterator begin_vertices() noexcept { 
        return vertices_.begin(); 
    }
    vertex_iterator end_vertices()   noexcept { 
        return vertices_.end(); 
    }
    const_vertex_iterator begin_vertices() const noexcept { 
        return vertices_.begin(); 
    }
    const_vertex_iterator end_vertices()   const noexcept { 
        return vertices_.end(); 
    }
    vertex_reverse_iterator rbegin_vertices() noexcept { 
        return vertices_.rbegin(); 
    }
    vertex_reverse_iterator rend_vertices() noexcept { 
        return vertices_.rend(); 
    }
    vertex_const_reverse_iterator rbegin_vertices() const noexcept { 
        return vertices_.rbegin(); 
    }
    vertex_const_reverse_iterator rend_vertices()   const noexcept { 
        return vertices_.rend(); 
    }

    edge_iterator begin_edges() noexcept { 
        return edges_.begin(); 
    }
    edge_iterator end_edges()   noexcept {
        return edges_.end(); 
    }
    const_edge_iterator begin_edges() const noexcept {
        return edges_.begin();
    }
    const_edge_iterator end_edges()   const noexcept {
        return edges_.end();
    }
    edge_reverse_iterator rbegin_edges() noexcept {
        return edges_.rbegin(); 
    }
    edge_reverse_iterator rend_edges()   noexcept {
        return edges_.rend(); 
    }
    edge_const_reverse_iterator rbegin_edges() const noexcept { 
        return edges_.rbegin(); 
    }
    edge_const_reverse_iterator rend_edges()  const noexcept { 
        return edges_.rend();
    }

    std::vector<edge_type> incident_edges(vertex_id v) const {
        if (!has_vertex(v)) throw std::out_of_range("incident_edges: vertex not found");
        std::vector<edge_type> inc;
        inc.reserve(adj_out_.at(v).size() + adj_in_.at(v).size());
        for (auto w : adj_out_.at(v)) 
            inc.emplace_back(v, w);
        for (auto u : adj_in_.at(v))  
            inc.emplace_back(u, v);
        return inc;
    }

    adjacent_iterator adjacent_begin(vertex_id v) const {
        auto it = adj_out_.find(v);
        if (it == adj_out_.end()) 
            throw std::out_of_range("adjacent_begin: vertex not found");
        return adjacent_iterator(it->second.begin());
    }
    adjacent_iterator adjacent_end(vertex_id v) const {
        auto it = adj_out_.find(v);
        if (it == adj_out_.end())
            throw std::out_of_range("adjacent_end: vertex not found");
        return adjacent_iterator(it->second.end());
    }

    void erase_vertex(vertex_iterator vit) {
        if (vit == vertices_.end()) 
            throw std::out_of_range("erase_vertex: end()");
        remove_vertex(vit->id);
    }

    void erase_edge(const_edge_iterator eit) {
        if (eit == end_edges()) 
            throw std::out_of_range("erase_edge: end()");
        remove_edge(eit->first, eit->second);
    }
};
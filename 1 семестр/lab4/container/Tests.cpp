#include "Directed_graph.h"
#include "UnitTest++/UnitTest++.h"
#include <string>

SUITE(FlexListTests) {
    TEST(DefaultConstructorCreatesEmptyList) {
        Flex_list<int> lst;
        CHECK(lst.empty());
        CHECK_EQUAL(0, lst.size());
    }

    TEST(PushBackAndFront) {
        Flex_list<int> lst;
        lst.push_back(10);
        lst.push_front(5);
        CHECK_EQUAL(2, lst.size());
        CHECK_EQUAL(5, lst.front());
        CHECK_EQUAL(10, lst.back());
    }

    TEST(InsertAndErase) {
        Flex_list<int> lst;
        lst.push_back(1);
        lst.push_back(3);
        auto it = lst.begin();
        ++it; 
        CHECK_EQUAL(2, lst.size());

        int expected[] = {1,3};
        int i=0;
        for(auto v : lst) {
            CHECK_EQUAL(expected[i], v);
            ++i;
        }

        it = lst.begin(); ++it;
        lst.erase(it);
        CHECK_EQUAL(1, lst.size());
    }

    TEST(ComparisonOperators) {
        Flex_list<int> a;
        a.push_back(1); a.push_back(2);

        Flex_list<int> b = a;
        CHECK(a == b);

        b.push_back(3);
        CHECK(a != b);
        CHECK(a < b);
    }
}

SUITE(DirectedGraphTests) {
    TEST(AddVerticesAndEdges) {
        Directed_graph<std::string> g;
        auto a = g.add_vertex("A");
        auto b = g.add_vertex("B");

        g.add_edge(a,b);

        CHECK(g.has_vertex(a));
        CHECK(g.has_vertex(b));
        CHECK(g.has_edge(a,b));
        CHECK_EQUAL(2, g.vertex_count());
        CHECK_EQUAL(1, g.edge_count());
    }

    TEST(DegreeCalculations) {
        Directed_graph<std::string> g;
        auto a = g.add_vertex("A");
        auto b = g.add_vertex("B");
        auto c = g.add_vertex("C");

        g.add_edge(a,b);
        g.add_edge(a,c);
        g.add_edge(b,c);

        CHECK_EQUAL(2, g.out_degree(a));
        CHECK_EQUAL(2, g.in_degree(c));
        CHECK_EQUAL(2, g.degree(a));
    }

    TEST(RemoveVertexAndEdge) {
        Directed_graph<std::string> g;
        auto a = g.add_vertex("A");
        auto b = g.add_vertex("B");

        g.add_edge(a,b);
        CHECK_EQUAL(1, g.edge_count());

        g.remove_edge(a,b);
        CHECK(!g.has_edge(a,b));
        CHECK_EQUAL(0, g.edge_count());

        g.remove_vertex(a);
        CHECK(!g.has_vertex(a));
        CHECK_EQUAL(1, g.vertex_count());
    }

    TEST(AdjacentIterator) {
        Directed_graph<std::string> g;
        auto a = g.add_vertex("A");
        auto b = g.add_vertex("B");
        auto c = g.add_vertex("C");

        g.add_edge(a,b);
        g.add_edge(a,c);

        std::vector<Directed_graph<std::string>::vertex_id> adj;
        for(auto it = g.adjacent_begin(a); it != g.adjacent_end(a); ++it) {
            adj.push_back(*it);
        }
        CHECK_EQUAL(2, adj.size());
        CHECK(std::find(adj.begin(), adj.end(), b) != adj.end());
        CHECK(std::find(adj.begin(), adj.end(), c) != adj.end());
    }
}
int main(){
    return UnitTest::RunAllTests();
}
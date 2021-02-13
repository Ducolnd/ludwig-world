// #pragma once

// #include <vector>
// #include <cmath>
// #include <list>

// #include "helper/math/math.hpp"

// struct Node;

// struct Node {
//     vec2 coordinate; // Relative location in grid
//     Node *parent;

//     uint32_t gcost = 0; // Distance from start
//     uint32_t hcost = 0; // Distance from end

//     bool traversable;

//     uint32_t index;

//     Node(vec2 s, bool trav);
//     uint32_t fcost() { return gcost + hcost; }
//     bool operator == (const Node &node); 
// };

// class Grid {
//     public:
//         std::vector<std::vector<Node>> grid; // Passable or not

//         Grid(std::vector<std::vector<Node>> _grid);
//         std::vector<Node> getNeightbours(Node &node);
// };

// bool xinlist(std::list<Node> list, Node node);
// void astar(vec2 start, vec2 end, Grid &grid);
// uint32_t getDistance(Node &nodeA, Node &nodeB);
// #include "helper/includes.hpp"

// #include "pathfinding.hpp"


// Node::Node(vec2 s, bool trav) : coordinate(s) {
//     parent = Node();
//     traversable = trav;
// }

// bool Node::operator == (const Node &node) {
//     return (coordinate.x == node.coordinate.x && coordinate.y == node.coordinate.y) {
// }

// Grid::Grid(std::vector<std::vector<Node>> _grid) {
//     grid = _grid;
    
// }

// std::vector<Node> Grid::getNeightbours(Node &node) {
//     std::vector<Node> neightbours;

//     for (int x = -1; x <=1; x++) {
//         for (int y = -1; y <=1; y++) {
//             if (x == 0 && y== 0) {continue;}

//             uint32_t neigx = node.coordinate.y + y;
//             uint32_t neigy = node.coordinate.x + x;

//             if (neigx >= 0 && neigx < grid.size() && neigy >= 0 && neigy < grid[0].size()) {
//                 neightbours.push_back(grid[neigx][neigy]);
//             }
//         }  
//     }
//     return neightbours;
// }

// bool xinlist(std::list<Node> list, Node node) {
//     for (const Node &n : list) {
//         if (node == n) {return true;}
//     }
//     return false;
// }



// void astar(vec2 start, vec2 end, Grid &grid) {
//     std::list<Node> open;
//     std::list<Node> closed;

//     Node startnode = Node(start, true);
//     Node targetnode(end, true);

//     open.push_back(startnode);

//     while (open.size() > 0) {
//         Node &current_node = startnode;

//         for (Node &n : open) {
//             if (n.fcost() < current_node.fcost() || n.fcost() == current_node.fcost() && n.hcost < current_node.hcost) {
//                 current_node = n;
//             }
//         }

//         open.remove(current_node);
//         closed.push_back(current_node);

//         if (current_node == targetnode) {
//             return;
//         }

//         for (Node &neighbour : grid.getNeightbours(current_node)) {
//             if (!neighbour.traversable || xinlist(closed, neighbour)) {
//                 continue;
//             }

//             uint32_t newMovementCost = current_node.gcost + getDistance(current_node, neighbour);

//             if (newMovementCost < neighbour.gcost || !xinlist(open, neighbour)) {
//                 neighbour.gcost = newMovementCost;
//                 neighbour.hcost = getDistance(neighbour, targetnode);
//                 neighbour.parent = current_node;
//             }
//         }
//     }
// }

// uint32_t getDistance(Node &nodeA, Node &nodeB) {
//     uint32_t distX = abs(nodeA.coordinate.x - nodeB.coordinate.x);
//     uint32_t distY = abs(nodeA.coordinate.y - nodeB.coordinate.y);

//     if (distX > distY) {
//         return 14 * distY + 10 * (distX - distY);
//     }
//     return 10 * distY + 14 * (distX - distY);
// }
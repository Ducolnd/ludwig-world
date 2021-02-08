// #include <entt/entt.hpp>
// #include <SFML/Graphics.hpp>
// #include <iostream>

// #include "pathfindingSystem.hpp"

// #include "components/ai/pathfindingComponent.hpp"
// #include "components/ai/pathComponent.hpp"
// #include "components/movement/locationComponent.hpp"

// void pathfindingSystem(entt::registry &registry, World &world) {
//     auto view = registry.view<pathComponent, pathfindingComponent, locationComponent>();

//     for (auto& ent : view) {
//         auto& path = registry.get<pathComponent>(ent).path;
//         auto& location = registry.get<locationComponent>(ent).vec;
//         auto& target = registry.get<locationComponent>(registry.get<pathfindingComponent>(ent).target);

//         Chunk& in_chunk = world.getChunk(location.x / world.chunkwidth, location.y / world.chunkwidth);
//     }
// }
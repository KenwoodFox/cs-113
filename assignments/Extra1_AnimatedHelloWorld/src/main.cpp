/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <iostream>

// # Includes for our own headers
#include "loader.h"

// Graphics
std::vector<glm::vec3> cur_vertices; // Every vertice were drawing on the screen now
std::vector<glm::vec2> cur_uvs;
std::vector<glm::vec3> cur_normals;

int main()
{
    std::cout << loadOBJ("../3d/Cube.obj", cur_vertices, cur_uvs, cur_normals);

    // std::cout << glm::to_string(cur_vertices) << std::endl;

    printf(MOTD); // Print build info
    return 0;
}

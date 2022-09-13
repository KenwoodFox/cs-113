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
    std::cout << loadOBJ("../3d/SmallTestShape.obj", cur_vertices, cur_uvs, cur_normals) << std::endl;

    for (uint8_t i = 0; i < 6; i++)
    {
        std::cout << cur_vertices[i].x << std::endl;
        std::cout << cur_vertices[i].y << std::endl;
        std::cout << cur_vertices[i].z << std::endl;
        std::cout << std::endl;
    }

    printf(MOTD); // Print build info
    return 0;
}

/* Methods and tools
 * for file i/o
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <glm/glm.hpp>

bool loadOBJ(
    const char *path,
    std::vector<glm::vec3> &out_verts,
    std::vector<glm::vec2> &out_uvs,
    std::vector<glm::vec3> &out_normals)
{
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return false;
    }

    // Great resource http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/
    while (1)
    {

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader

        // Verts
        if (strcmp(lineHeader, "v") == 0)
        {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            out_verts.push_back(vertex);
        }
        else if (strcmp(lineHeader, "vt") == 0)
        {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            out_uvs.push_back(uv);
        }

        // Normals
        else if (strcmp(lineHeader, "vn") == 0)
        {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            out_normals.push_back(normal);
        }

        // Special and messy
        else if (strcmp(lineHeader, "f") == 0)
        {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
            if (matches != 9)
            {
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                return false;
            }
            // vertexIndices.push_back(vertexIndex[0]);
            // vertexIndices.push_back(vertexIndex[1]);
            // vertexIndices.push_back(vertexIndex[2]);
            // uvIndices.push_back(uvIndex[0]);
            // uvIndices.push_back(uvIndex[1]);
            // uvIndices.push_back(uvIndex[2]);
            // normalIndices.push_back(normalIndex[0]);
            // normalIndices.push_back(normalIndex[1]);
            // normalIndices.push_back(normalIndex[2]);
        }
    }
}

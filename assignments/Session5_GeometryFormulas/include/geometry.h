#include <cmath>

/* Calculates the volume of a sphere
 *
 * @param r The radius of a sphere.
 * @return The volume of a sphere.
 */
double sphere_volume(double r)
{
    return (4.0 / 3.0) * M_PI * pow(r, 3);
}

/* Calculates the volume of a cylinder
 *
 * @param r The radius of a cylinder.
 * @param h The height of a cylinder.
 * @return The volume of a cylinder.
 */
double cylinder_volume(double r, double h)
{
    return M_PI * pow(r, 2) * h;
}

/* Calculates the volume of a cone
 *
 * @param r The radius of a cone.
 * @param h The height of a cone.
 * @return The volume of a cone.
 */
double cone_volume(double r, double h)
{
    return M_PI * pow(r, 2) * (h / 3.0);
}

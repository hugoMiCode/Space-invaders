#include "Path.h"
#include "Engine.h"


Path::Path(std::string path)
{
    last = sf::Vector2i();
    pathS = path;
    endTab = false;
    ligne = 0;

    std::ifstream fichier{ "Trajectoires/" + path + ".tkt" };
    std::string line{ "" };

    int t{ 0 };
    int x{ 0 };
    int y { 0 };

    while (std::getline(fichier, line)) {
        fichier >> t >> x >> y;

        coord.push_back(sf::Vector3i(x, y, t));
    }
}

sf::Vector2f Path::path(float t, float angle)
{
    if (pathS == "fire" || pathS == "Fire" || pathS == "FIRE")
        return fireShipEnemy(t, angle);
    else
        return sf::Vector2f(0.f, 0.f);
}

sf::Vector3f Path::path(float t, sf::Vector2f pos, float k)
{
    sf::Vector2f coordUpdate(pathEnemy(t));
    return sf::Vector3f(coordUpdate.x - pos.x / 2, coordUpdate.y - pos.y / 2, endTab);
}

sf::Vector2f Path::fireShipEnemy(float t, float angle)
{
    return sf::Vector2f(sin(angle * 3.1415f / 180.0f) * t, cos(angle * 3.1415f / 180.f) * t );
}

sf::Vector2i Path::pathEnemy(float t)
{
    for (unsigned int i{ 0 }; i < coord.size(); i++)
        if (coord[i].z >= t * 1000) {
            last = sf::Vector2i{ coord[i].x, coord[i].y };
            endTab = false;
            return last;
        }

    endTab = true;
    return last;
}
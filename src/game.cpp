#include "game.hpp"

using namespace std;

float getDistanceBetween(sf::Vector2f point1, sf::Vector2f point2) {
    return sqrt(((point1.x - point2.x) * (point1.x - point2.x)) + ((point1.y - point2.y) * (point1.y - point2.y)));
}

bool onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
  
    return false;
}

int orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
  
    if (val == 0) return 0;
  
    return (val > 0)? 1: 2;
}

bool doIntersect(sf::Vector2f p1, sf::Vector2f q1, sf::Vector2f p2, sf::Vector2f q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  
    return false;
}

sf::Vector2f lineLineIntersection(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, sf::Vector2f D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.y - A.y;
    double b1 = A.x - B.x;
    double c1 = a1*(A.x) + b1*(A.y);
 
    // Line CD represented as a2x + b2y = c2
    double a2 = D.y - C.y;
    double b2 = C.x - D.x;
    double c2 = a2*(C.x)+ b2*(C.y);
 
    double determinant = a1*b2 - a2*b1;
 
    if (determinant == 0)
    {
        return sf::Vector2f(-1,-1);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return sf::Vector2f(x, y);
    }
}

Game::Game(sf::RenderWindow &win) {
    window = &win;
    
    Line* l1 = new Line(sf::Vector2f(500.f, 0.f), sf::Vector2f(500.f, 1000.f));
    lines.push_back(l1);

    l1 = new Line(sf::Vector2f(0.f, 500.f), sf::Vector2f(1000.f, 500.f));

    lines.push_back(l1);

    l1 = new Line(sf::Vector2f(250.f, 500.f), sf::Vector2f(500.f, 250.f));

    lines.push_back(l1);
}

void calculateCollision(sf::RectangleShape line, sf::Vector2f &position, sf::Vector2f &velocity) {
    
}


void Game::run() {
    int cnt = 0;
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            // update event based components
            player.updateWithEvent(event);
        }
        sf::Vector2f shit = player.getNewPosition();
        handleCollision();

        // update component velocity
        player.update();

        // handle collisions and movable objects
        // for (sf::RectangleShape *rect : lines) {
        //     window->draw(*rect);
        // }
        

        window->clear();
        // draw window
        player.draw(window);

        for (Line *line : lines) {
            line->draw(window);
        }

        
        window->display();
    }
}

void Game::handleCollision() {
    sf::Vector2f current_position = player.getPosition();
    sf::Vector2f new_position = player.getNewPosition();
    sf::Vector2f closest_point = new_position;
    if (player.getVelocity().x > 0) {
        new_position.x = new_position.x + PLAYER_SIZE_X;
    } 
    if (player.getVelocity().y > 0) {
        new_position.y = new_position.y + PLAYER_SIZE_Y;
    }
    for (Line *line : lines) {
        if (doIntersect(new_position, current_position, line->start, line->end)) {
            cout<<"yes"<<endl;
            sf::Vector2f collision_point = lineLineIntersection(new_position, current_position, line->start, line->end);
            cout<<"point: " << collision_point.x << " " << collision_point.y << endl;
            if (getDistanceBetween(current_position, closest_point) > getDistanceBetween(current_position, collision_point)) {
                closest_point = collision_point;
            }
        }
    }
}

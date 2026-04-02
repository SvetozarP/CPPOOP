#include "Snake.h"
#include <algorithm>

Snake::Snake(const int fieldRows,
    const int fieldCols,
    const Point& startPos) :
    _FIELD_ROWS(fieldRows),
    _FIELD_COLS(fieldCols),
    _currPos(startPos)
{
    _snakeNodes.push_back(startPos);
}

Snake::~Snake() {
}

std::deque<Point>& Snake::getSnakeNodes() {
    return _snakeNodes;
}

StatusCode Snake::move(const Direction dir,
    const std::vector<Point>& obstacles,
    std::vector<Point>& powerUps)
{
    Point newHeadPos = _snakeNodes.front();

    switch (dir) {
    case Direction::UP:
        newHeadPos.row--;
        break;
    case Direction::RIGHT:
        newHeadPos.col++;
        break;
    case Direction::DOWN:
        newHeadPos.row++;
        break;
    case Direction::LEFT:
        newHeadPos.col--;
        break;
    }

    if (newHeadPos.row < 0 || newHeadPos.row >= _FIELD_ROWS ||
        newHeadPos.col < 0 || newHeadPos.col >= _FIELD_COLS) {
        return StatusCode::SNAKE_DEAD;
    }

    for (const Point& obstacle : obstacles) {
        if (newHeadPos == obstacle) {
            return StatusCode::SNAKE_DEAD;
        }
    }

	for (size_t i = 1; i < _snakeNodes.size(); ++i) { // Check if the new head position collides with the snake's body (starting from index 1 to skip the current head)
        if (newHeadPos == _snakeNodes[i]) {
            return StatusCode::SNAKE_DEAD;
        }
    }


    auto powerUpIt = std::find(powerUps.begin(), powerUps.end(), newHeadPos);
    if (powerUpIt != powerUps.end()) {
        _snakeNodes.push_front(newHeadPos);
        powerUps.erase(powerUpIt);
        return StatusCode::SNAKE_GROWING;
    }

    _snakeNodes.push_front(newHeadPos);
    _snakeNodes.pop_back();
    return StatusCode::SNAKE_MOVING;
}
#include "object.h"
#include "game.h"

Object::Object() {} // TODO
Object::~Object() {}

Object::Object(int width, int height, bool collidable) {
    // Initializing all the attributes. We set x = y = 0 for the moment,
    // subject to change depending on whether or not we want it
    // as an argument in the constructor
    width_ = width;
    height_ = height;
    collidable_ = collidable;
    position_ = Position();
    position_.x = 0;
    position_.y = 0;
}

int Object::GetWidth() {
    return width_;
}

int Object::GetHeight() {
    return height_;
}

int Object::GetObjId() {
    return obj_id;
}

bool Object::IsCollidable() {
    return collidable_;
}

Position Object::GetPosition() {
    return position_;
}

Object Object::Copy() {
    Object new_object(width_, height_, collidable_);
    return new_object;
}

void Object::InteractButton() {
    if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_E]) {
        // Have the object be affected, not sure how to do this
    }
}

bool Object::InteractCollision(Character character) {
    // Checks if the object is collidable and if the character is currently colliding with it.

    // We haven't yet done the position and width/height attributed for the character class,
    // hence I set them as true for the moment
    bool width_condition = true;  // position_.x < character.position_.x + character.rect_w && character.position_.x < position_.x + width_
    bool height_condition = true; // position_.y < character.position_.y + character.rect_h && character.position_.y < position_.y + height_
    bool x_collision = false;
    bool y_collision = false;
    if (collidable_) {
        if (height_condition) {
            y_collision = true;
        } else if (width_condition) {
            x_collision = true;
        }
    }
    // Might want to prevent the character from moving if there is a collision.
    return (x_collision || y_collision);
}

Portal::Portal(int width, int height, int map_id) {
    width_ = width;
    height_ = height;
    map_id_ = map_id;
    collidable_ = false;
}

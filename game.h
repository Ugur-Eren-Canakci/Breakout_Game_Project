#pragma once

#ifndef GAME_H
#define GAME_H

#include <memory>
#include <typeinfo>
#include <vector>
#include <map>

#include "constants.h"
#include "paddle.h"
#include "ball.h"
#include "background.h"
#include "brick.h"
#include "brick_placements.h"

using namespace std::literals;

// Use aliases to simplify the code
using entity_vector = std::vector<std::unique_ptr<entity>>;
using entity_alias_vector = std::vector<entity*>;

class entity_manager {
private:
    entity_vector all_entities;
    std::map<size_t, entity_alias_vector> grouped_entities;
public:
    template <typename T, typename... Args>
    T& create(Args&&... args) {
        // assert type in compile-time to be of entity
        static_assert(std::is_base_of<entity, T>::value,
            R"("T" type parameter in create() must be derived from "entity")");
        
        // Create a unique_ptr to the entity
        // Forward the arguments to the entity's constructor
        auto ptr{ std::make_unique<T>(std::forward<Args>(args)...) };

        // Make an alias pointer to the allocated memory
        // This will be stored in the entity_type_vector
        auto ptr_alias = ptr.get();

        // prepare hash code for grouped_entities
        auto hash_code = typeid(T).hash_code();

        // place the ptr_alias into the hash code's vector
        grouped_entities[hash_code].emplace_back(ptr_alias);

        // insert the unique_ptr into all_entities
        all_entities.emplace_back(std::move(ptr));

        // return the object
        return *ptr_alias;
    }

    // Function to scan all entities and clean up the destroyed ones
    void refresh();

    // Function to destroy all entities
    void clear();

    // Function to retrieve all the objects of a given type
    template <typename T>
    auto& get_all() {
        return grouped_entities[typeid(T).hash_code()];
    }

    // Apply a function to all entities of a given type
    template <typename T, typename Func>
    void apply_all(const Func& func) {
        auto& entity_group{ get_all<T>() };

        for (auto ptr : entity_group)
            func(*dynamic_cast<T*>(ptr));
    }

    // Function to update all the entities
    void update();

    // Function to make all the entities draw themselves
    void draw(sf::RenderWindow& window);
};

class game {
private:
    enum class game_state { paused, running};

    game_state state{game_state::running};
	
    sf::RenderWindow game_window{ 
        sf::VideoMode({ constants::window_width,
                        constants::window_height
        }),
        "Breakout_Not_A_Game_Yet"s 
    };
    // will manage every object of type entity
    entity_manager manager; 
    
public:

    game();
    void run(); 
    void reset();
};

#endif
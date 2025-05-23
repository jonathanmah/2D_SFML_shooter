#include <iostream>
#include <cmath>
#include "entities/Character.h"
#include "weapons/Projectile.h"
#include "core/GameState.h"

static int projectile_count = 0;
static constexpr float COLLATERAL_REDUCTION_FACTOR = 0.8f;
/*
    Construct a projectile
    
    AnimData animData : given the animation data (static animation right now)
    sf::Vector2f position : starting position of the projectile in pixels
    sf::Vector2f velocity : velocity of the projectile, will move at this rate every frame update
    int damage : amount of damage the projectiles does when collides
*/

Projectile::Projectile(ProjectileData projectileData, sf::Vector2f sourcePosition, sf::Vector2f normalized)
: sprite(*projectileData.anim.texture), animData(projectileData.anim), velocity(projectileData.speed*normalized), damage(projectileData.damage), 
collateralCount(projectileData.collateralCount), scale(projectileData.scale), acceleration(projectileData.acceleration),
lifetime(projectileData.lifetime), createsBlood(true), sourcePosition(sourcePosition){
    sprite.setTextureRect(sf::IntRect(projectileData.anim.textureFrame.position, projectileData.anim.textureFrame.size));
    sprite.setPosition({sourcePosition.x, sourcePosition.y});
    sprite.setScale({scale, scale});
    sprite.setOrigin({sprite.getLocalBounds().size.x / 2, sprite.getLocalBounds().size.y / 2});
    Rotate(velocity);
    projectile_count++;
}

bool Projectile::HasHit(int characterId) {
    if (hitCharacters.find(characterId) != hitCharacters.end()) {
        return true;
    }
    return false;
}

// logic to update when a projectile collides, also any extra collision effects can be done here
void Projectile::UpdateProjectileStatus(Character& character, GameState& state, std::vector<std::unique_ptr<Projectile>>::iterator& it) {
    if(GetCollateralCount() > 1) {
        if(HasHit(character.id)){
            ++it;
            return;
        }
        DecrementCollateralCount();
        SetDamage(GetDamage()*COLLATERAL_REDUCTION_FACTOR);
        hitCharacters.insert(character.id);
        ++it;
    } else {
        //#TODO need to somehow tell rocket animation to explode when this happens here for RPG
        it = state.projectiles.erase(it);
    }
    projectile_count++;
}


// rotate facing direction of gun muzzle
void Projectile::Rotate(sf::Vector2f velocity) {
    // get angle of velocity in radians with arc tangent
    float radians = atan2(velocity.y,velocity.x);
    sf::Angle angle = sf::radians(radians);
    sprite.setRotation(angle);
}
/*
#TODO only sets position and rotation for now.  Will need to pass deltatime to add animation to a projectile later

Update the projectile position and rotation based on its velocity

*/
void Projectile::UpdatePosition(float deltaTime) {
    sprite.setPosition(GetPosition() + velocity);
    Rotate(velocity);
}

void Projectile::UpdateAnimation(float deltaTime) {
    AnimUtil::UpdateSpriteAnim(sprite, animData, deltaTime);
}

// Update the position of every projectile
void Projectile::UpdateProjectiles(GameState& state, float deltaTime) {
    for (auto it = state.projectiles.begin(); it != state.projectiles.end();) {
        if ((*it)->lifetime < 0.f) {
            it = state.projectiles.erase(it);
        } else {
            (*it)->UpdatePosition(deltaTime);
            (*it)->UpdateAnimation(deltaTime);
            (*it)->lifetime -= deltaTime;
            if((*it)->ReachedDest()){
                (*it)->ActivatePostTargetReached(state, it);
                    
            } else{
                ++it;
            }
            
        }
    }
}

// render a projectile
void Projectile::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    HitboxDebugger::DrawSpriteGlobalBoundsHitbox(window, sprite);
}

// render all projectiles
void Projectile::RenderProjectiles(GameState& state, bool drawHitbox) {    
    state.batchRenderer->BatchRenderSprites(state.projectiles);
    if(drawHitbox) {
        for(auto& projectile : state.projectiles) {
            HitboxDebugger::DrawSpriteGlobalBoundsHitbox(state.window, projectile->sprite);
        }
    }
}
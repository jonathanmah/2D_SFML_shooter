#pragma once
#include "weapons/Weapon.h"

class BatchRenderer;

class Uzi : public Weapon {

private:
    void RotateBaseToMouseGlobal() override;

public:

sf::Sprite spriteSecond;
sf::Vector2f relativeSecond; // relative vector from weapon origin to global mouse pos
sf::Vector2f muzzlePositionSecond; // Position of the weapon muzzle
sf::Vector2f spriteSecondOffset;
sf::Vector2f muzzleSecondOffset;

    Uzi();
    
    void CreateProjectile(Player& player, std::vector<std::unique_ptr<Projectile>>& projectiles) override;
    void UpgradeWeapon() override;
    void Update(GameState& state, Player& player, sf::Vector2f mousePosGlobal, float deltaTime) override;
    void Draw(sf::RenderWindow& window, BatchRenderer& BatchRenderer) override;
    void UpdateBase(sf::Vector2f characterPosition, float deltaTime) override;
    void UpdateBaseTransformations(sf::Vector2f characterPosition, float deltaTime) override;
    void SetMuzzlePosition() override;
    void AttemptShoot(Player& player, std::vector<std::unique_ptr<Projectile>>& projectiles, float deltaTime) override;
    void AddMuzzleFlashEffect() override;
    void CreateShell() override;
    void UpdateMuzzleFlashes(float deltaTime) override;
    // creat shell and muzzle flash overrides too...
};
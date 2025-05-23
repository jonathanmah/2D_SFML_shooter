#pragma once
#include "weapons/Weapon.h"

class Barrett50 : public Weapon {

public:
    Barrett50();
    void CreateProjectile(Player& player, std::vector<std::unique_ptr<Projectile>>& projectiles) override;
    void UpgradeWeapon() override;
};

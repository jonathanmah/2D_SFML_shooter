#include "weapons/derived/Ak47.h"
#include <iostream>

static const ProjectileData ak47BulletReg = {
    AnimUtil::ProjectileAnim::medBulletReg,
    20.f, // speed
    1.f, // damage 
    1.f, // bullet scale
    1, // collateral count
};

static const ProjectileData ak47BulletUpgrade = {
    AnimUtil::ProjectileAnim::redLaser,
    40.f, // speed
    250.f, // damage 
    .2f, // bullet scale
    4, // collateral count
};

Ak47::Ak47() : 
Weapon(AnimUtil::WeaponAnim::ak47, 
        ak47BulletReg, 
        {
            1.f, //scale 
            0.f, // baseOffsetX
            24.f, // baseOffsetY
            0.f, // x offset from muzzle
            -2.8f, // y offset from muzzle (pre recoil translation)
            48.f, // muzzleOffsetscalar
            0.15f, // fireRate
            .15f, // time since last bullet fired
            0.f, // current accumulated spread offset
            .12f, // spread offset max
            .01f, //  spread offset growth
            .015f, // spread offset decay
            .0f, // time left until gun returns back to original position after recoil
            .15f, // total time gun takes to return back
            5.f, // amount of offset, vector created using this scalar opposite point direction
            5.f, // shell offset x
            -5.f, // shell offset y
        }
    )
{
    sprite.setOrigin({sprite.getLocalBounds().size.x / 3, sprite.getLocalBounds().size.y / 2});
}

void Ak47::CreateProjectile(Player& player, std::vector<std::unique_ptr<Projectile>>& projectiles) {
    sf::Vector2f adjustedNormal = (GetTargetWithSpread(mousePosGlobal) - GetPosition()).normalized();
    projectiles.emplace_back(std::make_unique<Projectile>(projectileData, muzzlePosition, adjustedNormal));
}

void Ak47::UpgradeWeapon() {
    sprite.setTextureRect(AnimUtil::WeaponAnim::ak47Upgraded);
    projectileData = ak47BulletUpgrade;
    weaponData.spreadDeviationMax = 0.f;
    isUpgraded = true;
}
#pragma once

#include <SFML/Graphics.hpp>


class Blood;

struct AnimData {
    sf::Texture* texture = nullptr;
    sf::IntRect textureFrame; // a rect obj, position and size of a frame in texture
    int frameSpacing = 0;
    int currFrame = 0;
    int totalFrames = 1;
    float animSpeed = 0.1f;
    float deltaTimeSum = 0.f;
    int rowLength = 100;
    int yFrameSpacing = 0;
    bool hangLastFrame = false;
    int initCurrFrame = 0;
};

struct SubRectData {
    std::vector<sf::IntRect> frameSequence;
    float animSpeed = 0.1f;
    bool repeat = false;
    bool hide = true;
    int currFrame = 0;
    float deltaTimeSum = 0.f;
};

class AnimUtil {

public:
    static sf::Texture* playerTexture;
    static sf::Texture* dungeonTexture;
    static sf::Texture* bloodTexture;
    static sf::Texture* weaponsTexture;
    static sf::Texture* projectilesTexture;
    static sf::Texture* explosionTexture;
    static sf::Texture* explosionUpgradedTexture;
    static sf::Texture* nukeTexture;
    static sf::Texture* statusEffectsTexture;
    static sf::Texture* onFireTexture;
    static sf::Texture* onFireUpgradedTexture;
    static sf::Texture* energyExplosionTexture;
    static sf::Texture* lowMonsterTexture;
    static sf::Texture* wolfTexture;
    static sf::Texture* scytheDemonTexture;
    static sf::Texture* mageDemonTexture;
    static sf::Texture* spiderDemonTexture;
    static sf::Texture* bossDemonTexture;

    static void LoadTextures();
    // update a sequence horizontal
    static bool UpdateSpriteAnim(sf::Sprite& sprite, AnimData& animData, float deltaTime);
    // update a consistent sequence on a 2D sheet
    static bool UpdateSpriteXYAnim(sf::Sprite& sprite, AnimData& animData, float deltaTime);

    // update an offset sequence on 2Dsheet
    static bool UpdateSpriteXYOffsetAnim(sf::Sprite& sprite, AnimData& animData, float deltaTime);

    // animate a hardcoded sequence of subrects
    static bool UpdateSubRect(SubRectData& subRectData, float deltaTime);

    struct PlayerAnim {
        static const AnimData idle;
        static const AnimData walk;
        static const AnimData shootIdle;
        static const AnimData shootWalk;
        static const AnimData death;
        static const AnimData dance;
    };

    // MONSTERS


    struct ZombieAnim {
        static const AnimData walk;
        static const AnimData idle;
        static const AnimData attack;
        static const AnimData death;
    };
    struct WolfAnim {
        static const AnimData walk;
        static const AnimData idle;
        static const AnimData run;
        static const AnimData attack;
        static const AnimData death;
    };
    struct SmallDemonAnim {
        static const AnimData walk;
        static const AnimData idle;
        static const AnimData attack;
        static const AnimData death;
    };
    struct BigDemonAnim {
        static const AnimData walk;
        static const AnimData idle;
        static const AnimData attack;
        static const AnimData death;
    };





    struct BloodAnim {
        static const AnimData spray1;
        static const AnimData spray2;
        static const AnimData spray3;
        static const AnimData spray4;
        static const AnimData spray5;
        static const AnimData spray6;
        static const AnimData ground;
        static const AnimData leftFootprint;
        static const AnimData rightFootprint;
    };

      // WEAPONS

      struct WeaponAnim {
        static const AnimData ak47;
        static const sf::IntRect ak47Upgraded;
        static const AnimData famas;
        static const sf::IntRect famasUpgraded;
        static const AnimData barrett50;
        static const sf::IntRect barrett50Upgraded;
        static const AnimData rpg; // upgraded is loaded rect
        static const sf::IntRect rpgReloadRect;
        static const sf::IntRect rpgLoadedRect;
        static const sf::IntRect rpgUpgradedReloadRect;
        static const sf::IntRect rpgUpgradedLoadedRect;

        static const AnimData p90;
        static const sf::IntRect p90Upgraded;
        static const AnimData scarH;
        static const sf::IntRect scarHUpgraded;
        static const AnimData m4a1;
        static const sf::IntRect m4a1Upgraded;
        static const AnimData m1014;
        static const sf::IntRect m1014Upgraded;
        static const AnimData ump45;
        static const sf::IntRect ump45Upgraded;
        static const AnimData uzi;
        static const sf::IntRect uziUpgraded;
        static const AnimData flamethrower;
        static const sf::IntRect flamethrowerUpgraded;
        static const AnimData m32;
        static const sf::IntRect m32Upgraded;
        static const AnimData m240;
        static const sf::IntRect m240Upgraded;
        static const AnimData m9;
        static const sf::IntRect m9Upgraded;
        static const AnimData magnum;
        static const sf::IntRect magnumUpgraded;

        static const AnimData fragGrenade;
        static const AnimData stunGrenade;
        static const AnimData smokeGrenade;
    };

    struct WeaponFxAnim {
        static const AnimData muzzleFlash1;
        static const AnimData muzzleFlash2;
        static const AnimData muzzleFlash3;
        static const AnimData muzzleFlash4;
        static const AnimData muzzleFlash5;

        static const AnimData explosion;
        static const AnimData explosionUpgraded;
        static const AnimData energyExplosion;
        static const AnimData nuke;
        static const SubRectData rpgBackfire;
        static const SubRectData rpgSmoke;
    };

    struct StatusFxAnim {
        static const AnimData frozen;
        static const AnimData paralyze;
        static const AnimData onFire;
        static const AnimData onFireUpgraded;
    };

    struct ProjectileAnim {
        static const AnimData smallBulletReg;
        static const AnimData medBulletReg;
        static const AnimData barrett50BulletReg;
        static const AnimData barrett50BulletUpgrade;
        static const AnimData shotgunPelletReg;
        static const AnimData rpgRocketReg;
        static const AnimData rpgRocketUpgrade;
        static const AnimData m32GrenadeReg;
        static const AnimData m32GrenadeUpgrade;
        static const AnimData redLaser;
        static const AnimData yellowLaser;
        static const AnimData orangeLaser;
        static const AnimData purpleLaser;
        static const AnimData whiteLaser;
        static const AnimData smallRedLaser;
        static const AnimData famasFlameBullet;
        static const AnimData lightningBullet;
        static const AnimData iceBullet;
        static const AnimData atomBullet;
        static const AnimData waveBullet;
        static const AnimData electricBullet;

    };
};
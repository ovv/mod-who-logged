#include "who_logged.h"

std::string GetPlayerClassName(uint32 classId)
{
    switch (classId)
    {
        case CLASS_WARLOCK: return "Warlock";
        case CLASS_WARRIOR: return "Warrior";
        case CLASS_MAGE: return "Mage";
        case CLASS_SHAMAN: return "Shaman";
        case CLASS_DEATH_KNIGHT: return "Death Knight";
        case CLASS_DRUID: return "Druid";
        case CLASS_HUNTER: return "Hunter";
        case CLASS_PALADIN: return "Paladin";
        case CLASS_ROGUE: return "Rogue";
        case CLASS_PRIEST: return "Priest";
        default: return "Unknown Class";
    }
}

void LogConnectMessage(std::string action, std::string configKey, Player* player) {
    if (!sConfigMgr->GetOption<bool>(configKey, true))
        return;

    std::string playerIP = player->GetSession()->GetRemoteAddress();
    std::string playerName = player->GetName();
    uint32 playerAccountID = player->GetSession()->GetAccountId();
    uint32 playerLevel = player->GetLevel();
    std::string playerClass = GetPlayerClassName(player->getClass());

    LOG_INFO("module", "Player '{}' has {} : Level '{}' : Class '{}' : IP '{}' : AccountID '{}'", playerName.c_str(), action, std::to_string(playerLevel), playerClass.c_str(), playerIP.c_str(), playerAccountID);

}

void WhoLoggedAnnounce::OnPlayerLogin(Player* player)
{
    LogConnectMessage("logged in", "PlayerLoginAnnounce", player);
}

void WhoLoggedAnnounce::OnPlayerLogout(Player* player)
{
    LogConnectMessage("logged out", "PlayerLogoutAnnounce", player);
}

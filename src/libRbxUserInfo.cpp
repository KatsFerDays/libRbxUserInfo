#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include "libRbxUserInfo.hpp"

namespace RbxUserInfo {
    using json = nlohmann::json;

    User MakeUser(json userInfoParse, json onlineStatParse) {
        User out;
        out.username = userInfoParse.at("name");
        out.displayName = userInfoParse.at("displayName");
        out.creationDate = userInfoParse.at("created");
        out.description = userInfoParse.at("description");
        out.lastLocation = onlineStatParse.at("LastLocation");
        out.lastOnline = onlineStatParse.at("LastOnline");
        out.userID = userInfoParse.at("id");
        out.locationType = onlineStatParse.at("LocationType");
        out.gameID = onlineStatParse.at("GameId");
        out.placeID = onlineStatParse.at("PlaceId");
        out.presenceType = onlineStatParse.at("PresenceType");
        out.universeID = onlineStatParse.at("UniverseId");
        out.verified = userInfoParse.at("hasVerifiedBadge");
        out.banned = userInfoParse.at("isBanned");
        out.isOnline = onlineStatParse.at("IsOnline");
        return out;
    }

    User GetInfoByID(int userID) {
        cpr::Response userInfo = cpr::Get(cpr::Url{"https://users.roblox.com/v1/users/" + userID});
        cpr::Response onlineStat = cpr::Get(cpr::Url{"https://api.roblox.com/users/" + std::to_string(userID) + "/onlinestatus/"});
        if (userInfo.status_code != 200 || onlineStat.status_code != 200) {
            return *(new User);
        }
        json userInfoParse = json::parse(userInfo.text);
        json onlineStatParse = json::parse(onlineStat.text);

        return MakeUser(userInfoParse, onlineStatParse);
    }

    User GetInfoByUsername(std::string username) {
        cpr::Response nameToID = cpr::Get(cpr::Url{"https://api.roblox.com/users/get-by-username?username=" + username});
        json nameToIDParse = json::parse(nameToID.text);
        if (nameToIDParse.contains("success")) {
            if (!nameToIDParse["success"]) {return *(new User);}
        }
        return GetInfoByID(nameToIDParse.at("Id"));
    }
}
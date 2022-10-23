#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include "libRbxUserInfo.hpp"
#include <iostream>

namespace RbxUserInfo {
    using json = nlohmann::json;

    User MakeUser(json userInfoParse, json onlineStatParse) {
        User out;
        try {
            out.username = userInfoParse.at("name").get<std::string>();
            out.displayName = userInfoParse.at("displayName").get<std::string>();
            out.creationDate = userInfoParse.at("created").get<std::string>();
            out.description = userInfoParse.at("description").get<std::string>();
            out.lastLocation = onlineStatParse.at("LastLocation").get<std::string>();
            out.lastOnline = onlineStatParse.at("LastOnline").get<std::string>();
            out.userID = userInfoParse.at("id").get<int>();
            out.locationType = onlineStatParse.at("LocationType").get<int>();
            out.gameID = onlineStatParse.at("GameId").get<int>();
            out.placeID = onlineStatParse.at("PlaceId").get<int>();
            out.presenceType = onlineStatParse.at("PresenceType").get<int>();
            out.universeID = onlineStatParse.at("UniverseId").get<int>();
            out.verified = userInfoParse.at("hasVerifiedBadge").get<bool>();
            out.banned = userInfoParse.at("isBanned").get<bool>();
            out.isOnline = onlineStatParse.at("IsOnline").get<bool>();
        }
        catch(std::exception& e) {
            std::cerr << e.what();
            system("pause");
        return out;
    }

    User GetInfoByID(int userID) {
        cpr::Response userInfo = cpr::Get(cpr::Url{"https://users.roblox.com/v1/users/" + std::to_string(userID)});
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
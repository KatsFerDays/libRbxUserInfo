namespace RbxUserInfo {
    struct User {
        std::string username = "";
        std::string displayName = "";
        std::string creationDate = "";
        std::string description = "";
        std::string lastLocation = "";
        std::string lastOnline = "";
        int userID = -1;
        int locationType = -1;
        int placeID = -1;
        int presenceType = -1;
        int universeID = -1;
        bool verified = false;
        bool banned = false;
        bool isOnline = false;
    };

    User GetInfoByID(int userID);
    User GetInfoByUsername(std::string username);
}
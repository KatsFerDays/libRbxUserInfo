namespace RbxUserInfo {
    struct User {
        std::string username;
        std::string displayName;
        std::string creationDate;
        std::string description;
        std::string lastLocation;
        std::string lastOnline;
        int userID;
        int locationType;
        int placeID;
        int presenceType;
        int universeID;
        bool verified;
        bool banned;
        bool isOnline;
    };

    User GetInfoByID(int userID);
    User GetInfoByUsername(std::string username);
}
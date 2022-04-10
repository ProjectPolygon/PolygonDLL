#include "pch.h"
#include "Util.h"

const std::vector<std::string> Util::allowedHosts
{
    "polygon.pizzaboxer.xyz",
    "polygondev.pizzaboxer.xyz",
    "polygonapi.pizzaboxer.xyz",
    "clientsettingsapi.pizzaboxer.xyz",

    "roblox.com",
    "www.roblox.com",
    "assetdelivery.roblox.com",

    "tadah.rocks",
    "www.tadah.rocks",
    "api.tadah.rocks",
    "clientsettings.tadah.rocks",

    "calones.xyz",
    "www.calones.xyz",
    "cdn.calones.xyz"
};

const std::vector<std::string> Util::allowedSchemes
{
    "http",
    "https",
    "ftp"
};

const std::vector<std::string> Util::allowedEmbeddedSchemes
{
    "javascript",
    "jscript",
    "res"
};

// https://stackoverflow.com/questions/48212992/how-to-find-out-if-there-is-any-non-ascii-character-in-a-string-with-a-file-path
bool Util::isASCII(const std::string& s)
{
    return !std::any_of(s.begin(), s.end(), [](char c) {
        return static_cast<unsigned char>(c) > 127;
    });
}
#pragma once
#include <cstdio>
#include <map>
#include <string>

class Translations {
    std::map<std::string, std::string> mTexts;
public:
    void set(const std::string& key, std::string text) { mTexts[key] = std::move(text); }
    const std::string& get(const std::string& key) const { return mTexts.at(key); }
};

class Display {
public:
    void show(const std::string& text) { std::printf("Display: %s\n", text.c_str()); }
};

class Thermostat {
    Translations& mTranslations;
    Display mDisplay;
public:
    explicit Thermostat(Translations& translations) : mTranslations{translations} {}
    void render(double temperature);
};

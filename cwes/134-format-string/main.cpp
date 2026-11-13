#include LAB_VARIANT

int main(int argc, char* argv[]) {
    Translations translations;
    translations.set("temp", argc > 1 ? argv[1] : "Temperatur: %s °C");
    translations.set("temperature", argc > 1 ? argv[1] : "Temperatur: {:s} °C");
    Thermostat thermostat{translations};
    thermostat.render(21.5);
}

#ifndef SAFEPROGRESSYSTEM_H_INCLUDED
#define SAFEPROGRESSYSTEM_H_INCLUDED

class SaveSystem {
public:
    void Write(const Player& player) {
        PlayerSaveData data = player.GetSaveData();
        std::ofstream outFile("Progres.sav");

        if (outFile.is_open()) {
            outFile << data.hp_max << " "
                    << data.hp << " "
                    << data.repair << " "
                    << data.damage << " "
                    << data.exp << " "
                    << data.token << " "
                    << data.speed << " "
                    << data.attackSpeed << " "
                    << data.oldId << " "
                    << data.inventory.size() << " ";
            for(int i = 0; i < (int)data.inventory.size(); i++) {
                outFile << data.inventory[i] << " ";
            }
            for(int i=0; i < (int)priceupgrades.size(); i++) {
                outFile << priceupgrades[i] << " ";
            }
            for(int i=0; i < (int)priceitems.size(); i++) {
                outFile << priceitems[i] << " ";
            }
            for(int i=0; i < (int)ItemDB.size(); i++) {
                // Зберігаємо 1 або 0 замість bool для надійності
                outFile << (ItemDB[i].isbuy ? 1 : 0) << " ";
            }

            outFile << "\n" << data.name << "\n";

            outFile.close();
            setcurspos(65, 41);
            std::cout << "Game Saved Successfully!";
        }
    }

    void Read(Player& player) {
        std::ifstream inFile("Progres.sav");

        setcurspos(60, 40);
        if (!inFile.is_open()) {
            std::cout << "Файлу збереження немає. Створюємо новий...\n";
            Write(player);
            return;
        }
        if (inFile.peek() == std::ifstream::traits_type::eof()) {
            std::cout << "Файл збереження порожній. Створюємо новий...\n";
            inFile.close();
            Write(player);
            return;
        }

        PlayerSaveData data;

        if (inFile.is_open()) {
            inFile >> data.hp_max >> data.hp >> data.repair >> data.damage >> data.exp >> data.token >> data.speed >> data.attackSpeed
            >> data.oldId;

            int invSize;
            inFile >> invSize;

            data.inventory.resize(invSize);
            for(int i = 0; i < invSize; i++) {
                inFile >> data.inventory[i];
            }

            for(int i=0; i < (int)priceupgrades.size(); i++) {
                inFile >> priceupgrades[i];
            }
            for(int i=0; i < (int)priceitems.size(); i++) {
                inFile >> priceitems[i];
            }
            for(int i=0; i < (int)ItemDB.size(); i++) {
                int isBuyInt;
                inFile >> isBuyInt;
                ItemDB[i].isbuy = (isBuyInt == 1);
            }

            inFile >> std::ws;
            std::getline(inFile, data.name);

            inFile.close();

            player.LoadSaveData(data);
            setcurspos(65, 41);
            std::cout << "Game Loaded Successfully!";
        }
    }
};

#endif // SAFEPROGRESSYSTEM_H_INCLUDED

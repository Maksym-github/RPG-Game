#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

enum ItemType { weapon, helmet, potion, granate};
struct Item{
    int id;
    std::string name;
    float value;
    ItemType type;
    bool isbuy;
};
std::vector<Item> ItemDB={
    {1, "Sword1", 5, weapon, false},
    {2, "Sword2", 10, weapon, false},
    {3, "Sword3", 20, weapon, false},
    {4, "Granate", 20, granate, false},
    {5, "HP recovery I", 5, potion, false}
};
Item& getItem(int id){
    for(int i=0;i<(int)ItemDB.size();i++){
        if(ItemDB[i].id == id)
            return ItemDB[i];
    }
    return ItemDB[0];
}

#endif // ITEM_H_INCLUDED

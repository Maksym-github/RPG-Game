#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

struct Item{
    int id;
    std::string name;
    int damage;
};
std::vector<Item> ItemDB={
    {1, "Sword1", 5},
    {2, "Sword2", 10},
    {3, "Sword3", 20}
};
Item getItem(int id){
    for(int i=0;i<ItemDB.size();i++){
        if(ItemDB[i].id == id)
            return ItemDB[i];
    }
}

#endif // ITEM_H_INCLUDED

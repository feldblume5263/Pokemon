#pragma once
#include <string>
#include <iostream>

enum ItemType
{
    HPRecovery_Item, MonsterBall_Item
};

class Item
{
protected:
    int item_type;
    int item_volume;
    std::string item_name;
    std::string item_description;


    int recovery_volume = 0.0f;
    float chatchProbility = 0.0f;

public:
    Item()
    {

    }

    Item(std::string _Item)
    {
        if (_Item == "HyperPotion")
            HyperPotion();
        if (_Item == "MaxPotion")
            MaxPotion();
        if (_Item == "HyperBall")
            HyperBall();
    }
    
    void setVolume(int _item_volume)
    {
        item_volume = _item_volume;
    }
    int getItemType()
    {
        return item_type;
    }
    int getItemVolume()
    {
        return item_volume;
    }
    std::string getItemName()
    {
        return item_name;
    }
    std::string getItemDesc()
    {
        return item_description;
    }
    int getIntrinsic()
    {
        return 0;
    }

    int getRecoveryVolume()
    {
        return recovery_volume;
    }
    int getCatchPro()
    {
        return chatchProbility;
    }
    void HyperPotion()
    {
        item_type = HPRecovery_Item;
        item_volume = 2;
        item_name = "HyperPotion";
        item_description = "Spray-type wound drug. Restores 200 HP of 1 Pokemon.";
        recovery_volume = 200;
    }

    void MaxPotion()
    {
        item_type = HPRecovery_Item;
        item_volume = 2;
        item_name = "MaxPotion";
        item_description = "Spray-type wound drug. Recover all HP of 1 Pokemon.";
        recovery_volume = 200;
    }
    void HyperBall()
    {
        item_type = MonsterBall_Item;
        item_volume = 2;
        item_name = "HyperBall";
        item_description = "A very high-performance ball that makes Pokemon easier to catch than a Super ball";
        chatchProbility = 99.0f;
    }
};

class HPRecoveryItem : public Item
{
private:
    int recovery_volume = 0.0f;

    void HyperPotion()
    {
        item_type = HPRecovery_Item;
        item_volume = 2;
        item_name = "HyperPotion";
        item_description = "Spray-type wound drug. Restores 200 HP of 1 Pokemon.";
        recovery_volume = 200;
    }

    void MaxPotion()
    {
        item_type = HPRecovery_Item;
        item_volume = 2;
        item_name = "MaxPotion";
        item_description = "Spray-type wound drug. Recover all HP of 1 Pokemon.";
        recovery_volume = 200;
    }

public:
    HPRecoveryItem(std::string _HPRecoveryItem)
    {
        if (_HPRecoveryItem == "HyperPotion")
            HyperPotion();
        if (_HPRecoveryItem == "MaxPotion")
            MaxPotion();
    }

    int getIntrinsic()
    {
        return recovery_volume;
    }
};

class MonsterBallItem : public Item
{
private:
    float chatchProbility = 0.0f;

    void HyperBall()
    {
        item_type = MonsterBall_Item;
        item_volume = 2;
        item_name = "HyperBall";
        item_description = "A very high-performance ball that makes Pokemon easier to catch than a Super ball";
        chatchProbility = 99.0f;
    }
public:
    MonsterBallItem(std::string _MonsterBallItem)
    {
        if (_MonsterBallItem == "HyperBall")
            HyperBall();
    }

    int getIntrinsic()
    {
        return chatchProbility;
    }

};
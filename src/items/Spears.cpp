#include <mc/src/common/world/item/registry/ItemRegistry.hpp>
#include <mc/src/common/world/item/ItemStack.hpp>

#include <amethyst/Log.hpp>

#include "Spears.hpp"

float SpeedDamageRatio;
class WoodenSpear : public Item {
public:
	WoodenSpear(const std::string& identifier, short numId)
		: Item(identifier, numId)
	{
		Log::Info("SpearItem created with id: {}", numId);
	}
	ItemStack& use(ItemStack& itemStack, Player& player) const override {
		float SpeedDamageRatio = 1.4f;
		const CompoundTag* tag = itemStack.mUserData;
		int CurrentItemHealth = Item::getDamageValue(tag);
		Log::Info("Old Health: {}", CurrentItemHealth);
		CurrentItemHealth--;
		Item::setDamageValue(itemStack, CurrentItemHealth);
		Log::Info("Spear Activated, Current Item Health: {}", CurrentItemHealth);
		return itemStack;
	}
};

void ModSpears::registerItems(RegisterItemsEvent& ev){
	auto& WoodenSpears = ev.itemRegistry.registerItemShared<WoodenSpear>("bs-Spears:Wooden_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-Spears:wooden_spear", 0)
		.setMaxStackSize(1);
}
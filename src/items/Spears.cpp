#include <mc/src/common/world/item/registry/ItemRegistry.hpp>
#include <mc/src/common/world/item/ItemStack.hpp>
#include <mc/src/common/world/actor/ActorDamageSource.hpp>
#include <mc/src/common/world/phys/Vec3.hpp>
#include <mc/src/common/world/actor/Mob.hpp>
#include <amethyst/Log.hpp>

#include "Spears.hpp"



float SpeedDamageRatio = 1.4f;
class WoodenSpear : public Item{
public:
	WoodenSpear(const std::string& identifier, short numId)
		: Item(identifier, numId)
	{
		Log::Info("SpearItem created with id: {}", numId);
		canBeCharged();
	}
	void hurtActor(ItemStack& stack, Actor& target, Mob& attacker) const override {
		float playerSpeed = attacker.getSpeed(); // incomplete type mob is not allowed # No compile error when adding Mob.hpp
		float newDamage = (playerSpeed / SpeedDamageRatio) + 2;
	}
	ItemStack& use(ItemStack& itemStack, Player& player) const override {
		const CompoundTag* tag = itemStack.mUserData;
		int CurrentItemHelth = Item::getDamageValue(tag);
		CurrentItemHelth++;
		Item::setDamageValue(itemStack, CurrentItemHelth);
		return itemStack;
	}
};

void ModSpears::registerItems(RegisterItemsEvent& ev){
	auto& WoodenSpears = ev.itemRegistry.registerItemShared<WoodenSpear>("bs-spears:Wooden_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-spears:wooden_spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(63);
}
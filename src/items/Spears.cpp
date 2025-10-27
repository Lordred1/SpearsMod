#include <mc/src/common/world/item/registry/ItemRegistry.hpp>
#include <mc/src/common/world/item/ItemStack.hpp>
#include <mc/src/common/world/actor/ActorDamageSource.hpp>
#include <mc/src/common/world/phys/Vec3.hpp>
#include <mc/src/common/world/actor/Mob.hpp>
#include <mc/src/common/world/entity/components/StateVectorComponent.hpp> //DELTA POS BABY
#include <amethyst/Log.hpp>

#include "Spears.hpp"



float SpeedDamageRatio = 1.4f;
float newDamage;
class WoodenSpear : public Item{
public:
	WoodenSpear(const std::string& identifier, short numId)
		: Item(identifier, numId)
	{
		Log::Info("Wooden Spear created with id: {}", numId);
		
	}
	virtual float getSpeed() const {
		return 13.0f;
	}
	void hurtActor(ItemStack& stack, Actor& target, Mob& attacker) const override {
		float playerSpeed = attacker.getSpeed();   // incomplete type mob is not allowed # No compile error when adding Mob.hpp
		Log::Info("Player speed: {}", playerSpeed);
		newDamage = (playerSpeed / SpeedDamageRatio) + 2;
		const CompoundTag* tag = stack.mUserData;
		int CurrentItemHelth = Item::getDamageValue(tag);
		CurrentItemHelth++;
		Item::setDamageValue(stack, CurrentItemHelth);
	}
	virtual int getAttackDamage() const override {
		Log::Info("Damage Being Done: {}", newDamage + 2);
		return (newDamage + 2);
	};
	ItemStack& use(ItemStack& itemStack, Player& player) const override {
		
		return itemStack;
	}
	
};

void ModSpears::registerItems(RegisterItemsEvent& ev){
	auto& WoodenSpears = ev.itemRegistry.registerItemShared<WoodenSpear>("bs-spears:Wooden_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-spears:wooden_spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(63);

}

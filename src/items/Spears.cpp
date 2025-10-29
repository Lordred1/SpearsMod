#include <mc/src/common/world/item/registry/ItemRegistry.hpp>
#include <mc/src/common/world/item/ItemStack.hpp>
#include <mc/src/common/world/actor/ActorDamageSource.hpp>
#include <mc/src/common/world/phys/Vec3.hpp>
#include <mc/src/common/world/actor/Mob.hpp>
#include <mc/src/common/world/entity/components/StateVectorComponent.hpp> //DELTA POS BABY
#include <amethyst/Log.hpp>

#include "Spears.hpp"



float SpeedDamageRatio = 1.4f;

float speed = 0.0f;

class WoodenSpear : public Item{
public:

	
	WoodenSpear(const std::string& identifier, short numId)
		: Item(identifier, numId)
	{
		Log::Info("Wooden Spear created with id: {}", numId);
	}
	
	ItemStack& use(ItemStack& itemStack, Player& player) const override {
		/*const CompoundTag* tag = itemStack.mUserData;
		int CurrentItemHelth = Item::getDamageValue(tag);
		CurrentItemHelth++;
		Item::setDamageValue(itemStack, CurrentItemHelth);
		Log::Info("Item Health {}", CurrentItemHelth);*/
		return itemStack;
	}
	void hurtActor(ItemStack& stack, Actor& target, Mob& attacker) const override {
		const CompoundTag* tag = stack.mUserData;
		int CurrentItemHelth = Item::getDamageValue(tag);
		CurrentItemHelth++;
		Item::setDamageValue(stack, CurrentItemHelth);
		if (CurrentItemHelth < 0) {
			Item::setDamageValue(stack, 0);
		}
	}
	
	virtual void hitActor(ItemStack& itemStack, Actor& actor, Mob& attacker) const override {
		if (auto* comp = attacker.tryGetComponent<StateVectorComponent>()) {
			// Calculate full 3D velocity magnitude (always positive)
			float velocity = comp->mPosDelta.length() * 20.0f;
			speed = velocity;
			Log::Info("Player speed: {}", speed);
		}
	}
	
	virtual int getAttackDamage() const override{
		Log::Info("Speed: {}", speed);
		Log::Info("Damage: {}", 2 + (speed / 3) * 2);
		return 2 + (speed / 3) * 2;
	};
};

void ModSpears::registerItems(RegisterItemsEvent& ev){
	auto& WoodenSpears = ev.itemRegistry.registerItemShared<WoodenSpear>("bs-spears:Wooden_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-spears:wooden_spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(63);
	auto& StoneSpears = ev.itemRegistry.registerItemShared<Items>("bs-spears:Stone_Spear", ev.itemRegistry.getNexItemID())
		->setIconInfo("bs-spears:stone_spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(153);
}

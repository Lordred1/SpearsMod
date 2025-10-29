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
		Log::Info("Wooden Spear Created With ID: {}", numId);
	}
	
	ItemStack& use(ItemStack& itemStack, Player& player) const override {
		return itemStack;
	}
	void hurtActor(ItemStack& stack, Actor& target, Mob& attacker) const override {
		const CompoundTag* tag = stack.mUserData;
		int CurrentItemHelth = Item::getDamageValue(tag);
		CurrentItemHelth++;
		Item::setDamageValue(stack, CurrentItemHelth);
		if (CurrentItemHelth < 0) {
			Item::setDamageValue(stack, 1);
		}
	}
	
	virtual void hitActor(ItemStack& itemStack, Actor& actor, Mob& attacker) const override {
		if (auto* comp = attacker.tryGetComponent<StateVectorComponent>()) {
			// Calculate full 3D velocity magnitude (always positive)
			float velocity = comp->mPosDelta.length() * 20.0f;
			speed = velocity;
		}
	}
	
	virtual int getAttackDamage() const override{
		return 2 + (speed / 3) * 2;
	};
};
class StoneSpear : public Item {
public:
	StoneSpear(const std::string identifier, short numId)
		: Item(identifier, numId) {
		Log::Info("Stone Spear Created With ID: {}", numId);
	}
	ItemStack& use(ItemStack& itemStack, Player& player) const override {
		return itemStack;
	}
	void hurtActor(ItemStack& stack, Actor& target, Mob& attacker) const override {
		const CompoundTag* tag = stack.mUserData;
		int CurrentItemHelth = Item::getDamageValue(tag);
		CurrentItemHelth++;
		Item::setDamageValue(stack, CurrentItemHelth);
		if (CurrentItemHelth < 0) {
			Item::setDamageValue(stack, 1);
		}
	}
	virtual void hitActor(ItemStack& itemStack, Actor& actor, Mob& attacker) const override {
		if (auto* comp = attacker.tryGetComponent<StateVectorComponent>()) {
			float velocity = comp->mPosDelta.length() * 20.0f;
			speed = velocity;
		}
	}
	virtual int getAttackDamage() const override {
		return 3 + (speed / 3) * 2;
	};
};
class IronSpear : public Item {
public:
	IronSpear(const std::string& identifier, short numId)
		: Item(identifier, numId) {
		Log::Info("Iron Spear Created With ID: {}", numId);
	}ItemStack& use(ItemStack& itemStack, Player& player) const override {
		return itemStack;
	}
	void hurtActor(ItemStack& stack, Actor& target, Mob& attacker) const override {
		const CompoundTag* tag = stack.mUserData;
		int CurrentItemHelth = Item::getDamageValue(tag);
		CurrentItemHelth++;
		Item::setDamageValue(stack, CurrentItemHelth);
		if (CurrentItemHelth < 0) {
			Item::setDamageValue(stack, 1);
		}
	}

	virtual void hitActor(ItemStack& itemStack, Actor& actor, Mob& attacker) const override {
		if (auto* comp = attacker.tryGetComponent<StateVectorComponent>()) {
			float velocity = comp->mPosDelta.length() * 20.0f;
			speed = velocity;
		}
	}

	virtual int getAttackDamage() const override {
		return 4 + (speed / 3) * 2;
	};
};
class DiamondSpear : public Item {
public:
	DiamondSpear(const std::string identifier, short numId)
		: Item(identifier, numId) {
		Log::Info("Diamond Spear Created With ID: {}", numId);
	}
	ItemStack& use(ItemStack& itemStack, Player& player) const override {
		return itemStack;
	}
	void hurtActor(ItemStack& stack, Actor& target, Mob& attacker) const override {
		const CompoundTag* tag = stack.mUserData;
		int CurrentItemHelth = Item::getDamageValue(tag);
		CurrentItemHelth++;
		Item::setDamageValue(stack, CurrentItemHelth);
		if (CurrentItemHelth < 0) {
			Item::setDamageValue(stack, 1);
		}
	}
	virtual void hitActor(ItemStack& itemStack, Actor& actor, Mob& attacker) const override {
		if (auto* comp = attacker.tryGetComponent<StateVectorComponent>()) {
			float velocity = comp->mPosDelta.length() * 20.0f;
			speed = velocity;
		}
	}
	virtual int getAttackDamage() const override {
		return 5 + (speed / 3) * 2;
	};
};
class NetheriteSpear : public Item {
public:
	NetheriteSpear(const std::string& identifier, short numId)
		: Item(identifier, numId) {
		Log::Info("Netherite Spear Created With ID: {}", numId);
	}
	ItemStack& use(ItemStack& itemStack, Player& player) const override {
		return itemStack;
	}
	void hurtActor(ItemStack& stack, Actor& target, Mob& attacker) const override {
		const CompoundTag* tag = stack.mUserData;
		int CurrentItemHelth = Item::getDamageValue(tag);
		CurrentItemHelth++;
		Item::setDamageValue(stack, CurrentItemHelth);
		if (CurrentItemHelth < 0) {
			Item::setDamageValue(stack, 1);
		}
	}

	virtual void hitActor(ItemStack& itemStack, Actor& actor, Mob& attacker) const override {
		if (auto* comp = attacker.tryGetComponent<StateVectorComponent>()) {
			// Calculate full 3D velocity magnitude (always positive)
			float velocity = comp->mPosDelta.length() * 20.0f;
			speed = velocity;
			std::string getGroupInfo = getCreativeGroup();
			Log::Info("Group is: {}", getGroupInfo);
		}
	}
	virtual int getAttackDamage() const override {
		return 5 + speed;
	};
};
//int i; //used to change hash
void ModSpears::registerItems(RegisterItemsEvent& ev){

	auto& WoodenSpears = ev.itemRegistry.registerItemShared<WoodenSpear>("bs-spears:Wooden_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-spears:Wooden_Spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(63)
		.setCategory(CreativeItemCategory::Equipment);
	auto& StoneSpears = ev.itemRegistry.registerItemShared<StoneSpear>("bs-spears:Stone_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-spears:Stone_Spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(153)
		.setCategory(CreativeItemCategory::Equipment);
	auto& GoldSpears = ev.itemRegistry.registerItemShared<WoodenSpear>("bs-spears:Gold_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-spears:Gold_Spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(153)
		.setCategory(CreativeItemCategory::Equipment);
	auto& IronSpears = ev.itemRegistry.registerItemShared<IronSpear>("bs-spears:Iron_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-spears:Iron_Spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(253)
		.setCategory(CreativeItemCategory::Equipment);
	auto& DiamondSpears = ev.itemRegistry.registerItemShared<DiamondSpear>("bs-spears:Diamond_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-spears:Diamond_Spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(1553)
		.setCategory(CreativeItemCategory::Equipment);
	auto& NetheriteSpears = ev.itemRegistry.registerItemShared<NetheriteSpear>("bs-spears:Netherite_Spear", ev.itemRegistry.getNextItemID())
		->setIconInfo("bs-spears:Netherite_Spear", 0)
		.setMaxStackSize(1)
		.setMaxDamage(2054)
		.setCategory(CreativeItemCategory::Equipment);
	
}

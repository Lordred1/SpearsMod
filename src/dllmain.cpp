#include "dllmain.hpp"
#include "items/Spears.hpp"

// Ran when the mod is loaded into the game by AmethystRuntime

ModFunction void Initialize(AmethystContext& ctx, const Amethyst::Mod& mod) 
{
	//Amethyst::EventBus& bus = Amethyst::GetEventBus();
	Amethyst::InitializeAmethystMod(ctx, mod);
    Amethyst::GetEventBus().AddListener<OnStartJoinGameEvent>(&OnStartJoinGame);
	Amethyst::GetEventBus().AddListener<RegisterItemsEvent>(&ModSpears::registerItems);
}

void OnStartJoinGame(OnStartJoinGameEvent& event)
{
}

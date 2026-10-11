#include "GameState.h"
#include <iostream>

#include "../tilemap/MapConstants.h"

GameState::GameState(Window* window)
	:StateManager(window)
{
	LoadAssets();
    
    m_Map = std::make_unique<TileMap>(GetWindow(), MapConstants::WorldTileRows, MapConstants::WorldTileCols,
                                      MapConstants::TileSize, "res/map/map.txt");
    m_Map->SetTileIdentity(1, TextureArea(&m_AssetManager->GetTexture(AssetManager::GetFromImageDir("MapTiles.png")), Rect(0, 0, 16, 16)));

	InitEntities();
	InitObjects();
	InitUI();

	std::cout << "GameState Initialized!" << std::endl;
}

void GameState::LoadAssets()
{
    m_AssetManager = std::make_unique<AssetManager>();
    
    m_AssetManager->LoadTexture(AssetManager::GetFromImageDir("MapTiles.png"));
}

void GameState::InitEntities()
{
}

void GameState::InitObjects()
{
}

void GameState::InitUI()
{
}


GameState::~GameState()
{
}

void GameState::Update(float deltaTime)
{
}

void GameState::Render()
{
    m_Map->Render();
}

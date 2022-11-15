#pragma once
#include "Module.h"
#include "Globals.h"
//#include "Animation.h"

struct SDL_Texture;

class ModuleSceneTitle : public Module
{
public:
	//Constructor
	ModuleSceneTitle(Application* app, bool start_enabled = true);
	~ModuleSceneTitle();

	bool Start();
	update_status Update();
	bool CleanUp();

	//bool Start() override;

	//update_status Update() override;

	//update_status PostUpdate() override;

public:

	SDL_Texture* bgTexture = nullptr;
};
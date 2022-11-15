#include "ModuleSceneTitle.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
//#include "ModulePhysics.h"
#include "ModuleFadeToBlack.h"

ModuleSceneTitle::ModuleSceneTitle(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}

ModuleSceneTitle::~ModuleSceneTitle()
{

}

// Load assets
bool ModuleSceneTitle::Start()
{
	LOG("Loading title assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	bgTexture = App->textures->Load("pinball/intro.jpg");
	//App->audio->PlayMusic("Assets/Fx/intro.wav", 1.0f);

	return ret;
}

bool ModuleSceneTitle::CleanUp()
{
	LOG("Unloading Title scene");

	return true;
}

update_status ModuleSceneTitle::Update()
{
	if (App->input->GetKey(SDL_SCANCODE_SPACE|| SDL_SCANCODE_RETURN) == KEY_DOWN)
	{
		App->fade_to_black->FadeToBlack(this, (Module*)App->scene_intro, 90);
	}

	return UPDATE_CONTINUE;
}

//update_status ModuleSceneTitle::PostUpdate() //COMENTAT PERQUÈ NO HI HA POST UPDATE, NO SÉ SI CAL
//{
//	// Draw everything --------------------------------------
//	App->render->Blit(bgTexture, 0, 0, NULL);
//
//	return Update_Status::UPDATE_CONTINUE;
//}

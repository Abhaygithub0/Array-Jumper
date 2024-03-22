#include "../../header/Level/LevelService.h"
#include "../../header/Level/LevelController.h"

namespace Level
{
	LevelService::LevelService()
	{
		level_controller = new LevelController();
	}

	LevelService::~LevelService() {};

	void LevelService::intialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	BoxDimentions LevelService::getBoxDimensions()
	{
		return level_controller->getBoxDimentions();
	}

	BlockType LevelService::getCurrentBoxValue(int currentPosition)
	{
		return level_controller->getCurrentBoxValue(currentPosition);
	}

	bool LevelService::isLastLevel()
	{
		return level_controller->isLastLevel();
	}

	void LevelService::loadNextLevel()
	{
		level_controller->loadNextLevel();
	}

	int LevelService::getCurrentLevelNumber()
	{
		return level_controller->getCurrentLevelNumber();
	}

	void LevelService::resetLevels()
	{
		level_controller->reset();
	}
	
	void LevelService::destroy()
	{
		delete(level_controller);
	}
}

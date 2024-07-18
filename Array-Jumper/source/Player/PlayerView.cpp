#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Global/ServiceLocator.h"
#include"../../header/Player/PlayerController.h"
#include"../../header/Player/PlayerModel.h"

namespace Player
{
	
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;
		game_window = nullptr;
		player_image = nullptr;
		player_image = new ImageView();

		 
	}

	PlayerView::~PlayerView() {}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadPlayer();
	}
	void PlayerView::CalculatePlayerDimensions()
	{
		current_box_dimensions = ServiceLocator::getInstance()->getLevelService()->getBoxDimensions();
		player_height = current_box_dimensions.box_height;
		player_width = current_box_dimensions.box_width;
	}
	void PlayerView::update()
	{
		player_image->setPosition(calulcatePlayerPosition());
	}

	void PlayerView::render()
	{
		switch (player_controller->getPlayerState())
		{
		case PlayerState::ALIVE:
			drawPlayer();
			break;
		}
	}
	void PlayerView::CalculatePlayerDimensions()
	{
		player_height = 1000.f;
		player_width = 1000.f;
	}
	sf::Vector2f PlayerView::calulcatePlayerPosition()
	{
		float xPosition = current_box_dimensions.box_spacing + static_cast<float>(player_controller->getCurrentPosition()) * (current_box_dimensions.box_width + current_box_dimensions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height - current_box_dimensions.bottom_offset - player_height;
		return sf::Vector2f(xPosition, yPosition);
	}
	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path,
			player_width,
			player_height,
			sf::Vector2f(0, 0));
	}
	void PlayerView::loadPlayer()
	{
		CalculatePlayerDimensions();
		initializePlayerImage();
	}
	void PlayerView::drawPlayer()
	{
		player_image->render();
	}
}



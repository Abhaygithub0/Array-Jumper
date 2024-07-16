#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Player/PlayerService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Player::PlayerService* player_service;
        Graphics::GraphicService* graphic_service;
        Event::EventService* event_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;

        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        ServiceLocator();
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphics::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Sound::SoundService* getSoundService();
        UI::UIService* getUIService();
        Player::PlayerService* getPlayerService();
    };
}
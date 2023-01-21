#pragma once

#include <format>

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace sfe
{
	/*
	* A sf::View wrapper class that allows direct position, zoom, etc modification
	* Can be passed to window as a view would. Eg. window.setView(camera);
	*/
	class Camera
	{
	private:
		sf::View mView;
		sf::Vector2f mPosition;
		float mRotation = 0.f;
		float mZoomFactor = 1.f;
		const sf::Vector2f mOriginalSize;
		sf::FloatRect mCameraBounds;
		bool mIsBounded = false;
	public:
		Camera() = default;
		Camera(const sf::View& view);
		Camera(const sf::RenderWindow& window);

		operator sf::View() const
		{
			return mView;
		}

		void setPosition(const sf::Vector2f& pos);
		const sf::Vector2f& getPosition() const;

		void rotate(float angle);
		void setRotation(const float rotation);
		float getRotation() const;
		
		void zoom(float factor);
		void setZoom(float factor);
		float getZoom() const;

		void move(const sf::Vector2f& offset);

		void setCameraBounds(const sf::FloatRect& rect);
		const sf::FloatRect& getCameraBounds() const;
		void resetCameraBounds();

		const sf::View& getView() const;
	};
}



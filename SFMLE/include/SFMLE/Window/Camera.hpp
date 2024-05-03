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
		/*const */sf::Vector2f mOriginalSize;
		sf::FloatRect mCameraLimit;
		bool mIsBounded = false;
	public:
		Camera() = default;
		Camera(const sf::View& view);
		Camera(const sf::RenderWindow& window);

		Camera(const Camera& camera);
		Camera& operator=(const Camera& camera);

		operator sf::View() const
		{
			return mView;
		}

		operator const sf::View&() const
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

		// the bounding box that the camera is free to move in, and will stop if hitting the edges
		void setCameraLimit(const sf::FloatRect& rect);
		const sf::FloatRect& getCameraLimit() const;
		void resetCameraLimit();

		const sf::FloatRect getViewBounds() const;
		const sf::View& getView() const;
	};
}



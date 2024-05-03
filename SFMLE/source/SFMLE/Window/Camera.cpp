#include "SFMLE/Window/Camera.hpp"

namespace sfe
{
	Camera::Camera(const sf::View& view)
		: mView(view)
		, mOriginalSize(view.getSize())
	{
		mView.setCenter(mView.getSize() / 2.f);
	}

	Camera::Camera(const sf::RenderWindow& window)
		:	Camera(window.getView())
	{
	}

	Camera::Camera(const Camera& camera)
	{
		*this = camera;
	}

	Camera& Camera::operator=(const Camera& camera)
	{
		mView = camera.mView;
		mPosition = camera.mPosition;
		mRotation = camera.mRotation;
		mZoomFactor = camera.mZoomFactor;
		mOriginalSize = camera.mOriginalSize;
		mCameraLimit = camera.mCameraLimit;
		mIsBounded = camera.mIsBounded;
		return *this;
	}

	void Camera::setPosition(const sf::Vector2f& pos)
	{
		if (!mIsBounded)
		{
			mView.move(pos - mPosition);
			mPosition = pos;
		}
		else
		{
			auto newPos = pos;
			if (pos.x < mCameraLimit.left) newPos.x = mCameraLimit.left;
			if (pos.x + mView.getSize().x > (mCameraLimit.left + mCameraLimit.width)) newPos.x = mCameraLimit.left + mCameraLimit.width - mView.getSize().x;
			if (pos.y < mCameraLimit.top) newPos.y = mCameraLimit.top;
			if (pos.y + mView.getSize().y > (mCameraLimit.top + mCameraLimit.height)) newPos.y = mCameraLimit.top + mCameraLimit.height - mView.getSize().y;

			mView.move(newPos - mPosition);
			mPosition = newPos;
		}
	}

	const sf::Vector2f& Camera::getPosition() const
	{
		return mPosition;
	}

	void Camera::rotate(float angle)
	{
		mView.rotate(angle);
		mRotation += angle;
	}

	void Camera::setRotation(const float rotation)
	{
		mView.setRotation(rotation);
		mRotation = rotation;
	}

	float Camera::getRotation() const
	{
		return mRotation;
	}

	void Camera::zoom(float factor)
	{
		mZoomFactor *= factor;
		mView.zoom(factor);
	}

	void Camera::setZoom(float factor)
	{
		mZoomFactor = factor;
		mView.setSize(mOriginalSize * factor);
	}

	float Camera::getZoom() const
	{
		return mZoomFactor;
	}

	void Camera::move(const sf::Vector2f& offset)
	{
		if (!mIsBounded)
		{
			mPosition += offset;
			mView.move(offset);
		}
		else
		{
			auto newOffset = offset;
			if (offset.x + mPosition.x < mCameraLimit.left) newOffset.x = mCameraLimit.left;
			if (offset.x + mPosition.x + mView.getSize().x > (mCameraLimit.left + mCameraLimit.width)) newOffset.x = 0.f;// mCameraBounds.left + mCameraBounds.width - mView.getSize().x;
			if (offset.y + mPosition.y < mCameraLimit.top) newOffset.y = mCameraLimit.top;
			if (offset.y + mPosition.y + mView.getSize().y > (mCameraLimit.top + mCameraLimit.height)) newOffset.y = 0.f;// = mCameraBounds.top + mCameraBounds.height - mView.getSize().y;

			mPosition += newOffset;
			mView.move(newOffset);
		}
	}

	void Camera::setCameraLimit(const sf::FloatRect& rect)
	{
		mCameraLimit = rect;
		mIsBounded = true;
	}

	const sf::FloatRect& Camera::getCameraLimit() const
	{
		return mCameraLimit;
	}

	void Camera::resetCameraLimit()
	{
		mIsBounded = false;
		mCameraLimit = sf::FloatRect();
	}

	const sf::FloatRect Camera::getViewBounds() const
	{
		return sf::FloatRect
		(
			mPosition,
			mOriginalSize
			/*mZoomFactor < 1.f ?
				sf::Vector2f{ mView.getSize().x * (1.f + mZoomFactor), mView.getSize().y * (1.f + mZoomFactor)} :
				sf::Vector2f{ mView.getSize().x * mZoomFactor, mView.getSize().y * mZoomFactor }*/
		);
	}

	const sf::View& Camera::getView() const
	{
		return mView;
	}
}


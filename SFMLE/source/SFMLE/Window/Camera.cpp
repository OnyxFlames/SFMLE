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
			if (pos.x < mCameraBounds.left) newPos.x = mCameraBounds.left;
			if (pos.x + mView.getSize().x > (mCameraBounds.left + mCameraBounds.width)) newPos.x = mCameraBounds.left + mCameraBounds.width - mView.getSize().x;
			if (pos.y < mCameraBounds.top) newPos.y = mCameraBounds.top;
			if (pos.y + mView.getSize().y > (mCameraBounds.top + mCameraBounds.height)) newPos.y = mCameraBounds.top + mCameraBounds.height - mView.getSize().y;

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
		printf("Zoom: %f\n", mZoomFactor);
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
			if (offset.x + mPosition.x < mCameraBounds.left) newOffset.x = mCameraBounds.left;
			if (offset.x + mPosition.x + mView.getSize().x > (mCameraBounds.left + mCameraBounds.width)) newOffset.x = 0.f;// mCameraBounds.left + mCameraBounds.width - mView.getSize().x;
			if (offset.y + mPosition.y < mCameraBounds.top) newOffset.y = mCameraBounds.top;
			if (offset.y + mPosition.y + mView.getSize().y > (mCameraBounds.top + mCameraBounds.height)) newOffset.y = 0.f;// = mCameraBounds.top + mCameraBounds.height - mView.getSize().y;

			mPosition += newOffset;
			mView.move(newOffset);
		}
	}

	void Camera::setCameraBounds(const sf::FloatRect& rect)
	{
		mCameraBounds = rect;
		mIsBounded = true;
	}

	const sf::FloatRect& Camera::getCameraBounds() const
	{
		return mCameraBounds;
	}

	void Camera::resetCameraBounds()
	{
		mIsBounded = false;
		mCameraBounds = sf::FloatRect();
	}

	const sf::View& Camera::getView() const
	{
		return mView;
	}
}


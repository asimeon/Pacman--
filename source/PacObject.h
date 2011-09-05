
#ifndef PACOBJECT_H
#define PACOBJECT_H

#include <SDL.h>
#include <string>
#include "Vector3.h"

class PacObject
{
public:
	PacObject();
	virtual ~PacObject();

	virtual void Initialise();
	virtual void Uninitialise();

	virtual void Update(float a_fDeltatime) = 0;
	virtual void Render(SDL_Surface* a_pScreen) = 0;

	inline Vector3f GetPosition() const { return m_kPosition; }
	inline void SetPosition(Vector3f a_kPosition) { m_kPosition = a_kPosition; }

	inline int GetSpriteWidth() const { return m_iSurfaceWidth; }
	inline int GetSpriteHeight() const { return m_iSurfaceHeight; }

	void LoadSpriteFromFile(std::string a_ssFilename, int a_iWidth, int a_iHeight);
	inline SDL_Surface* GetSurface() const { return m_pSurface; }

	inline float GetScale() const { return m_fScale; }
	inline void SetScale(float a_fScale) { m_fScale = a_fScale; }

	inline bool GetToRender() const { return m_bRender; }
	inline void SetToRender(bool a_bRender) { m_bRender = a_bRender; }

protected:
	SDL_Surface* m_pSurface;

	Vector3f m_kPosition;

	int m_iSurfaceWidth;
	int m_iSurfaceHeight;
	float m_fScale;
	bool m_bRender;
};

#endif // PACOBJECT_H

//-----------------------------------------------------------------------------
// File: Scene.h
//-----------------------------------------------------------------------------

#pragma once

#include "Shader.h"
#include "Player.h"
#define MAX_LIGHTS			16

#define POINT_LIGHT			1
#define SPOT_LIGHT			2
#define DIRECTIONAL_LIGHT	3

struct LIGHT
{
	XMFLOAT4				m_xmf4Ambient;
	XMFLOAT4				m_xmf4Diffuse;
	XMFLOAT4				m_xmf4Specular;
	XMFLOAT3				m_xmf3Position;
	float 					m_fFalloff;
	XMFLOAT3				m_xmf3Direction;
	float 					m_fTheta; //cos(m_fTheta)
	XMFLOAT3				m_xmf3Attenuation;
	float					m_fPhi; //cos(m_fPhi)
	bool					m_bEnable;
	int						m_nType;
	float					m_fRange;
	float					padding;
};

struct LIGHTS
{
	LIGHT					m_pLights[MAX_LIGHTS];
	XMFLOAT4				m_xmf4GlobalAmbient;
	int						m_nLights;
};

class CScene
{
public:
	CHeightMapTerrain* m_pTerrain = NULL;
	void EnemyByBulletCollisions();
	void RotateObjectTowardsTarget();

	float m_fSpace = 500.0f;

	void PlayerByBulletCollisions();
	float m_fSpeed = 0.0f;
	CScene();
	~CScene();
	void EnemyByEnemyCollisions();
	bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	virtual void CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseShaderVariables();

	void BuildDefaultLightsAndMaterials();
	void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	void ReleaseObjects();

	ID3D12RootSignature* CreateGraphicsRootSignature(ID3D12Device* pd3dDevice);
	ID3D12RootSignature* GetGraphicsRootSignature() { return(m_pd3dGraphicsRootSignature); }

	bool ProcessInput(UCHAR* pKeysBuffer);
	void AnimateObjects(float fTimeElapsed);
	void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera = NULL);

	void PlayeByObjectCollision();

	void ReleaseUploadBuffers();

	void Particles_Object(XMFLOAT3 pos, int nParticles);
	void EnermyParticles(XMFLOAT3 pos, int nParticles);

	BoundingOrientedBox		m_xmOOBB;

	CBulletObject* m_pBullet = NULL;
	CPlayer* m_pPlayer = NULL;

public:
	ID3D12RootSignature* m_pd3dGraphicsRootSignature = NULL;

	CEnemyObject** m_ppGameObjects = NULL;
	CGameObject** pTree_Objects = NULL;
	CGameObject** pBuilding_Objects = NULL;
	CGameObject** pLamp_Objects = NULL;

	int							m_nGameObjects = 0;
	int TreeObjects = 0;
	int BuldingNum = 0;
	int PlaneNum = 0;
	int LampNum = 0;
	CParticleObject** pParticle = NULL;
	CEnemyObject* bulletObjects = NULL;
	int							ParticleCNT = 0;

	LIGHT* m_pLights = NULL;
	int							m_nLights = 0;

	XMFLOAT4					m_xmf4GlobalAmbient;

	ID3D12Resource* m_pd3dcbLights = NULL;
	LIGHTS* m_pcbMappedLights = NULL;

	CGameObject* m_pParticleModel = NULL;

	float						m_fElapsedTime = 0.0f;
	bool				m_bGameOver = false;
	float				m_fRestartCounter = 0.0f;

};

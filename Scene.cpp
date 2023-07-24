//-----------------------------------------------------------------------------
// File: CScene.cpp
//-----------------------------------------------------------------------------

#include "stdafx.h"
#include "Scene.h"
#include<random>
default_random_engine dre;
uniform_int_distribution<int> uidX1{ 1000,1800 };
uniform_int_distribution<int> uidX2{ 2200,4000 };
uniform_int_distribution<int> lights{1700, 2200 };
uniform_int_distribution<int> uidZ{ 1000,3000 };
uniform_int_distribution<int> uid{ 0,1 };

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::BuildDefaultLightsAndMaterials()
{
	m_nLights = 55;
	m_pLights = new LIGHT[m_nLights];
	::ZeroMemory(m_pLights, sizeof(LIGHT) * m_nLights);

	m_xmf4GlobalAmbient = XMFLOAT4(0.8, 0.8, 0.8, 1.0f);

	m_pLights[0].m_bEnable = true;
	m_pLights[0].m_nType = POINT_LIGHT;
	m_pLights[0].m_fRange = 1000.0f;
	m_pLights[0].m_xmf4Ambient = XMFLOAT4(0.1f, 0.0f, 0.0f, 1.0f);
	m_pLights[0].m_xmf4Diffuse = XMFLOAT4(0.4f, 0.0f, 0.0f, 1.0f);
	m_pLights[0].m_xmf4Specular = XMFLOAT4(0.5f, 0.5f, 0.5f, 0.0f);
	m_pLights[0].m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_pLights[0].m_xmf3Direction = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_pLights[0].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.001f, 0.0001f);
	m_pLights[1].m_bEnable = true;
	m_pLights[1].m_nType = SPOT_LIGHT;
	m_pLights[1].m_fRange = 500.0f;
	m_pLights[1].m_xmf4Ambient = XMFLOAT4(0.1f, 0.1f, 0.1f, 1.0f);
	m_pLights[1].m_xmf4Diffuse = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	m_pLights[1].m_xmf4Specular = XMFLOAT4(0.3f, 0.3f, 0.3f, 0.0f);
	m_pLights[1].m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_pLights[1].m_xmf3Direction = XMFLOAT3(0.0f, 0.0f, 1.0f);
	m_pLights[1].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.0001f);
	m_pLights[1].m_fFalloff = 8.0f;
	m_pLights[1].m_fPhi = (float)cos(XMConvertToRadians(40.0f));
	m_pLights[1].m_fTheta = (float)cos(XMConvertToRadians(20.0f));
	m_pLights[2].m_bEnable = true;
	m_pLights[2].m_nType = DIRECTIONAL_LIGHT;
	m_pLights[2].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[2].m_xmf4Diffuse = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[2].m_xmf4Specular = XMFLOAT4(0.4f, 0.4f, 0.4f, 0.0f);
	m_pLights[2].m_xmf3Direction = XMFLOAT3(1.0f, 0.0f, 0.0f);
	m_pLights[3].m_bEnable = true;
	m_pLights[3].m_nType = SPOT_LIGHT;
	m_pLights[3].m_fRange = 600.0f;
	m_pLights[3].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[3].m_xmf4Diffuse = XMFLOAT4(0.3f, 0.7f, 0.0f, 1.0f);
	m_pLights[3].m_xmf4Specular = XMFLOAT4(0.3f, 0.3f, 0.3f, 0.0f);
	m_pLights[3].m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_pLights[3].m_xmf3Direction = XMFLOAT3(1.0f, 0.0f, 0.0f);
	m_pLights[3].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.0001f);
	m_pLights[3].m_fFalloff = 8.0f;
	m_pLights[3].m_fPhi = (float)cos(XMConvertToRadians(90.0f));
	m_pLights[3].m_fTheta = (float)cos(XMConvertToRadians(30.0f));
	m_pLights[4].m_bEnable = true;
	m_pLights[4].m_nType = SPOT_LIGHT;
	m_pLights[4].m_fRange = 600.0f;
	m_pLights[4].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[4].m_xmf4Diffuse = XMFLOAT4(0.3f, 0.7f, 0.0f, 1.0f);
	m_pLights[4].m_xmf4Specular = XMFLOAT4(0.3f, 0.3f, 0.3f, 0.0f);
	m_pLights[4].m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_pLights[4].m_xmf3Direction = XMFLOAT3(1.0f, 0.0f, 0.0f);
	m_pLights[4].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.0001f);
	m_pLights[4].m_fFalloff = 8.0f;
	m_pLights[4].m_fPhi = (float)cos(XMConvertToRadians(90.0f));
	m_pLights[4].m_fTheta = (float)cos(XMConvertToRadians(30.0f));
	m_pLights[4].m_bEnable = true;

	m_pLights[5].m_nType = SPOT_LIGHT;
	m_pLights[5].m_fRange = 600.0f;
	m_pLights[5].m_xmf4Ambient = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
	m_pLights[5].m_xmf4Diffuse = XMFLOAT4(0.3f, 0.7f, 0.0f, 1.0f);
	m_pLights[5].m_xmf4Specular = XMFLOAT4(0.3f, 0.3f, 0.3f, 0.0f);
	m_pLights[5].m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_pLights[5].m_xmf3Direction = XMFLOAT3(1.0f, 0.0f, 0.0f);
	m_pLights[5].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.0001f);
	m_pLights[5].m_fFalloff = 8.0f;
	m_pLights[5].m_fPhi = (float)cos(XMConvertToRadians(90.0f));
	m_pLights[5].m_fTheta = (float)cos(XMConvertToRadians(30.0f));
	for (int i = 5; i < m_nLights; i++) {
		m_pLights[i].m_bEnable = true;
		m_pLights[i].m_nType = SPOT_LIGHT;
		m_pLights[i].m_fRange = 500.0f;
		m_pLights[i].m_xmf4Ambient = XMFLOAT4(0.1f, 0.1f, 0.1f, 1.0f);
		m_pLights[i].m_xmf4Diffuse = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
		m_pLights[i].m_xmf4Specular = XMFLOAT4(0.3f, 0.3f, 0.3f, 0.0f);
		m_pLights[i].m_xmf3Position = XMFLOAT3(0, 0, 0);
		m_pLights[i].m_xmf3Direction = XMFLOAT3(0.0f, -1.0f, 0.0f);
		m_pLights[i].m_xmf3Attenuation = XMFLOAT3(1.0f, 0.01f, 0.0001f);
		m_pLights[i].m_fFalloff = 8.0f;
		m_pLights[i].m_fPhi = (float)cos(XMConvertToRadians(40.0f));
		m_pLights[i].m_fTheta = (float)cos(XMConvertToRadians(20.0f));
	}
}
void CScene::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	m_pd3dGraphicsRootSignature = CreateGraphicsRootSignature(pd3dDevice);

	CMaterial::PrepareShaders(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);

	BuildDefaultLightsAndMaterials();
	//////////////////////////지형그리기///////////////////////////

	CTerrainShader* pTerrainShader = new CTerrainShader();
	pTerrainShader->CreateShader(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);

	CMaterialColors* pMaterialColors = new CMaterialColors();
	pMaterialColors->m_xmf4Ambient = XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f);
	pMaterialColors->m_xmf4Diffuse = XMFLOAT4(0.83f, 0.7f, 0.2f, 1.0f);
	pMaterialColors->m_xmf4Specular = XMFLOAT4(0.0f, 0.0f, 0.0f, 8.0f); //(r,g,b,a=power)
	pMaterialColors->m_xmf4Emissive = XMFLOAT4(0.0f, 0.2f, 0.0f, 1.0f);

	CMaterial* pMaterial = new CMaterial();
	pMaterial->SetShader(pTerrainShader);
	pMaterial->SetMaterialColors(pMaterialColors);

	XMFLOAT3 xmf3Scale(10.0f, 2.0f, 10.0f);
	XMFLOAT3 xmf3Pos(0.0, 0.0f, 0.0);
	XMFLOAT4 xmf4Color(0.0f, 0.2f, 0.0f, 0.0f);
	m_pTerrain = new CHeightMapTerrain(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, _T("Terrain/terrain.raw"), 513, 513, 64, 64, xmf3Scale, xmf4Color);

	m_pTerrain->SetPosition(xmf3Pos);
	m_pTerrain->Rotate(0.0, 0.0, 0.0);
	m_pTerrain->SetMaterial(pMaterial);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	TreeObjects = 60;
	TREEObject* TREE_Object = NULL;
	pTree_Objects = new CGameObject * [TreeObjects];

	CGameObject* TreeModel = CGameObject::LoadGeometryFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "Model/TREE.bin");
	for (int i = 0; i < TreeObjects; ++i) { //여기
		TREE_Object = new TREEObject();
		TREE_Object->SetChild(TreeModel, true);
		TREE_Object->OnInitialize();
		int RandomNumberX[2] = { uidX1(dre) ,uidX2(dre) };
		int index = uid(dre);
		int PosX = RandomNumberX[index];
		int PosZ = uidZ(dre);
		TREE_Object->SetPosition(PosX, m_pTerrain->GetHeight(PosX, PosZ), PosZ);
		TREE_Object->SetScale(6.0f, 6.0f, 6.0f);
		TREE_Object->Rotate(0.0f, 180.0f, 0.0f);
		TREE_Object->m_xmOOBB = BoundingOrientedBox(TREE_Object->GetPosition(), XMFLOAT3(6.0f, 6.0f, 6.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
		TREE_Object->SetOOBB();
		pTree_Objects[i] = TREE_Object;
	}
	///////////////////////////////////////////////////////////////////////////////////////
	//빌딩 만들기 
	BuldingNum = 20;
	BuildingObject* Building_Object = NULL;
	pBuilding_Objects = new CGameObject * [BuldingNum];

	CGameObject* BuildingModel = CGameObject::LoadGeometryFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "Model/StyleD-Building1.bin");
	for (int i = 0; i < BuldingNum; ++i) { //여기
		Building_Object = new BuildingObject();
		Building_Object->SetChild(BuildingModel, true);
		Building_Object->OnInitialize();
		int RandomNumberX[2] = { uidX1(dre) ,uidX2(dre) };
		int index = uid(dre);
		int PosX = RandomNumberX[index];
		int PosZ = uidZ(dre);
		Building_Object->SetPosition(PosX, m_pTerrain->GetHeight(PosX, PosZ), PosZ);
		Building_Object->SetScale(4.0f, 4.0f, 4.0f);
		Building_Object->Rotate(0.0f, 180.0f, 0.0f);
		Building_Object->m_xmOOBB = BoundingOrientedBox(Building_Object->GetPosition(), XMFLOAT3(30.0f, 30.0f, 30.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
		Building_Object->SetOOBB();
		pBuilding_Objects[i] = Building_Object;
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//가로등
	LampNum = 9;
	LampObject* Lamp_Object = NULL;
	pLamp_Objects = new CGameObject * [LampNum];
	CGameObject* LampModel = CGameObject::LoadGeometryFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "Model/Traffic-StreetLampALOD1.bin");

	for (int i = 0; i < LampNum; ++i) { //여기
		Lamp_Object = new LampObject();
		Lamp_Object->SetChild(LampModel, true);
		Lamp_Object->OnInitialize();
		int RandomNumberX[2] = { uidX1(dre) ,uidX2(dre) };
		int index = uid(dre);
		int PosX = RandomNumberX[index];
		int PosZ = uidZ(dre);
		Lamp_Object->SetPosition(PosX, m_pTerrain->GetHeight(PosX, PosZ), PosZ);
		Lamp_Object->SetScale(5.0f, 5.0f, 5.0f);
		Lamp_Object->Rotate(0.0f, 0.0, 0.0f);
		pLamp_Objects[i] = Lamp_Object;
	}
	///////////////////////////////////////////////////////////////////////////////////////

	m_nGameObjects = 4;
	m_ppGameObjects = new CEnemyObject * [m_nGameObjects];

	m_pParticleModel = CGameObject::LoadGeometryFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "Model/Cube.bin");
	ParticleCNT = 300;
	CEnemyObject* pApacheObject = NULL;

	CGameObject* pOldCarModel = CGameObject::LoadGeometryFromFile(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature, "Model/OldCar.bin");
	//CGunshipObject* pGunshipObject = NULL;
	pApacheObject = new CEnemyObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	pApacheObject->SetChild(pOldCarModel, true);
	pApacheObject->OnInitialize();
	pApacheObject->SetPosition(1900.f, 0, 2000.f);
	pApacheObject->SetScale(5.0f, 5.0f, 5.0f);
	pApacheObject->Rotate(0.0f, 180.0f, 0.0f);
	pApacheObject->m_xmOOBB = BoundingOrientedBox(pApacheObject->GetPosition(), XMFLOAT3(5.0f, 5.0f, 7.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
	pApacheObject->SetOOBB();
	m_ppGameObjects[0] = pApacheObject;

	pApacheObject = new CEnemyObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	pApacheObject->SetChild(pOldCarModel, true);
	pApacheObject->OnInitialize();
	pApacheObject->SetPosition(2000.0f,0, 1300.0f);
	pApacheObject->SetScale(5.0f, 5.0f, 5.0f);
	pApacheObject->Rotate(0.0f, 180.0f, 0.0f);

	m_ppGameObjects[1] = pApacheObject;
	m_ppGameObjects[1]->m_xmOOBB = BoundingOrientedBox(pApacheObject->GetPosition(), XMFLOAT3(5.0f, 5.0f, 7.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
	pApacheObject->SetOOBB();

	pApacheObject = new CEnemyObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	pApacheObject->SetChild(pOldCarModel, true);
	pApacheObject->OnInitialize();
	pApacheObject->SetPosition(1500.0f,0, 3000.0f);
	pApacheObject->SetScale(5.0f, 5.0f, 5.0f);
	pApacheObject->Rotate(0.0f, 180.0f, 0.0f);

	m_ppGameObjects[2] = pApacheObject;
	m_ppGameObjects[2]->m_xmOOBB = BoundingOrientedBox(pApacheObject->GetPosition(), XMFLOAT3(5.0f, 5.0f, 7.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
	pApacheObject->SetOOBB();


	pApacheObject = new CEnemyObject(pd3dDevice, pd3dCommandList, m_pd3dGraphicsRootSignature);
	pApacheObject->SetChild(pOldCarModel, true);
	pApacheObject->OnInitialize();
	pApacheObject->SetPosition(2400.0f,0, 3000.0f);
	pApacheObject->SetScale(5.0f, 5.0f, 5.0f);
	pApacheObject->Rotate(0.0f, 180.0f, 0.0f);

	m_ppGameObjects[3] = pApacheObject;
	m_ppGameObjects[3]->m_xmOOBB = BoundingOrientedBox(pApacheObject->GetPosition(), XMFLOAT3(5.0f, 5.0f, 7.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
	pApacheObject->SetOOBB();
	for (int i = 0; i < m_nGameObjects; ++i) {
		m_ppGameObjects[i]->setTerrain(m_pTerrain);
	}

	Particles_Object(XMFLOAT3(0.0f, 0.0f, 0.0f), 20);


	for (int i = 0; i < 4; i++)
		EnermyParticles(m_ppGameObjects[i]->GetPosition(), 20);


	CreateShaderVariables(pd3dDevice, pd3dCommandList);
}

void CScene::ReleaseObjects()
{
	if (m_pd3dGraphicsRootSignature) m_pd3dGraphicsRootSignature->Release();

	if (m_ppGameObjects)
	{
		for (int i = 0; i < m_nGameObjects; i++) if (m_ppGameObjects[i]) m_ppGameObjects[i]->Release();
		delete[] m_ppGameObjects;
	}
	//터레인
	if (m_pTerrain) delete m_pTerrain;
	// 
	//나무
	//Building_Object
	if (pBuilding_Objects)
	{
		for (int i = 0; i < BuldingNum; i++) if (pBuilding_Objects[i]) pBuilding_Objects[i]->Release();
		delete[] pBuilding_Objects;
	}

	
	//pLamp_Objects
	if (pLamp_Objects)
	{
		for (int i = 0; i < 1; i++) if (pLamp_Objects[i]) pLamp_Objects[i]->Release();
		delete[] pLamp_Objects;
	}
	if (pTree_Objects)
	{
		for (int i = 0; i < TreeObjects; i++) if (pTree_Objects[i]) pTree_Objects[i]->Release();
		delete[] pTree_Objects;
	}

	if (pParticle)
	{
		for (int i = 0; i < ParticleCNT; i++) if (pParticle[i]) pParticle[i]->Release();
		delete[] pParticle;
	}

	ReleaseShaderVariables();

	if (m_pLights) delete[] m_pLights;
}

ID3D12RootSignature* CScene::CreateGraphicsRootSignature(ID3D12Device* pd3dDevice)
{
	ID3D12RootSignature* pd3dGraphicsRootSignature = NULL;

	D3D12_ROOT_PARAMETER pd3dRootParameters[3];

	pd3dRootParameters[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
	pd3dRootParameters[0].Descriptor.ShaderRegister = 1; //Camera
	pd3dRootParameters[0].Descriptor.RegisterSpace = 0;
	pd3dRootParameters[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	pd3dRootParameters[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
	pd3dRootParameters[1].Constants.Num32BitValues = 32;
	pd3dRootParameters[1].Constants.ShaderRegister = 2; //GameObject
	pd3dRootParameters[1].Constants.RegisterSpace = 0;
	pd3dRootParameters[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	pd3dRootParameters[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
	pd3dRootParameters[2].Descriptor.ShaderRegister = 4; //Lights
	pd3dRootParameters[2].Descriptor.RegisterSpace = 0;
	pd3dRootParameters[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	D3D12_ROOT_SIGNATURE_FLAGS d3dRootSignatureFlags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT | D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS;
	D3D12_ROOT_SIGNATURE_DESC d3dRootSignatureDesc;
	::ZeroMemory(&d3dRootSignatureDesc, sizeof(D3D12_ROOT_SIGNATURE_DESC));
	d3dRootSignatureDesc.NumParameters = _countof(pd3dRootParameters);
	d3dRootSignatureDesc.pParameters = pd3dRootParameters;
	d3dRootSignatureDesc.NumStaticSamplers = 0;
	d3dRootSignatureDesc.pStaticSamplers = NULL;
	d3dRootSignatureDesc.Flags = d3dRootSignatureFlags;

	ID3DBlob* pd3dSignatureBlob = NULL;
	ID3DBlob* pd3dErrorBlob = NULL;
	D3D12SerializeRootSignature(&d3dRootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &pd3dSignatureBlob, &pd3dErrorBlob);
	pd3dDevice->CreateRootSignature(0, pd3dSignatureBlob->GetBufferPointer(), pd3dSignatureBlob->GetBufferSize(), __uuidof(ID3D12RootSignature), (void**)&pd3dGraphicsRootSignature);
	if (pd3dSignatureBlob) pd3dSignatureBlob->Release();
	if (pd3dErrorBlob) pd3dErrorBlob->Release();

	return(pd3dGraphicsRootSignature);
}

void CScene::CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	UINT ncbElementBytes = ((sizeof(LIGHTS) + 255) & ~255); //256의 배수
	m_pd3dcbLights = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL, ncbElementBytes, D3D12_HEAP_TYPE_UPLOAD, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);

	m_pd3dcbLights->Map(0, NULL, (void**)&m_pcbMappedLights);
}

void CScene::UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList)
{
	::memcpy(m_pcbMappedLights->m_pLights, m_pLights, sizeof(LIGHT) * m_nLights);
	::memcpy(&m_pcbMappedLights->m_xmf4GlobalAmbient, &m_xmf4GlobalAmbient, sizeof(XMFLOAT4));
	::memcpy(&m_pcbMappedLights->m_nLights, &m_nLights, sizeof(int));
}

void CScene::ReleaseShaderVariables()
{
	if (m_pd3dcbLights)
	{
		m_pd3dcbLights->Unmap(0, NULL);
		m_pd3dcbLights->Release();
	}
}
void CScene::ReleaseUploadBuffers()
{
	for (int i = 0; i < m_nGameObjects; i++) m_ppGameObjects[i]->ReleaseUploadBuffers();
	for (int i = 0; i < TreeObjects; i++) pTree_Objects[i]->ReleaseUploadBuffers();
	for (int i = 0; i < BuldingNum; i++) pBuilding_Objects[i]->ReleaseUploadBuffers();
	for (int i = 0; i < LampNum; i++) pLamp_Objects[i]->ReleaseUploadBuffers();

	if (m_pTerrain) m_pTerrain->ReleaseUploadBuffers();

	
}

bool CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	return(false);
}

bool CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{

			break;
		case 'F':	
		default:
			break;
		}
		break;
	default:
		break;
	}
	return(false);
}

bool CScene::ProcessInput(UCHAR* pKeysBuffer)
{
	return(false);
}


void CScene::EnemyByEnemyCollisions()
{
	if (m_ppGameObjects[0]->m_xmOOBB.Intersects(m_ppGameObjects[1]->m_xmOOBB))m_ppGameObjects[0]->m_xmf4x4Transform._41 -= 30.0f;
	if (m_ppGameObjects[0]->m_xmOOBB.Intersects(m_ppGameObjects[2]->m_xmOOBB))m_ppGameObjects[0]->m_xmf4x4Transform._43 -= 30.0f;
	if (m_ppGameObjects[1]->m_xmOOBB.Intersects(m_ppGameObjects[2]->m_xmOOBB))m_ppGameObjects[1]->m_xmf4x4Transform._41 -= 30.0f;
	if (m_ppGameObjects[1]->m_xmOOBB.Intersects(m_ppGameObjects[3]->m_xmOOBB))m_ppGameObjects[1]->m_xmf4x4Transform._43 -= 30.0f;
	if (m_ppGameObjects[2]->m_xmOOBB.Intersects(m_ppGameObjects[3]->m_xmOOBB))m_ppGameObjects[2]->m_xmf4x4Transform._41 -= 30.0f;
	if (m_ppGameObjects[2]->m_xmOOBB.Intersects(m_ppGameObjects[1]->m_xmOOBB))m_ppGameObjects[2]->m_xmf4x4Transform._43 -= 30.0f;

}

void CScene::EnemyByBulletCollisions()
{
	CBulletObject** ppBullets = ((HeroPlayer*)m_pPlayer)->m_ppBullets;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < BULLETS; j++)
		{
			if (ppBullets[j]->m_bActive && m_ppGameObjects[i]->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB))
			{
				CEnemyObject* pExplosiveObject = (CEnemyObject*)m_ppGameObjects[i];
				pExplosiveObject->m_bBlowingUp = true;
				if (i)
				{
					for (int k = 0; k < ParticleCNT; k++)
					{
						pParticle[k]->SetMovingSpeed(60.0f);
						pParticle[k]->SetPosition(m_ppGameObjects[i]->GetPosition());
					}
				}
				ppBullets[j]->Reset();
			}
		}
	}
}



void CScene::PlayerByBulletCollisions()
{
	for (int i = 0; i < 4; i++)
	{
		CBulletObject** ppBullets = ((CEnemyObject*)m_ppGameObjects[i])->m_ppBullets;
		for (int j = 0; j < BULLETS; j++)
		{
			if (ppBullets[j]->m_bActive && m_pPlayer->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB))
			{
				m_pPlayer->playercollCNT();
				if (m_pPlayer->mycollision > 500) {
					int count = m_pPlayer->mycollision;
					m_bGameOver = true;
					for (int i = 0; i < ParticleCNT; i++)
					{
						pParticle[i]->SetMovingSpeed(60.0f);
						pParticle[i]->SetPosition(m_pPlayer->GetPosition());
					}
					m_pPlayer->mycollision = 0;
				}

		
			}
		}
	}


}

void CScene::AnimateObjects(float fTimeElapsed)
{

	for (int i = 0; i < 4; ++i) {
		XMFLOAT3 enemyPos = m_ppGameObjects[i]->GetPosition();
		if (m_pTerrain->GetHeight(enemyPos.x, enemyPos.z)<enemyPos.y) {
			enemyPos.y -= 1.0;
			m_ppGameObjects[i]->SetPosition(enemyPos.x, enemyPos.y, enemyPos.z);
		}
	}
	m_fElapsedTime = fTimeElapsed;
	static float cnt = 0;
	cnt += fTimeElapsed;

	XMFLOAT3 PlayerLook = ((HeroPlayer*)m_pPlayer)->GetUp();
	XMFLOAT3 PlayerPosition = ((HeroPlayer*)m_pPlayer)->GetPosition();
	if (cnt > 4) {
		for (int i = 0; i < 4; i++) {
			((CEnemyObject*)m_ppGameObjects[i])->FireBullet(NULL);
		}
		cnt = 0;
	}
	for (int i = 0; i < m_nGameObjects; i++) 
	{
		m_ppGameObjects[i]->LookAt(PlayerPosition, XMFLOAT3(0, 1, 0));
		m_ppGameObjects[i]->UpdateTransform();
		m_ppGameObjects[i]->SetScale(5.0, 5.0, 5.0);
		m_ppGameObjects[i]->OnEnemyUpdateCallback(fTimeElapsed);
	}
	//총알과 충돌시 원래 자리로 리스폰 
	if (m_ppGameObjects[0]->m_bBlowingUp == true) {
		m_ppGameObjects[0]->SetPosition(1900.f, m_pTerrain->GetHeight(1900.f, 2000.f), 2000.f);
		m_ppGameObjects[0]->m_bBlowingUp = false;
	}
	if (m_ppGameObjects[1]->m_bBlowingUp == true) {
		m_ppGameObjects[1]->SetPosition(2000.0f, m_pTerrain->GetHeight(2000.0f, 1300.0f), 1300.0f);
		m_ppGameObjects[1]->m_bBlowingUp = false;

	}
	if (m_ppGameObjects[2]->m_bBlowingUp == true) {
		m_ppGameObjects[2]->SetPosition(1500.0f, m_pTerrain->GetHeight(1500.0f, 3000.0f), 3000.0f);
		m_ppGameObjects[2]->m_bBlowingUp = false;

	}
	if (m_ppGameObjects[3]->m_bBlowingUp == true) {
		m_ppGameObjects[3]->SetPosition(2400.0f, m_pTerrain->GetHeight(2400.0f, 3000.0f), 3000.0f);
		m_ppGameObjects[3]->m_bBlowingUp = false;

	}

	for (int i = 0; i < 4; i++)
	{
		m_fSpeed = 0.001;
		m_ppGameObjects[i]->m_xmf4x4Transform._41 += ((-m_ppGameObjects[i]->m_xmf4x4Transform._41 + m_pPlayer->GetPosition().x) / (m_fSpace + (i * 2.0))) + m_fSpeed;
		m_ppGameObjects[i]->m_xmf4x4Transform._43 += ((-m_ppGameObjects[i]->m_xmf4x4Transform._43 + m_pPlayer->GetPosition().z) / (m_fSpace + (i * 2.0))) + m_fSpeed;
	}
	if (m_bGameOver) {
		m_pPlayer->Sleep();
		m_fRestartCounter += fTimeElapsed;
		if (m_ppGameObjects[0]->is_chack) { //충돌시 적 객체는 원래 자리로 .. 
			m_ppGameObjects[0]->SetPosition(1925.f, m_pTerrain->GetHeight(1925.f, 1950.f), 1950.f);
			m_ppGameObjects[1]->SetPosition(2035.0f, m_pTerrain->GetHeight(2035.0f, 1500.0f), 1500.0f);
			m_ppGameObjects[2]->SetPosition(1800.0f, m_pTerrain->GetHeight(1800.0f, 2500.0f), 2500.0f);
			m_ppGameObjects[3]->SetPosition(2200.0f, m_pTerrain->GetHeight(2200.0f, 2500.0f), 2500.0f);
			m_ppGameObjects[0]->is_chack = false;
		}

		if (m_fRestartCounter > 2)
		{
			m_fRestartCounter = 0.0f;
			m_bGameOver = false;
			m_pPlayer->Awake();
			m_pPlayer->Reset();
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (m_ppGameObjects[i]->GetPosition().z < -40.0f) //오브젝트가 움직임 
		{
			m_ppGameObjects[i]->SetPositionZ(RANDOM_NUM(400, 900));
			m_ppGameObjects[i]->SetPositionX(RANDOM_NUM(-900, 900));
		}
	}
	for (int i = 0; i < m_nGameObjects; i++) m_ppGameObjects[i]->Animate(fTimeElapsed, NULL);
	for (int i = 0; i < TreeObjects; i++) pTree_Objects[i]->Animate(fTimeElapsed, NULL);
	for (int i = 0; i < LampNum; i++) pLamp_Objects[i]->Animate(fTimeElapsed, NULL);
	for (int i = 0; i < BuldingNum; i++) pBuilding_Objects[i]->Animate(fTimeElapsed, NULL);
	for (int i = 0; i < ParticleCNT; i++)pParticle[i]->Animate(fTimeElapsed, NULL);

	m_pPlayer->Animate(fTimeElapsed, NULL);
	if (m_pLights)
	{
		m_pLights[1].m_xmf3Position = m_ppGameObjects[0]->GetPosition();
		m_pLights[1].m_xmf3Direction = m_ppGameObjects[0]->GetLook();
		m_pLights[2].m_xmf3Position = m_ppGameObjects[1]->GetPosition();
		m_pLights[2].m_xmf3Direction = m_ppGameObjects[1]->GetLook();
		m_pLights[3].m_xmf3Position = m_ppGameObjects[2]->GetPosition();
		m_pLights[3].m_xmf3Direction = m_ppGameObjects[2]->GetLook();
		m_pLights[4].m_xmf3Position = m_ppGameObjects[3]->GetPosition();
		m_pLights[4].m_xmf3Direction = m_ppGameObjects[3]->GetLook();
	
		m_pLights[5].m_xmf3Position = m_pPlayer->GetPosition();
		m_pLights[5].m_xmf3Direction = m_pPlayer->GetLookVector();
		for (int i = 0; i < LampNum; ++i) {
			m_pLights[i+6].m_xmf3Position = pLamp_Objects[i]->GetPosition();
			m_pLights[i+6].m_xmf3Position.y = pLamp_Objects[i]->GetPosition().y +80;
			m_pLights[i+6].m_xmf3Position.z = pLamp_Objects[i]->GetPosition().z +40;
		}
		
	}
	PlayeByObjectCollision();
	EnemyByEnemyCollisions();
	EnemyByBulletCollisions();
	PlayerByBulletCollisions();
}


void CScene::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	for (int i = 0; i < 4; ++i) {
		m_ppGameObjects[i]->Update(m_fElapsedTime);
	}
	pd3dCommandList->SetGraphicsRootSignature(m_pd3dGraphicsRootSignature);

	pCamera->SetViewportsAndScissorRects(pd3dCommandList);
	pCamera->UpdateShaderVariables(pd3dCommandList);

	UpdateShaderVariables(pd3dCommandList);

	D3D12_GPU_VIRTUAL_ADDRESS d3dcbLightsGpuVirtualAddress = m_pd3dcbLights->GetGPUVirtualAddress();
	pd3dCommandList->SetGraphicsRootConstantBufferView(2, d3dcbLightsGpuVirtualAddress); //Lights
	if (m_pTerrain) m_pTerrain->Render(pd3dCommandList, pCamera);

	for (int i = 0; i < 4; i++)
	{
		static int count = 0;
		if (m_ppGameObjects[i] && m_ppGameObjects[i]->m_bBlowingUp == false) //충돌처리 효과주기 
		{
			m_ppGameObjects[i]->Animate(m_fElapsedTime, NULL);
			m_ppGameObjects[i]->UpdateTransform(NULL);
			m_ppGameObjects[i]->CGameObject::Render(pd3dCommandList, pCamera);
			m_ppGameObjects[i]->Render(pd3dCommandList, pCamera);
		}
		if (m_ppGameObjects[i] && m_ppGameObjects[i]->m_bBlowingUp == true) {
			count += 1;
			if (count >= 1000) {
				m_ppGameObjects[i]->m_bBlowingUp = false;
				count = 0;
			}
		}
	}

	for (int i = 0; i < TreeObjects; ++i) {
		if (pTree_Objects[i])
		{
			pTree_Objects[i]->Animate(m_fElapsedTime, NULL);
			pTree_Objects[i]->UpdateTransform(NULL);
			pTree_Objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
	for (int i = 0; i < LampNum; ++i) {
		if (pLamp_Objects[i])
		{
			pLamp_Objects[i]->Animate(m_fElapsedTime, NULL);
			pLamp_Objects[i]->UpdateTransform(NULL);
			pLamp_Objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
	for (int i = 0; i < BuldingNum; ++i) {
		if (pBuilding_Objects[i])
		{
			pBuilding_Objects[i]->Animate(m_fElapsedTime, NULL);
			pBuilding_Objects[i]->UpdateTransform(NULL);
			pBuilding_Objects[i]->Render(pd3dCommandList, pCamera);
		}
	}
	for (int i = 0; i < ParticleCNT; i++) //파티클 작동 w
	{
		if (pParticle[i] && m_bGameOver)
		{
			pParticle[i]->Animate(m_fElapsedTime, NULL);
			pParticle[i]->UpdateTransform(NULL);
			pParticle[i]->Render(pd3dCommandList, pCamera);
		}
		if (pParticle[i])
		{
			pParticle[i]->Animate(m_fElapsedTime, NULL);
			pParticle[i]->UpdateTransform(NULL);
			pParticle[i]->Render(pd3dCommandList, pCamera);
		}
	}

}

void CScene::PlayeByObjectCollision()
{
	for (int i = 0; i < m_nGameObjects; i++)
	{
		BoundingOrientedBox wmPlayerOOBB = m_pPlayer->m_xmOOBB;
		ContainmentType containType = m_ppGameObjects[i]->m_xmOOBB.Contains(wmPlayerOOBB);

		if (m_ppGameObjects[i]->m_xmOOBB.Intersects(wmPlayerOOBB))
		{
			XMFLOAT3 CameraPosition = m_pPlayer->GetCamera()->GetPosition();
			m_bGameOver = true;
			m_ppGameObjects[0]->is_chack = true;

			for (int i = 0; i < ParticleCNT; i++)
			{
				pParticle[i]->SetMovingSpeed(60.0f);
				pParticle[i]->SetPosition(m_pPlayer->GetPosition());
			}
		}
	}
	for (int i = 0; i < TreeObjects; i++)
	{
		BoundingOrientedBox wmPlayerOOBB = m_pPlayer->m_xmOOBB;
		ContainmentType containType = pTree_Objects[i]->m_xmOOBB.Contains(wmPlayerOOBB);

		if (pTree_Objects[i]->m_xmOOBB.Intersects(wmPlayerOOBB))
		{
			XMFLOAT3 CameraPosition = m_pPlayer->GetCamera()->GetPosition();
			m_bGameOver = true;

			for (int i = 0; i < ParticleCNT; i++)
			{
				pParticle[i]->SetMovingSpeed(60.0f);
				pParticle[i]->SetPosition(m_pPlayer->GetPosition());
			}
		}
	}

	for (int i = 0; i < BuldingNum; i++)
	{
		BoundingOrientedBox wmPlayerOOBB = m_pPlayer->m_xmOOBB;
		ContainmentType containType = pBuilding_Objects[i]->m_xmOOBB.Contains(wmPlayerOOBB);

		if (pBuilding_Objects[i]->m_xmOOBB.Intersects(wmPlayerOOBB))
		{
			XMFLOAT3 CameraPosition = m_pPlayer->GetCamera()->GetPosition();
			m_bGameOver = true;

			for (int i = 0; i < ParticleCNT; i++)
			{
				pParticle[i]->SetMovingSpeed(60.0f);
				pParticle[i]->SetPosition(m_pPlayer->GetPosition());
			}
		}
	}



}

void CScene::Particles_Object(XMFLOAT3 pos, int nParticles)
{
	pParticle = new CParticleObject * [ParticleCNT];
	CParticleObject* pParticleObject = NULL;
	for (int i = 0; i < ParticleCNT; i++)
	{
		pParticleObject = new CParticleObject();
		pParticleObject->SetChild(m_pParticleModel, true);
		pParticleObject->OnInitialize();
		pParticleObject->Awake();
		pParticleObject->SetMovingDirection(XMFLOAT3(
			(float)RANDOM_NUM(-1000, 1000),
			(float)RANDOM_NUM(-1000, 1000),
			(float)RANDOM_NUM(-1000, 1000)));
		pParticleObject->SetPosition(pos);
		pParticleObject->SetScale(5.0f, 5.0f, 5.0f);
		pParticleObject->SetMovingRange(1.0f);
		pParticleObject->SetRotationAxis(XMFLOAT3(
			(float)RANDOM_NUM(-1000, 1000),
			(float)RANDOM_NUM(-1000, 1000),
			(float)RANDOM_NUM(-1000, 1000)));
		pParticleObject->SetRotationSpeed((float)RANDOM_NUM(50, 100));
		pParticleObject->SetMovingSpeed(.0f);
		pParticle[i] = pParticleObject;
	}

}

void CScene::EnermyParticles(XMFLOAT3 pos, int nParticles)
{
	pParticle = new CParticleObject * [ParticleCNT];
	CParticleObject* pParticleObject = NULL;
	for (int i = 0; i < ParticleCNT; i++)
	{
		pParticleObject = new CParticleObject();
		pParticleObject->SetChild(m_pParticleModel, true);
		pParticleObject->OnInitialize();
		pParticleObject->Awake();
		pParticleObject->SetMovingDirection(XMFLOAT3(
			(float)RANDOM_NUM(-1000, 1000),
			(float)RANDOM_NUM(-1000, 1000),
			(float)RANDOM_NUM(-1000, 1000)));
		pParticleObject->SetPosition(pos);
		pParticleObject->SetScale(5.0f, 5.0f, 5.0f);
		pParticleObject->SetMovingRange(1.0f);
		pParticleObject->SetRotationAxis(XMFLOAT3(
			(float)RANDOM_NUM(-1000, 1000),
			(float)RANDOM_NUM(-1000, 1000),
			(float)RANDOM_NUM(-1000, 1000)));
		pParticleObject->SetRotationSpeed((float)RANDOM_NUM(50, 100));
		pParticleObject->SetMovingSpeed(.0f);
		pParticle[i] = pParticleObject;
	}


}

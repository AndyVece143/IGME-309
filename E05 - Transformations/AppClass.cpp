#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Andy vece - ajv2073@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes
	/*
	m_pMesh = new MyMesh();
	m_pMesh->GenerateCube(1.0f, C_BLACK);
	*/

	m_uMeshCount = 100;
	for (int i = 0; i < m_uMeshCount; i++)
	{
		MyMesh* mesh = new MyMesh();
		meshList.push_back(mesh);
		meshList[i]->GenerateCube(1.0f, C_BLUE);
	}
		
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	static float fTimer = 0;	//store the new timer
	static uint uClock = m_pSystem->GenClock(); //generate a new clock for that timer
	fTimer += static_cast<float>(m_pSystem->GetDeltaTime(uClock)); //get the delta time for that timer

	//m_pMesh->Render(m4Projection, m4View, ToMatrix4(m_qArcBall));

	uint i = 0;
	static float fHorizontal = -10.0f;
	static vector3 v3Position(fHorizontal, 0.0f, 0.0f);

	v3Position.x = fHorizontal + fTimer;
	v3Position.y = glm::cos(glm::radians(fTimer * 60.0f));
	matrix4 m4Position = glm::translate(vector3(-5.0f, 0.0f, -15.0f)) * glm::translate(v3Position);

	//Row 1
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 8.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(9.0f, 8.0f, 0.0f))); i++;

	//Row 2
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 7.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 7.0f, 0.0f))); i++;

	//Row 3
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 6.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 6.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 6.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 6.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 6.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 6.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(9.0f, 6.0f, 0.0f))); i++;

	//Row 4
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 5.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 5.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 5.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 5.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 5.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(9.0f, 5.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(10.0f, 5.0f, 0.0f))); i++;

	//Row 5
	
	for (int j = 0; j < 11; j++)
	{
		meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(j + 1.0f, 4.0f, 0.0f))); i++;
	}

	//Row 6
	
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(1.0f, 3.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 3.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 3.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 3.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 3.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 3.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 3.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(9.0f, 3.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(11.0f, 3.0f, 0.0f))); i++;

	//Row 7
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(1.0f, 2.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 2.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(9.0f, 2.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(11.0f, 2.0f, 0.0f))); i++;
	
	//Row 8
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 1.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 1.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 1.0f, 0.0f))); i++;
	meshList[i]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 1.0f, 0.0f))); i++;

	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//Release meshes
	//SafeDelete(m_pMesh);
	std::vector<MyMesh*> m_pMeshList;
	uint uSize = m_pMeshList.size();
	for (uint i = 0; i < uSize; ++i)
	{
		if (m_pMeshList[i] != nullptr)
		{
			delete m_pMeshList[i];
			m_pMeshList[i] = nullptr;
		}
	}

	//release GUI
	ShutdownGUI();
}
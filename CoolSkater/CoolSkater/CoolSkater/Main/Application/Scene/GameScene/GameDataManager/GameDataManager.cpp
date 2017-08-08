﻿
//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "GameDataManager.h"


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
GameDataManager::GameDataManager() : 
	m_PlayerSpeed(0.0f),
	m_Score(0),
	m_Life(0),
	m_PlayerProgress(0.0f),
	m_IsGolden(false)
{
}

GameDataManager::~GameDataManager()
{
}

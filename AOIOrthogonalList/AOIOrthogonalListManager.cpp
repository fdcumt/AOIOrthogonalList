
#include "AOIOrthogonalListManager.h"

AOI_OrthogonalListManager::AOI_OrthogonalListManager()
{
	m_pXHead.m_PreEntity = &m_pXHead;
	m_pXHead.m_NextEntity = &m_pXHead;

	m_pYHead.m_PreEntity = &m_pYHead;
	m_pYHead.m_NextEntity = &m_pYHead;
}

void AOI_OrthogonalListManager::Enter(KeyType key, float InX, float InY)
{
	add(key, InX, m_XMap, &m_pXHead);
	add(key, InY, m_YMap, &m_pYHead);
}

void AOI_OrthogonalListManager::Leave(KeyType key)
{
	remove(key, m_XMap, &m_pXHead);
	remove(key, m_YMap, &m_pYHead);
}

void AOI_OrthogonalListManager::add(KeyType id, float value, std::map<KeyType, AOI_OrthogonalListEntity*> &MapRef, AOI_OrthogonalListEntity *pHead)
{
	remove(id, MapRef, pHead); 

	AOI_OrthogonalListEntity* pNewNode = new AOI_OrthogonalListEntity;

	pNewNode->m_value = value;
	AOI_OrthogonalListEntity *pCurNode = pHead->m_NextEntity;

	while (pCurNode != pHead && value>pCurNode->m_value)
	{
		pCurNode = pCurNode->m_NextEntity;
	}

	pNewNode->m_NextEntity = pCurNode;
	pNewNode->m_PreEntity = pCurNode->m_PreEntity;

	pNewNode->m_PreEntity->m_NextEntity = pNewNode;
	pNewNode->m_NextEntity->m_PreEntity = pNewNode;
}

void AOI_OrthogonalListManager::remove(KeyType id, std::map<KeyType, AOI_OrthogonalListEntity*> &MapRef, AOI_OrthogonalListEntity *pHead)
{
	std::map<KeyType, AOI_OrthogonalListEntity*>::iterator it = MapRef.find(id);

	if (it == MapRef.end()) 
	{
		return ;
	}

	AOI_OrthogonalListEntity* pNode = it->second;

	pNode->m_PreEntity->m_NextEntity = pNode->m_NextEntity;
	pNode->m_NextEntity->m_PreEntity = pNode->m_PreEntity;

	pNode->m_NextEntity = NULL;
	pNode->m_PreEntity  = NULL;

	delete pNode;
}


#pragma once
#include <map>
typedef int KeyType ;

struct AOI_OrthogonalListEntity
{
	float m_value;
	AOI_OrthogonalListEntity *m_PreEntity;
	AOI_OrthogonalListEntity *m_NextEntity;
};

class AOI_OrthogonalListManager
{
public:
	AOI_OrthogonalListManager();
	void Enter(KeyType key, float InX, float InY);
	void Leave(KeyType key);

private:
	// 从小到大
	AOI_OrthogonalListEntity m_pXHead;
	AOI_OrthogonalListEntity m_pYHead;

	std::map<KeyType, AOI_OrthogonalListEntity*> m_XMap;
	std::map<KeyType, AOI_OrthogonalListEntity*> m_YMap;

private:
	void add(KeyType id, float value, std::map<KeyType, AOI_OrthogonalListEntity*> &MapRef, AOI_OrthogonalListEntity *pHead);
	void remove(KeyType id, std::map<KeyType, AOI_OrthogonalListEntity*> &MapRef, AOI_OrthogonalListEntity *pHead);
};



#pragma once

typedef struct _tabArr
{
public:
	int* pInt; 
	int iCount;
	int iMaxCount;
protected:

private:

}tArr;
void InitArr(tArr* _pArr);

void ReleaseArr(tArr* _pArr);

void PushBack(tArr* _pArr, int _iData);

void Reallocte(tArr* _pArr);
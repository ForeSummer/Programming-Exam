
// ColorBoardDoc.h : CColorBoardDoc ��Ľӿ�
//


#pragma once
#include "Geometry.h"
#include "Line.h"
#include "Circle.h"
#include "Rectan.h"

class CColorBoardDoc : public CDocument
{
protected: // �������л�����
	CColorBoardDoc();
	DECLARE_DYNCREATE(CColorBoardDoc)

// ����
public:
	CObArray geometries;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CColorBoardDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

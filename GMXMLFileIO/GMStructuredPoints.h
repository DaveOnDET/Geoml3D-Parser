#pragma once
#include "vtkStructuredPoints.h"
#include "export.h"
#include<string>
#include "vtkMatrix4x4.h"


class GMXMLFILEIO_EXPORT GMStructuredPoints : public vtkStructuredPoints
{
public:
	GMStructuredPoints(void);
	~GMStructuredPoints(void);

	static GMStructuredPoints *New();
	vtkTypeMacro(GMStructuredPoints, vtkStructuredPoints);
	
	std::string GetID();
	void SetID(std::string);
	vtkMatrix4x4*  GetTransformMatrix();
	void CreateTransformMatrix();
	void ReadFile(char*);
protected:
	std::string         _ID;
	vtkMatrix4x4*       _TransformMatrix;

	//std::string         _Labels[3];
	//std::string         _Uom;
};


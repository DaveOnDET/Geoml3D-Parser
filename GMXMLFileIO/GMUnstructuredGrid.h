#pragma once
#include "vtkUnstructuredGrid.h"
#include "Export.h"
#include<string>

class GMXMLFILEIO_EXPORT GMUnstructuredGrid : public vtkUnstructuredGrid
{
public:
	GMUnstructuredGrid(void);
	~GMUnstructuredGrid(void);
	vtkTypeMacro(GMUnstructuredGrid, vtkUnstructuredGrid);
	static GMUnstructuredGrid *New();
	std::string GetID();
	void SetID(std::string);
	int GetGeometryType();
	void SetGeometryType(int i);
	void ReadFile(char* filename);
protected:
	std::string         _ID;
	int                 _GeometryType; // 1:tin 2 ten 3 line 4 point
};

